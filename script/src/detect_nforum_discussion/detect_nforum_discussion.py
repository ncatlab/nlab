#!/usr/bin/env python3

"""
API for detecting the latest nForum discussion corresponding to an nLab page

Depends on MySQLdb.

Depends on the environment variables:
* NLAB_DATABASE_NAME, NLAB_DATABASE_USER, NLAB_DATABASE_PASSWORD
* NLAB_LOG_DIRECTORY
* NLAB_NFORUM_PREFIX

---

To use, set up (if it is not already in place) a virtual environment as follows.

    python3 -m venv venv

    source venv/bin/activate

    pip3 install MySQLdb

    deactivate

Once the virtual environment has been set up, to use the API, launch the
virtual environment by running:

    source venv/bin/activate

Then run the script as follows (it will not work if using the ./ syntax).

    python detect_nforum_discussion.py --help

This will describe the available options.

When finished, shut down the virtual environment by running:

    deactivate
"""

import argparse
import logging
import MySQLdb
import os
import sys
import time

"""
Initialises logging. Logs to

nforum_discussion_detector.log
"""
logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)
logging_stream_handler = logging.StreamHandler()
logging_stream_handler.setLevel(logging.INFO)
logging.Formatter.converter = time.gmtime
logging_formatter = logging.Formatter(
    "%(asctime)s %(levelname)s %(name)s %(message)s")
logging_stream_handler.setFormatter(logging_formatter)
logger.addHandler(logging_stream_handler)
log_directory = os.environ["NLAB_LOG_DIRECTORY"]
logging_file_handler = logging.FileHandler(
    os.path.join(log_directory, "nforum_discussion_detector.log"))
logging_file_handler.setFormatter(logging_formatter)
logger.addHandler(logging_file_handler)

class FailedToCarryOutQueryException(Exception):
    pass

"""
For a single database query
"""
def execute_single_with_parameters(query, parameters):
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
        logger.warning(
            "Failed to carry out the query " +
            query +
            " with parameters: " +
            str(parameters) +
            ". Error: " +
            str(e))
        database_connection.rollback()
        raise FailedToCarryOutQueryException()
    finally:
        cursor.close()
        database_connection.close()
    return results

class NoDiscussionIDException(Exception):
    pass

"""
Finds the DiscussionID of the last active nForum discussion with the same
name as a given nLab page. If no discussion can be found with the same name,
a NoDiscussionIDException is raised.
"""
def nforum_discussion_id(nlab_page_name):
    query_results = execute_single_with_parameters(
        "SELECT DiscussionID FROM mathforge_nforum_Discussion " +
        "WHERE Name = BINARY %s " +
        "AND CategoryID = 5 " +
        "ORDER BY DateLastActive DESC LIMIT 1",
        [nlab_page_name])
    try:
        discussion_id = query_results[0][0]
        logger.info(
            "Successfully found last active nForum discussion ID for nLab " +
            "page " +
            nlab_page_name +
            " to be: " +
            str(discussion_id))
        return discussion_id
    except IndexError:
        logger.info(
            "No nForum discussion found for nLab page " +
            nlab_page_name)
        raise NoDiscussionIDException()

class NoCommentException(Exception):
    pass

"""
Finds the number of the last comment, or equivalently the total number of
comments, in a discussion with a particular DiscussionID. Raises a
NoCommentException if the discussion has no comment (this should never occur
under ordinary circumstances).
"""
def last_comment_number(discussion_id):
    query_results = execute_single_with_parameters(
        "SELECT Count(CommentID) FROM mathforge_nforum_Comment " +
        "WHERE DiscussionID = %s",
        [discussion_id])
    try:
        last_comment_number = query_results[0][0]
        logger.info(
            "Successfully last comment number in nForum discussion " +
            "with ID " +
            str(discussion_id) +
            " to be: " +
            str(last_comment_number))
        return last_comment_number
    except IndexError:
        logger.warning(
            "No comment found in discussion with ID: " +
            str(discussion_id))
        raise NoCommentException()

"""
Returns a link to the last active nForum discussion with the same
name as a given nLab page. If no discussion can be found with the same name,
a NoDiscussionIDException is raised, and if the found discussion has no comment,
a NoCommentException is raised.
"""
def nforum_discussion_link(nlab_page_name):
    discussion_id = nforum_discussion_id(nlab_page_name)
    comment_number = last_comment_number(discussion_id)
    return (
        os.environ['NLAB_NFORUM_PREFIX'] +
        str(discussion_id) +
        "/#Item_" +
        str(comment_number))

"""
Sets up the command line argument parsing
"""
def argument_parser():
    parser = argparse.ArgumentParser(
        description = (
            "Returns a link to the last comment in the last active nForum " +
            "discussion corresponding to a given nLab page, if such a " +
            "discussion and comment exist. If they do not exist, nothing is " +
            "returned."))
    parser.add_argument(
        "nlab_page_name",
        help = "Name of created nLab page")
    return parser

def main():
    parser = argument_parser()
    arguments = parser.parse_args()
    nlab_page_name = arguments.nlab_page_name
    try:
        link_to_discussion = nforum_discussion_link(nlab_page_name)
        logger.info(
            "Successfully constructed link to nForum discussion " +
            "corresponding to nLab page with name " +
             nlab_page_name +
            ". Link: " +
            link_to_discussion)
        print(link_to_discussion)
    except (NoDiscussionIDException, NoCommentException):
        logger.info(
            "Could not construct link to nForum discussion corresponding " +
            "to nLab page with name " +
            nlab_page_name)
    except Exception as e:
        logger.warning(
            "Due to an unforeseen error, could not construct link to nForum " +
            "discussion corresponding to nLab page with name " +
            nlab_page_name +
            ". Error: " +
            str(e))
        sys.exit(1)

if __name__ == "__main__":
    main()
