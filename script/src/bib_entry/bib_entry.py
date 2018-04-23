#!/usr/bin/python3

"""
API for creating a bib entry for citation of an nLab page

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

    python bib_entry.py --help

This will describe the available options.

When finished, shut down the virtual environment by running:

    deactivate
"""

import argparse
import datetime
import logging
import MySQLdb
import os
import string
import sys
import time
import urllib.parse

"""
Initialises logging. Logs to

bib_entry.log
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
    os.path.join(log_directory, "bib_entry.log"))
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
Replaces any unicode symbols in an nLab page name by ascii approximations.

The list of unicode symbols appearing in nLab page names is hardcoded, as
are their ascii approximations. The list should be updated whenever a page
title with a unicode symbol that has not previously been used is made.

We replace "ä" by "ae" by default, but this is not acceptable in Finnish,
so we hardcode a couple of Finnish names. In addition, we hardcode the
replacement of the single occurring Chinese name, and the three occurring
Russian names.
"""
def replace_unicode(page_name):
    if page_name == "道德经":
        return "Tao Te Ching"
    elif page_name == "Е. Б. Богомольний":
        return "Evgeny Bogomolny"
    elif page_name == "Павел Мнёв":
        return "Pavel Mnev"
    elif page_name == "Jouko Väänänen":
        return "Jouko Vaananen"
    elif page_name == "Syksy Räsänen":
        return "Syksy Rasanen"
    elif page_name == "Владимир Воеводский" or page_name == "ВладимирВоеводский":
        return "Vladimir Voevodsky"
    elif page_name == "Erdal İnönü":
        return "Erdal Inonu"
    replacements = {
        "à": "a",
        "á": "a",
        "â": "a",
        "ã": "a",
        "ą": "a",
        "ä": "ae",
        "æ": "ae",
        "å": "aa",
        "Á": "A",
        "ě": "e",
        "ë": "e",
        "é": "e",
        "è": "e",
        "É": "E",
        "İ": "i",
        "î": "i",
        "í": "i",
        "ï": "i",
        "ô": "o",
        "ō": "o",
        "ó": "o",
        "ò": "o",
        "ő": "o",
        "ö": "oe",
        "Ø": "Oe",
        "ø": "oe",
        "ú": "u",
        "ü": "ue",
        "ç": "c",
        "ć": "c",
        "č": "c",
        "Č": "c",
        "ß": "ss",
        "ł": "l",
        "Ł": "L",
        "ℓ": "l",
        "ń": "n",
        "ñ": "n",
        "ř": "r",
        "ś": "s",
        "Š": "S",
        "š": "s",
        "ý": "y",
        "∞": "infinity",
        "’": "'",
        "ω": "omega",
        "Π": "Pi",
        "\u200b": "",
        "κ": "k",
        "–": "-"}
    replaced_page_name = ""
    for character in page_name:
        try:
            replacement = replacements[character]
        except KeyError:
            replaced_page_name += character
        else:
            replaced_page_name += replacement
    return replaced_page_name

"""
Returns a citation key for a given nLab page, of the following form.

nLab:page_name

In all cases, spaces in the page name are replaced by underscores, and the
entire page name is made lower case.

If unicode_permitted is false, unicode symbols are in addition replaced by
ascii approximations.
"""
def bib_entry_citation_key(page_name, unicode_permitted):
    if not unicode_permitted:
        page_name = replace_unicode(page_name)
    page_name = "_".join(page_name.lower().split())
    return "nlab:" + page_name

"""
Replaces any unicode symbols in an nLab page name by LaTeX approximations.

The list of unicode symbols appearing in nLab page names is hardcoded, as
are their ascii approximations. The list should be updated whenever a page
title with a unicode symbol that has not previously been used is made.

We hardcode the replacement of the single occurring Chinese name, and the three
occurring Russian names.
"""
def latex_page_name(page_name, unicode_permitted):
    if unicode_permitted:
        replaced_page_name = ""
        for character in page_name:
            if character.isupper():
                replaced_page_name += "{{" + character + "}}"
            else:
                replaced_page_name += character
        return replaced_page_name
    if page_name == "道德经":
        return "Tao {{T}}e {{C}}hing"
    elif page_name == "Е. Б. Богомольний":
        return "Evgeny {{B}}ogomolny"
    elif page_name == "Павел Мнёв":
        return "Pavel {{M}}nev"
    elif page_name == "Владимир Воеводский" or page_name == "ВладимирВоеводский":
        return "Vladimir {{V}}oevodsky"
    elif page_name == "Erdal İnönü":
        return "Erdal {{\\.{I}}}n\\\"{o}n\\\"{u}"
    replacements = {
        "à": "\\`{a}",
        "á": "\\'{a}",
        "â": "\\^{a}",
        "ã": "\\~{a}",
        "ą": "\\k{a}",
        "ä": "\\\"{a}",
        "æ": "\\ae",
        "å": "\\aa",
        "Á": "{{\\'{A}}}",
        "ě": "\\v{e}",
        "ë": "\\\"{e}",
        "é": "\\'{e}",
        "è": "\\`{e}",
        "É": "{{\\'{E}}}",
        "İ": "{{\\.{I}}}",
        "î": "\\^{i}",
        "í": "\\'{i}",
        "ï": "\\\"{i}",
        "ô": "\\^{o}",
        "ō": "\\={o}",
        "ó": "\\'{o}",
        "ò": "\\`{o}",
        "ő": "\\H{o}",
        "ö": "\\\"{o}",
        "Ø": "{{\\O}}",
        "ø": "\\o",
        "ú": "\\'{u}",
        "ü": "\\\"{u}",
        "ç": "\\c{c}",
        "ć": "\\'{c}",
        "č": "\\v{c}",
        "Č": "{{\\v{C}}}",
        "ß": "\\ss",
        "ł": "\\l{}",
        "Ł": "{{\\L{}}}",
        "ℓ": "l",
        "ń": "\\'{n}",
        "ñ": "\\~{n}",
        "ř": "\\v{r}",
        "ś": "\\'{s}",
        "Š": "{{\\v{S}}}",
        "š": "\\v{s}",
        "ý": "\\'{y}y",
        "∞": "{$\infty}",
        "’": "'",
        "ω": "{$\omega}",
        "Π": "{$\Pi}",
        "\u200b": "",
        "κ": "{$\kappa}",
        "–": "-"}
    replaced_page_name = ""
    for character in page_name:
        try:
            replacement = replacements[character]
        except KeyError:
            if character.isupper():
                replaced_page_name += "{{" + character + "}}"
            else:
                replaced_page_name += character
        else:
            replaced_page_name += replacement
    return replaced_page_name

