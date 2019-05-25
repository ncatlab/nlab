#!/usr/bin/python3.7

import enum
import find_block
import json
import os
import urllib.parse

class SizeUnit(enum.Enum):
    PIXELS = "px"
    EM = "em"

class Float(enum.Enum):
    LEFT = "left"
    RIGHT = "right"

class ImageFromFileException(Exception):
    def __init__(self, message):
        super().__init__(message)

class _ImageFileDoesNotExistException(Exception):
    pass

class _HasCharacterWhichIsNotPermittedException(Exception):
    def __init__(self, message):
        super().__init__(message)

class _InvalidMarginJsonException(Exception):
    def __init__(self, message):
        super().__init__(message)

def _check_exists(web_address, file_name):
   web_files_root_directory = os.environ["WEB_FILES_ROOT"]
   file_path = os.path.join(
       web_files_root_directory,
       web_address,
       "files",
       file_name)
   if not os.path.exists(file_path):
       raise _ImageFileDoesNotExistException()

def _check_has_only_permitted_characters(value, key):
    if not value:
        return
    permitted_characters = [
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', \
        'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', \
        '3', '4', '5', '6', '7', '8', '9', '0', '-', ' ', ',' ]
    for character in value:
        if character.lower() not in permitted_characters:
            raise _HasCharacterWhichIsNotPermittedException(
                "The '" +
                key +
                "' value in the following imagefromfile block " +
                "contains the character " +
                character +
                ", which is not permitted. Only a-z, 0-9, spaces, -, and , " +
                "may be used.")

def serialise_margin(margin_json):
    if not isinstance(margin_json, dict):
        raise _InvalidMarginJsonException(
            "In the following imagefromfile block, the value of " +
            "'margin' should be a JSON with keys 'top', 'right', 'bottom', " +
            "'left', and optionally 'unit', but it is not.")
    keys = margin_json.keys()
    if "unit" in keys:
        permitted_keys = [ "bottom", "left", "right", "top", "unit" ]
    else:
        permitted_keys = [ "bottom", "left", "right", "top" ]
    if sorted(margin_json.keys()) != permitted_keys:
       raise _InvalidMarginJsonException(
            "In the following imagefromfile block, the value of " +
            "'margin' should be a JSON with keys 'top', 'right', 'bottom', " +
            "'left', and optionally 'unit', but it is does not have exactly " +
            "these keys.")
    try:
        top = int(margin_json["top"])
    except ValueError:
        raise _InvalidMarginJsonException(
            "In the following imagefromfile block, the value of " +
            "'top' in the 'margin' block should be an integer.")
    try:
        right = int(margin_json["right"])
    except ValueError:
        raise _InvalidMarginJsonException(
            "In the following imagefromfile block, the value of " +
            "'right' in the 'margin' block should be an integer.")
    try:
        bottom = int(margin_json["bottom"])
    except ValueError:
        raise _InvalidMarginJsonException(
            "In the following imagefromfile block, the value of " +
            "'bottom' in the 'margin' block should be an integer.")
    try:
        left = int(margin_json["left"])
    except ValueError:
        raise _InvalidMarginJsonException(
            "In the following imagefromfile block, the value of " +
            "'left' in the 'margin' block should be an integer.")
    try:
        unit = SizeUnit(margin_json["unit"])
    except KeyError:
        unit = SizeUnit.PIXELS
    except ValueError:
        raise ImageFromFileException(
            "In the following imagefromfile block, the value of " +
            "'unit' in the 'margin' block must be one of the following: " +
            ", ".join([ unit.value for unit in SizeUnit ]) +
            ".")
    return (
        str(top) +
        unit.value +
        " " +
        str(right) +
        unit.value +
        " " +
        str(bottom) +
        unit.value +
        " " +
        str(left) +
        unit.value)

def image_from_file_processor(description):
    description = description.strip()
    try:
        description_json = json.loads("{" + description + "}")
    except json.JSONDecodeError as jsonDecodeError:
        print(jsonDecodeError)
        raise ImageFromFileException(
            "An \\image from file{...} block must be in JSON format, except " +
            "that curly brackets should not be used at the beginning and " +
            "end. This is not the case for: " +
            description)
    try:
        file_name = description_json["file_name"]
    except KeyError:
        raise ImageFromFileException(
            "The following imagefromfile block does not include the " +
            "key 'file_name'")
    try:
        web_address = description_json["web"]
    except KeyError:
        web_address = "nlab"
    try:
        _check_exists(web_address, file_name)
    except _ImageFileDoesNotExistException:
        raise ImageFromFileException(
            "There is no file with 'web' and 'file_name' as given in the " +
            "following imagefromfile block: " +
            description)
    try:
        width = int(description_json["width"])
    except KeyError:
        width = None
    except ValueError:
        raise ImageFromFileException(
            "The value of 'width' must be an integer in the following " +
            "imagefromfile block: " +
             description)
    try:
        height = int(description_json["height"])
    except KeyError:
        height = None
    except ValueError:
        raise ImageFromFileException(
            "The value of 'height' must be an integer in the following " +
            "imagefromfile block: " +
             description)
    if (width is not None) or (height is not None):
        try:
            unit = SizeUnit(description_json["unit"])
        except KeyError:
            unit = SizeUnit.PIXELS
        except ValueError:
            raise ImageFromFileException(
                "In the following imagefromfile block, the value of " +
                "'unit' must be one of the following: " +
                ", ".join([ unit.value for unit in SizeUnit ]) +
                ". Block: " +
                description)
    try:
        alt = description_json["alt"]
    except KeyError:
        alt = None
    try:
        _check_has_only_permitted_characters(alt, "alt")
    except _HasCharacterWhichIsNotPermittedException as \
            alt_has_character_which_is_not_permitted_exception:
        raise ImageFromFileException(
            str(alt_has_character_which_is_not_permitted_exception) +
            ". Block: " +
           description)
    try:
        float_type = Float(description_json["float"])
    except KeyError:
        float_type = None
    except ValueError:
        raise ImageFromFileException(
            "In the following imagefromfile block, the value of " +
            "'float' must be one of the following: " +
            ", ".join([ float_type.value for float_type in Float ]) +
            ". Block: " +
            description)
    try:
        margin = serialise_margin(description_json["margin"])
    except KeyError:
        margin = None
    except _InvalidMarginJsonException as invalid_margin_json_exception:
        raise ImageFromFileException(
            str(invalid_margin_json_exception) +
            " Block: " +
            description)
    try:
        caption = description_json["caption"]
    except KeyError:
        caption = None
    try:
        _check_has_only_permitted_characters(caption, "caption")
    except _HasCharacterWhichIsNotPermittedException as \
            caption_has_character_which_is_not_permitted_exception:
        raise ImageFromFileException(
            str(caption_has_character_which_is_not_permitted_exception) +
            ". Block: " +
           description)
    image_html = (
        "<img src=\"/" +
        web_address +
        "/files/" +
        urllib.parse.quote_plus(file_name) +
        "\"")
    if width:
       image_html = (
           image_html +
           " width=\"" +
           str(width) +
           unit.value +
           "\"")
    if height:
       image_html = (
           image_html +
           " height=\"" +
           str(height) +
           unit.value +
           "\"")
    if alt:
       image_html = (
           image_html +
           " alt=\"" +
           str(alt) +
           "\"")
    style = None
    if float_type:
       style = (
           "float: " +
           float_type.value)
    if margin:
        if style:
            style = (
                style +
                "; margin: " +
                margin)
        else:
            style = (
                "margin: " +
                margin)
    image_html = image_html + "/>"
    if caption:
        image_html = (
            "<figure style=\"margin: 0 0 0 0\">\n" +
            image_html +
            "\n<figcaption style=\"text-align: center\">" +
            caption +
            "</figcaption>\n" +
            "</figure>")
    if style:
        image_html = (
            "<div style='" +
            style +
            "'>\n  " +
            image_html +
            "\n</div>")
    return image_html

def define():
    return find_block.Block(
        "\\begin{imagefromfile}",
        "\\end{imagefromfile}",
        image_from_file_processor,
        True)
