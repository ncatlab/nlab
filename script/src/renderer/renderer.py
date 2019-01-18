#!/usr/bin/python3.7

import argparse
import category_block
import errno
import centre_block
import find_block
import include_block
import json
import link_block
import logging
import MySQLdb
import nowiki_block
import os
import re
import redirects_block
import reference_block
import reference_numbering
import svg_header_block
import subprocess
import sys
import table_of_contents
import table_of_contents_block
import tex_block
import tex_parser
import theorem_environment_blocks
import tikz_diagram_block
import time

"""
Initialises logging. Logs to

renderer.log
"""
logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)
logging.Formatter.converter = time.gmtime
logging_formatter = logging.Formatter(
    "%(asctime)s %(levelname)s %(name)s %(message)s")
log_directory = os.environ["NLAB_LOG_DIRECTORY"]
logging_file_handler = logging.FileHandler(
    os.path.join(log_directory, "renderer.log"))
logging_file_handler.setFormatter(logging_formatter)
logger.addHandler(logging_file_handler)

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

class Flag:
    def __init__(self):
        self.is_set = False

    def set_to(self, truth_value):
        self.is_set = truth_value

class RenderingException(Exception):
    def __init__(self, message):
        super().__init__(message)

def _name_of_page(page_id):
    query_results = _execute_single_with_parameters(
        "SELECT name FROM pages WHERE id = %s",
        [ page_id ])
    return query_results[0][0]

def _web_id_of_page(page_id):
    query_results = _execute_single_with_parameters(
        "SELECT web_id FROM pages WHERE id = %s",
        [ page_id ])
    return query_results[0][0]

def _web_address_of_page(page_id):
    query_results = _execute_single_with_parameters(
        "SELECT address FROM webs " +
        "LEFT JOIN pages ON pages.web_id = webs.id " +
        "WHERE pages.id = %s",
        [page_id])
    return query_results[0][0]

def _content_of_page(page_id):
    query_results = _execute_single_with_parameters(
        "SELECT content FROM revisions " +
        "WHERE page_id = %s " +
        "ORDER BY id DESC LIMIT 1",
        [ page_id ])
    return query_results[0][0]

def _references_before_rendering(page_id):
    query_results = _execute_single_with_parameters(
        "SELECT wiki_references.id, referenced_name, link_type, web_id FROM " +
        "wiki_references LEFT JOIN pages ON page_id = pages.id " +
        "WHERE page_id = %s " +
        "AND link_type != %s",
        [ page_id, "A" ])
    return list(query_results)

def _remove_references_not_from_rendering_web(
        references_before_rendering,
        rendering_web_id):
    return [ reference for reference in references_before_rendering \
        if int(reference[3]) == rendering_web_id ]

def _update_pages_where_redirect_was_used(
        reference_name,
        pages_to_re_render_and_expire):
    query_results = _execute_single_with_parameters(
        "SELECT page_id FROM wiki_references " +
        "WHERE referenced_name = %s " +
        "AND link_type = %s",
        [ reference_name, "L" ])
    pages_to_re_render_and_expire.extend(
        [ query_result[0] for query_result in query_results ])
    _execute_single_with_parameters(
        "UPDATE wiki_references " +
        "SET link_type = %s " +
        "WHERE referenced_name = %s " +
        "AND link_type = %s",
        [ "W", reference_name, "L"])

def _delete_references_which_no_longer_exist(
        references,
        pages_to_re_render_and_expire):
    if not references:
        return
    reference_ids_to_delete = []
    for reference in references:
        reference_id = reference[0]
        reference_name = reference[1]
        link_type = reference[2]
        if link_type == "R":
            _update_pages_where_redirect_was_used(
               reference_name,
               pages_to_re_render_and_expire)
        reference_ids_to_delete.append(reference_id)
    condition_string = "id = %s"
    for reference_id in reference_ids_to_delete[1:]:
        condition_string += " OR id = %s"
    _execute_single_with_parameters(
        "DELETE FROM wiki_references WHERE (" +
        condition_string +
        ")",
        reference_ids_to_delete)

def _pages_included_in(page_name):
    query_results = _execute_single_with_parameters(
        "SELECT page_id FROM wiki_references " +
        "LEFT JOIN pages ON pages.id = wiki_references.page_id " +
        "WHERE referenced_name = %s " +
        "AND link_type = %s",
        [ page_name, "I"])
    return [ query_result[0] for query_result in query_results ]

