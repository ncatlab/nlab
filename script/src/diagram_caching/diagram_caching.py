#!/usr/bin/env python3.7
r"""
Generates SVG from a diagram source.
Uses the external programs pdflatex and pdf2svg, which need to be on PATH.

Input: the diagram as parsed by script/src/renderer/renderer.py
Output: SVG code for the diagram, with ids prefixed by a hash of the diagram.

Important:
Do not set TEXMFOUTPUT in any loaded texmf configuration file when running this program.
This compromises security.

Depends on the following environment variables:
* NLAB_LOG_DIRECTORY: log directory.
* NLAB_DIAGRAM_CACHE_DIRECTORY:
  If this is set, use this directory as a SVG compilation cache.
  Diagrams are identified by their base64-encoded (URL-safe) SHA-1 hash.
  Will be created if not existing.
* NLAB_PDF_LATEX:
  Command line for invoking pdflatex.
  This will be called with working directory the directory of the LaTeX file to process.
  This script may append several options to the call (see run_pdflatex):
  - -halt-on-error
  - -no-shell-escape
  - -cnf-line openin_any=p
  - -cnf-line openout_any=p
  Defaults to pdflatex.
* NLAB_DIAGRAM_TIMEOUT:
  Timeout in seconds to use for calls to helper programs (pdflatex and pdf2svg).
  Defaults to 5.
* NLAB_DIAGRAM_LATEX_RESTRICT_OPEN:
  Defaults to 1.
  If set to 0, disables passing 'openin_any=a' and 'openout_any=a' to pdflatex.
  These arguments might not be supported for older versions.
  If set to 0, you must make sure that pdflatex is called with openin_any and openout_any configured with value 'p' (paranoid).

Security considerations:
* Generally speaking, it is dangerous to run user-provided LaTeX code.
  We attempt to protect against this using the below.
* We disallow executing system commands via \write18.
  This is achieved by passing -no-shell-escape to pdflatex.
  This overrides any such setting in texmf configuration files.
* We create a temporary directory for the diagram rendering.
  We contain the user-provided LaTeX code to only read and write files under this directory hierarchy
  This is achieved by passing the configuration options 'openin_any=a' and 'openout_any=a' to pdflatex.
  If TEXMFOUTPUT set in any loaded texmf configuration file, this compromises this setting.
  It allows reading and writing also under the directory hierarchy of TEXMFOUTPUT.
* We do not use a string-searching-based blacklist of LaTeX commands.
  Such hackery attempted protection is easily circumvented.

TODO:
* We don't really need to report the source of the diagram in error messages here.
  That could (should?) be done in the renderer.
"""

import base64
import hashlib
import logging
import os
from pathlib import Path
import re
import shlex
import string
import subprocess
import sys
import tempfile
import time
import lxml.etree


# Logging.

logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)
logging.Formatter.converter = time.gmtime
logging_formatter = logging.Formatter(
    "%(asctime)s %(levelname)s %(name)s %(message)s")
log_directory = os.environ["NLAB_LOG_DIRECTORY"]
logging_file_handler = logging.FileHandler(
    os.path.join(log_directory, "diagrams.log"))
logging_file_handler.setFormatter(logging_formatter)
logger.addHandler(logging_file_handler)


# General purpose functions.

def replace(pattern, callback, string, perform_replacement = True, flags = 0):
    '''
    Perform all replacements of the given regular expression pattern in a given string.
    The replacement expressions are computed using the passed callback function.

    Arguments:
    * pattern: the pattern to match,
    * callback: function taking an re.Match object and returning a replacement string for this match,
    * string: the string for which to perform replacements,
    * perform_replacement: if set to False, do not return the string replacement (but still call the callback function).
    '''
    def replace_iter():
        last = 0
        for match in re.finditer(pattern, string, flags = flags):
            (start, end) = match.span()
            yield string[last : start]
            yield callback(match)
            last = end
        yield string[last :]

    fragments = list(replace_iter())
    return str().join(fragments) if perform_replacement else None


# Main function

class DiagramParsingException(Exception):
    pass

