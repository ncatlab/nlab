#!/usr/bin/python3

"""
For creating SVG code from a tikz diagram
"""

import find_block
import os
import subprocess
import nowiki_block

class TikzDiagramException(Exception):
    def __init__(self, message):
        super().__init__(message)

def tikz_diagram_processor(tikz_diagram):
    tikz_diagram = (
        "\\begin{tikzpicture}" +
        tikz_diagram +
        "\\end{tikzpicture}")
    diagram_api_path = os.environ["NLAB_DIAGRAM_API_PATH"]
    completed_tikz_diagram_process = subprocess.run(
        [ diagram_api_path, "tikz" ],
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
    diagram_api_path = os.environ["NLAB_DIAGRAM_API_PATH"]
    completed_tikz_diagram_process = subprocess.run(
        [ diagram_api_path, "tikz", "-c" ],
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

def handle_tikz_diagrams(content):
    processor = find_block.Processor([
        define_tikz(),
        define_tikz_commutative_diagram(),
        nowiki_block.define(True) ])
    return processor.process(content)

