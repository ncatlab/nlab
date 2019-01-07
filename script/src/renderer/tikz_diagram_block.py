#!/usr/bin/python3

"""
For creating SVG code from a tikz diagram
"""

import find_block
import os
import subprocess

class TikzDiagramException(Exception):
    def __init__(self, message):
        super().__init__(message)

def tikz_diagram_processor(tikz_diagram):
    tikz_diagram = (
        "\\begin{tikzpicture}" +
        tikz_diagram +
        "\\end{tikzpicture}")
    tikz_diagram_api_path = os.environ["NLAB_TIKZ_DIAGRAM_API_PATH"]
    completed_tikz_diagram_process = subprocess.run(
        [ tikz_diagram_api_path ],
        input = tikz_diagram,
        text = True,
        capture_output = True)
    if completed_tikz_diagram_process.returncode != 0:
        raise TikzDiagramException(
            completed_tikz_diagram_process.stderr)
    return completed_tikz_diagram_process.stdout

def tikz_commutative_diagram_processor(tikz_diagram):
    if tikz_diagram.strip()[0] == '[':
        tikz_diagram = (
            "\\begin{tikzcd}" +
            tikz_diagram +
            "\\end{tikzcd}")
    else:
        tikz_diagram = (
            "\\begin{tikzcd}" +
            "[row sep=huge, column sep=huge, transform shape, nodes = {scale=1.25}]" +
            tikz_diagram +
            "\\end{tikzcd}")
    tikz_diagram_api_path = os.environ["NLAB_TIKZ_DIAGRAM_API_PATH"]
    completed_tikz_diagram_process = subprocess.run(
        [ tikz_diagram_api_path, "-c" ],
        input = tikz_diagram,
        text = True,
        capture_output = True)
    if completed_tikz_diagram_process.returncode != 0:
        raise TikzDiagramException(
            completed_tikz_diagram_process.stderr)
    return completed_tikz_diagram_process.stdout

def define_tikz():
    return find_block.Block(
        "\\begin{tikzpicture}",
        "\\end{tikzpicture}",
        tikz_diagram_processor,
        True)

def define_tikz_commutative_diagram():
    return find_block.Block(
        "\\begin{tikzcd}",
        "\\end{tikzcd}",
        tikz_commutative_diagram_processor,
        True)

def handle_commutative_diagrams(content):
    processor = find_block.Processor(
        [ define_tikz(), define_tikz_commutative_diagram() ])
    return processor.process(content)

