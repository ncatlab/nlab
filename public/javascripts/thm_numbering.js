/* counters for theorem environments */

var envs = ["theorem", "lemma", "prop", "cor", "defn", "example", "note", "remark"];
var theorem_label_selector = envs.map(function(s) {return ".num_" + s + " .theorem_label"}).join(",");

function generateThmNumbers() {
  // add numbering to the table of contents
  $$(".maruku_toc > ul li a").each(function(x, index) {
    x.insert({top: (index+1) + ". "});
  });

  // find the context menu and mark all h2 elements;
  // we want to skip them below in the numbering
  $$(".toc.clickDown h2").each(function(x) {
    x.addClassName("context_menu")
  });

  // now add the theorem numbering
  var section_counter = 0;
  var theorem_counter = 0;
  // find both section titles and theorem labels, and iterate
  $$(theorem_label_selector + ",#Content h2:not(.context_menu)").each(function(tag, index) {
    if (tag.tagName == "h2") { // this is a section title
      section_counter += 1;
      theorem_counter = 0;
      tag.insert({top: section_counter + ". "});
    } else { // this is a theorem label
      theorem_counter += 1;
      var theorem_number = section_counter + "." + theorem_counter;
      tag.writeAttribute("theoremNumber", theorem_number);
      tag.insert(" " + theorem_number);
    }
  });

  // look at all references, replace them by the new theorem number
  $$("a.maruku-ref").each(function(x) {
    var thm_id = x.getAttribute("href").substr(1);
    var thm_parent = document.getElementById(thm_id);
    if (thm_parent == null) {
      console.log("Problem with reference for: " + x.toString())
      return x.text
    }
    var thm_label = thm_parent.select(".theorem_label").first();
    if (thm_label == null) {
      console.log("Problem with reference for: " + x.toString())
      return x.text
    }
    var thm_number = thm_label.getAttribute("theoremNumber");
    x.update(thm_number);
  });
}
