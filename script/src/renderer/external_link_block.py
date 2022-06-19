#!/usr/bin/env python3.7

"""
Library for parsing external links
"""

import find_block

class ExternalLinkException(Exception):
    pass

def external_link_block_processor(link):
    split_link = link.split("](", 1)
    if len(split_link) == 0:
        return link
    link_text = split_link[0]
    link_url = split_link[1]
    if not (
            "#" in link_url or \
            link_url.startswith("https") or \
            link_url.startswith("http")):
        raise ExternalLinkException
    return (
        "<a href=\"" +
        link_url +
        "\">" +
        link_text +
        "</a>")

def define():
    return find_block.Block(
        "[",
        ")",
        external_link_block_processor,
        True)

