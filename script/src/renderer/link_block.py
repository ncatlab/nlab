#!/usr/bin/env python3

"""
Library defining a block for links, and a processor for the contents of
such a block
"""

import find_block
import MySQLdb
import os
import urllib.parse

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

class InvalidWikiLinkFormatException(Exception):
    def __init__(self, message):
        super().__init__(message)

class _NotFileLinkException(Exception):
    pass

class _NoSuchWebException(Exception):
    pass

class _NoExistingReferenceToFileException(Exception):
    pass

class _NoSuchFileException(Exception):
    pass

def _formatted_web_name(name):
    return "".join(name.split()).lower().strip().replace("'","")

def _id_of_web(web_name):
    query_results = _execute_single_with_parameters(
        "SELECT id, name, address FROM webs",
        [])
    for web_id, name, address in query_results:
        formatted_name = _formatted_web_name(name)
        formatted_web_name = _formatted_web_name(web_name)
        if (formatted_name == formatted_web_name) or (address == web_name):
            return web_id, address
    raise _NoSuchWebException()

def _address_of_web(web_id):
    query_results = _execute_single_with_parameters(
        "SELECT address FROM webs WHERE id = %s",
        [ web_id ])
    try:
        return query_results[0][0]
    except IndexError:
        raise _NoSuchWebException

def _published(web_id):
    query_results = _execute_single_with_parameters(
        "SELECT published FROM webs WHERE id = %s",
        [ web_id ])
    try:
        return True if query_results[0][0] == 1 else False
    except IndexError:
        raise _NoSuchWebException

def _existing_redirect(page_name, web_id):
    query_results = _execute_single_with_parameters(
        "SELECT wiki_references.id FROM wiki_references " +
        "LEFT JOIN pages ON pages.id = wiki_references.page_id " +
        "WHERE referenced_name = %s " +
        "AND web_id = %s " +
        "AND link_type = %s",
        [ page_name, web_id, "R"])
    try:
        query_results[0]
        return True
    except IndexError:
        return False

def _exists(page_name, web_id):
    query_results = _execute_single_with_parameters(
        "SELECT id FROM pages " +
        "WHERE name = %s " +
        "AND web_id = %s",
        [ page_name, web_id])
    try:
        query_results[0]
        return True
    except IndexError:
        return _existing_redirect(page_name, web_id)

def _reference_to_existing_page_already_present(
        references_before_rendering,
        reference_page_name,
        reference_web_id):
    for i in range(0, len(references_before_rendering)):
        reference_id, referenced_name, link_type, web_id = \
            references_before_rendering[i]
        if referenced_name == reference_page_name and link_type == "L" \
                and int(reference_web_id) == int(web_id):
            del references_before_rendering[i]
            return True
    return False

def _reference_to_wanted_page_already_present(
        references_before_rendering,
        reference_page_name,
        reference_web_id):
    for i in range(0, len(references_before_rendering)):
        reference_id, referenced_name, link_type, web_id = \
            references_before_rendering[i]
        if referenced_name == reference_page_name and link_type == "W" \
                and int(reference_web_id) == int(web_id):
            del references_before_rendering[i]
            return True
    return False

def _make_reference_to_existing_page(page_id, reference_page_name):
    _execute_single_with_parameters(
        "INSERT INTO wiki_references(" +
        "created_at, updated_at, page_id, referenced_name, link_type) " +
        "VALUES (" +
        "NOW(), NOW(), %s, %s, %s)",
        [ page_id, reference_page_name, "L" ])

def _make_reference_to_wanted_page(page_id, reference_page_name):
    _execute_single_with_parameters(
        "INSERT INTO wiki_references(" +
        "created_at, updated_at, page_id, referenced_name, link_type) " +
        "VALUES (" +
        "NOW(), NOW(), %s, %s, %s)",
        [ page_id, reference_page_name, "W" ])

def _exists_file(file_name, web_id):
    query_results = _execute_single_with_parameters(
        "SELECT description FROM wiki_files " +
        "WHERE file_name = %s " +
        "AND web_id = %s",
        [ file_name, web_id])
    try:
        return query_results[0][0]
    except IndexError:
        raise _NoSuchFileException

