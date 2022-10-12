#!/usr/bin/env python3

"""
Adds a bibliography item to the database.
Expects a entry on stdin.
Outputs the generated citation key of the saved bibliography item.

Depends on MySQLdb.

Depends on the environment variables:
* NLAB_DATABASE_NAME, NLAB_DATABASE_USER, NLAB_DATABASE_PASSWORD
* NLAB_LOG_DIRECTORY
"""

import argparse
import enum
import json
import logging
import MySQLdb
import os
import sys
import time

"""
Initialises logging. Logs to

citations.log
"""
logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)
logging.Formatter.converter = time.gmtime
logging_formatter = logging.Formatter(
    "%(asctime)s %(levelname)s %(name)s %(message)s")
log_directory = os.environ["NLAB_LOG_DIRECTORY"]
logging_file_handler = logging.FileHandler(
    os.path.join(log_directory, "citations.log"))
logging_file_handler.setFormatter(logging_formatter)
logger.addHandler(logging_file_handler)

"""
For a transaction (list of database queries)
"""
def execute_with_parameters(queries_with_parameters):
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
        for query, parameters in queries_with_parameters:
            cursor.execute(query, parameters)
        results = cursor.fetchall()
        database_connection.commit()
        cursor.close()
    except MySQLdb.Error as database_error:
        database_connection.rollback()
        raise database_error
    finally:
        database_connection.close()
    return results

class AuthorFormatException(Exception):
    def __init__(self, message):
        super().__init__(message)

class CitationKeyAlreadyUsedException(Exception):
    def __init__(self, message):
        super().__init__(message)

class UnexpectedBibtexFieldException(Exception):
    def __init__(self, message):
        super().__init__(message)

class BibtexType(enum.Enum):
    ARTICLE = "article"
    BOOK = "book"
    BOOKLET = "booklet"
    CONFERENCE = "conference"
    INBOOK = "inbook"
    INCOLLECTION = "incollection"
    INPROCEEDINGS = "inproceedings"
    MANUAL = "manual"
    MASTERSTHESIS = "mastersthesis"
    MISC = "misc"
    PHDTHESIS = "phdthesis"
    PROCEEDINGS = "proceedings"
    TECHREPORT = "techreport"
    UNPUBLISHED = "unpublished"

class BibtexField(enum.Enum):
    ADDRESS = "address"
    ANNOTE = "annote"
    AUTHOR = "author"
    BOOKTITLE = "booktitle"
    CHAPTER = "chapter"
    CROSSREF = "crossref"
    EDITION = "edition"
    EDITOR = "editor"
    HOWPUBLISHED = "howpublished"
    INSTITUTION = "institution"
    JOURNAL = "journal"
    KEY_BIBLIOGRAPHIC = "key"
    MONTH = "month"
    NOTE = "note"
    NUMBER = "number"
    ORGANIZATION = "organization"
    PAGES = "pages"
    PUBLISHER = "publisher"
    SCHOOL = "school"
    SERIES = "series"
    TITLE = "title"
    TYPE = "type"
    VOLUME = "volume"
    YEAR = "year"

    def is_custom_field(self):
        return False

class ZentralblattBibtexField(enum.Enum):
    FJOURNAL = "fjournal"
    ISBN = "isbn"
    ISSN = "issn"
    LANGUAGE = "language"
    MSC2010 = "msc2010"
    ZBL = "zbl"

    def is_custom_field(self):
        return True

def store(bibtex_json, made_by):
    bibtex_json["custom"] = json.dumps(bibtex_json["custom"])
    parameters = list(bibtex_json.values())
    parameters.append(made_by)
    try:
        execute_with_parameters([
            [
            "INSERT INTO bibliography(" +
            ", ".join(bibtex_json.keys()) +
            ") VALUES (" +
            ", ".join(["%s"] * len(bibtex_json)) +
            ")",
            bibtex_json.values()
            ],
            [
            "INSERT INTO bibliography_edits(reference_id, made_by, made_at) " +
            "VALUES (LAST_INSERT_ID(), %s, NOW())",
            [ made_by ]
            ]
        ])
    except MySQLdb.Error as database_error:
        if "duplicate entry" in str(database_error).lower():
            raise CitationKeyAlreadyUsedException(
                "Citation key already used: " + bibtex_json["citation_key"])
        else:
            raise database_error

