#!/usr/bin/env python3.7

"""
Library defining a block for adding an extra blank line around a table, so that
is correctly parsed by Maruku.
"""

import find_block

def html_table_processor(table):
    return (
        "\n" +
        "<table" +
        table +
        "/table>\n")

def define():
    return find_block.Block(
        "<table",
        "/table>",
        lambda table: html_table_processor(table),
        True)
