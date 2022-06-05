#!/usr/bin/env python3

"""
Detects whether an edit to an nLab page is spam. Content of edit to be passed on stdin.

Depends on MySQLdb.

Depends on the environment variables:
* NLAB_DATABASE_NAME, NLAB_DATABASE_USER, NLAB_DATABASE_PASSWORD
* NLAB_LOG_DIRECTORY
* NLAB_AUTHOR_TO_USER_FILE: (script/author_to_user)
"""

import argparse
import difflib
import logging
import MySQLdb
import os
import sys
import time

"""
Initialises logging. Logs to

spam_detector.log
"""
logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)
logging.Formatter.converter = time.gmtime
logging_formatter = logging.Formatter(
    "%(asctime)s %(levelname)s %(name)s %(message)s")
log_directory = os.environ["NLAB_LOG_DIRECTORY"]
logging_file_handler = logging.FileHandler(
    os.path.join(log_directory, "spam_detector.log"))
logging_file_handler.setFormatter(logging_formatter)
logger.addHandler(logging_file_handler)

class SpamDetectionException(Exception):
    def __init__(self, difference_ratio, threshold):
        super().__init__()
        self.difference_ratio = difference_ratio
        self.threshold = threshold

"""
For a single database query
"""
def _execute_single_with_parameters(query, parameters):
    database_user = os.environ["NLAB_DATABASE_USER"]
    database_password = os.environ["NLAB_DATABASE_PASSWORD"]
    database_name = os.environ["NLAB_DATABASE_NAME"]
    database_connection = MySQLdb.connect(
        user = database_user,
        password= database_password,
        db = database_name,
        charset = "utf8",
        use_unicode = True)
    cursor = database_connection.cursor()
    try:
        cursor.execute(query, parameters)
        results = cursor.fetchall()
        database_connection.commit()
    except MySQLdb.Error as e:
        database_connection.rollback()
        raise e
    finally:
        cursor.close()
        database_connection.close()
    return results

def _content_of_page(page_id):
    query_results = _execute_single_with_parameters(
        "SELECT content, id FROM revisions " +
        "WHERE page_id = %s " +
        "ORDER BY id DESC LIMIT 1",
        [ page_id ])
    return query_results[0][0], query_results[0][1]

def _has_nforum_user(nlab_author):
    query_results = _execute_single_with_parameters(
        "SELECT UserID FROM mathforge_user WHERE Name = %s",
        [nlab_author])
    if len(query_results) == 1:
        return True
    names = nlab_author.split()
    if len(names) == 2:
        query_results = _execute_single_with_parameters(
            "SELECT UserID FROM mathforge_user " +
            "WHERE FirstName = %s AND LastName = %s",
            [names[0], names[1]])
        if len(query_results) == 1:
            return True
        names_joined_with_underscore = names[0] + "_" + names[1]
        query_results = _execute_single_with_parameters(
            "SELECT UserID FROM mathforge_user " +
            "WHERE Name = %s",
            [names_joined_with_underscore])
        if len(query_results) == 1:
            return True
    author_to_user_filename = os.environ["NLAB_AUTHOR_TO_USER_FILE"]
    with open(author_to_user_filename, "r") as author_to_user_file:
        for line in author_to_user_file:
            author_and_user = line.split(",")
            number_of_columns = len(author_and_user)
            if (number_of_columns > 2) or (number_of_columns < 2):
                logger.warning(
                    "Syntax error in author_to_user file at the following " +
                    "line: " +
                    line)
            else:
                author = author_and_user[0].strip()
                if author == nlab_author:
                    return True
    return False

def _number_of_pages_edited_up_to_limit(author, limit):
    query_results = _execute_single_with_parameters(
        "SELECT COUNT(DISTINCT page_id) FROM revisions " +
        "WHERE author = %s",
        [ author ])
    number_of_pages_edited = query_results[0][0]
    if number_of_pages_edited > limit:
        return limit
    return number_of_pages_edited

def detect_spam(
         current_content,
         new_content,
         is_title_change,
         author,
         has_nforum_user):
    sequence_matcher = difflib.SequenceMatcher(
        None,
        current_content,
        new_content)
    difference_ratio = sequence_matcher.quick_ratio()
    if (not has_nforum_user) and is_title_change:
        threshold = 0.6
    elif not has_nforum_user:
        threshold = 0.4
    elif is_title_change:
        threshold = 0.4 * (1 - _number_of_pages_edited_up_to_limit(author, 250) / 250)
    else:
        threshold = 0.2 * (1 - _number_of_pages_edited_up_to_limit(author, 250) / 250)
    if difference_ratio < threshold:
        raise SpamDetectionException(difference_ratio, threshold)
    return difference_ratio, threshold

"""
Sets up the command line argument parsing
"""
def argument_parser():
    parser = argparse.ArgumentParser(
        description = (
            "Tries to detect whether an edit to an nLab page is spam. " +
            "Content of edit to be passed on stdin"))
    parser.add_argument(
        "page_id",
        help = "Id of edited nLab page")
    parser.add_argument(
        "author",
        help = "Author of edit")
    parser.add_argument(
        "-t",
        "--title",
        help = (
            "New title of page if title will be changed"))
    return parser

def main():
    parser = argument_parser()
    arguments = parser.parse_args()
    page_id = arguments.page_id
    author = arguments.author
    title = arguments.title
    is_title_change = (title is not None)
    new_page_content = sys.stdin.read()
    try:
        current_page_content, current_revision_id = _content_of_page(page_id)
    except Exception as exception:
        logger.warning(
            "An unexpected error occurred when fetching current content of " +
            "page with ID: " +
            page_id +
            ". Error: " +
            str(exception))
        sys.exit("An unexpected error occurred")
    try:
        has_nforum_user = _has_nforum_user(author)
    except Exception as exception:
        logger.warning(
            "An unexpected error occurred when determining whether there " +
            "is an nForum user corresponding to the nLab author " +
            author +
            ". Error: " +
            str(exception))
        sys.exit("An unexpected error occurred")
    log_message = (
        " change to page with ID " +
        page_id +
        ". Revision ID of current page: " +
        str(current_revision_id) +
        ". Author of edit: " +
        author +
        ". Has corresponding nForum user: " +
        str(has_nforum_user))
    if is_title_change:
        log_message += ". Intended title change: " + title
    else:
        log_message += ". No intended title change"
    try:
        difference_ratio, threshold = detect_spam(
            current_page_content,
            new_page_content,
            is_title_change,
            author,
            has_nforum_user)
        log_message += (
            ". Difference ratio: " +
            str(difference_ratio) +
            ". Threshold: " +
            str(threshold))
        log_message = "Approved" + log_message
        print("OK")
    except SpamDetectionException as spamDetectionException:
        log_message += (
            ". Difference ratio: " +
            str(spamDetectionException.difference_ratio) +
            ". Threshold: " +
            str(spamDetectionException.threshold) +
            ". Blocked content: " +
            new_page_content)
        log_message = "Blocked" + log_message
        print("Blocked")
    except Exception as exception:
        log_message = (
            "An unexpected error occurred when trying to approve " +
            log_message +
            ". Error: " +
            str(exception))
        logger.warning(log_message)
        sys.exit("An unexpected error occurred")
    logger.info(log_message)

if __name__=="__main__":
    main()
