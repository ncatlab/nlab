#!/usr/bin/python3

import find_block

def define_linebreak():
    return find_block.Block(
        "\\linebreak",
        None,
        lambda linebreak_content: "<br/>",
        True)