def _reference_to_existing_file_already_present(
        references_before_rendering,
        reference_file_name,
        reference_web_id):
    for i in range(0, len(references_before_rendering)):
        reference = references_before_rendering[i]
        reference_id, referenced_name, link_type, web_id = reference
        if referenced_name == reference_file_name and link_type == "F" \
                and web_id == reference_web_id:
            del references_before_rendering[i]
            return True
    return False

def _reference_to_wanted_file_already_present(
        references_before_rendering,
        reference_file_name,
        reference_web_id):
    for i in range(0, len(references_before_rendering)):
        reference_id, referenced_name, link_type, web_id = \
            references_before_rendering[i]
        if referenced_name == reference_file_name and link_type == "E" \
                and web_id == reference_web_id:
            del references_before_rendering[i]
            return True
    return False

def _make_reference_to_existing_file(page_id, file_name):
    _execute_single_with_parameters(
        "INSERT INTO wiki_references(" +
        "created_at, updated_at, page_id, referenced_name, link_type) " +
        "VALUES (" +
        "NOW(), NOW(), %s, %s, %s)",
        [ page_id, file_name, "F" ])

def _make_reference_to_wanted_file(page_id, file_name):
    _execute_single_with_parameters(
        "INSERT INTO wiki_references(" +
        "created_at, updated_at, page_id, referenced_name, link_type) " +
        "VALUES (" +
        "NOW(), NOW(), %s, %s, %s)",
        [ page_id, file_name, "E" ])

def file_link_processor(
        page_id,
        references_before_rendering,
        file_name,
        file_description,
        file_type,
        web_id,
        web_address):
    if file_type not in ["file", "pic"]:
        raise _NotFileLinkException()
    try:
        description = _exists_file(file_name, web_id)
    except _NoSuchFileException:
        if not _reference_to_wanted_file_already_present(
                references_before_rendering,
                file_name,
                web_id):
            _make_reference_to_wanted_file(page_id, file_name)
        return (
             "<span class='newWikiWord'>" +
            file_name +
            "<a href='/" +
            web_address +
            "/files/" +
            urllib.parse.quote_plus(file_name) +
            "'>" +
            "?" +
            "</a>" +
            "</span>")
    if not _reference_to_existing_file_already_present(
            references_before_rendering,
            file_name,
            web_id):
        _make_reference_to_existing_file(page_id, file_name)
    if file_description:
        link_text = file_description
    elif description:
        link_text = description
    else:
        link_text = file_name
    description = description.replace("'", "&#39;").replace("\"", "&#34;")
    if file_type == "file":
        return ("<a class='existingWikiWord' " +
            "href='/" +
            web_address +
            "/files/" +
            urllib.parse.quote_plus(file_name) +
            "' title='" +
            description +
            "'>" +
            link_text +
            "</a>")
    return (
        "<img src='/" +
        web_address +
        "/files/" +
        urllib.parse.quote_plus(file_name) +
        "' alt='" +
        description +
        "'/>")

def _web_and_page_details(page_name_parts):
    web_name = page_name_parts[0]
    try:
        web_id, web_address = _id_of_web(web_name)
    except _NoSuchWebException:
        raise InvalidWikiLinkFormatException(page_link)
    file_name = page_name_parts[1]
    return web_id, web_address, file_name

