#!/usr/bin/python3.7

import argparse
import json
import logging
import MySQLdb
import os
import re
import sys
import time
import urllib.parse

import mistletoe_nlab_renderer

"""
Initialises logging. Logs to

all_references.log
"""
logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)
logging.Formatter.converter = time.gmtime
logging_formatter = logging.Formatter(
    "%(asctime)s %(levelname)s %(name)s %(message)s")
log_directory = os.environ["NLAB_LOG_DIRECTORY"]
logging_file_handler = logging.FileHandler(
    os.path.join(log_directory, "all_references.log"))
logging_file_handler.setFormatter(logging_formatter)
logger.addHandler(logging_file_handler)

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

"""
Essentially the same as the corresponding method in reference_renderer.py,
with markdown italics replaced by HTML
"""
def _render_title(title):
    pattern = re.compile(r"(?!\[\[([^\|]+?)\]\])\[\[([^\|]+?)\|([^\|]+?)\]\]")
    match = pattern.match(title)
    if match:
        return (
            "_" +
            "<em><a class=\"existingWikiWord\" " +
            "href=\"/nlab/show/" +
            urllib.parse.quote_plus(match.group(2).strip()) +
            "\">" +
            match.group(3).strip() +
            "</a>" +
            "</em>")
    pattern = re.compile(r"\[\[([^\|]+?)\]\]")
    match = pattern.match(title)
    if match:
        return (
            "<em>" +
            "<a class=\"existingWikiWord\" " +
            "href=\"/nlab/show/" +
            urllib.parse.quote_plus(match.group(1).strip()) +
            "\">" +
            match.group(1).strip() +
            "</a>" +
            "</em>")
    return "<em>" + title + "</em>"

def fetch_all():
    results = _execute_single_with_parameters(
        "SELECT citation_key, title, year, author FROM bibliography",
        [])
    return [
        {
            "citation_key": result[0],
            "title": _render_title(result[1]),
            "year": result[2],
            "author": mistletoe_nlab_renderer.render(
                result[3]).replace("<p>", "").replace("</p>", "").strip()
        } for result in results
    ];

"""
Sets up the command line argument parsing
"""
def argument_parser():
    parser = argparse.ArgumentParser(
        description = (
            "For obtaining a summary of all references in the bibliography"))
    return parser

def main():
    parser = argument_parser()
    parser.parse_args()
    try:
        print(json.dumps(fetch_all(), indent=2))
    except Exception as exception:
        logger.error(
            "An unexpected error occurred when fetching all references. " +
            "Error: " +
            str(exception))
        sys.exit("An unexpected error occurred")

if __name__ == "__main__":
    main()