def main():
    diagram = sys.stdin.read()
    logger.debug('Diagram:\n' + diagram)

    hash = hashlib.sha1(diagram.encode('utf-8')).digest()
    hash_encoded = base64.urlsafe_b64encode(hash).decode('utf-8')
    logger.info(f'Diagram hash {hash_encoded}')

    cache = os.environ.get('NLAB_DIAGRAM_CACHE_DIRECTORY')
    if cache:
        cache = Path(cache)
        cached_as = cache / hash_encoded
        try:
            rendering = cached_as.read_bytes()
            logger.info(f'Diagram rendering found in cache.')
            sys.stdout.buffer.write(rendering)
            return
        except FileNotFoundError:
            pass

    logger.info(f'Producing LaTeX for diagram...')
    latex = diagram_to_latex(diagram)

    logger.info(f'Compiling LaTeX to SVG...')
    timeout = int(os.environ.get('NLAB_DIAGRAM_TIMEOUT', '5'))
    restrict_open = bool(int(os.environ.get('NLAB_DIAGRAM_LATEX_RESTRICT_OPEN', '1')))
    svg = latex_to_svg(latex, timeout, restrict_open, diagram)

    logger.info(f'Translating identifiers in SVG...')
    xml_prefix_ids(svg, hash_encoded + '-')

    if cache:
        logger.info('Writing diagram rendering to cache...')
        cache.mkdir(exist_ok = True)
        svg.write(cached_as)
    svg.write(sys.stdout.buffer)


# Converting a diagram source to a Latex source.

class UnknownDiagramTypeException(DiagramParsingException):
    pass

def diagram_to_latex(diagram):
    for f in [
        diagram_to_latex_tikzcd,
        diagram_to_latex_tikz,
        diagram_to_latex_xypic,
    ]:
        try:
            return f(diagram)
        except UnknownDiagramTypeException:
            pass

    raise DiagramParsingException('\n'.join([
        'Could not guess the type of the following diagram:',
        diagram,
    ]))

def diagram_to_latex_tikzcd(diagram):
    match = re.fullmatch(r'\\begin\{tikzcd\}(.*)\\end\{tikzcd\}', diagram, flags = re.DOTALL)
    if not match:
        raise UnknownDiagramTypeException()

    template = r'''\documentclass[class=scrartcl]{standalone}
\KOMAoptions{fontsize=12pt}
\usepackage{tikz}
\usepackage{amsmath,amssymb,amsthm,mathtools}
\usetikzlibrary{cd}
\begin{document}
\begin{tikzcd}$diagram_body\end{tikzcd}
\end{document}'''

    return string.Template(template).substitute(
        diagram_body = match.group(1),
    )

def diagram_to_latex_tikz(diagram):
    match = re.fullmatch(r'\\begin\{tikzpicture\}(.*)\\end\{tikzpicture\}', diagram, flags = re.DOTALL)
    if not match:
        raise UnknownDiagramTypeException()

    libraries = list()
    def parse_libraries(match):
        for s in match.group(1).split(','):
            s = s.strip()
            if s:
                libraries.append(s)
        return str()

    diagram_body = replace(
        r'\\usetikzlibrary\{([\w\s,]*)\}',
        parse_libraries,
        match.group(1),
        flags = re.DOTALL,
    )

    template = r'''\documentclass[class=scrartcl]{standalone}
\KOMAoptions{fontsize=12pt}
\usepackage{tikz}
\usepackage{amsmath,amssymb,amsthm,mathtools}
\usetikzlibrary{$libraries}
\begin{document}
\begin{tikzpicture}$diagram_body\end{tikzpicture}
\end{document}'''

    return string.Template(template).substitute(
        libraries = ','.join(libraries),
        diagram_body = diagram_body,
    )

def diagram_to_latex_xypic(diagram):
    # In the markup, we would use the following match:
    #   match = re.fullmatch(r'\begin{xymatrix([^{}]*)}(.*)\end{xymatrix}', diagram)
    # However, the current renderer translates this into the following before calling this script.
    match = re.fullmatch(r'\\xymatrix([^{}]*)\s*\{(.*)\}', diagram, flags = re.DOTALL)
    if not match:
        raise UnknownDiagramTypeException()

    params = dict()
    def parse_params(match):
        for param in match.group(1).split(','):
            try:
                (key, value) = param.split('=', 1)
            except ValueError:
                raise DiagramParsingException('invalid xymatrix parameter: ' + param)
            key = key.strip()
            value = value.strip()
            if key not in ['font', 'border']:
                raise DiagramParsingException('unknown xymatrix parameter key: ' + key)
            if not re.fullmatch(r'[\w\\]+', value, flags = re.ASCII | re.DOTALL):
                raise DiagramParsingException('invalid xymatrix parameter value: ' + value)
            params[key] = value
        return str()

    diagram_params = replace(
        r'\[([^\[\]]+)\]',
        parse_params,
        match.group(1),
        flags = re.DOTALL,
    )

    def document_params():
        yield '12pt'
        border = params.get('border')
        if border:
            yield 'border=' + border

    template = r'''\documentclass[$document_params]{standalone}
\usepackage{amsmath,amssymb,amsthm,mathtools,xcolor}
\usepackage[all,color,2cell]{xy}
\UseTwocells
\begin{document}
$font_size
\xymatrix$diagram_params{$diagram_body}
\end{document}'''

    return string.Template(template).substitute(
        document_params = ','.join(document_params()),
        font_size = params.get('font', ''),
        diagram_params = diagram_params,
        diagram_body = match.group(2),
    )


