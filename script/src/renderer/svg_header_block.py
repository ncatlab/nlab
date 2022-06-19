#!/usr/bin/env python3.7

"""
Maruku removes a crucial header from inline SVG files. We add it back.
"""

import find_block

def header_processor(header):
    xlmns_attribute = 'xmlns="http://www.w3.org/2000/svg"'
    xlmns_attribute_variant = "xmlns='http://www.w3.org/2000/svg'"
    if (xlmns_attribute in header) or (xlmns_attribute_variant in header):
        return (
            "<svg" +
            header +
            ">")
    return (
        "<svg" +
        header +
        ' ' +
        xlmns_attribute +
        ">")

def define():
    return find_block.Block(
        "<svg",
        ">",
        lambda header: header_processor(header),
        True)