def _pages_which_require(page_name):
    query_results = _execute_single_with_parameters(
        "SELECT page_id FROM wiki_references " +
        "LEFT JOIN pages ON pages.id = wiki_references.page_id " +
        "WHERE referenced_name = %s " +
        "AND link_type = %s",
        [ page_name, "W" ])
    return [ query_result[0] for query_result in query_results ]

"""
We first make sure there is at least \n before <table> and one \n after
</table>. Then we make sure that there are exactly two occurrences.
"""
def _surround_tables_with_blank_lines(rendered_page_content):
    blank_lines_before_tables = rendered_page_content.replace(
        "<table",
        "\n<table")
    exactly_two_blank_lines_before_tables = re.sub(
        r'\n+<table',
        "\n\n<table",
        blank_lines_before_tables)
    blank_lines_after_tables = exactly_two_blank_lines_before_tables.replace(
        "</table>",
        "</table>\n")
    exactly_two_blank_lines_before_and_after_tables = re.sub(
        r'/table>\n+',
        "/table>\n\n",
        blank_lines_after_tables)
    return exactly_two_blank_lines_before_and_after_tables

def _process_references(page_content):
    references_processor = find_block.Processor([
        reference_block.define()])
    return references_processor.process(page_content)

def _write_to_file_for_maruku(page_id, content_for_rendering):
    root_page_content_directory = os.environ["NLAB_PAGE_CONTENT_DIRECTORY"]
    maruku_root_page_content_directory = os.path.join(
        root_page_content_directory,
        "maruku")
    web_address = _web_address_of_page(page_id)
    page_content_directory = os.path.join(
        maruku_root_page_content_directory,
        web_address)
    if not os.path.exists(page_content_directory):
        try:
            os.mkdir(page_content_directory)
        except OSError as osError:
            if osError.errno != errno.EEXIST:
                raise osError
    page_name = _name_of_page(page_id)
    page_content_file_name = \
        "_".join(page_name.split()).replace("/", "¤") + ".md"
    page_content_path = os.path.join(
        page_content_directory,
        page_content_file_name)
    with open(page_content_path, "w") as page_content_file:
        page_content_file.write(content_for_rendering)
    return page_content_directory, page_content_file_name

"""
Renders the page content, handling redirects, includes, links to nLab
pages, category links, table of contents, etc.
"""
def render(page_id, page_content):
    page_content = centre_block.handle_initial_centring(page_content)
    page_content = tikz_diagram_block.handle_commutative_diagrams(page_content)
    pages_to_re_render_and_expire = []
    pages_to_render_to_include = []
    references_before_rendering = _references_before_rendering(page_id)
    page_name = _name_of_page(page_id)
    rendering_web_id = _web_id_of_page(page_id)
    pages_to_re_render_and_expire.extend(_pages_which_require(page_name))
    blocks = [
        include_block.define(
            page_id,
            rendering_web_id,
            references_before_rendering,
            pages_to_render_to_include),
        redirects_block.define(
            page_id,
            rendering_web_id,
            references_before_rendering,
            pages_to_re_render_and_expire),
        link_block.define(
            page_id,
            rendering_web_id,
            references_before_rendering),
        category_block.define(
            page_id,
            rendering_web_id,
            references_before_rendering),
        nowiki_block.define(),
        reference_block.define(),
        tex_block.define_single(page_id),
        tex_block.define_double(page_id)]
    processor = find_block.Processor(blocks)
    processed_content = processor.process(page_content)
    processed_content = _surround_tables_with_blank_lines(processed_content)
    references_before_rendering = _remove_references_not_from_rendering_web(
        references_before_rendering,
        rendering_web_id)
    if references_before_rendering:
        logger.info(
            "On page with ID " +
            str(page_id) +
            " the following references no longer exist: " +
            str(references_before_rendering))
    _delete_references_which_no_longer_exist(
        references_before_rendering,
        pages_to_re_render_and_expire)
    pages_to_re_render_and_expire.extend(pages_to_render_to_include)
    pages_to_re_render_and_expire.extend(_pages_included_in(page_name))
    pages_to_re_render_and_expire = list(set(pages_to_re_render_and_expire))
    if pages_to_render_to_include:
        pages_to_re_render_and_expire.append(page_id)
    return processed_content,  pages_to_re_render_and_expire

