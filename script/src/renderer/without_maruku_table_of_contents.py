#!/usr/bin/python3

import find_block
import MySQLdb
import os
import table_of_contents_block

class EmptyHeaderException(Exception):
    pass

class _NotAHeaderException(Exception):
    pass

class InvalidHeaderStructureException(Exception):
    def __init__(self, message):
        self.message = message

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

def _id_of_page(page_name):
    query_results = _execute_single_with_parameters(
        "SELECT id FROM pages WHERE name = %s",
        [ page_name ])
    return query_results[0][0]

def _content_of_page(page_name):
    page_id = _id_of_page(page_name.strip())
    query_results = _execute_single_with_parameters(
        "SELECT content FROM revisions " +
        "WHERE page_id = %s " +
        "ORDER BY id DESC LIMIT 1",
        [ page_id ])
    return query_results[0][0]

def _split_header(header_line):
    header_depth = 0
    for i, character in enumerate(header_line):
        if character != "#":
            index_of_beginning_of_header = i
            break
        header_depth += 1
    if header_depth > 5:
        raise _NotAHeaderException()
    return header_depth, header_line[index_of_beginning_of_header:].strip()

def _replace_include(line):
    replaced_lines = []
    split_at_beginning_of_include = line.split("[[!include ")
    after_beginning_of_include = split_at_beginning_of_include[1]
    split_at_end_of_include = after_beginning_of_include.split("]]")
    before_include = split_at_beginning_of_include[0]
    if before_include:
        replaced_lines.append(before_include)
    page_name = split_at_end_of_include[0]
    content_of_page_to_include = _content_of_page(page_name)
    replaced_lines.extend(content_of_page_to_include.splitlines())
    after_include = split_at_end_of_include[1]
    if after_include:
        replaced_lines.append(after_include)
    return replaced_lines

def _table_of_contents(page_content, placeholder):
    page_lines = page_content.splitlines()
    current_header_depth = 1
    table_of_contents_html = "<div class='nlab_toc'>\n"
    page_content_with_headers = []
    found_first_line_of_table_of_contents_specifier = False
    after_table_of_contents = False
    page_lines_with_includes = []
    for line in page_lines:
        if "[[!include " in line:
            page_lines_with_includes.extend(_replace_include(line))
        else:
            page_lines_with_includes.append(line)
    for line in page_lines_with_includes:
        if not after_table_of_contents:
            if placeholder in line:
                after_table_of_contents = True
            page_content_with_headers.append(line)
            continue
        stripped_line = line.strip()
        if not stripped_line.startswith("##"):
            page_content_with_headers.append(line)
            continue
        try:
            header_depth, header = _split_header(stripped_line)
        except _NotAHeaderException:
            page_content_with_headers.append(line)
            continue
        if not header:
            raise EmptyHeaderException()
        modified_header = "_".join(header.split()).lower()
        header_contents_html = (
            "<li>" +
            "<a href='#" +
            modified_header +
            "'>" +
            header +
            "</a>" +
            "</li>" +
            "\n")
        if header_depth == current_header_depth:
            table_of_contents_html += header_contents_html
        elif header_depth > current_header_depth:
            if header_depth != current_header_depth + 1:
                raise InvalidHeaderStructureException(
                    "A sub-heading must be at depth one smaller than the " +
                    "heading it is immediately under. This is not the case " +
                    "for the heading: " +
                    stripped_line)
            table_of_contents_html += "<ul>\n"
            table_of_contents_html += header_contents_html
            current_header_depth += 1
        else:
            depth_difference = current_header_depth - header_depth
            table_of_contents_html += "</ul>\n" * depth_difference
            table_of_contents_html += header_contents_html
            current_header_depth = header_depth
        page_content_with_headers.append(
            "<h" +
            str(current_header_depth) +
            " id='" +
            modified_header +
            "'>" +
            header +
            "</h" +
            str(current_header_depth) +
            ">\n")
    depth_difference = current_header_depth - 1
    table_of_contents_html += "</ul>\n" * depth_difference
    table_of_contents_html += "</div>\n"
    return table_of_contents_html

class Flag:
    def __init__(self):
        self.is_set = False

    def set_to(self, truth_value):
        self.is_set = truth_value

def _add_placeholder(page_content, placeholder, table_of_contents_flag):
    processor = find_block.Processor([
        table_of_contents_block.define(placeholder, table_of_contents_flag)])
    return processor.process(page_content)

def add_to(page_content):
    placeholder = "[[!table_of_contents]]"
    table_of_contents_flag = Flag()
    page_content_with_placeholder = _add_placeholder(
        page_content,
        placeholder,
        table_of_contents_flag)
    if not table_of_contents_flag.is_set:
        return page_content
    table_of_contents = _table_of_contents(
        page_content,
        placeholder)
    return page_content_with_placeholder.replace(placeholder, table_of_contents)
