#!/usr/bin/python3

"""
For creating SVG code from a tikz diagram
"""

import find_block
import os
import subprocess
import nowiki_block

class XyPicDiagramException(Exception):
    def __init__(self, message):
        super().__init__(message)

def remove_new_lines_at_start_of_block(diagram):
    split_at_opening_brace = diagram.split("}", 1)
    if len(split_at_opening_brace) == 0:
        raise XyPicDiagramException(
            "Missing end brace } after \\begin{xymatrix")
    return split_at_opening_brace[0] + "{" + split_at_opening_brace[1].strip()

def xypic_diagram_processor(xypic_diagram):
    xypic_diagram = (
        "\\xymatrix@" +
        remove_new_lines_at_start_of_block(xypic_diagram) +
        "}")
    diagram_api_path = os.environ["NLAB_DIAGRAM_API_PATH"]
    completed_xypic_diagram_process = subprocess.run(
        [ diagram_api_path, "xypic" ],
        input = xypic_diagram,
        text = True,
        capture_output = True)
    if completed_xypic_diagram_process.returncode != 0:
        raise XyPicDiagramException(
            completed_xypic_diagram_process.stderr)
    return completed_xypic_diagram_process.stdout

def define_xymatrix_default_size():
    return find_block.Block(
        "\\begin{xymatrix}",
        "\\end{xymatrix}",
        lambda diagram: xypic_diagram_processor(
            "=5em}" + diagram),
        True)

def define_xymatrix_document_parameters():
    return find_block.Block(
        "\\begin{xymatrix[",
        "\end{xymatrix}",
        lambda diagram: xypic_diagram_processor(
            "=5em[" + diagram),
        True)

def define_xymatrix():
    return find_block.Block(
        "\\begin{xymatrix@",
        "\\end{xymatrix}",
        xypic_diagram_processor,
        True)

def handle_xypic_diagrams(content):
    processor = find_block.Processor([
        define_xymatrix(),
        define_xymatrix_default_size(),
        define_xymatrix_document_parameters(),
        nowiki_block.define(True) ])
    return processor.process(content)

