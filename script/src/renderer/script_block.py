#!/usr/bin/python3

"""
Library for preventing javascript blocks from being executed
"""

import find_block

class ScriptNotPermittedException(Exception):
    pass

def script_block_processor(script):
    raise ScriptNotPermittedException()

def define_script_tags():
    return find_block.Block(
        "<script",
        "/script>",
        script_block_processor,
        False)

def define_javascript_prefix():
    return find_block.Block(
        "javascript:",
        None,
        script_block_processor,
        False)
