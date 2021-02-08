import mistletoe
import os
import re
import subprocess
import urllib.parse

class RendererException(Exception):
    def __init__(self, message):
        super().__init__(message)

def _render_latex(latex):
    latex_renderer_subprocess = subprocess.run(
        os.environ["RUN_COMMAND_FOR_LATEX_COMPILER"].split(),
        capture_output = True,
        text = True,
        check = True,
        input = latex)
    rendered_latex = latex_renderer_subprocess.stdout
    if "<merror>" in rendered_latex:
        raise LatexTokenRendererException(
            "LaTeX syntax error in following: " +
            latex)
    return rendered_latex

"""
Matches anything within $ and $, not beginning with $$, or within \( and \),
and processes it with a LaTeX compiler
"""
class _InlineLatexToken(mistletoe.span_token.SpanToken):
    pattern = re.compile(r"((?<!\$)\$(?!\$)(.+?)\$)|(\\\((.*?)\\\))")

    def __init__(self, match):
        self.latex = match.group(0)
        if self.latex.startswith("\("):
            self.latex = "$" + self.latex[2:-2] + "$"

    def render(self):
        return _render_latex(self.latex)

"""
Matches anything of the form [[ x | y]] which does not contain any further |,
and converts it to a link to an nLab page x with displayed text y
"""
class _NlabPageLinkWithDisplayTextToken(mistletoe.span_token.SpanToken):
    pattern = re.compile(r"(?!\[\[([^\|]+?)\]\])\[\[([^\|]+?)\|([^\|]+?)\]\]")

    def __init__(self, match):
        self.nlab_page_name = match.group(2).strip()
        self.display_text = match.group(3).strip()

    def render(self):
        return (
            "<a class=\"existingWikiWord\" " +
            "href=\"/nlab/show/" +
            urllib.parse.quote_plus(self.nlab_page_name) +
            "\">" +
            self.display_text +
            "</a>")

class _nLabRenderer(mistletoe.html_renderer.HTMLRenderer):
    def __init__(self):
        token_classes = _nLabRenderer.token_classes_to_use()
        super().__init__(*token_classes)

    def render_inline_latex_token(self, token):
        try:
            return token.render()
        except RendererException:
            return (
                "<span style=\"background-color: red\">" +
                token.latex +
                "</span>")

    def render_nlab_page_link_with_display_text_token(self, token):
        return token.render()

    @staticmethod
    def token_classes_to_use():
        token_classes = []
        token_classes.append(_InlineLatexToken)
        token_classes.append(_NlabPageLinkWithDisplayTextToken)

        return token_classes

def render(markdown):
    with _nLabRenderer() as renderer:
        html = renderer.render(mistletoe.Document(markdown))
    return html