def citation_key(authors, year):
    key = ""
    author_parts = authors.split("and")
    for author in author_parts:
        author = author.strip()
        if author.startswith("[["):
            if not author.endswith("]]"):
                raise AuthorFormatException(
                    "An nLab author link must be in the following format." +
                    "\n\n[[nLab page name for author | author name in " +
                    "bibliographic format]]\n\n The author's name " +
                    "in bibliographic format is usually:\n\n" +
                    "surname, first names/initials.\n\nThis is not the case " +
                    "for: " +
                    author)
            nlab_link_parts = author[:-2].split('|')
            if len(nlab_link_parts) != 2:
                raise AuthorFormatException(
                    "An nLab author link must be in the following format." +
                    "\n\n[[nLab page name for author | author name in " +
                    "bibliographic format]]\n\n The author's name " +
                    "in bibliographic format is usually:\n\n" +
                    "surname, first names/initials.\n\nThis is not the case " +
                    "for: " +
                    author)
            author = nlab_link_parts[1]
        key += "".join(author.split(",")[0].split())
    key += str(year)
    return key

def parse_line(line):
    line_parts = line.split("=", 1)
    field = line_parts[0].lower().strip()
    try:
        bibtex_field = BibtexField(field)
    except ValueError:
        try:
            bibtex_field = ZentralblattBibtexField(field)
        except:
            raise UnexpectedBibtexFieldException(
                "Unexpected bibtex field '" +
                field +
                "'")
    bibtex_value = \
        line_parts[1].strip()[:-1].lstrip("{").rstrip("}").rstrip(".")
    return bibtex_field, bibtex_value

def parse(bibtex_entry):
    bibtex_entry = bibtex_entry.strip()
    bibtex_json = dict()
    bibtex_json["verbatim"] = bibtex_entry
    bibtex_json["custom"] = dict()
    bibtex_entry_lines = bibtex_entry.split("\n")
    first_line_parts = bibtex_entry_lines[0].split("{", 1)
    bibtex_json["document_type"] = BibtexType(
        first_line_parts[0][1:].lower().strip()).value
    if len(first_line_parts) > 1:
        bibtex_json["external_citation_key"] = \
            first_line_parts[1].split(",")[0].strip()
    for line in bibtex_entry_lines[1:-1]:
        bibtex_field, bibtex_value = parse_line(line)
        if bibtex_field.is_custom_field():
            bibtex_json["custom"][bibtex_field.name.lower()] = bibtex_value
        else:
            bibtex_json[bibtex_field.name.lower()] = bibtex_value
    last_line_parts = bibtex_entry_lines[-1].split("}",1)
    last_line_before_brace = last_line_parts[0]
    if '=' in last_line_before_brace:
        bibtex_field, bibtex_value = parse_line(last_line_before_brace)
        if bibtex_field.is_custom_field():
            bibtex_json["custom"][bibtex_field.name.lower()] = bibtex_value
        else:
            bib, made_btex_json[bibtex_field.name.lower()] = bibtex_value
    return bibtex_json

def add(bibtex_entry, made_by):
    try:
        bibtex_json = parse(bibtex_entry)
    except UnexpectedBibtexFieldException as unexpectedBibtexFieldException:
        logger.warning(
            str(unexpectedBibtexFieldException) +
            " when adding the following BibTex entry: " +
            bibtex_entry)
        sys.exit(str(unexpectedBibtexFieldException))
    logger.info(
        "Successfully constructed the JSON " +
        json.dumps(bibtex_json) +
        " from the following BibTex entry: " +
        bibtex_entry)
    bibtex_json["author"] = \
        bibtex_json["author"].replace("{", "").replace("}", "")
    try:
        bibtex_json["citation_key"] = citation_key(
            bibtex_json["author"],
            bibtex_json["year"])
    except AuthorFormatException as authorFormatException:
        logger.warning(
            str(authorFormatException) +
            ". BibTex entry: " +
            bibtex_entry)
        sys.exit(str(authorFormatException))
    try:
        store(bibtex_json, made_by)
    except CitationKeyAlreadyUsedException as citationKeyAlreadyUsedException:
        logger.warning(
            str(citationKeyAlreadyUsedException) +
            ". BibTex entry: " +
            bibtex_entry)
        sys.exit(str(citationKeyAlreadyUsedException))
    return bibtex_json["citation_key"]

"""
Sets up the command line argument parsing
"""
def argument_parser():
    parser = argparse.ArgumentParser(
        description = (
            "For saving references in the database. Expects a BibTex entry " +
            "on stdin. Outputs the generated citation key of the saved " +
            "reference"))
    parser.add_argument(
        "made_by",
        help = "Name of person who added the reference")
    return parser

def main():
    parser = argument_parser()
    arguments = parser.parse_args()
    made_by = arguments.made_by
    bibtex_entry = sys.stdin.read()
    try:
        print(add(bibtex_entry, made_by))
    except Exception as exception:
        logger.error(
            "An unexpected error occurred when adding a BibTex entry. " +
            "Error: " +
            str(exception) +
            ". BibTex entry: " +
            bibtex_entry)
        sys.exit("An unexpected error occurred")

if __name__ == "__main__":
    main()
