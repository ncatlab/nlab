#!/usr/bin/env python3

"""
Library defining a block for converting \bibitem{something}, where something is
the citation key of some entry in the 'bibliography' table of the nLab
database into a reference. If no such entry can be found, returns 'something?'
as a link to creating the reference.

Renders a bibliography item.
Calls the command specified by RUN_COMMAND_FOR_LATEX_COMPILER (usually itex2MML).

Depends on MySQLdb and mistletoe.

Depends on the environment variables:
* NLAB_DATABASE_NAME, NLAB_DATABASE_USER, NLAB_DATABASE_PASSWORD
* RUN_COMMAND_FOR_LATEX_COMPILER
"""

import argparse
import datetime
import json
import MySQLdb
import os
import sys

import find_block
import mistletoe_nlab_renderer

class ReferenceNotFoundException(Exception):
    def __init__(self, citation_key):
        super().__init__("No reference found with key: " + citation_key)

class UnsupportedReferenceTypeException(Exception):
    def __init__(self, reference_type):
        super().__init__(
            "Reference type not yet supported: " +
            reference_type +
            ". Please raise this at the <a " +
            'href="' + os.environ["NFORUM_URL"] + '">nForum</a>.')

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

def _render_article(reference):
    return ", ".join([
        reference[5],
        "_" + reference[21] + "_",
        reference[12] + " " + reference[23],
        reference[18] + " (" + reference[24] + ")"
    ])

def render(citation_key):
    try:
        reference = _execute_single_with_parameters(
            "SELECT * FROM bibliography WHERE citation_key = %s",
            [ citation_key ])[0]
    except IndexError:
        raise ReferenceNotFoundException(citation_key)
    reference_type = reference[2]
    if reference_type == "article":
        return mistletoe_nlab_renderer.render(_render_article(reference))
    else:
        raise UnsupportedReferenceTypeException(reference_type)

def _made_at(citation_key):
    timestamp = _execute_single_with_parameters(
        "SELECT made_at FROM bibliography LEFT JOIN bibliography_edits ON " +
        "bibliography.id = bibliography_edits.reference_id WHERE " +
        "citation_key = %s",
        [ citation_key ])[0][0]
    return datetime.datetime.strftime(timestamp, "%Y-%m-%d %H:%M:%S")

"""
Sets up the command line argument parsing
"""
def argument_parser():
    parser = argparse.ArgumentParser(
        description = (
            "For rendering a reference"))
    parser.add_argument(
        "citation_key",
        help = "Citation key of the reference")
    return parser

def main():
    parser = argument_parser()
    arguments = parser.parse_args()
    citation_key = arguments.citation_key
    rendered_reference_json = dict()
    try:
        rendered_reference_json["reference"] = \
            render(citation_key)
        rendered_reference_json["made_at"] = _made_at(citation_key)
        print(json.dumps(rendered_reference_json, indent=2))
    except (ReferenceNotFoundException,
            UnsupportedReferenceTypeException) as exception:
        sys.exit(str(exception))
    except Exception as exception:
        raise exception
        sys.exit("An unexpected error occurred")

if __name__ == "__main__":
    main()