def initial_rendering(page_id, page_content):
    error_message = None
    error = None
    try:
        processed_content, pages_to_re_render_and_expire = render(
            page_id,
            page_content)
    except find_block.MoreThanOneMatchException:
        error_message = "Page contains a block with more than one match"
    except redirects_block.RedirectCannotBeEmptyException:
        error_message = "Page contains an empty redirect"
    except redirects_block.RedirectAlreadyExistsOnDifferentPageException as \
            redirect_already_exists_exception:
        error_message = (
            "There is already a redirect of '" +
            redirect_already_exists_exception.redirect_name +
            "' to the page: " +
            redirect_already_exists_exception.page_to_which_already_redirects)
    except include_block.IncludeCannotBeEmptyException:
        error_message = "Page contains an empty include"
    except include_block.CircularIncludeException:
        error_message = "Page contains a circular include"
    except include_block.PageToIncludeDoesNotExistException as \
            page_to_include_does_not_exist_exception:
        error_message = (
            "The page " +
            str(page_to_include_does_not_exist_exception) +
            " cannot be included because it does not exist")
    except link_block.InvalidWikiLinkFormatException as \
            invalid_wiki_link_format_exception:
        invalid_link = str(invalid_wiki_link_format_exception)
        if not invalid_link:
            error_message = "Page contains an empty link"
        else:
            error_message = (
                "Page contains a link to an nLab page with invalid syntax: " +
                invalid_link)
    except category_block.InvalidCategoryFormatException:
        error_message = (
            "Page contains a category specification with invalid syntax")
    except table_of_contents.EmptyHeaderException:
        error_message = (
            "Page has an empty header, that is, a line of the form ##...# " +
            "without any header being provided")
    except table_of_contents.InvalidHeaderStructureException as \
            invalid_header_structure_exception:
        error_message = (
            "Page has an invalid header.\n\n " +
            str(invalid_header_structure_exception))
    except tex_parser.InvalidTexException as invalid_tex_exception:
        error_message = str(invalid_tex_exception)
    except tikz_diagram_block.TikzDiagramException as tikz_diagram_exception:
        error_message = str(tikz_diagram_exception)
    except Exception as exception:
        error_message = "An unexpected error occurred when rendering the page"
        error = exception
    if error_message is not None:
        if error is not None:
            log_error_message = error_message + ". Error: " + str(error)
        else:
            log_error_message = error_message
        logger.warning(
            "Could not render content for page with ID: " +
            str(page_id) +
            ". " +
            log_error_message)
        raise RenderingException(error_message)
    return processed_content, pages_to_re_render_and_expire

def maruku_rendering(page_id, page_content):
    logger.info(
        "Beginning rendering page with id " +
        str(page_id) +
        " with Maruku")
    page_content = page_content.replace("\r\n", "\n")
    maruku_content_directory, file_for_rendering = _write_to_file_for_maruku(
        page_id, page_content)
    # Maruku emits a lot to stdout, which we shall ignore
    completed_process = subprocess.run(
        [ "maruku", "-m", "itex2mml", file_for_rendering ],
        cwd = maruku_content_directory,
        capture_output = True)
    if not completed_process.returncode == 0:
        logger.warning(
            "Maruku failed to render the file " +
            file_for_rendering +
            " for page with id: " +
            str(page_id))
        raise RenderingException(
            "An error occurred when rendering the page. Check especially " +
            "any tex edits or additions")
    logger.info(
        "Successfully rendered with Maruku the file " +
        file_for_rendering +
        " for page with id: " +
        str(page_id))
    maruku_outputted_file_name = file_for_rendering[:-2] + "xhtml"
    maruku_outputted_file_path = os.path.join(
        maruku_content_directory,
        maruku_outputted_file_name)
    with open(maruku_outputted_file_path, "r") as maruku_outputted_file:
        processed_xml_content = maruku_outputted_file.read()
    # Maruku adds an <xml> tag and a DOCTYPE tag which need to be removed
    split_processed_xml_content = processed_xml_content.split("<html", 1)
    processed_content = "<html" + split_processed_xml_content[1]
    return processed_content

