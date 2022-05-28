#!/usr/bin/env python3

"""
For centring of some content.
"""

import find_block

def centre_processor(blocks, content):
    return (
        "<div style=\"text-align: center\">" +
        find_block.Processor(blocks).process(content) +
        "</div>")

def define_center(blocks):
    return find_block.Block(
        "\\begin{center}",
        "\\end{center}",
        lambda content: centre_processor(blocks, content),
        True)

def define_centre(blocks):
    return find_block.Block(
        "\\begin{centre}",
        "\\end{centre}",
        lambda content: centre_processor(blocks, content),
        True)
