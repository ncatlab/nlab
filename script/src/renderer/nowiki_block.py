#!/usr/bin/env python3.7

"""
Library defining a block for specifying that content should not be parsed
as it otherwise should be.
"""
import find_block

def nowiki_processor(nowiki_content, retain_nowiki_block):
    if retain_nowiki_block or ("[[!include" in nowiki_content):
        return "<nowiki>" + nowiki_content + "</nowiki>"
    return nowiki_content

def define(retain_nowiki_block = False):
    return find_block.Block(
        "<nowiki>",
        "</nowiki>",
        lambda content: nowiki_processor(content, retain_nowiki_block),
        True)
