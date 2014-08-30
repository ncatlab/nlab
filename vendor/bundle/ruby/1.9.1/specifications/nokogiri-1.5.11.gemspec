# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{nokogiri}
  s.version = "1.5.11"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = [%q{Aaron Patterson}, %q{Mike Dalessio}, %q{Yoko Harada}, %q{Tim Elliott}]
  s.date = %q{2013-12-14}
  s.description = %q{Nokogiri (鋸) is an HTML, XML, SAX, and Reader parser.  Among Nokogiri's
many features is the ability to search documents via XPath or CSS3 selectors.

XML is like violence - if it doesn’t solve your problems, you are not using
enough of it.}
  s.email = [%q{aaronp@rubyforge.org}, %q{mike.dalessio@gmail.com}, %q{yokolet@gmail.com}, %q{tle@holymonkey.com}]
  s.executables = [%q{nokogiri}]
  s.extensions = [%q{ext/nokogiri/extconf.rb}]
  s.extra_rdoc_files = [%q{CHANGELOG.ja.rdoc}, %q{CHANGELOG.rdoc}, %q{C_CODING_STYLE.rdoc}, %q{Manifest.txt}, %q{README.ja.rdoc}, %q{README.rdoc}, %q{ROADMAP.md}, %q{STANDARD_RESPONSES.md}, %q{Y_U_NO_GEMSPEC.md}, %q{ext/nokogiri/html_document.c}, %q{ext/nokogiri/html_element_description.c}, %q{ext/nokogiri/html_entity_lookup.c}, %q{ext/nokogiri/html_sax_parser_context.c}, %q{ext/nokogiri/html_sax_push_parser.c}, %q{ext/nokogiri/nokogiri.c}, %q{ext/nokogiri/xml_attr.c}, %q{ext/nokogiri/xml_attribute_decl.c}, %q{ext/nokogiri/xml_cdata.c}, %q{ext/nokogiri/xml_comment.c}, %q{ext/nokogiri/xml_document.c}, %q{ext/nokogiri/xml_document_fragment.c}, %q{ext/nokogiri/xml_dtd.c}, %q{ext/nokogiri/xml_element_content.c}, %q{ext/nokogiri/xml_element_decl.c}, %q{ext/nokogiri/xml_encoding_handler.c}, %q{ext/nokogiri/xml_entity_decl.c}, %q{ext/nokogiri/xml_entity_reference.c}, %q{ext/nokogiri/xml_io.c}, %q{ext/nokogiri/xml_libxml2_hacks.c}, %q{ext/nokogiri/xml_namespace.c}, %q{ext/nokogiri/xml_node.c}, %q{ext/nokogiri/xml_node_set.c}, %q{ext/nokogiri/xml_processing_instruction.c}, %q{ext/nokogiri/xml_reader.c}, %q{ext/nokogiri/xml_relax_ng.c}, %q{ext/nokogiri/xml_sax_parser.c}, %q{ext/nokogiri/xml_sax_parser_context.c}, %q{ext/nokogiri/xml_sax_push_parser.c}, %q{ext/nokogiri/xml_schema.c}, %q{ext/nokogiri/xml_syntax_error.c}, %q{ext/nokogiri/xml_text.c}, %q{ext/nokogiri/xml_xpath_context.c}, %q{ext/nokogiri/xslt_stylesheet.c}]
  s.files = [%q{bin/nokogiri}, %q{CHANGELOG.ja.rdoc}, %q{CHANGELOG.rdoc}, %q{C_CODING_STYLE.rdoc}, %q{Manifest.txt}, %q{README.ja.rdoc}, %q{README.rdoc}, %q{ROADMAP.md}, %q{STANDARD_RESPONSES.md}, %q{Y_U_NO_GEMSPEC.md}, %q{ext/nokogiri/html_document.c}, %q{ext/nokogiri/html_element_description.c}, %q{ext/nokogiri/html_entity_lookup.c}, %q{ext/nokogiri/html_sax_parser_context.c}, %q{ext/nokogiri/html_sax_push_parser.c}, %q{ext/nokogiri/nokogiri.c}, %q{ext/nokogiri/xml_attr.c}, %q{ext/nokogiri/xml_attribute_decl.c}, %q{ext/nokogiri/xml_cdata.c}, %q{ext/nokogiri/xml_comment.c}, %q{ext/nokogiri/xml_document.c}, %q{ext/nokogiri/xml_document_fragment.c}, %q{ext/nokogiri/xml_dtd.c}, %q{ext/nokogiri/xml_element_content.c}, %q{ext/nokogiri/xml_element_decl.c}, %q{ext/nokogiri/xml_encoding_handler.c}, %q{ext/nokogiri/xml_entity_decl.c}, %q{ext/nokogiri/xml_entity_reference.c}, %q{ext/nokogiri/xml_io.c}, %q{ext/nokogiri/xml_libxml2_hacks.c}, %q{ext/nokogiri/xml_namespace.c}, %q{ext/nokogiri/xml_node.c}, %q{ext/nokogiri/xml_node_set.c}, %q{ext/nokogiri/xml_processing_instruction.c}, %q{ext/nokogiri/xml_reader.c}, %q{ext/nokogiri/xml_relax_ng.c}, %q{ext/nokogiri/xml_sax_parser.c}, %q{ext/nokogiri/xml_sax_parser_context.c}, %q{ext/nokogiri/xml_sax_push_parser.c}, %q{ext/nokogiri/xml_schema.c}, %q{ext/nokogiri/xml_syntax_error.c}, %q{ext/nokogiri/xml_text.c}, %q{ext/nokogiri/xml_xpath_context.c}, %q{ext/nokogiri/xslt_stylesheet.c}, %q{ext/nokogiri/extconf.rb}]
  s.homepage = %q{http://nokogiri.org}
  s.licenses = [%q{MIT}]
  s.rdoc_options = [%q{--main}, %q{README.rdoc}]
  s.require_paths = [%q{lib}]
  s.required_ruby_version = Gem::Requirement.new(">= 1.8.7")
  s.rubyforge_project = %q{nokogiri}
  s.rubygems_version = %q{1.8.6}
  s.summary = %q{Nokogiri (鋸) is an HTML, XML, SAX, and Reader parser}

  if s.respond_to? :specification_version then
    s.specification_version = 4

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_development_dependency(%q<rdoc>, ["~> 4.0"])
      s.add_development_dependency(%q<hoe-bundler>, [">= 1.1"])
      s.add_development_dependency(%q<hoe-debugging>, [">= 1.0.3"])
      s.add_development_dependency(%q<hoe-gemspec>, [">= 1.0"])
      s.add_development_dependency(%q<hoe-git>, [">= 1.4"])
      s.add_development_dependency(%q<mini_portile>, [">= 0.2.2"])
      s.add_development_dependency(%q<minitest>, ["~> 2.2.2"])
      s.add_development_dependency(%q<rake>, [">= 0.9"])
      s.add_development_dependency(%q<rake-compiler>, ["~> 0.8.0"])
      s.add_development_dependency(%q<racc>, [">= 1.4.6"])
      s.add_development_dependency(%q<rexical>, [">= 1.0.5"])
      s.add_development_dependency(%q<hoe>, ["~> 3.7"])
    else
      s.add_dependency(%q<rdoc>, ["~> 4.0"])
      s.add_dependency(%q<hoe-bundler>, [">= 1.1"])
      s.add_dependency(%q<hoe-debugging>, [">= 1.0.3"])
      s.add_dependency(%q<hoe-gemspec>, [">= 1.0"])
      s.add_dependency(%q<hoe-git>, [">= 1.4"])
      s.add_dependency(%q<mini_portile>, [">= 0.2.2"])
      s.add_dependency(%q<minitest>, ["~> 2.2.2"])
      s.add_dependency(%q<rake>, [">= 0.9"])
      s.add_dependency(%q<rake-compiler>, ["~> 0.8.0"])
      s.add_dependency(%q<racc>, [">= 1.4.6"])
      s.add_dependency(%q<rexical>, [">= 1.0.5"])
      s.add_dependency(%q<hoe>, ["~> 3.7"])
    end
  else
    s.add_dependency(%q<rdoc>, ["~> 4.0"])
    s.add_dependency(%q<hoe-bundler>, [">= 1.1"])
    s.add_dependency(%q<hoe-debugging>, [">= 1.0.3"])
    s.add_dependency(%q<hoe-gemspec>, [">= 1.0"])
    s.add_dependency(%q<hoe-git>, [">= 1.4"])
    s.add_dependency(%q<mini_portile>, [">= 0.2.2"])
    s.add_dependency(%q<minitest>, ["~> 2.2.2"])
    s.add_dependency(%q<rake>, [">= 0.9"])
    s.add_dependency(%q<rake-compiler>, ["~> 0.8.0"])
    s.add_dependency(%q<racc>, [">= 1.4.6"])
    s.add_dependency(%q<rexical>, [">= 1.0.5"])
    s.add_dependency(%q<hoe>, ["~> 3.7"])
  end
end