def page_link_for(page_name):
    return "http://ncatlab.org/nlab/show/" + urllib.parse.quote(page_name)

def revision_link_for(page_name, revision_number):
    return (
        "http://ncatlab.org/nlab/revision/" +
        urllib.parse.quote(page_name) +
        "/" +
        str(revision_number))

class CouldNotFindDateOfRevisionException(Exception):
    pass

"""
Looks up the date upon which a revision with a certain ID was made.
"""
def date_of_revision(revision_id):
    query_results = execute_single_with_parameters(
        "SELECT revised_at FROM revisions WHERE id = %s",
        [revision_id])
    try:
        return query_results[0][0]
    except IndexError:
        raise CouldNotFindDateOfRevisionException()

"""
Creates a bib entry which looks as follows for a given nLab page and
revision number. Here page_name is the name of the page, with spaces replaced by
underscores, and unicode symbols replaced by ascii approximations if needed;
Page Name is the actual page name; and url_escaped_page_name is
a URL escaped version of the actual page name, e.g. with spaces replaced by
%20. The month and year are those of the current date if the page cited is
the current version of it, and are otherwise those of the date upon which
the cited revision of the page was edited.

@Misc{nlab:page_name,
  author = {{nLab authors}},
  title = {Page Name},
  howpublished = {\\url{http://ncatlab.org/nlab/show/url_escaped_page_name}},
  note = {\\href{http://ncatlab.org/nlab/revision/url_escaped_pagename/N}{Revision N}},
  month = {Month},
  year = XXXX
}
"""
def bib_entry_for(
        page_name,
        revision_number,
        revision_id,
        current,
        unicode_permitted):
    bib_entry_template = string.Template(
        "@misc{$citation_key,\n" +
        "  author = {{nLab authors}},\n" +
        "  title = {$page_name},\n" +
        "  howpublished = {\\url{$page_link}},\n" +
        "  note = {\\href{$revision_link}{Revision $number}},\n" +
        "  month = $month,\n" +
        "  year = $year\n" +
        "}")
    if current:
        date = datetime.datetime.utcnow()
    else:
        date = date_of_revision(revision_id)
    month = date.strftime("%B").lower()[:3]
    year = date.strftime("%Y")
    latex_name = latex_page_name(page_name, unicode_permitted)
    return bib_entry_template.substitute(
        citation_key = bib_entry_citation_key(page_name, unicode_permitted),
        page_name = latex_name,
        page_link = page_link_for(page_name),
        revision_link = revision_link_for(page_name, revision_number),
        number = str(revision_number),
        month = month,
        year = year)

"""
Sets up the command line argument parsing
"""
def argument_parser():
    parser = argparse.ArgumentParser(
        description = (
            "Returns bib entry for given nLab page"))
    parser.add_argument(
        "page_name",
        help = "Name of nLab page")
    parser.add_argument(
        "revision_number",
        type = int,
        help = "Revision number of nLab page")
    parser.add_argument(
        "revision_id",
        type = int,
        help = "ID of revision")
    parser.add_argument(
        "--current",
        action = "store_true",
        help = "If this revision is the current version of the page")
    parser.add_argument(
        "--unicode_permitted",
        action = "store_true",
        help = "If unicode is permitted in the bib entry")
    return parser

def main():
    parser = argument_parser()
    arguments = parser.parse_args()
    page_name = arguments.page_name
    revision_number = arguments.revision_number
    revision_id = arguments.revision_id
    current = arguments.current
    unicode_permitted = arguments.unicode_permitted
    try:
        bib_entry = bib_entry_for(
            page_name,
            revision_number,
            revision_id,
            current,
            unicode_permitted)
        message = (
            "Successfully created bib entry for page " +
            page_name +
            ", revision " +
            str(revision_number) +
            ". ")
        if unicode_permitted:
            message += "Unicode was used"
        else:
            message += "Unicode was not used"
        logger.info(message)
        print(bib_entry)
    except Exception as e:
        message = (
            "Due to an unforeseen error, could not create bib entry for " +
            page_name +
            ", revision " +
            str(revision_number) +
            " with id " +
            str(revision_id) +
            ". ")
        if unicode_permitted:
            message += "Unicode was to be used. "
        else:
            message += "Unicode was not to be used. "
        message += "Error: " + str(e)
        logger.warning(message)
        sys.exit(1)

if __name__ == "__main__":
    main()
