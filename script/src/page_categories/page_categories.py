#!/usr/bin/python3

"""
API for listing all page categories for a given web, and for checking whether
a given string defines a page category in this web

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

    python page_categories.py --help

This will describe the available options. As will be seen, there are three
subcommands, 'is_category', 'all_categories', and 'has_categories', whose
descriptions can be obtained by running

   python page_categories.py is_category --help

or

   python page_categories.py all_categories --help

or

   python page_categories.py has_categories --help

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

page_categories.log
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
    os.path.join(log_directory, "page_categories.log"))
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
Determines whether the string category_name is the name of a page category
for the given web
"""
def is_category(web_id, category_name):
    query_results = execute_single_with_parameters(
        "SELECT wiki_references.id FROM wiki_references " +
        "LEFT JOIN pages ON pages.id = wiki_references.page_id " +
        "WHERE web_id = %s AND referenced_name = %s AND link_type = %s " +
        "ORDER BY wiki_references.id LIMIT 1",
        [web_id, category_name, "C"])
    try:
        query_results[0]
        return True
    except IndexError:
        return False

"""
Lists all names of page categories for a given web
"""
def all_categories(web_id):
    query_results = execute_single_with_parameters(
        "SELECT DISTINCT(referenced_name) FROM wiki_references " +
        "LEFT JOIN pages ON pages.id = wiki_references.page_id " +
        "WHERE web_id = %s AND link_type = %s",
        [web_id, "C"])
    categories = [ query_result[0] for query_result in query_results ]
    sorted_categories = sorted(categories, key=str.lower)
    return sorted_categories

def has_categories(web_id):
    query_results = execute_single_with_parameters(
        "SELECT wiki_references.id FROM wiki_references " +
        "LEFT JOIN pages ON pages.id = wiki_references.page_id " +
        "WHERE web_id = %s AND link_type = %s "
        "ORDER BY wiki_references.id LIMIT 1",
        [web_id, "C"])
    try:
        query_results[0]
        return True
    except IndexError:
        return False

"""
Sets up the command line argument parsing
"""
def argument_parser():
    parser = argparse.ArgumentParser(
        description = (
            "Lists the names of all categories in a given web, or checks " +
            "whether a given string defines a category"))
    subparsers = parser.add_subparsers(dest="subcommand")
    parser_is_category = subparsers.add_parser(
        "is_category",
        help = "Checks whether a given string defines a category in a given " +
          "web, returning 'True' or 'False'")
    parser_all_categories = subparsers.add_parser(
        "all_categories",
        help = "Returns the list of all categories in a given web")
    parser_has_categories = subparsers.add_parser(
        "has_categories",
        help = "Checks whether a given web has any page categories")
    parser_is_category.add_argument(
        "web_id",
        type=int,
        help = "Id of a web")
    parser_is_category.add_argument(
        "category",
        help = "Name of possible category")
    parser_all_categories.add_argument(
        "web_id",
        type=int,
        help = "Id of a web")
    parser_has_categories.add_argument(
        "web_id",
        type=int,
        help = "Id of a web")
    return parser

def main():
    parser = argument_parser()
    arguments = parser.parse_args()
    web_id = arguments.web_id
    if arguments.subcommand == "all_categories":
        try:
            categories = all_categories(web_id)
            logger.info(
                "Successfully found all categories for web with id " +
                str(web_id))
            print(json.dumps(categories))
            return
        except Exception as e:
            logger.warning(
                "Due to an unforeseen error, could not obtain the list of " +
                "all categories for the web with id: " +
                str(web_id))
            sys.exit(1)
    if arguments.subcommand == "has_categories":
        try:
            has_category = has_categories(web_id)
            if has_category:
                message = " has at least one page category"
            else:
                message = " does not have any page categories"
            logger.info(
                "Successfully found that the web with id " +
                str(web_id) +
                message)
            print(has_category)
            return
        except Exception as e:
            logger.warning(
                "Due to an unforeseen error, could not determine whether " +
                "the web with id: " +
                str(web_id) +
                "has any page categories. Error: " +
                str(e))
            sys.exit(1)
    category_name = arguments.category
    try:
        found_category = is_category(web_id, category_name)
        if found_category:
            message = "defines"
        else:
            message = "does not define"
        logger.info(
            "Successfully found that " +
            category_name +
            " " +
            message +
            " a category for web with id " +
            str(web_id))
        print(found_category)
        return
    except Exception as e:
        logger.warning(
            "Due to an unforeseen error, could not determine whether " +
            category_name +
            " defines a category for the web with id: " +
            str(web_id) +
            ". Error: " +
            str(e))
        sys.exit(1)

if __name__ == "__main__":
    main()
