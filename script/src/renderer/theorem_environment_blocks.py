#!/usr/bin/python3

import find_block

_theorem_environments = {
    "defn": ("Definition", "num_defn"),
    "definition": ("Definition", "num_defn"),
    "thm": ("Theorem", "num_theorem"),
    "theorem": ("Theorem", "num_theorem"),
    "prop": ("Proposition", "num_prop"),
    "prpn": ("Proposition", "num_prop"),
    "proposition": ("Proposition", "num_prop"),
    "rmk": ("Remark", "num_remark"),
    "remark": ("Remark", "num_remark"),
    "cor": ("Corollary", "num_cor"),
    "corollary": ("Corollary", "num_cor"),
    "lem": ("Lemma", "num_lemma"),
    "lemma": ("Lemma", "num_lemma"),
    "notn": ("Notation", "num_defn"),
    "notation": ("Notation", "num_defn"),
    "terminology": ("Terminology", "num_defn"),
    "scholium": ("Scholium", "num_remark"),
    "conjecture": ("Conjecture", "num_prop"),
    "conj": ("Conjecture", "num_prop"),
    "example": ("Example", "num_remark"),
    "exercise": ("Exercise", "num_remark"),
    "statement": ("Statement", "num_theorem"),
    "assumption": ("Assumption", "num_theorem"),
    "assum": ("Assumption", "num_theorem"),
    "proof": ("Proof", "proof")
}

class LabelException(Exception):
    def __init__(self, message):
        super().__init__(message)

class Label:
    def __init__(self):
        self.label = None

    def set_to(self, label):
        if self.label is not None:
            raise LabelException(
                "Label has already been set to: " +
                self.label)
        self.label = label

    def get(self):
        return self.label

def _label(block_contents):
   label = Label()
   label_block = find_block.Block(
       "\\label{",
       "}",
       lambda label_block_contents: label.set_to(label_block_contents),
       True)
   label_processor = find_block.Processor([label_block])
   block_contents_without_label = label_processor.process(block_contents)
   if block_contents_without_label:
       block_contents_without_label = block_contents_without_label.strip()
   return label.get(), block_contents_without_label

def processor(
       displayed_environment_name,
       html_class_identifier,
       block_contents):
   label, block_contents_without_label = _label(block_contents)
   if label:
       div_block_beginning = (
           "<div class='" +
           html_class_identifier +
           "' id='" +
           label +
           "'>")
   else:
       div_block_beginning = (
           "<div class='" +
           html_class_identifier +
           "'>")
   return (
       "\n" + div_block_beginning + "\n" +
       "<h6>" + displayed_environment_name + "</h6>\n" +
       "<p>" +
       block_contents_without_label +
       "</p>\n" +
       "</div>\n")

def preliminary_processor(block_contents, identifier):
    block_contents_with_stripped_new_lines_at_end = block_contents.rstrip("\n")
    return (
        "\\begin{" +
        identifier +
        "}" +
        block_contents_with_stripped_new_lines_at_end +
        "\n\n" +
        "\\end{" +
        identifier +
        "}")

def define(identifier, displayed_environment_name, html_class_identifier):
    return find_block.Block(
        "\\begin{" + identifier + "}",
        "\\end{" + identifier + "}",
        lambda block_contents: processor(
            displayed_environment_name,
            html_class_identifier,
            block_contents),
        True)

def define_preliminary(identifier):
    return find_block.Block(
        "\\begin{" + identifier + "}",
        "\\end{" + identifier + "}",
        lambda block_contents: preliminary_processor(
            block_contents,
            identifier),
        True)

def define_all():
    for identifier, environment_data in _theorem_environments.items():
        displayed_environment_name = environment_data[0]
        html_class_identifier = environment_data[1]
        yield define(
            identifier,
            displayed_environment_name,
            html_class_identifier)

def define_all_preliminary():
    for identifier, environment_data in _theorem_environments.items():
        yield define_preliminary(identifier)
