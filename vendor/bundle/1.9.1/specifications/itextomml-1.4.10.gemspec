# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{itextomml}
  s.version = "1.4.10"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = [%q{Jacques Distler}]
  s.date = %q{2012-06-16}
  s.description = %q{itextomml provides native Ruby bindings to itex2MML, which converts itex equations to MathML.}
  s.email = %q{jdistler-gemcutter@golem.ph.utexas.edu}
  s.extensions = [%q{ext/extconf.rb}]
  s.files = [%q{ext/extconf.rb}]
  s.homepage = %q{http://golem.ph.utexas.edu/~distler/blog/itex2MML.html}
  s.require_paths = [%q{lib}, %q{ext}]
  s.rubygems_version = %q{1.8.6}
  s.summary = %q{Native Ruby bindings to itex2MML.}

  if s.respond_to? :specification_version then
    s.specification_version = 3

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
    else
    end
  else
  end
end
