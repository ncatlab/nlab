#!/usr/bin/python3

"""
Library defining a block for includes, and a processor for the contents of
such a block
"""

import find_block
import MySQLdb
import os

class IncludeCannotBeEmptyException(Exception):
    pass

class CircularIncludeException(Exception):
    pass

class PageToIncludeDoesNotExistException(Exception):
    def __init__(self, message):
        super().__init__(message)

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

class _NoSuchWebException(Exception):
    pass

def _name_of_page(page_id):
    query_results = _execute_single_with_parameters(
        "SELECT name FROM pages WHERE id = %s",
        [ page_id ])
    return query_results[0][0]

def _id_of_page(page_name):
    query_results = _execute_single_with_parameters(
        "SELECT id FROM pages WHERE name = %s",
        [ page_name ])
    try:
        return query_results[0][0]
    except IndexError:
        raise PageToIncludeDoesNotExistException(page_name)

def _content_of_page(page_id):
    query_results = _execute_single_with_parameters(
        "SELECT content FROM revisions " +
        "WHERE page_id = %s " +
        "ORDER BY id DESC LIMIT 1",
        [ page_id ])
    return query_results[0][0]

def _address_of_web(web_id):
    query_results = _execute_single_with_parameters(
        "SELECT address FROM webs WHERE id = %s",
        [ web_id ])
    try:
        return query_results[0][0]
    except IndexError:
        raise _NoSuchWebException

def _include_reference_already_present(
        references_before_rendering,
        page_name_to_include,
        rendering_web_id):
    for i in range(0, len(references_before_rendering)):
        reference_id, referenced_name, link_type, web_id = \
            references_before_rendering[i]
        if referenced_name == page_name_to_include and link_type == "I" \
                and int(web_id) == rendering_web_id:
            del references_before_rendering[i]
            return True
    return False

def _circular(page_id, page_name_to_include):
    page_name = _name_of_page(page_id)
    id_of_page_to_include = _id_of_page(page_name_to_include)
    query_results = _execute_single_with_parameters(
        "SELECT id FROM wiki_references " +
        "WHERE link_type = %s " +
        "AND referenced_name = %s " +
        "AND page_id = %s",
        ["I", page_name, id_of_page_to_include])
    try:
        query_results[0]
        return True
    except IndexError:
        return False

def _make_include_reference(
        page_id,
        original_page_name_to_include,
        page_name_to_include):
    if _circular(page_id, page_name_to_include):
        raise CircularIncludeException()
    _execute_single_with_parameters(
        "INSERT INTO wiki_references(" +
        "created_at, updated_at, page_id, referenced_name, link_type) " +
        "VALUES (" +
        "NOW(), NOW(), %s, %s, %s)",
        [ page_id, original_page_name_to_include, "I" ])

def _page_name_to_include(original_page_name_to_include, web_id):
    query_results = _execute_single_with_parameters(
        "SELECT page_id FROM wiki_references " +
        "LEFT JOIN pages ON pages.id = page_id " +
        "WHERE referenced_name = %s " +
        "AND link_type = %s " +
        "AND web_id = %s",
        [ original_page_name_to_include, "R", web_id ])
    try:
        page_id_to_include = query_results[0][0]
    except IndexError:
        page_id_to_include = _id_of_page(original_page_name_to_include)
    query_results = _execute_single_with_parameters(
        "SELECT name, web_id FROM pages " +
        "WHERE id = %s",
        [ page_id_to_include])
    return query_results[0]

def include_processor(
        page_id,
        references_before_rendering,
        pages_to_include,
        original_page_name_to_include,
        rendering_web_id):
    original_page_name_to_include = original_page_name_to_include.strip()
    page_name_to_include, web_id_of_page_to_include = _page_name_to_include(
        original_page_name_to_include,
        rendering_web_id)
    if not page_name_to_include:
        raise IncludeCannotBeEmptyException()
    if not _include_reference_already_present(
            references_before_rendering,
            original_page_name_to_include,
            rendering_web_id):
        _make_include_reference(
            page_id,
            original_page_name_to_include,
            page_name_to_include)
    page_content_directory = os.path.join(
        os.environ["NLAB_PAGE_CONTENT_DIRECTORY"],
        _address_of_web(web_id_of_page_to_include))
    path_to_page_to_include = os.path.join(
        page_content_directory,
        "_".join(page_name_to_include.split()))
    if os.path.exists(path_to_page_to_include):
        with open(path_to_page_to_include, "r") as page_to_include_file:
            page_to_include = page_to_include_file.read()
        try:
            after_opening_body_tag = page_to_include.split("<body>", 1)[1]
        except IndexError:
            return "<div>\n" + page_to_include + "</div>\n"
        content_to_include = after_opening_body_tag.split("</body>", 1)[0]
        return "<div>\n" + content_to_include + "</div>\n"
    id_of_page_to_include = _id_of_page(page_name_to_include)
    pages_to_include.append(id_of_page_to_include)
    return "[[!include " + page_name_to_include + "]]"

def define(
        page_id,
        rendering_web_id,
        references_before_rendering,
        pages_to_include):
    return find_block.Block(
        "[[!include ",
        "]]",
        lambda page_name_to_include: include_processor(
            page_id,
            references_before_rendering,
            pages_to_include,
            page_name_to_include,
            rendering_web_id),
        True)
