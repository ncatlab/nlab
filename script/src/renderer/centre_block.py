#!/usr/bin/python3

"""
For centring of some content.
"""

import find_block
import nowiki_block

def initial_centre_processor(content):
    return (
        "\nfor_centring\n" +
        content.strip() +
        "/for_centring\n")

def post_centre_processor(content):
    return (
        '<div style="text-align: center">' +
        content +
        "</div>")

def define_center():
    return find_block.Block(
        "\\begin{center}",
        "\\end{center}",
        initial_centre_processor,
        True)

def define_centre():
    return find_block.Block(
        "\\begin{centre}",
        "\\end{centre}",
        initial_centre_processor,
        True)

def handle_initial_centring(content):
    processor = find_block.Processor([
        define_center(),
        define_centre(),
        nowiki_block.define(True)])
    return processor.process(content)

def handle_post_centring(content):
    centre_paragraph_block = find_block.Block(
        "<p>for_centring",
        "/for_centring</p>",
        post_centre_processor,
        True)
    return find_block.Processor([centre_paragraph_block]).process(content)
