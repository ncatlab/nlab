#!/usr/bin/python3

"""
This API is designed so that the data governing the processing of jobs to be
immutable, and so that race conditions should not occur.
"""
import argparse
import datetime
import enum
import errno
import json
import logging
import os
import requests
import shutil
import subprocess
import sys
import time

"""
Initialises logging. Logs to

queue.log
"""
logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)
logging.Formatter.converter = time.gmtime
logging_formatter = logging.Formatter(
    "%(asctime)s %(levelname)s %(name)s %(message)s")
log_directory = os.environ["NLAB_LOG_DIRECTORY"]
logging_file_handler = logging.FileHandler(
    os.path.join(log_directory, "sequential_queue.log"))
logging_file_handler.setFormatter(logging_formatter)
logger.addHandler(logging_file_handler)

class InvalidJobJsonException(Exception):
    def __init__(self, message):
        self.message = message

_job_completed_directory_name = "completed"
_job_completed_time_file_name = "completed_time"
_job_completion_status_file_name = "completion_status"
_job_execution_json_file_name = "execution.json"
_job_json_file_name = "job.json"
_job_started_directory_name = "started"
_job_start_status_file_name = "start_status"
_job_start_time_file_name = "start_time"
_date_time_string_format = "%Y-%m-%d %H:%M:%S.%f"
_currently_processing_directory_name = "currently_processing"
_currently_processing_path = os.path.join(
    os.environ["QUEUE_CONTROL_DIRECTORY"],
    _currently_processing_directory_name)

class JobProcessingControl(enum.Enum):
    START = "start"

    def __str__(self):
        return self.value

class CallbackJobStatus(enum.Enum):
    COMPLETED_SUCCESSFULLY = "completed_successfully"
    COMPLETED_UNSUCCESSFULLY = "completed_unsuccessfully"

    def __str__(self):
        return self.value

class JobCompletionStatus(enum.Enum):
    COMPLETED_SUCCESSFULLY = CallbackJobStatus.COMPLETED_SUCCESSFULLY.value
    COMPLETED_UNSUCCESSFULLY = CallbackJobStatus.COMPLETED_UNSUCCESSFULLY.value
    EXPIRED = "expired"
    FAILED_TO_START = "failed_to_start"

class JobStartStatus(enum.Enum):
    SUCCESS = "success"
    FAILURE = "failure"

def _validate(job_json):
    try:
        job_json["max_time"]
    except KeyError:
        raise InvalidJobJsonException(
            "Missing key: max_time")
    try:
        job_json["execution_commands"]
        is_command_line_job = True
    except KeyError:
        is_command_line_job = False
    if is_command_line_job:
        if len(job_json.keys()) > 2:
            raise InvalidJobJsonException(
                "Unexpected key. If the key execution_commands is present, " +
                 "no other keys except max_time should be present")
        return
    try:
        job_json["execution_url"]
    except KeyError:
        raise InvalidJobJsonException(
            "Missing key: execution_url")
    try:
        job_json["execution_method"]
    except KeyError:
        raise InvalidJobJsonException(
            "Missing key: execution_method")
    try:
        job_json["execution_json"]
    except KeyError:
        raise InvalidJobJsonException(
            "Missing key: execution_json")
    if len(job_json.keys()) > 4:
        raise InvalidJobJsonException(
            "Unexpected key. Exactly the following keys must be present " +
            "if the key execution_commands is not present: " +
            "execution_url, execution_method, execution_json, max_time")

def _timestamp():
    current_datetime = datetime.datetime.utcnow()
    timestamp_components = [
        current_datetime.strftime("%Y"),
        current_datetime.strftime("%m"),
        current_datetime.strftime("%d"),
        current_datetime.strftime("%H"),
        current_datetime.strftime("%M"),
        current_datetime.strftime("%S"),
        current_datetime.strftime("%f") ]
    return "".join([str(timestamp_component) for timestamp_component in \
        timestamp_components])

