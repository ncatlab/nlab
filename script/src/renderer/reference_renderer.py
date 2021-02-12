#!/usr/bin/python3.7

"""
Library defining a block for converting \bibitem{something}, where something is
the citation key of some entry in the 'bibliography' table of the nLab
database into a reference. If no such entry can be found, returns 'something?'
as a link to creating the reference.
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
            "href=\"https://nforum.ncatlab.org\">nForum</a>.")

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

def _render_pages(pages):
    return pages.replace("--", "-")

def _render_article(reference):
    author = reference[5]
    title = reference[21]
    journal = reference[12]
    volume = reference[23]
    number = reference[16]
    pages = reference[18]
    year = reference[24]
    arxiv = reference[26]
    doi = reference[27]
    parts_of_rendering = [
        author,
        "_" + title + "_",
        journal + " " + volume
    ]
    if number:
        parts_of_rendering.append("No. " + str(number))
    final_parts_of_rendering = [
        _render_pages(pages),
        "(" + year + ")",
    ]
    if arxiv:
        if doi:
            final_parts_of_rendering.append(
                "(" + arxiv + ", " + doi + ")")
        else:
            final_parts_of_rendering.append(
                "(" + arxiv + ")")
    elif doi:
        final_parts_of_rendering.append(
            "(" + doi + ")")
    parts_of_rendering.append(" ".join(final_parts_of_rendering))
    return ", ".join(parts_of_rendering)

def render(citation_key):
    try:
        reference = _execute_single_with_parameters(
            "SELECT * FROM bibliography WHERE citation_key = %s",
            [ citation_key ])[0]
    except IndexError:
        raise ReferenceNotFoundException(citation_key)
    reference_type = reference[2]
    if reference_type == "article":
        rendered_reference = mistletoe_nlab_renderer.render(
            _render_article(reference))
    else:
        raise UnsupportedReferenceTypeException(reference_type)
    reference_id = reference[0]
    return rendered_reference, reference_id

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
            render(citation_key)[0]
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