def post_maruku_rendering(
        page_id,
        page_content,
        web_address,
        page_content_file_name):
    page_content = centre_block.handle_post_centring(page_content)
    logger.info(
        "Beginning rendering theorem environments for page with id: " +
        str(page_id))
    try:
        page_content_with_tex_theorem_environments = \
            process_tex_theorem_environments(page_content)
    except Exception as theorem_environments_exception:
        error_message = (
           "An unexpected error occurred when rendering the theorem " +
           "environments")
        logger.warning(
            error_message +
            ". Error: "+
            str(theorem_environments_exception))
        raise RenderingException(error_message)
    logger.info(
        "Successfully rendered theorem environments for page with id: " +
        str(page_id))
    logger.info(
        "Beginning rendering table of contents for page with id: " +
        str(page_id))
    try:
        processed_content = add_table_of_contents(
            page_content_with_tex_theorem_environments)
    except Exception as table_of_contents_exception:
        error_message = (
           "An unexpected error occurred when rendering the table of "+
           "contents")
        logger.warning(
            error_message +
            ". Error: "+
            str(table_of_contents_exception))
        raise RenderingException(error_message)
    logger.info(
        "Successfully rendered table of contents for page with id: " +
        str(page_id))
    try:
        processed_content = reference_numbering.number_equations(
            processed_content,
            web_address,
            page_content_file_name)
        processed_content = reference_numbering.reference_equations(
            processed_content,
            web_address,
            page_content_file_name)
    except Exception as equation_numbering_exception:
        error_message = (
           "An unexpected error occurred when rendering the equation " +
           "references")
        logger.warning(
            error_message +
            ". Error: "+
            str(equation_numbering_exception))
        raise RenderingException(error_message)
    logger.info(
        "Successfully rendered equation references for page with id: " +
        str(page_id))
    try:
        processed_content = post_process_tex(processed_content)
    except Exception as post_process_tex_exception:
        error_message = (
           "An unexpected error occurred when post-processing the MathML")
        logger.warning(
            error_message +
            ". Error: "+
            str(post_processing_tex_exception))
        raise RenderingException(error_message)
    logger.info(
        "Successfully post-processed MathML for page with id: " +
        str(page_id))
    try:
        processed_content = correct_svg_header(processed_content)
    except Exception as correct_svg_header_exception:
        error_message = (
           "An unexpected error occurred when correcting SVG header")
        logger.warning(
            error_message +
            ". Error: "+
            str(correct_svg_header_exception))
        raise RenderingException(error_message)
    logger.info(
        "Successfully corrected SVG header if necessary for page with id: " +
        str(page_id))
    return processed_content

def process_tex_theorem_environments(page_content):
    preliminary_theorem_environment_blocks = list(
        theorem_environment_blocks.define_all_preliminary())
    preliminary_theorem_environment_blocks.extend(
        list(table_of_contents_block.define_all_sections()))
    preliminary_theorem_environment_processor = find_block.Processor(
        preliminary_theorem_environment_blocks)
    processed_content = preliminary_theorem_environment_processor.process(
        page_content)
    processed_content = _process_references(processed_content)
    theorem_environment_processor = find_block.Processor(
        list(theorem_environment_blocks.define_all()))
    return theorem_environment_processor.process(processed_content)

def post_process_tex(page_content):
    tex_parser_blocks = [ tex_block.define_tex_post() ]
    tex_parser_processor = find_block.Processor(
        tex_parser_blocks)
    return tex_parser_processor.process(page_content)

def correct_svg_header(page_content):
    svg_header_processor = find_block.Processor(
        [ svg_header_block.define() ])
    return svg_header_processor.process(page_content)

def add_table_of_contents(page_content):
    table_of_contents_flag = Flag()
    table_of_contents_placeholder = "[[!table_of_contents]]"
    # Maruku typically surrounds \tableofcontents with a
    # paragraph
    page_content = re.sub(
        r'<p>\s*\\tableofcontents\s*</p>',
        r'\\tableofcontents',
        page_content)
    processor = find_block.Processor([
        table_of_contents_block.define_maruku_single_quotation_marks(
            table_of_contents_placeholder,
            table_of_contents_flag),
        table_of_contents_block.define_maruku_double_quotation_marks(
            table_of_contents_placeholder,
            table_of_contents_flag),
        table_of_contents_block.define_tex(
            table_of_contents_placeholder,
            table_of_contents_flag)])
    page_content_with_table_of_contents_placeholder = processor.process(
        page_content)
    if not table_of_contents_flag.is_set:
        return page_content
    return table_of_contents.add_to(
        page_content_with_table_of_contents_placeholder,
        table_of_contents_placeholder)

def _page_content_file_name(page_id):
    page_name = _name_of_page(page_id)
    return "_".join(page_name.split()).replace("/", "¤")

def write_processed_content(
        page_id,
        processed_content,
        web_address,
        page_content_file_name):
    root_page_content_directory = os.environ["NLAB_PAGE_CONTENT_DIRECTORY"]
    page_content_directory = os.path.join(
        root_page_content_directory,
        web_address)
    if not os.path.exists(page_content_directory):
        try:
            os.mkdir(page_content_directory)
        except OSError as osError:
            if osError.errno != errno.EEXIST:
                raise osError
    page_content_path = os.path.join(
        page_content_directory,
        page_content_file_name)
    with open(page_content_path, "w") as page_content_file:
        page_content_file.write(processed_content)

