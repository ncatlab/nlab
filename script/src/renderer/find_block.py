#!/usr/bin/env python3.7

"""
Library for parsing a string for 'blocks', and processing the contents.

The processing of the contents may either return a string if the processor is
a 'parser', or may simply execute some action.

The code allows for multiple blocks.

The algorithm implemented in the processor is intended to be quite efficient.
The string is to be parsed is passed through only once (up to some small shifts
backwards is the beginning of a block is partially matched without being
completely matched).
"""

class MoreThanOneMatchException(Exception):
    pass

class Block:
    def __init__(
            self,
            beginning,
            end,
            processor,
            is_parser,
            overrides = []):
        self.beginning = beginning
        self.end = end
        self.processor = processor
        self.is_parser = is_parser
        self.overrides = overrides

class Processor:
    def __init__(self, blocks):
        self.blocks = blocks
        self.number_of_matching_blocks = 0
        self.character_index = 0
        self.beginning_block_character = None
        self.end_of_block_character_index = 0
        self.matched_block = None
        self.block_end_remaining = None
        self.parsed_string = []

    def process(self, string_to_parse):
        matching_blocks = None
        to_process = []
        matched_block_end = []
        while True:
            try:
                if self.end_of_block_character_index == 0:
                    character = string_to_parse[self.character_index]
                else:
                    character = string_to_parse[
                        self.end_of_block_character_index]
            except IndexError:
                break
            if self.matched_block is not None and (
                    self.number_of_matching_blocks == 1):
                if self.matched_block.end is None:
                    if self.matched_block.is_parser:
                        self.parsed_string.append(self.matched_block.processor(
                            to_process))
                    else:
                        self.matched_block.processor("".join(to_process))
                    self.number_of_matching_blocks = 0
                    self.character_index = self.end_of_block_character_index
                    self.beginning_block_character = None
                    self.end_of_block_character_index = 0
                    self.matched_block = None
                    matching_blocks = None
                    self.block_end_remaining = None
                    to_process = []
                    matched_block_end = []
                    continue
                if character != self.block_end_remaining[0]:
                    if not matched_block_end:
                        to_process.append(character)
                    else:
                        matched_block_end.append(character)
                        to_process.append("".join(matched_block_end))
                        matched_block_end = []
                    self.block_end_remaining = self.matched_block.end
                    self.end_of_block_character_index += 1
                    continue
                self.block_end_remaining = self.block_end_remaining[1:]
                if not self.block_end_remaining:
                    if self.matched_block.is_parser:
                        processed = self.matched_block.processor(
                            "".join(to_process))
                        if processed is None:
                            processed = ""
                        self.parsed_string.append(processed)
                    else:
                        self.matched_block.processor("".join(to_process))
                    self.number_of_matching_blocks = 0
                    self.character_index = self.end_of_block_character_index + 1
                    self.beginning_block_character = None
                    self.end_of_block_character_index = 0
                    self.matched_block = None
                    matching_blocks = None
                    self.block_end_remaining = None
                    to_process = []
                    matched_block_end = []
                else:
                    matched_block_end.append(character)
                    self.end_of_block_character_index += 1
            elif self.number_of_matching_blocks == 0:
                matching_blocks = self._matching_blocks(
                    character,
                    self.blocks)
            else:
                matching_blocks = self._matching_blocks(
                    character,
                    matching_blocks)
        if self.matched_block is not None:
            self.parsed_string.append(string_to_parse[
                self.character_index:])
        parsed_string = "".join(self.parsed_string)
        self._tidy_up()
        return parsed_string

    def _matching_blocks(self, character, blocks):
        self.number_of_matching_blocks = 0
        found_matching_block = False
        matched_block = None
        matching_blocks = []
        for block in blocks:
            if not block.beginning:
                continue
            if character == block.beginning[0]:
                if self.beginning_block_character is None:
                    self.beginning_block_character = character
                self.number_of_matching_blocks += 1
                found_matching_block = True
                remainder_of_block_beginning = block.beginning[1:]
                if not remainder_of_block_beginning:
                    if matched_block is not None:
                        if matched_block.beginning in block.overrides:
                            matched_block = block
                        else:
                            raise MoreThanOneMatchException()
                    else:
                        matched_block = block
                else:
                    if self.matched_block is not None:
                        self.matched_block = None
                        self.block_end_remaining = None
                matching_blocks.append(Block(
                    remainder_of_block_beginning,
                    block.end,
                    block.processor,
                    block.is_parser))
        if matched_block is not None:
            self.matched_block = matched_block
            self.block_end_remaining = matched_block.end
        if found_matching_block:
            if self.end_of_block_character_index == 0:
                self.end_of_block_character_index = self.character_index + 1
            else:
                self.end_of_block_character_index += 1
            return matching_blocks
        else:
            if self.matched_block is not None:
                self.number_of_matching_blocks = 1
                return
            self.number_of_matching_blocks = 0
            if self.beginning_block_character is not None:
                self.parsed_string.append(self.beginning_block_character)
            else:
                self.parsed_string.append(character)
            self.character_index += 1
            self.beginning_block_character = None
            self.end_of_block_character_index = 0

    def _tidy_up(self):
        self.number_of_matching_blocks = 0
        self.character_index = 0
        self.beginning_block_character = None
        self.end_of_block_character_index = 0
        self.matched_block = None
        self.block_end_remaining = None
        self.parsed_string = []