def _max_time_exceeded(job_path, job_start_time_path):
    with open(job_start_time_path, "r") as job_start_time_file:
        job_start_time_string = job_start_time_file.read()
    job_start_time = datetime.datetime.strptime(
        job_start_time_string,
        _date_time_string_format)
    current_time = datetime.datetime.utcnow()
    job_json_path = os.path.join(
        job_path,
        _job_json_file_name)
    with open(job_json_path, "r") as job_json_file:
        job_json = json.load(job_json_file)
    max_time = job_json["max_time"]
    time_delta = current_time - job_start_time
    time_taken = time_delta.total_seconds()
    return time_taken > max_time, current_time

def _expire(
        current_time,
        job_id):
    _update_job_status(job_id, JobCompletionStatus.EXPIRED)
    logger.info(
        "Marked job with id " +
        str(job_id) +
        " as expired")

def  _execute_http_job(job_id, job_json, job_started_path):
    execution_json = job_json["execution_json"]
    execution_json_path = os.path.join(
        job_started_path,
        _job_execution_json_file_name)
    with open(execution_json_path, "w") as execution_json_file:
        execution_json_file.write(json.dumps(
            execution_json,
            indent = 2))
    execution_url = job_json["execution_url"]
    execution_method = job_json["execution_method"]
    request_timed_out = False
    try:
        execution_response = requests.request(
            execution_method,
            execution_url,
            json = execution_json,
            timeout = 10)
        response_status_code = execution_response.status_code
    except requests.exceptions.Timeout as timeoutException:
        request_timed_out = True
    job_start_status_path = os.path.join(
        job_started_path,
        _job_start_status_file_name)
    if (not response_status_code in [ 202, 200 ]) or request_timed_out:
        if request_timed_out:
            status = "timed out"
        else:
            status = str(response_status_code)
        logger.warning(
            "Could not start job with id: " +
            str(job_id) +
            ". Response status: " +
            status)
        with open(job_start_status_path, "w") as job_start_status_file:
            job_start_status_file.write(JobStartStatus.FAILURE.value)
        _update_job_status(
            str(job_id),
            JobCompletionStatus.FAILED_TO_START)
    else:
        logger.info(
            "Started job with id " +
            str(job_id))
        with open(job_start_status_path, "w") as job_start_status_file:
            job_start_status_file.write(JobStartStatus.SUCCESS.value)

def _execute_command_line_job(job_id, job_json, job_started_path):
    job_start_status_path = os.path.join(
        job_started_path,
        _job_start_status_file_name)
    try:
        execution_process = subprocess.Popen(job_json["execution_commands"])
    except Exception as exception:
        logger.warning(
            "Something went wrong when starting job with id: " +
            str(job_id))
        with open(job_start_status_path, "w") as job_start_status_file:
            job_start_status_file.write(JobStartStatus.FAILURE.value)
        _update_job_status(
            str(job_id),
            JobCompletionStatus.FAILED_TO_START)
        raise exception
    logger.info(
        "Started job with id " +
        str(job_id) +
        ". PID is: " +
        str(execution_process.pid))
    with open(job_start_status_path, "w") as job_start_status_file:
        job_start_status_file.write(JobStartStatus.SUCCESS.value)

def _check_for_expired_jobs(jobs_root_directory):
    if not os.path.exists(_currently_processing_path):
        return
    logger.info("Already processing, but checking for expired jobs")
    for job_timestamp in os.listdir(jobs_root_directory):
        job_path = os.path.join(
            jobs_root_directory,
            job_timestamp)
        if not os.path.isdir(job_path):
            continue
        job_started_path = os.path.join(
            job_path,
            _job_started_directory_name)
        job_start_time_path = os.path.join(
            job_started_path,
            _job_start_time_file_name)
        job_completed_path = os.path.join(
            job_path,
            _job_completed_directory_name)
        if os.path.exists(job_completed_path):
            continue
        if not os.path.exists(job_started_path):
            break
        max_time_exceeded, current_time = _max_time_exceeded(
            job_path,
            job_start_time_path)
        if max_time_exceeded:
            _expire(current_time, str(job_timestamp))
            logger.info(
                "Found an expired job, marking as no longer processing")
            shutil.rmtree(_currently_processing_path)
        logger.info("Finished checking for expired jobs")
        break

