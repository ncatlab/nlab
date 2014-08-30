# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{json}
  s.version = "1.8.1"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = [%q{Florian Frank}]
  s.date = %q{2013-10-17}
  s.description = %q{This is a JSON implementation as a Ruby extension in C.}
  s.email = %q{flori@ping.de}
  s.extensions = [%q{ext/json/ext/generator/extconf.rb}, %q{ext/json/ext/parser/extconf.rb}]
  s.extra_rdoc_files = [%q{README.rdoc}]
  s.files = [%q{README.rdoc}, %q{ext/json/ext/generator/extconf.rb}, %q{ext/json/ext/parser/extconf.rb}]
  s.homepage = %q{http://flori.github.com/json}
  s.licenses = [%q{Ruby}]
  s.rdoc_options = [%q{--title}, %q{JSON implemention for Ruby}, %q{--main}, %q{README.rdoc}]
  s.require_paths = [%q{lib}]
  s.rubygems_version = %q{1.8.6}
  s.summary = %q{JSON Implementation for Ruby}

  if s.respond_to? :specification_version then
    s.specification_version = 4

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_development_dependency(%q<permutation>, [">= 0"])
      s.add_development_dependency(%q<sdoc>, ["~> 0.3.16"])
    else
      s.add_dependency(%q<permutation>, [">= 0"])
      s.add_dependency(%q<sdoc>, ["~> 0.3.16"])
    end
  else
    s.add_dependency(%q<permutation>, [">= 0"])
    s.add_dependency(%q<sdoc>, ["~> 0.3.16"])
  end
end
