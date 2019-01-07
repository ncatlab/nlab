#!/usr/bin/python3

"""
Library defining a block for specifying that content should not be parsed
as it otherwise should be.
"""
import find_block

def nowiki_processor(nowiki_content):
    if "[[!include" in nowiki_content:
        return "<nowiki>" + nowiki_content + "</nowiki>"
    return nowiki_content

def define():
    return find_block.Block(
        "<nowiki>",
        "</nowiki>",
        nowiki_processor,
        True)
