#!/usr/bin/python3.7

"""
Library defining a block for converting \bibitem{something}, where something is
the citation key of some entry in the 'bibliography' table of the nLab
database into a reference. If no such entry can be found, returns 'something?'
as a link to creating the reference.
"""

import urllib.parse

import find_block
import reference_renderer

def _bibitem_processor(web_address, citation_key):
    try:
        return "* {#" + citation_key + "} " + reference_renderer.render(
            citation_key)
    except reference_renderer.ReferenceNotFoundException:
        return (
            "<span class='newWikiWord'>" +
            citation_key +
            "<a href=\"/" +
            web_address +
            "/new/" +
            urllib.parse.quote_plus(citation_key) +
            "?is_reference=1" +
            "\">" +
            "?" +
            "</a>" +
            "</span>")

def define(web_address):
    return find_block.Block(
        "\\bibitem{",
        "}",
        lambda citation_key: _bibitem_processor(web_address, citation_key),
        True)
