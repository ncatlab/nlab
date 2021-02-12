#!/usr/bin/python3.7

"""
Library defining a block for converting \bibitem{something}, where something is
the citation key of some entry in the 'bibliography' table of the nLab
database into a reference. If no such entry can be found, returns 'something?'
as a link to creating the reference. Also records the use of this reference
on the page in which \bibitem{something} is present.
"""

import MySQLdb
import os
import urllib.parse

import find_block
import reference_renderer

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

def _store_reference_use(reference_id, page_id):
    try:
        _execute_single_with_parameters(
            "INSERT INTO bibliography_uses(reference_id, page_id, " +
            "first_added) " +
            "VALUES (%s, %s, NOW())",
            [ reference_id, page_id ])
    except MySQLdb.Error as database_error:
        if "duplicate entry" in str(database_error).lower():
            pass
        else:
            raise database_error

def _bibitem_processor(web_address, citation_key, page_id):
    try:
        rendered_reference, reference_id = reference_renderer.render(
            citation_key)
    except reference_renderer.ReferenceNotFoundException:
        return (
            "<span class='newWikiWord'>" +
            citation_key +
            "<a href=\"/" +
            web_address +
            "/new/" +
            urllib.parse.quote_plus(citation_key) +
            "?is_reference=1" +
            "\">" +
            "?" +
            "</a>" +
            "</span>")
    _store_reference_use(reference_id, page_id)
    return "* {#" + citation_key + "} " + rendered_reference

def define(web_address, page_id):
    return find_block.Block(
        "\\bibitem{",
        "}",
        lambda citation_key: _bibitem_processor(
            web_address,
            citation_key,
            page_id),
        True)
