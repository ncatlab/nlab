#!/usr/bin/env python3

"""
Library defining a block for tex content
"""

import find_block
import tex_parser

def define_double(page_id):
    return find_block.Block(
        "$$",
        "$$",
        lambda tex_block: tex_parser.parse(page_id, tex_block, False),
        True)

def define_single(page_id):
    return find_block.Block(
        "$",
        "$",
        lambda tex_block: tex_parser.parse(page_id, tex_block, True),
        True)

def tex_post_parser(tex_string):
    tex_string = tex_string.replace(">llbracket</mo>", ">&#x27E6;</mo>")
    tex_string = tex_string.replace(">rrbracket</mo>", ">&#x27E7;</mo>")
    tex_string = tex_string.replace(">esh</mo>", ">&#x283;</mo>")
    return "<math" + tex_string + "/math>"

def define_tex_post():
    return find_block.Block(
        "<math",
        "/math>",
        tex_post_parser,
        True)
