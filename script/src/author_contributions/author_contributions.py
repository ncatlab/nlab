#!/usr/bin/env python3.7

"""
API for finding the list of nLab pages to which an nLab author has contributed

Depends on MySQLdb.

Depends on the environment variables:
* NLAB_DATABASE_NAME, NLAB_DATABASE_USER, NLAB_DATABASE_PASSWORD
* NLAB_LOG_DIRECTORY

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

    python author_contributions.py --help

This will describe the available options. As will be seen, there are three
subcommands, 'is_author', 'pages', and 'recent', whose descriptions can be
obtained by running

   python author_contributions.py is_author --help

or

   python author_contributions.py pages --help

or

   python author_contributions.py recent --help

When finished, shut down the virtual environment by running:

    deactivate
"""

import argparse
import json
import logging
import MySQLdb
import os
import sys
import time

"""
Initialises logging. Logs to

author_contributions.log
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
    os.path.join(log_directory, "author_contributions.log"))
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

def is_nlab_author(possible_author):
    query_results = execute_single_with_parameters(
        "SELECT id FROM revisions " +
        "WHERE author = %s " +
        "ORDER BY id LIMIT 1",
        [possible_author])
    try:
        query_results[0]
        return True
    except IndexError:
        return False

"""
Finds the list of nLab pages which a given nLab author has edited.
"""
def pages_contributed_to(nlab_author):
    query_results = execute_single_with_parameters(
        "SELECT DISTINCT(name) FROM pages " +
        "WHERE web_id = %s " +
        "AND id IN " +
        "(SELECT DISTINCT(page_id) FROM revisions " +
        "WHERE author = %s)",
        [1, nlab_author])
    pages = [ query_result[0] for query_result in query_results]
    sorted_pages = sorted(pages, key=str.lower)
    return sorted_pages

"""
Finds the last n number of pages which a given nLab author has edited,
together with the timestamps of when the edits took place, and the number
of the revision
"""
def last_pages_contributed_to(number_of_pages, nlab_author):
    query_results = execute_single_with_parameters(
        "SELECT name, revisions.updated_at, pages.id FROM pages " +
        "LEFT JOIN revisions ON pages.id = revisions.page_id " +
        "WHERE revisions.web_id = %s " +
        "AND author = %s " +
        "ORDER BY revisions.updated_at DESC LIMIT %s",
        [1, nlab_author, number_of_pages])
    return [ _page_edit_time_revision_number(page, edit_time, page_id) for \
       page, edit_time, page_id in query_results ]

def _page_edit_time_revision_number(page_name, edit_time, page_id):
   return {
       "page": page_name,
       "edit_time": edit_time.strftime("%X") +
           ", " +
           edit_time.strftime("%B %d %Y"),
       "revision_number": _revision_number(page_id, edit_time) }

def _revision_number(page_id, edit_time):
    query_results = execute_single_with_parameters(
        "SELECT COUNT(id) FROM revisions " +
        "WHERE web_id = %s " +
        "AND page_id = %s " +
        "AND updated_at <= %s",
        [1, page_id, edit_time])
    return query_results[0][0]

"""
Sets up the command line argument parsing
"""
def argument_parser():
    parser = argparse.ArgumentParser(
        description = (
            "Detects nLab authors, returns a list of the nLab pages to which " +
            "an nLab author has contributed"))
    subparsers = parser.add_subparsers(dest="subcommand")
    parser_is_author = subparsers.add_parser(
        "is_author",
        help = "Checks whether a given string is an nLab author, returning " +
        "'True' or 'False'")
    parser_pages_contributed_to = subparsers.add_parser(
        "pages",
        help = "Returns the list of nLab pages to which an nLab author has " +
        "contributed")
    parser_last_pages_contributed_to = subparsers.add_parser(
        "recent",
        help = "Returns the list of nLab pages to which an nLab author has " +
        "recently contributed, along with the time at which the " +
        "contributions were made, and the revision number of the contribution")
    parser_is_author.add_argument(
        "possible_author",
        help = "String to be checked as to whether it defines an nLab author")
    parser_pages_contributed_to.add_argument(
        "nlab_author",
        help = "nLab author")
    parser_last_pages_contributed_to.add_argument(
        "nlab_author",
        help = "nLab author")
    parser_last_pages_contributed_to.add_argument(
        "-n",
        "--number_of_pages",
        type = int,
        default = 30,
        help = "Number of pages to look at, i.e. last n for some n")
    return parser

def main():
    parser = argument_parser()
    arguments = parser.parse_args()
    if arguments.subcommand == "is_author":
        possible_author = arguments.possible_author
        try:
            is_author = is_nlab_author(possible_author)
            if is_author:
                logger.info(
                    "Successfully detected that " +
                    possible_author +
                    " is an nLab author")
            print(is_author)
            return
        except Exception as e:
            logger.warning(
                "Due to an unforeseen error, could not detect whether " +
                possible_author +
                " defines an nLab author. Error: " +
                str(e))
            sys.exit(1)
    if arguments.subcommand == "pages":
        nlab_author = arguments.nlab_author
        try:
            pages = pages_contributed_to(nlab_author)
            logger.info(
                "Successfully found pages to which nLab author " +
                nlab_author +
                " has contributed.")
            print(json.dumps(pages))
            return
        except Exception as e:
            logger.warning(
                "Due to an unforeseen error, could not find pages to which " +
                "nLab author " +
                nlab_author +
                " has contributed. Error: " +
                str(e))
            sys.exit(1)
    if arguments.subcommand == "recent":
        nlab_author = arguments.nlab_author
        number_of_pages = arguments.number_of_pages
        if number_of_pages < 10:
            sys.exit(
                "Number of pages must be greater than or equal to 10")
        try:
            pages = last_pages_contributed_to(number_of_pages, nlab_author)
            logger.info(
                "Successfully found last " +
                str(number_of_pages) +
                " pages to which nLab author " +
                nlab_author +
                " has contributed.")
            print(json.dumps(pages))
            return
        except Exception as e:
            logger.warning(
                "Due to an unforeseen error, could not find last " +
                str(number_of_pages) +
                " pages to which " +
                "nLab author " +
                nlab_author +
                " has contributed. Error: " +
                str(e))
            sys.exit(1)

if __name__ == "__main__":
    main()