# Converting a LaTeX source to SVG.

def latex_to_svg(latex, timeout = 5, restrict_open = True, diagram = None):
    '''
    Converts a given LaTeX source into an ET.Element object.
    Uses the programs pdflatex and pdf2svg, which need to be on the executable path.

    Arguments:
    * latex: the LaTeX source to convert.
    * timeout: the timeout to use for each of the calls to the helpers programs.
    * restrict_open:
        Whether to pass configuration options for openin_any and openout_any to pdflatex via '--cnf-line'.
        This may not be supported for older versions.
    * diagram: If set, report in error messages this as the diagram source instead of the LaTeX source.

    Important:
    If restrict_open is not set, make sure that pdflatex is called with openin_any and openout_any configured with value 'p' (paranoid).
    See the documentation of this script.
    '''
    description = 'LaTeX source' if diagram is None else 'diagram'
    source = latex if diagram is None else diagram

    with tempfile.TemporaryDirectory() as dir:
        dir = Path(dir)
        (dir / 'diagram.tex').write_text(latex)

        try:
            run_pdflatex(dir, 'diagram', timeout, restrict_open)
        except PDFRenderingException as e:
            raise DiagramParsingException('\n'.join([
                f'An error occurred when running pdflatex on the following {description}:',
                source,
                'The error was:',
                str(e),
            ])) from None

        try:
            run_pdf2svg(dir, 'diagram.pdf', 'diagram.svg', timeout)
        except SVGExtractionException as e:
            raise DiagramParsingException('\n'.join([
                f'An error occurred when running pdf2svg on the following {description}:',
                source,
                'The error was:',
                str(e),
            ]))

        return lxml.etree.parse(dir / 'diagram.svg')

class PDFRenderingException(Exception):
    pass

def run_pdflatex(dir, filename, timeout, restrict_open):
    # It is dangerous to run if TEXMFOUTPUT is set.
    # The LaTeX code may then read and write arbitary files within the hierarchy of the directory specified by TEXMFOUTPUT.
    # For example, if it is set to '/tmp', it exposes other programs that run simultaneously.
    if 'TEXMFOUTPUT' in os.environ:
        raise PDFRenderingException('TEXMFOUTPUT set, refusing to run')

    def args():
        yield from shlex.split(os.environ.get('NLAB_PDFLATEX', 'pdflatex'))
        yield '-halt-on-error'
        # Christian: I checked that these take precedence over the texmf.cfg configuration file:
        yield '-no-shell-escape'
        if restrict_open:
            yield from ['-cnf-line', 'openin_any=p']
            yield from ['-cnf-line', 'openout_any=p']
        yield filename

    try:
        process = subprocess.run(
            list(args()),
            cwd = dir,
            capture_output = True,
            timeout = timeout,
        )
    except subprocess.TimeoutExpired:
        raise PDFRenderingException("timed out")
    if process.returncode:
        match = re.search(
            r'\n\!\s*(.*)\n\!',
            process.stdout.decode(),
            flags = re.DOTALL,
        )
        if match:
            raise PDFRenderingException(match.group(1))
        else:
            raise PDFRenderingException("unable to extract error")

class SVGExtractionException(Exception):
    pass

def run_pdf2svg(dir, filename_in, filename_out, timeout):
    try:
        process = subprocess.run(
            ['pdf2svg', filename_in, filename_out],
            cwd = dir,
            capture_output = True,
            timeout = timeout,
        )
    except subprocess.TimeoutExpired:
        raise SVGExtractionException("timed out")
    if process.returncode:
        raise SVGExtractionException(process.stderr.decode())


# Making sure identifiers in an SVG instance have their own namespace.

def xml_prefix_ids(xml, prefix):
    '''
    Prefix all ids in an ET.ElementTree object.
    This includes all id attributes and references to such ids within other attributes.
    The latter detection is only works for attribute values of the form "#id" and "url(#id)".
    '''
    url_pattern = re.compile(r'url\(#([^()]*)\)')

    def f(x):
        for (key, value) in list(x.attrib.items()):
            if value.startswith('#'):
                x.attrib[key] = '#' + prefix + value[1 :]
            else:
                match = url_pattern.fullmatch(value)
                if match:
                    x.attrib[key] = 'url(#{})'.format(prefix + match.group(1))

        id = x.attrib.get('id')
        if id is not None:
            x.attrib['id'] = prefix + id
        for y in x:
            f(y)

    f(xml.getroot())


# The entry point.

if __name__ == '__main__':
    try:
        logger.info(f'Diagram renderer started.')
        main()
        logger.info(f'Diagram renderer finished.')
    except Exception as e:
        logger.error(e)
        sys.exit(e)
