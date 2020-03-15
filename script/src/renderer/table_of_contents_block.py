#!/usr/bin/python3

"""
Library defining a block for inserting a table of contents
"""

import find_block

def table_of_contents_processor(placeholder, table_of_contents_flag):
    table_of_contents_flag.set_to(True)
    return placeholder

def define(placeholder, table_of_contents_flag):
    return find_block.Block(
        "* table of contents",
        "toc}",
        lambda table_of_contents_definition: table_of_contents_processor(
            placeholder, table_of_contents_flag),
        True)

def define_tex(placeholder, table_of_contents_flag):
    return find_block.Block(
        "\\tableofcontents",
        None,
        lambda table_of_contents_definition: (
            "\n<h1 id='section_table_of_contents'>Contents</h1>\n" +
            table_of_contents_processor(placeholder, table_of_contents_flag)),
        True)

def define_maruku_single_quotation_marks(placeholder, table_of_contents_flag):
    return find_block.Block(
        "<div class='maruku_toc'>",
        "</div>",
        lambda table_of_contents_definition: table_of_contents_processor(
            placeholder, table_of_contents_flag),
        True)

def define_maruku_double_quotation_marks(placeholder, table_of_contents_flag):
    return find_block.Block(
        "<div class=\"maruku_toc\">",
        "</div>",
        lambda table_of_contents_definition: table_of_contents_processor(
            placeholder, table_of_contents_flag),
        True)

_tex_section_levels = {
    "section": 2,
    "subsection": 3,
    "subsubsection": 4,
    "subsubsubsection": 5,
    "subsubsubsubsection": 6
}

def _section_html(tex_section_name, tex_section_title):
    return (
        "<h" +
        str(_tex_section_levels[tex_section_name]) +
        " id='" +
        "section_" + "_".join(tex_section_title.split()) +
        "'>" +
        tex_section_title +
        "</h" +
        str(_tex_section_levels[tex_section_name]) +
        ">")

def define_section(tex_section_name):
    return find_block.Block(
        "\\" + tex_section_name + "{",
        "}",
        lambda tex_section_title: _section_html(
            tex_section_name,
            tex_section_title),
        True)

def define_all_sections():
    for tex_section_name in _tex_section_levels.keys():
        yield define_section(tex_section_name)
