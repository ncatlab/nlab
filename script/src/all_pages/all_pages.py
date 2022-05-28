#!/usr/bin/env python3

"""
Lists all pages for a given web. Prints a JSON dump of a list of page data.

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

    python all_pages.py --help

This will describe the available options.

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

all_pages.log
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
    os.path.join(log_directory, "all_pages.log"))
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

"""
Finds all distinct page names for a given web
"""
def all_pages(web_id):
    query_results = execute_single_with_parameters(
        "SELECT DISTINCT(name) FROM pages " +
        "WHERE web_id = %s",
        [web_id])
    pages = [ query_result[0] for query_result in query_results ]
    sorted_pages = sorted(pages, key=str.lower)
    return sorted_pages

"""
Finds all distinct page names for a given web, for pages in a given category
"""
def all_pages_in_category(web_id, category_name):
    query_results = execute_single_with_parameters(
        "SELECT DISTINCT(name) FROM pages " +
        "LEFT JOIN wiki_references ON pages.id = wiki_references.page_id " +
        "WHERE web_id = %s AND referenced_name = %s AND link_type = %s",
        [web_id, category_name, "C"])
    pages = [ query_result[0] for query_result in query_results ]
    sorted_pages = sorted(pages, key=str.lower)
    return sorted_pages

"""
Sets up the command line argument parsing
"""
def argument_parser():
    parser = argparse.ArgumentParser(
        description = (
            "Lists the names of all pages in a given web, optionally in a " +
            "given category"))
    parser.add_argument(
        "web_id",
        type=int,
        help = "Id of a web")
    parser.add_argument(
        "-c",
        "--category",
        help = "Category name")
    return parser

def main():
    parser = argument_parser()
    arguments = parser.parse_args()
    web_id = arguments.web_id
    category_name = arguments.category
    if not category_name:
        try:
            pages = all_pages(web_id)
            logger.info(
                "Successfully found all pages for web with id " +
                str(web_id))
            print(json.dumps(pages))
            return
        except Exception as e:
            logger.warning(
                "Due to an unforeseen error, could not obtain the list of " +
                "all pages for the web with id: " +
                str(web_id) +
                ". Error: " +
                str(e))
            sys.exit(1)
    try:
        pages = all_pages_in_category(web_id, category_name)
        logger.info(
            "Successfully found all pages in category " +
            category_name +
            " for web with id " +
            str(web_id))
        print(json.dumps(pages))
        return
    except Exception as e:
        logger.warning(
            "Due to an unforeseen error, could not obtain the list of all " +
            "pages in category " +
            category_name +
            " for the web with id: " +
            str(web_id) +
            ". Error: " +
            str(e))
        sys.exit(1)

if __name__ == "__main__":
    main()
