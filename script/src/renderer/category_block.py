#!/usr/bin/env python3

"""
Library defining a block for categories, and a processor for the contents of
such a block
"""

import database
import find_block
import urllib.parse

class InvalidCategoryFormatException(Exception):
    def __init__(self, message):
        super().__init__(message)

class _NoSuchWebException(Exception):
    pass

def _address_of_web(web_id):
    query_results = database.execute_single_with_parameters(
        "SELECT address FROM webs WHERE id = %s",
        [ web_id ])
    try:
        return query_results[0][0]
    except IndexError:
        raise _NoSuchWebException

def _category_reference_already_present(
        references_before_rendering,
        category,
        rendering_web_id):
    for i in range(0, len(references_before_rendering)):
        reference_id, referenced_name, link_type, web_id = \
            references_before_rendering[i]
        if referenced_name == category and link_type == "C" \
                and int(web_id) == rendering_web_id:
            del references_before_rendering[i]
            return True
    return False

def _make_category_reference(page_id, category):
    database.execute_single_with_parameters(
        "INSERT INTO wiki_references(" +
        "created_at, updated_at, page_id, referenced_name, link_type) " +
        "VALUES (" +
        "NOW(), NOW(), %s, %s, %s)",
        [ page_id, category, "C" ])

def category_processor(
        page_id,
        categories_specification,
        references_before_rendering,
        rendering_web_id):
    if not categories_specification:
        raise InvalidCategoryFormatException(page_link)
    stripped_categories_specification = categories_specification.strip()
    categories = stripped_categories_specification.split(",")
    html_string = (
        "<div class='property'>" +
        "category: ")
    is_first_category = True
    for category in categories:
        category = category.strip()
        if not _category_reference_already_present(
                references_before_rendering,
                category,
                rendering_web_id):
            _make_category_reference(page_id, category)
        if not is_first_category:
            html_string += ", "
        else:
            is_first_category = False
        html_string += (
            "<a class='category_link' " +
            "href='/" +
            _address_of_web(rendering_web_id) +
            "/all_pages/" +
            urllib.parse.quote_plus(category) +
            "'>" +
            category +
            "</a>")
    html_string += "</div>"
    return html_string

def define(page_id, rendering_web_id, references_before_rendering):
    return find_block.Block(
        "\ncategory:",
        "\n",
        lambda categories_specification: category_processor(
            page_id,
            categories_specification,
            references_before_rendering,
            rendering_web_id),
        True)
