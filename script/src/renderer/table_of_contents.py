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
    page_content_directory = os.environ["NLAB_PAGE_CONTENT_DIRECTORY"]
    page_content_path = os.path.join(
        page_content_directory,
        "_".join(page_name.split(" ")))
    with open(page_content_path, "r") as page_content_file:
        content = page_content_file.read()
    return content

def _split_header(header_line):
    split_at_header_beginning = header_line.split("<h", 1)
    after_header_beginning = split_at_header_beginning[1]
    try:
        header_size = int(after_header_beginning[0])
    except ValueError:
        raise _NotAHeaderException()
    if header_size > 6 or header_size < 2:
        raise _NotAHeaderException()
    split_at_id = after_header_beginning.split("id='", 1)
    if len(split_at_id) > 1:
        after_id = split_at_id[1]
        href = after_id.split("'", 1)[0]
    else:
        split_at_id = after_header_beginning.split("id=\"", 1)
        try:
            after_id = split_at_id[1]
            href = after_id.split("\"", 1)[0]
        except IndexError:
            href = None
    after_header_tag = after_header_beginning.split(">",1)[1]
    header = after_header_tag.split("</h")[0]
    return header_size, href, header

def _table_of_contents(page_content, placeholder):
    page_lines = page_content.splitlines()
    current_header_size = 1
    header_sizes = []
    table_of_contents_html = "<div class='maruku_toc'>\n"
    after_table_of_contents = False
    for line in page_lines:
        if not after_table_of_contents:
            if placeholder in line:
                after_table_of_contents = True
            else:
                continue
        stripped_line = line.strip()
        if not "<h" in stripped_line:
            continue
        try:
            header_size, href, header = _split_header(stripped_line)
        except _NotAHeaderException:
            continue
        if not header:
            raise EmptyHeaderException()
        if href is not None:
            header_contents_html = (
                "<li>" +
                "<a href='#" +
                href +
                "'>" +
                header +
                "</a>" +
                "</li>" +
                "\n")
        else:
            header_contents_html = (
                "<li>" +
                header +
                "</li>" +
                "\n")
        if header_size == current_header_size:
            table_of_contents_html += header_contents_html
        elif header_size > current_header_size:
            table_of_contents_html += "<ul>\n"
            table_of_contents_html += header_contents_html
            header_sizes.append(header_size)
            current_header_size = header_size
        else:
            header_sizes.pop()
            max_depth = len(header_sizes)
            depth = 1
            if depth == max_depth:
                table_of_contents_html += "</ul>\n" * depth
                table_of_contents_html += header_contents_html
                current_header_size = 2
                continue
            while depth < max_depth:
                previous_header_size = header_sizes.pop()
                if previous_header_size <= header_size:
                    table_of_contents_html += "</ul>\n" * depth
                    table_of_contents_html += header_contents_html
                    if previous_header_size != header_size:
                        header_sizes.extend([previous_header_size, header_size])
                    else:
                        header_sizes.append(header_size)
                    current_header_size = header_size
                    break
                if depth + 1 == max_depth:
                    table_of_contents_html += "</ul>\n" * (depth + 1)
                    table_of_contents_html += header_contents_html
                    current_header_size = 2
                    break
                depth += 1
    table_of_contents_html += "</ul>\n" * len(header_sizes)
    table_of_contents_html += "</div>\n"
    return table_of_contents_html

def _find_header_which_needs_rendering_processor(
        header,
        need_to_render_for_toc_flag):
    stripped_header = header.strip()
    if stripped_header == "### Context" or stripped_header == "###Context":
        return "\n##" + header
    header_depth = 2
    for character in header:
        if character == '#':
            header_depth +=1
        else:
            break
    if header_depth <= 6:
        need_to_render_for_toc_flag.set_to(True)
    return "\n##" + header

def _process_table_of_contents_block(placeholder, table_of_contents_flag):
    table_of_contents_flag.set_to(True)
    return placeholder

def add_placeholder(
        page_content,
        placeholder,
        table_of_contents_flag,
        need_to_render_for_toc_flag):
    header_block = find_block.Block(
        "\n##",
        " ",
        lambda header: _find_header_which_needs_rendering_processor(
            header,
            need_to_render_for_toc_flag),
        True)
    placeholder_block = find_block.Block(
        placeholder,
        None,
        lambda found_placeholder: _process_table_of_contents_block(
            placeholder + "\n\n",
            table_of_contents_flag),
        True)
    processor = find_block.Processor([
        table_of_contents_block.define(
            placeholder,
            table_of_contents_flag),
        placeholder_block,
        header_block])
    return processor.process(page_content)

def add_to(page_content, placeholder):
    table_of_contents = _table_of_contents(
        page_content,
        placeholder)
    return page_content.replace(placeholder, table_of_contents)
