# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{mongrel}
  s.version = "1.2.0.pre2"

  s.required_rubygems_version = Gem::Requirement.new("> 1.3.1") if s.respond_to? :required_rubygems_version=
  s.authors = [%q{Zed A. Shaw}]
  s.date = %q{2010-03-18}
  s.description = %q{Mongrel is a small library that provides a very fast HTTP 1.1 server for Ruby web applications.  It is not particular to any framework, and is intended to be just enough to get a web application running behind a more complete and robust web server.

What makes Mongrel so fast is the careful use of an Ragel extension to provide fast, accurate HTTP 1.1 protocol parsing. This makes the server scream without too many portability issues.

See http://mongrel.rubyforge.org for more information.}
  s.email = [%q{mongrel-users@rubyforge.org}]
  s.executables = [%q{mongrel_rails}]
  s.extensions = [%q{ext/http11/extconf.rb}]
  s.extra_rdoc_files = [%q{History.txt}, %q{Manifest.txt}, %q{README.txt}, %q{LICENSE}]
  s.files = [%q{bin/mongrel_rails}, %q{History.txt}, %q{Manifest.txt}, %q{README.txt}, %q{LICENSE}, %q{ext/http11/extconf.rb}]
  s.homepage = %q{http://mongrel.rubyforge.org/}
  s.rdoc_options = [%q{--main}, %q{README.txt}]
  s.require_paths = [%q{lib}, %q{ext}]
  s.required_ruby_version = Gem::Requirement.new(">= 1.8.6")
  s.rubyforge_project = %q{mongrel}
  s.rubygems_version = %q{1.8.6}
  s.summary = %q{Mongrel is a small library that provides a very fast HTTP 1.1 server for Ruby web applications}

  if s.respond_to? :specification_version then
    s.specification_version = 3

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_runtime_dependency(%q<gem_plugin>, ["~> 0.2.3"])
      s.add_runtime_dependency(%q<daemons>, ["~> 1.0.10"])
      s.add_development_dependency(%q<rubyforge>, [">= 2.0.3"])
      s.add_development_dependency(%q<gemcutter>, [">= 0.3.0"])
      s.add_development_dependency(%q<rake-compiler>, ["~> 0.7.0"])
      s.add_development_dependency(%q<hoe>, [">= 2.5.0"])
    else
      s.add_dependency(%q<gem_plugin>, ["~> 0.2.3"])
      s.add_dependency(%q<daemons>, ["~> 1.0.10"])
      s.add_dependency(%q<rubyforge>, [">= 2.0.3"])
      s.add_dependency(%q<gemcutter>, [">= 0.3.0"])
      s.add_dependency(%q<rake-compiler>, ["~> 0.7.0"])
      s.add_dependency(%q<hoe>, [">= 2.5.0"])
    end
  else
    s.add_dependency(%q<gem_plugin>, ["~> 0.2.3"])
    s.add_dependency(%q<daemons>, ["~> 1.0.10"])
    s.add_dependency(%q<rubyforge>, [">= 2.0.3"])
    s.add_dependency(%q<gemcutter>, [">= 0.3.0"])
    s.add_dependency(%q<rake-compiler>, ["~> 0.7.0"])
    s.add_dependency(%q<hoe>, [">= 2.5.0"])
  end
end
