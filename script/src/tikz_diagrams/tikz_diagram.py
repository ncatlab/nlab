#!/usr/bin/python3.7

import argparse
import errno
import find_block
import glob
import logging
import os
import random
import subprocess
import string
import sys
import time

"""
Initialises logging. Logs to

tikz_diagrams.log
"""
logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)
logging.Formatter.converter = time.gmtime
logging_formatter = logging.Formatter(
    "%(asctime)s %(levelname)s %(name)s %(message)s")
log_directory = os.environ["NLAB_LOG_DIRECTORY"]
logging_file_handler = logging.FileHandler(
    os.path.join(log_directory, "tikz_diagrams.log"))
logging_file_handler.setFormatter(logging_formatter)
logger.addHandler(logging_file_handler)

class PdfRenderingException(Exception):
    def __init__(self, message):
        super().__init__(message)

class SvgRenderingException(Exception):
    def __init__(self, message):
        super().__init__(message)

def create_diagram_source_directory_if_needed():
    diagram_source_directory = os.environ["NLAB_TIKZ_DIAGRAM_SOURCE_DIRECTORY"]
    try:
        os.mkdir(diagram_source_directory)
    except OSError as osError:
        if osError.errno != errno.EEXIST:
            raise osError
    return diagram_source_directory

def extract_tikz_libraries(tikz_diagram):
    libraries = []
    tikz_library_block = find_block.Block(
        "\\usetikzlibrary{",
        "}",
        lambda library: libraries.append(
            "\\usetikzlibrary{" + library + "}"),
        False)
    tikz_library_processor = find_block.Processor([tikz_library_block])
    without_tikz_libraries = tikz_library_processor.process(tikz_diagram)
    library_lines = "\n".join(libraries)
    return library_lines, without_tikz_libraries

def extract_error(output):
    error_description_begun = False
    error_description = []
    for output_line in output.split("\n"):
        if output_line.strip().startswith("!"):
            error_description.append(output_line)
            error_description_begun = True
        elif output_line.strip().startswith("l.") and error_description_begun:
            try:
                identifier = output_line.strip().split(" ", 1)[1]
            except IndexError:
                break
            if identifier:
                error_description.append("Line: " + identifier)
            break
    return "\n".join(error_description)

def create_pdf(
        diagram_source_directory,
        diagram_id,
        tikz_diagram,
        is_commutative_diagram):
    tikz_diagram_template_path = os.environ["NLAB_TIKZ_DIAGRAM_TEMPLATE"]
    with open(tikz_diagram_template_path, "r") as tikz_diagram_template_file:
        tikz_diagram_template = tikz_diagram_template_file.read()
    if not is_commutative_diagram:
        libraries, tikz_diagram_without_tikz_libraries = extract_tikz_libraries(
            tikz_diagram)
        tex_source = string.Template(tikz_diagram_template).substitute(
            tikz_libraries = libraries,
            tikz_diagram = tikz_diagram_without_tikz_libraries)
    else:
        tex_source = string.Template(tikz_diagram_template).substitute(
            tikz_libraries = "\\usetikzlibrary{cd}",
            tikz_diagram = tikz_diagram)
    tex_path = os.path.join(diagram_source_directory, diagram_id + ".tex")
    with open(tex_path, "w") as tex_source_file:
        tex_source_file.write(tex_source)
    completed_pdf_process = subprocess.run(
         [ "pdflatex", tex_path ],
         cwd = diagram_source_directory,
         capture_output = True)
    if completed_pdf_process.returncode != 0:
        raise PdfRenderingException(
            extract_error(completed_pdf_process.stdout.decode()))

def create_svg(diagram_source_directory, diagram_id):
    pdf_path = os.path.join(diagram_source_directory, diagram_id + ".pdf")
    svg_path = os.path.join(diagram_source_directory, diagram_id + ".svg")
    completed_svg_process = subprocess.run(
        [ "pdf2svg", pdf_path, svg_path ],
        cwd = diagram_source_directory)
    if completed_svg_process.returncode != 0:
        raise SvgRenderingException(completed_svg_process.stderr)
    with open(svg_path, "r") as svg_file:
        svg_diagram_lines = svg_file.read().splitlines()
    return "\n".join(svg_diagram_lines[1:])

def remove_diagram_files(diagram_source_directory, diagram_id):
    diagram_id_path = os.path.join(diagram_source_directory, diagram_id + "*")
    for diagram_file in glob.glob(diagram_id_path):
        os.remove(diagram_file)

"""
Sets up the command line argument parsing
"""
def argument_parser():
    parser = argparse.ArgumentParser(
        description = (
            "Creates SVG source from tikz diagram code passed into stdin"))
    parser.add_argument(
        "-c",
        "--commutative_diagram",
        action = "store_true",
        help = "If is a commutative diagram to be rendered using tikzcd")
    return parser

def main():
    parser = argument_parser()
    arguments = parser.parse_args()
    is_commutative_diagram = arguments.commutative_diagram
    tikz_diagram = sys.stdin.read().strip()
    diagram_source_directory = create_diagram_source_directory_if_needed()
    diagram_id = str(random.randint(10**8, (10**9) - 1))
    try:
       create_pdf(
           diagram_source_directory,
           diagram_id,
           tikz_diagram,
           is_commutative_diagram)
       svg_diagram = create_svg(diagram_source_directory, diagram_id)
    except PdfRenderingException as pdfRenderingException:
        message = (
            "An error occurred when running pdflatex on the following " +
            "diagram. \n" +
            tikz_diagram +
            "\nThe error was: " +
            str(pdfRenderingException))
        logger.warning(message)
        sys.exit(message)
    except SvgRenderingException as svgRenderingException:
        message = (
            "An error occurred when creating an SVG from a PDF for the " +
            "following diagram. \n" +
            tikz_diagram)
        logger.warning(
            message +
            "\nThe error was: " +
            str(svgRenderingException))
        sys.exit(message)
    except Exception as exception:
        message = (
            "An unexpected error occurred when creating an SVG from a PDF " +
            "for the following diagram. \n" +
            tikz_diagram)
        logger.warning(
            message +
            "\nThe error was: " +
            str(exception))
        sys.exit(message)
    finally:
        remove_diagram_files(diagram_source_directory, diagram_id)
    logger.info(
        "Successfully created an SVG for the following diagram. \n" +
        tikz_diagram)
    print(svg_diagram)

if __name__ == "__main__":
    main()