def _process_jobs():
    jobs_root_directory = os.environ["QUEUE_JOB_ROOT_DIRECTORY"]
    _check_for_expired_jobs(jobs_root_directory)
    maximum_number_of_simultaneous_jobs = int(
        os.environ["QUEUE_MAXIMUM_NUMBER_OF_SIMULTANEOUS_JOBS"])
    number_of_started_jobs = 0
    try:
        os.mkdir(_currently_processing_path)
    except OSError as osError:
        if osError.errno == errno.EEXIST:
            logger.info(
                "Already running through job list for processing, so will " +
                "not do so again")
            return
        else:
            raise osError
    logger.info("Beginning running through job list for processing")
    for job_timestamp in os.listdir(jobs_root_directory):
        if number_of_started_jobs >= maximum_number_of_simultaneous_jobs:
            logger.info(
                "Number of started jobs is " +
                str(number_of_started_jobs) +
                " which is greater than or equal to the maximum number, " +
                "namely: " +
                str(maximum_number_of_simultaneous_jobs))
            break
        job_path = os.path.join(
            jobs_root_directory,
            job_timestamp)
        if not os.path.isdir(job_path):
            continue
        job_started_path = os.path.join(
            job_path,
            _job_started_directory_name)
        job_start_time_path = os.path.join(
            job_started_path,
            _job_start_time_file_name)
        job_completed_path = os.path.join(
            job_path,
            _job_completed_directory_name)
        if os.path.exists(job_completed_path):
            continue
        try:
            os.mkdir(job_started_path)
        except OSError as osError:
            if osError.errno == errno.EEXIST:
                max_time_exceeded, current_time = _max_time_exceeded(
                    job_path,
                    job_start_time_path)
                if max_time_exceeded:
                    _expire(
                        current_time,
                        str(job_timestamp))
                    continue
                else:
                    logger.info(
                        "Job with id " +
                        str(job_timestamp) +
                        " has started but has not completed. ")
                    number_of_started_jobs += 1
                    continue
            else:
                raise osError
        current_time = datetime.datetime.utcnow().strftime(
            _date_time_string_format)
        with open(job_start_time_path, "w") as job_start_time_file:
            job_start_time_file.write(current_time)
        job_json_path = os.path.join(
            job_path,
            _job_json_file_name)
        with open(job_json_path, "r") as job_json_file:
            job_json = json.load(job_json_file)
        try:
            execution_commands = job_json["execution_commands"]
        except KeyError:
            _execute_http_job(job_timestamp, job_json, job_started_path)
            continue
        _execute_command_line_job(job_timestamp, job_json,job_started_path)

    logger.info("Finished running through job list for processing")
    shutil.rmtree(_currently_processing_path)
    logger.info("Currently started jobs: " + str(number_of_started_jobs))

def _update_job_status(job_id, job_status):
    jobs_root_directory = os.environ["QUEUE_JOB_ROOT_DIRECTORY"]
    completed_jobs_directory = os.environ["QUEUE_COMPLETED_JOBS_DIRECTORY"]
    job_path = os.path.join(
        jobs_root_directory,
        job_id)
    completed_job_path = os.path.join(
        completed_jobs_directory,
        job_id)
    shutil.move(job_path, completed_job_path)
    current_time_string = datetime.datetime.strftime(
        datetime.datetime.utcnow(),
        _date_time_string_format)
    logger.info(
        "Completion time of job with id " +
        str(job_id) +
        " is: " +
        current_time_string)
    logger.info(
        "Completion status of job with id " +
        str(job_id) +
        " is: " +
        job_status.value)
    logger.info(
        "Removing job with id " +
        str(job_id) +
        " as has completed")
    shutil.rmtree(completed_job_path)

