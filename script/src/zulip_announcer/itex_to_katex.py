"""Rewrites of itex2MML-specific syntax into KaTeX-compatible TeX (prototype).

Covers only the constructs that occur often in the nForum corpus; see
katex_check.py for measuring what is left.
"""

import html
import re

SIMPLE = {
    r"\sslash": r"\mathbin{/\mkern-6mu/}",
    r"\widebar": r"\overline",
    r"\infinity": r"\infty",
    r"\bottom": r"\bot",
    r"\union": r"\cup",
    r"\intersection": r"\cap",
    r"\nwarr": r"\nwarrow",
    r"\nearr": r"\nearrow",
    r"\searr": r"\searrow",
    r"\swarr": r"\swarrow",
    r"\slash": r"/",
    r"\parr": r"\mathbin{\text{⅋}}",
    r"\invamp": r"\mathbin{\text{⅋}}",
    r"\esh": r"\text{ʃ}",
    r"\id": r"\mathrm{id}",
    r"\colim": r"\operatorname*{colim}",
    r"\Hom": r"\operatorname{Hom}",
    r"\op": r"\mathrm{op}",
    r"\dom": r"\operatorname{dom}",
    r"\cod": r"\operatorname{cod}",
    r"\im": r"\operatorname{im}",
}
SIMPLE_RE = re.compile(r"(\\[A-Za-z]+)(?![A-Za-z])")


def _group(s, i):
    """Return (content, end) of the brace group starting at s[i] == '{'."""
    depth = 0
    for j in range(i, len(s)):
        ch = s[j]
        if ch == "\\":
            continue
        if ch == "{" and (j == 0 or s[j - 1] != "\\"):
            depth += 1
        elif ch == "}" and s[j - 1] != "\\":
            depth -= 1
            if depth == 0:
                return s[i + 1 : j], j + 1
    raise ValueError("unbalanced")


def _skip_ws(s, i):
    while i < len(s) and s[i].isspace():
        i += 1
    return i


def _rewrite_command(s, name, nargs, build):
    out = []
    i = 0
    pat = re.compile(re.escape(name) + r"(?![A-Za-z])")
    while True:
        m = pat.search(s, i)
        if not m:
            out.append(s[i:])
            return "".join(out)
        out.append(s[i : m.start()])
        j = m.end()
        args = []
        try:
            for _ in range(nargs):
                j = _skip_ws(s, j)
                if j >= len(s) or s[j] != "{":
                    raise ValueError
                a, j = _group(s, j)
                args.append(a)
        except ValueError:
            out.append(s[m.start() : m.end()])
            i = m.end()
            continue
        out.append(build(*args))
        i = j


def _array(body):
    body = re.sub(r"\\arrayopts\s*\{(?:[^{}]|\{[^{}]*\})*\}", "", body)
    return r"\begin{matrix}" + body + r"\end{matrix}"


def itex_to_katex(tex):
    tex = html.unescape(tex)
    # itex treats a bare '#' as an ordinary symbol
    tex = re.sub(r"(?<!\\)#", r"\\#", tex)
    # innermost-first: repeat until stable, since these nest
    for _ in range(5):
        new = _rewrite_command(tex, r"\array", 1, _array)
        new = _rewrite_command(
            new, r"\underoverset", 3, lambda u, o, b: r"\underset{%s}{\overset{%s}{%s}}" % (u, o, b)
        )
        if new == tex:
            break
        tex = new
    return SIMPLE_RE.sub(lambda m: SIMPLE.get(m.group(1), m.group(1)), tex)
