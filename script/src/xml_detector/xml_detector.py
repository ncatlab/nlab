#!/usr/bin/env python3

"""
Checks for presence of XML tags outside of a whitelist. Expects input on stdin.

Depends on the environment variables:
* XML_WHITELIST_PATH (script/src/xml_detector/xml_whitelist)
"""

import argparse
import os
import re
import sys

def obtain_whitelist():
    whitelist_path = os.environ["XML_WHITELIST_PATH"]
    with open(whitelist_path, "r") as whitelist_file:
        for whitelist_tag_content in whitelist_file:
            yield "<" + whitelist_tag_content.strip() + ">"

def check_for_xml_tag(whitelist, content):
    remaining_content = content
    while remaining_content:
        match = re.search("<.*?>", remaining_content)
        if match is None:
            return
        tag_content = match.group(0)
        if tag_content not in whitelist:
            # Needed by xypic
            try:
                float(tag_content[1:-1])
            except ValueError:
                sys.exit(
                    "The following tag is not permitted: " +
                    tag_content)
        remaining_content = remaining_content[match.end():]

"""
Sets up the command line argument parsing
"""
def argument_parser():
    parser = argparse.ArgumentParser(
        description = (
            "Checks for presence of XML tags outside of a whitelist. Expects " +
            "input on stdin"))
    return parser

def main():
    parser = argument_parser()
    arguments = parser.parse_args()
    content = sys.stdin.read().strip()
    whitelist = list(obtain_whitelist())
    check_for_xml_tag(whitelist, content)

if __name__ == "__main__":
    main()