def re_render(original_page_id, page_ids_to_re_render):
    if not page_ids_to_re_render:
        logger.info(
            "No pages need to be re-rendered as a consequence of rendering " +
            "the page with id " +
            str(original_page_id))
        return
    logger.info(
        "The following pages need to be re-rendered as a consequence of " +
        "rendering the page with id " +
        str(original_page_id) +
        ": " +
        str(page_ids_to_re_render) +
        ". Adding them to job queue")
    path_to_sequential_queue_api = (
        "/home/nlab/www/nlab-prod/script/src/sequential_queue/" +
        "sequential_queue.py")
    for page_id_to_re_render in page_ids_to_re_render:
        job = {
            "execution_commands": [
                "/home/nlab/www/nlab-prod/script/src/renderer/renderer.py",
                str(page_id_to_re_render),
                "-f",
                str(original_page_id)
            ],
            "max_time": 300
        }
        add_job_process = subprocess.Popen(
            [ path_to_sequential_queue_api, "add_job", json.dumps(job) ])
        logger.info(
            "Adding to job queue the re-rendering of page with id " +
            str(page_id_to_re_render) +
            " as a consequence of rendering the page with id: " +
            str(original_page_id) +
            ". PID of process for this is: " +
            str(add_job_process.pid))

def _indicate_success_of_re_rendering(job_id, completion_success):
    path_to_sequential_queue_api = (
        "/home/nlab/www/nlab-prod/script/src/sequential_queue/" +
        "sequential_queue.py")
    completed_process = subprocess.run(
        [
            path_to_sequential_queue_api,
            "job_status",
            job_id,
            completion_success
        ])
    if completed_process.returncode != 0:
        logger.warning(
            "Failed to update status of job with id " +
            str(job_id) +
            " to: " +
            completion_success)
    else:
        logger.info(
            "Successfully updated status of job with id " +
            str(job_id) +
            " to: " +
            completion_success)

"""
Sets up the command line argument parsing
"""
def argument_parser():
    parser = argparse.ArgumentParser(
        description = (
            "Renders the content of an nLab page"))
    parser.add_argument(
        "page_id",
        help = "Id of nLab page")
    parser.add_argument(
        "-f",
        "--from_page",
        help = (
            "If is a re-rendering of a page as a consequence of a rendering " +
            "of another page, is the ID of that other page"))
    parser.add_argument(
        "-q",
        "--queue_job_id",
        help = (
            "If is a re-rendering of a page coming from the job queue, is " +
            "the ID of the job"))
    parser.add_argument(
        "-c",
        "--page_content",
        action = "store_true",
        help = "Read content of nLab page")
    return parser

def main():
    parser = argument_parser()
    arguments = parser.parse_args()
    page_id = arguments.page_id
    read_page_content_from_stdin = arguments.page_content
    if read_page_content_from_stdin:
        page_content = sys.stdin.read()
    else:
        page_content = _content_of_page(page_id)
    from_page_id = arguments.from_page
    is_re_rendering = (from_page_id is not None)
    if is_re_rendering:
        queue_job_id = arguments.queue_job_id
    if not is_re_rendering:
        logger.info("Beginning rendering page with id: " + str(page_id))
    else:
        logger.info(
            "Beginning re-rendering page with id: " +
            str(page_id) +
            ". Page whose rendering triggered the re-rendering has id: " +
            str(from_page_id))
    # The following is necessary in case a category: block is at the end of
    # the content, without a new line.
    page_content = str(page_content) + "\n"
    web_address = _web_address_of_page(page_id)
    page_content_file_name = _page_content_file_name(page_id)
    try:
        initially_processed_content, pages_to_re_render_and_expire = \
            initial_rendering(page_id, page_content)
        maruku_processed_content = maruku_rendering(
            page_id,
            initially_processed_content)
        post_maruku_processed_content = post_maruku_rendering(
            page_id,
            maruku_processed_content,
            web_address,
            page_content_file_name)
        write_processed_content(
            page_id,
            post_maruku_processed_content,
            web_address,
            page_content_file_name)
    except RenderingException as renderingException:
        if is_re_rendering:
            _indicate_success_of_re_rendering(
                queue_job_id,
                "completed_unsuccessfully")
        sys.exit(str(renderingException))
    if not is_re_rendering:
        logger.info(
            "Successfully rendered content for page with id: " +
            str(page_id))
    else:
        logger.info(
            "Successfully re-rendered content for page with id: " +
            str(page_id) +
            ". Page whose rendering triggered the re-rendering has id: " +
            str(from_page_id))
        _indicate_success_of_re_rendering(
            queue_job_id,
            "completed_successfully")
    re_render(page_id, pages_to_re_render_and_expire)

if __name__ == "__main__":
    main()
