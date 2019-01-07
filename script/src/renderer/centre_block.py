#!/usr/bin/python3

"""
For centring of some content.
"""

import find_block

def centre_processor(content):
    return (
        '<div style="text-align: center">' +
        content +
        "</div>")

def define_center():
    return find_block.Block(
        "\\begin{center}",
        "\\end{center}",
        centre_processor,
        True)

def define_centre():
    return find_block.Block(
        "\\begin{centre}",
        "\\end{centre}",
        centre_processor,
        True)

def handle_centring(content):
    return find_block.Processor([define_center(), define_centre()]).process(
        content)
