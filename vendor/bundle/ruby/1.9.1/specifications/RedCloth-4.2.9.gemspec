# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{RedCloth}
  s.version = "4.2.9"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = [%q{Jason Garber}, %q{why the lucky stiff}, %q{Ola Bini}]
  s.date = %q{2011-11-27}
  s.description = %q{Textile parser for Ruby.}
  s.email = %q{redcloth-upwards@rubyforge.org}
  s.executables = [%q{redcloth}]
  s.extensions = [%q{ext/redcloth_scan/extconf.rb}]
  s.extra_rdoc_files = [%q{README.rdoc}, %q{COPYING}, %q{CHANGELOG}]
  s.files = [%q{bin/redcloth}, %q{README.rdoc}, %q{COPYING}, %q{CHANGELOG}, %q{ext/redcloth_scan/extconf.rb}]
  s.homepage = %q{http://redcloth.org}
  s.rdoc_options = [%q{--charset=UTF-8}, %q{--line-numbers}, %q{--inline-source}, %q{--title}, %q{RedCloth}, %q{--main}, %q{README.rdoc}]
  s.require_paths = [%q{lib}, %q{lib/case_sensitive_require}, %q{ext}]
  s.rubyforge_project = %q{redcloth}
  s.rubygems_version = %q{1.8.6}
  s.summary = %q{RedCloth-4.2.9}

  if s.respond_to? :specification_version then
    s.specification_version = 3

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_development_dependency(%q<bundler>, ["~> 1.0.10"])
      s.add_development_dependency(%q<rake>, ["~> 0.8.7"])
      s.add_development_dependency(%q<rspec>, ["~> 2.4"])
      s.add_development_dependency(%q<diff-lcs>, ["~> 1.1.2"])
      s.add_development_dependency(%q<rvm>, ["~> 1.2.6"])
      s.add_development_dependency(%q<rake-compiler>, ["~> 0.7.1"])
    else
      s.add_dependency(%q<bundler>, ["~> 1.0.10"])
      s.add_dependency(%q<rake>, ["~> 0.8.7"])
      s.add_dependency(%q<rspec>, ["~> 2.4"])
      s.add_dependency(%q<diff-lcs>, ["~> 1.1.2"])
      s.add_dependency(%q<rvm>, ["~> 1.2.6"])
      s.add_dependency(%q<rake-compiler>, ["~> 0.7.1"])
    end
  else
    s.add_dependency(%q<bundler>, ["~> 1.0.10"])
    s.add_dependency(%q<rake>, ["~> 0.8.7"])
    s.add_dependency(%q<rspec>, ["~> 2.4"])
    s.add_dependency(%q<diff-lcs>, ["~> 1.1.2"])
    s.add_dependency(%q<rvm>, ["~> 1.2.6"])
    s.add_dependency(%q<rake-compiler>, ["~> 0.7.1"])
  end
end