def add_job(arguments):
    try:
        job_json = json.loads(arguments.job_json)
    except ValueError as valueError:
        raise InvalidJobJsonException(str(valueError))
    _validate(job_json)
    jobs_root_directory = os.environ["QUEUE_JOB_ROOT_DIRECTORY"]
    timestamp = _timestamp()
    job_directory = os.path.join(
        jobs_root_directory,
        str(timestamp))
    os.mkdir(job_directory)
    try:
        job_json["execution_json"]["job_id"] = str(timestamp)
    except KeyError:
        job_json["execution_commands"].extend(["-q", str(timestamp)])
    job_file_path = os.path.join(
        job_directory,
        _job_json_file_name)
    with open(job_file_path, "w") as job_file:
        job_file.write(json.dumps(
            job_json,
            indent = 2))
    logger.info(
        "Successfully added job with id: " +
        str(timestamp) +
        ". Job json: " +
        json.dumps(job_json))
    if not arguments.not_for_immediate_processing:
        logger.info(
            "An attempt will be made to process job with id " +
            str(timestamp) +
            " immediately")
        path_to_sequential_queue_api = os.environ["NLAB_SEQUENTIAL_QUEUE_PATH"]
        processing_jobs_subprocess = subprocess.Popen(
            [ path_to_sequential_queue_api, "job_processing", "start" ])
        logger.info(
            "Started job processing following addition of job with id: " +
            str(timestamp) +
            ". PID for process in which this is taking place is: " +
            str(processing_jobs_subprocess.pid))
    else:
        logger.info(
           "No attempt will be made to process job with id " +
           str(timestamp) +
           " immediately")
    print(str(timestamp))

def job_status_update(arguments):
    job_id = arguments.job_id
    job_status = arguments.job_status
    _update_job_status(job_id, job_status)
    logger.info(
        "Successfully updated status of job with id " +
        str(job_id) +
        " to: " +
        job_status.value)
    path_to_sequential_queue_api = os.environ["NLAB_SEQUENTIAL_QUEUE_PATH"]
    processing_jobs_subprocess = subprocess.Popen(
        [ path_to_sequential_queue_api, "job_processing", "start" ])
    logger.info(
        "Started job processing following update of status for job with " +
        "id: " +
        str(job_id) +
        ". PID for process in which this is taking place is: " +
        str(processing_jobs_subprocess.pid))

def job_processing(arguments):
    control_command = arguments.control_command
    if control_command == JobProcessingControl.START:
        try:
            _process_jobs()
        except Exception as exception:
            if os.path.exists(_currently_processing_path):
                logger.warning(
                    "Removing currently processing directory because an " +
                    "error occurred")
                shutil.rmtree(_currently_processing_path)
            raise exception

"""
Sets up the command line argument parsing
"""
def argument_parser():
    parser = argparse.ArgumentParser(
        description = (
            "Places jobs on a queue and carries them out successively. Jobs " +
            "persist over stopping of the carrying out. Stopping and " +
            "starting of carrying out of jobs can be manually controlled."))
    subparsers = parser.add_subparsers(dest = "subcommand")
    add_job_parser = subparsers.add_parser(
        "add_job",
        help = "Add job to queue. Returns ID of job")
    add_job_parser.add_argument(
        "job_json",
        help = "JSON describing job")
    add_job_parser.add_argument(
        "-n",
        "--not_for_immediate_processing",
        action = "store_true",
        help = "If no attempt should be made to process the job immediately")
    job_status_parser = subparsers.add_parser(
        "job_status",
        help = "Update status of a job")
    job_status_parser.add_argument(
        "job_id",
        help = "ID of job, that returned when the job was added")
    job_status_parser.add_argument(
        "job_status",
        type = CallbackJobStatus,
        choices = list(CallbackJobStatus),
        help = "Updated status of job")
    job_processing_parser = subparsers.add_parser(
        "job_processing",
        help = "Control job processing")
    job_processing_parser.add_argument(
        "control_command",
        type = JobProcessingControl,
        choices = list(JobProcessingControl))
    return parser

def main():
    parser = argument_parser()
    arguments = parser.parse_args()
    subcommand = arguments.subcommand
    if subcommand == "add_job":
        try:
            add_job(arguments)
        except Exception as exception:
            logger.warning(
                "An unexpected error occurred when adding job. " +
                "Error: " +
                str(exception))
            sys.exit("An unexpected error occurred")
    elif subcommand == "job_status":
        try:
            job_status_update(arguments)
        except Exception as exception:
            logger.warning(
                "An unexpected error occurred when updating status of " +
                "job with id " +
                arguments.job_id +
                " to " +
                arguments.job_status.value +
                ". Error: " +
                str(exception))
            sys.exit("An unexpected error occurred")
    elif subcommand == "job_processing":
        try:
            job_processing(arguments)
        except Exception as exception:
            logger.warning(
                "An unexpected error occurred when handling control command: " +
                arguments.control_command.value +
                ". Error: " +
                str(exception))
            sys.exit("An unexpected error occurred")

if __name__ == "__main__":
    main()
