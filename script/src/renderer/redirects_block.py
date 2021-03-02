#!/usr/bin/python3

"""
Library defining a block for redirects, and a processor for the contents of
such a block
"""

import find_block
import MySQLdb
import os

class RedirectCannotBeEmptyException(Exception):
    pass

class RedirectAlreadyExistsOnDifferentPageException(Exception):
    def __init__(self, redirect_name, page_to_which_already_redirects):
        super().__init__()
        self.redirect_name = redirect_name
        self.page_to_which_already_redirects = page_to_which_already_redirects

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

def _name_of_page(page_id):
    query_results = _execute_single_with_parameters(
        "SELECT name FROM pages WHERE id = %s",
        [ page_id ])
    return query_results[0][0]

def _redirect_already_present(
        page_id,
        page_name_to_redirect,
        references_before_rendering,
        rendering_web_id):
    """
    query_results = _execute_single_with_parameters(
        "SELECT wiki_references.id, page_id FROM wiki_references " +
        "LEFT JOIN pages ON pages.id = wiki_references.page_id " +
        "WHERE link_type = %s " +
        "AND referenced_name = %s " +
        "AND web_id = %s",
        ["R", page_name_to_redirect, rendering_web_id])
    try:
        query_result = query_results[0]
    except IndexError:
        return False

    id_of_page_to_which_already_redirects = str(query_result[1])
    if page_id != str(id_of_page_to_which_already_redirects):
        page_name = _name_of_page(id_of_page_to_which_already_redirects)
        raise RedirectAlreadyExistsOnDifferentPageException(
            page_name_to_redirect,
            page_name)
    for i in range(0, len(references_before_rendering)):
        if references_before_rendering[i][0] == query_result[0]:
            del references_before_rendering[i]
            break
    """
    for i in range(0, len(references_before_rendering)):
        reference_id, referenced_name, link_type, web_id = \
            references_before_rendering[i]
        if referenced_name == page_name_to_redirect and link_type == "R" \
                and int(web_id) == rendering_web_id:
            del references_before_rendering[i]
            return True
    return False

def _make_redirect(page_id, page_name_to_redirect):
    _execute_single_with_parameters(
        "INSERT INTO wiki_references(" +
        "created_at, updated_at, page_id, referenced_name, link_type) " +
        "VALUES (" +
        "NOW(), NOW(), %s, %s, %s)",
        [ page_id, page_name_to_redirect, "R" ])

def _pages_in_which_redirect_is_wanted(
        page_name_to_redirect,
        rendering_web_id):
    query_results = _execute_single_with_parameters(
        "SELECT page_id FROM wiki_references " +
        "LEFT JOIN pages ON pages.id = wiki_references.page_id " +
        "WHERE referenced_name = %s " +
        "AND link_type = %s " +
        "AND web_id = %s",
        [ page_name_to_redirect, "W", rendering_web_id ])
    return [ query_result[0] for query_result in query_results ]

def _add_redirect_to(page_id_requiring_redirect, page_name_to_redirect):
    _execute_single_with_parameters(
       "UPDATE wiki_references SET link_type = %s " +
       "WHERE referenced_name = %s " +
       "AND page_id = %s " +
       "AND link_type = %s",
       [ "L", page_name_to_redirect, page_id_requiring_redirect, "W" ])

def redirect_processor(
        page_id,
        references_before_rendering,
        pages_to_re_render_and_expire,
        page_name_to_redirect,
        rendering_web_id,
        only_this):
    page_name_to_redirect = page_name_to_redirect.strip()
    if not page_name_to_redirect:
        raise RedirectCannotBeEmptyException()
    if only_this:
        return
    if _redirect_already_present(
            page_id,
            page_name_to_redirect,
            references_before_rendering,
            rendering_web_id):
        return
    _make_redirect(page_id, page_name_to_redirect)
    page_ids_requiring_redirect = _pages_in_which_redirect_is_wanted(
        page_name_to_redirect,
        rendering_web_id)
    for page_id_requiring_redirect in page_ids_requiring_redirect:
        _add_redirect_to(page_id_requiring_redirect, page_name_to_redirect)
        pages_to_re_render_and_expire.append(page_id_requiring_redirect)

def define(
        page_id,
        rendering_web_id,
        references_before_rendering,
        pages_to_re_render_and_expire,
        only_this):
    return find_block.Block(
        "[[!redirects ",
        "]]",
        lambda page_name_to_redirect: redirect_processor(
            page_id,
            references_before_rendering,
            pages_to_re_render_and_expire,
            page_name_to_redirect,
            rendering_web_id,
            only_this),
        False)
