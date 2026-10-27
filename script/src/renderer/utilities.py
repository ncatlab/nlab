"""
Utilities.
Adapted from util.print_parse in <https://github.com/ChalmersGU-data-structure-courses/lab-system>.

Requires Python ≥3.9.
"""

import dataclasses
import functools
import re
from collections.abc import Iterable
from typing import Annotated, ClassVar, Container, Protocol


class PrinterParser(Protocol):
    """
    A protocol for printer-parsers.
    These approximate isomorphisms.
    Some input domain is encoded (printed) to some output domain.
    Reversely, the output domain is decoded (parsed) to the input domain.
    Here, the input and output domains may be documented subsets of I and O, respectively.

    Ideally, this satisfies the following invariants:
    * `parse(print(x)) = x` for `x` in the input domain,
    * `print(parse(y)) = y` for `y` in the output domain.

    The first of these invariants is the more important one.
    The second is sometimes not be satisfied.
    There may then be several ways of representing an element of the input domain in the output domain.
    For example, this happens with case-insensitive parsing.

    In applications, the output type is often bigger than the output domain.
    For example, the output type is often str.
    In such cases, parse is a partial function that may raise an exception.
    We currently do not have a designated exception type for that.
    """

    def print(self, _x, /):
        """
        Print (encode) from the input domain to the output domain.
        """

    def parse(self, _y, /):
        """
        Parse (decode) from the output domain to the input domain.
        """


class Composition(PrinterParser):
    """
    The composition an iterable of printer parsers.
    Composes the printers in forward order and the parsers in reverse order.
    """

    def __init__(self, *pps: PrinterParser):
        self.pps = pps

    def print(self, x, /):
        for pp in self.pps:
            x = pp.print(x)
        return x

    def parse(self, y, /):
        for pp in reversed(self.pps):
            y = pp.parse(y)
        return y


@dataclasses.dataclass(frozen=True)
class CharEscape(PrinterParser):
    """
    Printer-parser for escaping characters in a string.
    Replaces specified characters (including the escape character) by the escape character followed by the specified replacement.

    Generalizes and improves Escape.
    The smart constructor `standard` provides a stand-in replacement.
    """

    escape: str
    replacements: dict[str, str]

    @property
    def escape_pairs(self) -> Iterable[tuple[str, str]]:
        yield (self.escape, self.escape)
        yield from self.replacements.items()

    @functools.cached_property
    def print_trans(self) -> dict[str, str]:
        table = {
            original: self.escape + escaped for original, escaped in self.escape_pairs
        }
        return str.maketrans(table)

    @functools.cached_property
    def parse_trans(self):
        return {escaped: original for original, escaped in self.escape_pairs}

    @functools.cached_property
    def parse_pattern(self) -> re.Pattern:
        return re.compile(re.escape(self.escape) + "(.)")

    def parse_replace(self, m: re.Match) -> str:
        return self.parse_trans[m.group(1)]

    def print(self, x: str, /) -> str:
        return x.translate(self.print_trans)

    def parse(self, y: str, /) -> str:
        return self.parse_pattern.sub(self.parse_replace, y)


@dataclasses.dataclass(frozen=True)
class PathSegmentSpecials(PrinterParser):
    """Escape path segments with special meaning (see SPECIALS)."""

    SPECIALS: ClassVar[Container[str]] = frozenset(["", ".", ".."])

    escape: str

    def print(self, x: str, /) -> str:
        if x in self.SPECIALS:
            return self.escape + x
        return x

    def parse(self, y: str, /) -> str:
        if y.startswith(self.escape):
            a = y.removeprefix(self.escape)
            if a in self.SPECIALS:
                return a
        return y


string_as_path_segment: Annotated[
    PrinterParser,
    """Escapes a general string as a non-special path segment.""",
] = Composition(
    CharEscape(escape="%", replacements={"/": "0"}),
    PathSegmentSpecials(escape="%"),
)
