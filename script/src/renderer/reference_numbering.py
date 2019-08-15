#!/usr/bin/python3

"""
"Library for numbering and referencing of equations
"""

import errno
import find_block
import json
import os
import sys

class Flag:
    def __init__(self):
        self.is_set = False

    def set_to(self, truth_value):
        self.is_set = truth_value

class _EquationIndex:
    def __init__(self):
        self.index = 0
        self.reference_dictionary = dict()

    def add(self, equation_reference):
        self.index += 1
        self.reference_dictionary[equation_reference] = self.index

def _equation_reference(equation_index, id_contents, has_label):
    equation_index.add(id_contents)
    has_label.set_to(True)
    return (
        "id=\"" +
        id_contents +
        "\"")

def _equation_processor(equation_index, equation_div_contents):
    within_div_tag = equation_div_contents.split(">", 1)[0]
    has_label = Flag()
    id_block_single_quotation_marks = find_block.Block(
        "id='",
        "'",
        lambda id_contents: _equation_reference(
            equation_index,
            id_contents,
            has_label),
        False)
    id_block_double_quotation_marks = find_block.Block(
        "id=\"",
        "\"",
        lambda id_contents: _equation_reference(
            equation_index,
            id_contents,
            has_label),
        False)
    within_div_tag_processor = find_block.Processor([
        id_block_single_quotation_marks,
        id_block_double_quotation_marks])
    within_div_tag_processor.process(within_div_tag)
    if not has_label.is_set:
        return equation_div_contents
    equation_numbering_block_single_quotation_marks = find_block.Block(
        "<span class='maruku-eq-number'>",
        "</span>",
        lambda span_content: (
            "<span class='maruku-eq-number'>" +
            "(" +
            str(equation_index.index) +
            ")" +
            "</span>"),
        True)
    equation_numbering_block_double_quotation_marks = find_block.Block(
        "<span class=\"maruku-eq-number\">",
        "</span>",
        lambda span_content: (
            "<span class=\"maruku-eq-number\">" +
            "(" +
            str(equation_index.index) +
            ")" +
            "</span>"),
        True)
    entire_div_processor = find_block.Processor([
        equation_numbering_block_single_quotation_marks,
        equation_numbering_block_double_quotation_marks])
    processed_div_contents = entire_div_processor.process(
        equation_div_contents)
    return processed_div_contents

def _equation_block_single_quotation_marks(equation_index):
    return find_block.Block(
        "<div class='maruku-equation'",
        "</div>",
        lambda div_content: (
            "<div class=\"maruku-equation\"" +
            _equation_processor(equation_index, div_content) +
            "</div>"),
        True)

def _equation_block_double_quotation_marks(equation_index):
    return find_block.Block(
        "<div class=\"maruku-equation\"",
        "</div>",
        lambda div_content: (
            "<div class=\"maruku-equation\"" +
            _equation_processor(equation_index, div_content) +
            "</div>"),
        True)

def _process_equation_reference(equation_reference, equation_references):
    equation_reference = "eq:" + equation_reference
    try:
        equation_number = str(
            equation_references[equation_reference])
    except KeyError:
        equation_number = "?"
    return (
        "<a class=\"maruku-eqref\" href=\"#" +
        equation_reference +
        "\">(" +
        equation_number +
        ")</a>")

def _process_maruku_equation_reference_single_quotation_marks(
        maruku_equation_reference,
        equation_references):
    within_opening_tag = maruku_equation_reference.split(">", 1)[0]
    equation_reference = within_opening_tag.split("'", 2)[1][1:]
    try:
        equation_number = str(
            equation_references[equation_reference])
    except KeyError:
        equation_number = "?"
    return (
        "<a class=\"maruku-eqref\" href=\"#" +
        equation_reference +
        "\">(" +
        equation_number +
        ")</a>")

def _process_maruku_equation_reference_double_quotation_marks(
        maruku_equation_reference,
        equation_references):
    within_opening_tag = maruku_equation_reference.split(">", 1)[0]
    equation_reference = within_opening_tag.split("\"", 2)[1][1:]
    try:
        equation_number = str(
            equation_references[equation_reference])
    except KeyError:
        equation_number = "?"
    return (
        "<a class=\"maruku-eqref\" href=\"#" +
        equation_reference +
        "\">(" +
        equation_number +
        ")</a>")

def _equation_reference_block(equation_references):
    return find_block.Block(
        "(eq:",
        ")",
        lambda equation_reference: _process_equation_reference(
            equation_reference, equation_references),
        True)

def _maruku_equation_reference_block_single_quotation_marks(
        equation_references):
    return find_block.Block(
        "<a class='maruku-eqref'",
        "</a>",
        lambda maruku_equation_reference: \
            _process_maruku_equation_reference_single_quotation_marks(
                maruku_equation_reference,
                equation_references),
        True)

def _maruku_equation_reference_block_double_quotation_marks(
        equation_references):
    return find_block.Block(
        "<a class=\"maruku-eqref\"",
        "</a>",
        lambda maruku_equation_reference: \
            _process_maruku_equation_reference_double_quotation_marks(
                maruku_equation_reference,
                equation_references),
        True)

"""
Numbers the equations, and stores the numbering to reference mapping as a JSON
"""
def number_equations(page_content, web_address, page_content_file_name):
    equation_index = _EquationIndex()
    processor = find_block.Processor([
        _equation_block_single_quotation_marks(equation_index),
        _equation_block_double_quotation_marks(equation_index)])
    processed_content = processor.process(page_content)
    root_page_content_directory = os.environ["NLAB_PAGE_CONTENT_DIRECTORY"]
    page_content_directory = os.path.join(
        root_page_content_directory,
        web_address)
    equation_references_directory = os.path.join(
        page_content_directory,
        "equation_references")
    try:
        os.mkdir(page_content_directory)
        os.mkdir(equation_references_directory)
    except OSError as osError:
        if osError.errno != errno.EEXIST:
            raise osError
    equation_references_path = os.path.join(
        equation_references_directory,
        page_content_file_name + ".json")
    with open(equation_references_path, "w") as equation_references_file:
        equation_references_file.write(
            json.dumps(equation_index.reference_dictionary, indent = 2))
    return processed_content

"""
References the equations, given the index-to-reference JSON
"""
def reference_equations(page_content, web_address, page_content_file_name):
    root_page_content_directory = os.environ["NLAB_PAGE_CONTENT_DIRECTORY"]
    page_content_directory = os.path.join(
        root_page_content_directory,
        web_address)
    equation_references_directory = os.path.join(
        page_content_directory,
        "equation_references")
    equation_references_path = os.path.join(
        equation_references_directory,
        page_content_file_name + ".json")
    with open(equation_references_path, "r") as equation_references_file:
        equation_references = json.load(equation_references_file)
    processor = find_block.Processor([
        _equation_reference_block(equation_references),
        _maruku_equation_reference_block_single_quotation_marks(
            equation_references),
        _maruku_equation_reference_block_double_quotation_marks(
            equation_references)])
    return processor.process(page_content)