def link_processor(
        page_id,
        references_before_rendering,
        page_link,
        rendering_web_id):
    if not page_link:
        raise InvalidWikiLinkFormatException(page_link)
    stripped_page_link = page_link.strip()
    parts = stripped_page_link.split("|")
    if len(parts) > 2:
        raise InvalidWikiLinkFormatException(page_link)
    page_name = parts[0]
    page_name = " ".join(
        page_name.replace("\n", " ").replace("\r", " ").split()).strip()
    try:
        link_text = parts[1]
        link_text_same_as_page_name = False
    except IndexError:
        link_text = page_name
        link_text_same_as_page_name = True
    if not page_name or not link_text:
        raise InvalidWikiLinkFormatException(page_link)
    page_name_parts = page_name.split(":")
    if len(page_name_parts) > 3:
        raise InvalidWikiLinkFormatException(page_link)
    if not link_text_same_as_page_name:
        link_text_parts = link_text.split(":")
        number_of_link_text_parts = len(link_text_parts)
        if number_of_link_text_parts > 2:
            raise InvalidWikiLinkFormatException(page_link)
        if number_of_link_text_parts == 2:
            description = link_text_parts[0]
            file_type = link_text_parts[1]
            if len(page_name_parts) > 2:
                raise InvalidWikiLinkFormatException(page_link)
            if len(page_name_parts) == 1:
                file_name = page_name
                web_id = rendering_web_id
                web_address = _address_of_web(rendering_web_id)
            else:
                web_id, web_address, file_name = _web_and_page_details(
                    page_name_parts)
            try:
                return file_link_processor(
                    page_id,
                    references_before_rendering,
                    file_name,
                    description,
                    file_type,
                    web_id,
                    web_address)
            except _NotFileLinkException:
                # In this case, the link text is presumably intended to have a
                # colon
                pass
    if len(page_name_parts) == 3:
        file_type = page_name_parts[2]
        if file_type not in ["file", "pic"]:
            raise InvalidWikiLinkFormatException(page_link)
        description = ""
        web_id, web_address, file_name = _web_and_page_details(
            page_name_parts)
        return file_link_processor(
            page_id,
            references_before_rendering,
            file_name,
            description,
            file_type,
            web_id,
            web_address)
    if len(page_name_parts) == 2:
        page_name_or_file_type = page_name_parts[1]
        if page_name_or_file_type in ["file", "pic"]:
            file_name = page_name_parts[0]
            description = ""
            file_type = page_name_or_file_type
            web_id = rendering_web_id
            web_address = _address_of_web(rendering_web_id)
            return file_link_processor(
                page_id,
                references_before_rendering,
                file_name,
                description,
                file_type,
                web_id,
                web_address)
        web_name = page_name_parts[0]
        page_name = page_name_or_file_type
        page_name = page_name_parts[1]
        if link_text_same_as_page_name:
            link_text = page_name
        try:
            web_id, web_address = _id_of_web(web_name)
        except _NoSuchWebException:
            raise InvalidWikiLinkFormatException(page_link)
    else:
        web_id = rendering_web_id
        web_address = _address_of_web(rendering_web_id)
    page_name_split_at_reference = page_name.split("#", 1)
    page_name_without_reference = page_name_split_at_reference[0]
    try:
        reference = page_name_split_at_reference[1]
    except IndexError:
        reference = None
    if _exists(page_name_without_reference, web_id):
        if not _reference_to_existing_page_already_present(
                references_before_rendering,
                page_name_without_reference,
                web_id):
            _make_reference_to_existing_page(
                page_id,
                page_name_without_reference)
        link_text = link_text.replace("*", "\*")
        if reference is not None:
            page_name_for_href = (
                urllib.parse.quote_plus(page_name_without_reference) +
                "#" +
                urllib.parse.quote_plus(reference))
        else:
            page_name_for_href = urllib.parse.quote_plus(
                page_name_without_reference)
        show_or_published = "/published/" if _published(web_id) else "/show/"
        return ("<a class='existingWikiWord' " +
            "href='/" +
            web_address +
            show_or_published +
            page_name_for_href +
            "'>" +
            link_text +
            "</a>")
    if not _reference_to_wanted_page_already_present(
            references_before_rendering,
            page_name_without_reference,
            web_id):
        _make_reference_to_wanted_page(
            page_id,
            page_name_without_reference)
    return (
        "<span class='newWikiWord'>" +
        link_text +
        "<a href='/" +
        web_address +
        "/new/" +
        urllib.parse.quote_plus(page_name_without_reference) +
        "'>" +
        "?" +
        "</a>" +
        "</span>")

def define(page_id, rendering_web_id, references_before_rendering):
    return find_block.Block(
        "[[",
        "]]",
        lambda page_link: link_processor(
            page_id,
            references_before_rendering,
            page_link,
            rendering_web_id),
        True)
