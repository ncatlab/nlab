#!/usr/bin/python3

"""
Library defining a block for converting \ref{Something}, where Something is
the id of some div of type num_, to a link to the div.
"""

import find_block

def reference_processor(reference):
    return (
        "<a class='maruku-ref' href='#" +
        reference +
        "'>" +
        "</a>")

def define():
    return find_block.Block(
        "\\ref{",
        "}",
        reference_processor,
        True)
