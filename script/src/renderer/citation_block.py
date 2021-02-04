#!/usr/bin/python3.7

"""
Library defining a block for converting \cite{something}, where something is
the label of some anchor point (intended to be one created by parsing
\bibitem{something}, i.e. a citation key in the nLab bibliography)
"""

import find_block

def _citation_processor(citation_key):
    return (
        "<a class='maruku-ref' href='#" +
        citation_key +
        "'>" +
        citation_key +
        "</a>")

def define():
    return find_block.Block(
        "\\cite{",
        "}",
        _citation_processor,
        True)
