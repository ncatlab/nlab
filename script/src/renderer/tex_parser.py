#!/usr/bin/python3

import find_block
import subprocess

class InvalidTexException(Exception):
    def __init__(self, message):
        super().__init__(message)

_calligraphic_letters = {
    "A": "&#x1D49C;",
    "B": "&#x212C;",
    "C": "&#x1D49E;",
    "D": "&#x1D49F;",
    "E": "&#x2130;",
    "F": "&#x2131;",
    "G": "&#x1D4A2;",
    "H": "&#x0210B;",
    "I": "&#x02110;",
    "J": "&#x1D4A5;",
    "K": "&#x1D4A6;",
    "L": "&#x02112;",
    "M": "&#x02133;",
    "N": "&#x1D4A9;",
    "O": "&#x1D4AA;",
    "P": "&#x1D4AB;",
    "Q": "&#x1D4AC;",
    "R": "&#x0211B;",
    "S": "&#x1D4AE;",
    "T": "&#x1D4AF;",
    "U": "&#x1D4B0;",
    "V": "&#x1D4B1;",
    "W": "&#x1D4B2;",
    "X": "&#x1D4B3;",
    "Y": "&#x1D4B4;",
    "Z": "&#x1D4B5;",
}

_greek_letters = {
    "alpha": "&alpha;",
    "Alpha": "&Alpha;",
    "beta": "&beta;",
    "Beta": "&Beta;",
    "gamma": "&gamma;",
    "Gamma": "&Gamma;",
    "delta": "&delta;",
    "Delta": "&Delta;",
    "epsilon": "&epsilon;",
    "Epsilon": "&Epsilon;",
    "zeta": "&zeta;",
    "Zeta": "&Zeta;",
    "eta": "&eta;",
    "Eta": "&Eta;",
    "theta": "&theta;",
    "Theta": "&Theta;",
    "iota": "&iota;",
    "Iota": "&iota;",
    "kappa": "&kappa;",
    "Kappa": "&Kappa;",
    "lambda": "&lambda;",
    "Lambda": "&Lambda;",
    "mu": "&mu;",
    "Mu": "&Mu;",
    "nu": "&nu;",
    "Nu": "&Nu;",
    "xi": "&xi;",
    "Xi": "&Xi;",
    "omicron": "&omicron;",
    "Omicron": "&Omicron;",
    "pi": "&pi;",
    "Pi": "&Pi;",
    "rho": "&rho;",
    "Rho": "&Rho;",
    "sigma": "&sigma;",
    "Sigma": "&Sigma;",
    "tau": "&tau;",
    "Tau": "&Tau;",
    "upsilon": "&upsilon;",
    "Upsilon": "&Upsilon;",
    "phi": "&phi;",
    "Phi": "&Phi;",
    "chi": "&chi;",
    "Chi": "&Chi;",
    "psi": "&psi;",
    "Psi": "&Psi;",
    "omega": "&omega;",
    "Omega": "&Omega;"
}

_hebrew_letters = {
    "aleph": "&#x2135;"
}

_miscellaneous_mathematical_symbols = {
    "cdots": "&#x22ef;",
    "leftarrow": "&#x2190;",
    "rightarrow": "&#x2192;",
    "times": "&times;"
}

_mathematical_symbols = _greek_letters.copy()
_mathematical_symbols.update(_hebrew_letters)
_mathematical_symbols.update(_miscellaneous_mathematical_symbols)

def _process_calligraphic(tex_string):
    calligraphic_characters = []
    for character in tex_string:
        try:
            calligraphic_letter = _calligraphic_letters[character]
        except KeyError:
            raise InvalidTexException(
                "The following string within a \mathcal{} block contains " +
                "a character which cannot be converted to a calligraphic " +
                "character. Only upper case Roman letters can be used.")
        calligraphic_characters.append(calligraphic_letter)
    return "".join(calligraphic_characters)

def _mathcal_block():
    return find_block.Block(
        "\\mathcal{",
        "}",
        _process_calligraphic,
        True)

def _html_for_symbol(mathematical_symbol_characters):
    try:
        return _mathematical_symbols[
            "".join(mathematical_symbol_characters)]
    except KeyError:
        raise InvalidTexException(
            "No mapping available for Tex symbol: " +
            "".join(mathematical_symbol_characters))

def _process_symbols(tex_string):
    processed_tex_string = []
    found_beginning_of_symbol = False
    mathematical_symbol = []
    for character in tex_string:
        if character == '\\':
            if not found_beginning_of_symbol:
                found_beginning_of_symbol = True
            else:
                html_for_symbol = _html_for_symbol(mathematical_symbol)
                processed_tex_string.extend(html_for_symbol)
                mathematical_symbol = []
        elif found_beginning_of_symbol and character == ' ':
            html_for_symbol = _html_for_symbol(mathematical_symbol)
            processed_tex_string.extend(html_for_symbol)
            processed_tex_string.append(' ')
            mathematical_symbol = []
            found_beginning_of_symbol = False
        elif found_beginning_of_symbol and character == '{':
            processed_tex_string.append('\\')
            processed_tex_string.extend(mathematical_symbol)
            processed_tex_string.append(' ')
            mathematical_symbol = []
            found_beginning_of_symbol = False
        elif found_beginning_of_symbol:
            mathematical_symbol.append(character)
        else:
            processed_tex_string.append(character)
    if found_beginning_of_symbol:
        return _html_for_symbol(mathematical_symbol)
    return "".join(processed_tex_string)

def _validate(tex_string):
    if not tex_string:
        raise InvalidTexException(
            "A LaTeX block has not been closed or opened properly somewhere")
    path_to_itex_to_mml = "/home/nlab/www/nlab-prod/script/itex2MML"
    validation_subprocess = subprocess.run(
        [ path_to_itex_to_mml ],
        input = bytes("$" + tex_string + "$", "utf-8"),
        stdout = subprocess.PIPE)
    itex_to_mml_output = validation_subprocess.stdout.decode("utf-8")
    if "<merror>" in itex_to_mml_output:
        raise InvalidTexException(
            "Invalid LaTeX block: " +
            tex_string)

def parse_to_html(tex_string):
    tex_processor = find_block.Processor([
        _mathcal_block()
    ])
    processed_tex = tex_processor.process(tex_string)
    processed_tex = _process_symbols(processed_tex)
    return (
        "<span class='mathematics'>" +
        processed_tex +
        "</span>")

def parse(page_id, tex_string, is_inline):
    if int(page_id) not in [ 75, 1015 ]:
        _validate(tex_string)
        if is_inline:
            return "$" + tex_string + "$"
        else:
            return "$$" + tex_string + "$$"
    return parse_to_html(tex_string)
