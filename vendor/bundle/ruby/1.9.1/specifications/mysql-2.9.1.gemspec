# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{mysql}
  s.version = "2.9.1"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = [%q{TOMITA Masahiro}]
  s.date = %q{2013-02-16}
  s.description = %q{This is the MySQL API module for Ruby. It provides the same functions for Ruby
programs that the MySQL C API provides for C programs.

This package is offered as gem for easy installation using RubyGems. It wraps
unmodified tmtm's mysql-ruby extension into a proper gem.

Please note that tmtm (Tomita Mashahiro) has deprecated development of this
extension and only update it for bug fixes.}
  s.email = [%q{tommy@tmtm.org}]
  s.extensions = [%q{ext/mysql_api/extconf.rb}]
  s.extra_rdoc_files = [%q{History.txt}, %q{Manifest.txt}, %q{README.txt}]
  s.files = [%q{History.txt}, %q{Manifest.txt}, %q{README.txt}, %q{ext/mysql_api/extconf.rb}]
  s.homepage = %q{http://github.com/luislavena/mysql-gem}
  s.rdoc_options = [%q{--main}, %q{README.txt}]
  s.require_paths = [%q{lib}]
  s.required_ruby_version = Gem::Requirement.new(">= 1.8.7")
  s.rubyforge_project = %q{mysql-win}
  s.rubygems_version = %q{1.8.6}
  s.summary = %q{This is the MySQL API module for Ruby}

  if s.respond_to? :specification_version then
    s.specification_version = 3

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_development_dependency(%q<rdoc>, ["~> 3.10"])
      s.add_development_dependency(%q<rake-compiler>, ["~> 0.8.1"])
      s.add_development_dependency(%q<hoe>, ["~> 3.5"])
    else
      s.add_dependency(%q<rdoc>, ["~> 3.10"])
      s.add_dependency(%q<rake-compiler>, ["~> 0.8.1"])
      s.add_dependency(%q<hoe>, ["~> 3.5"])
    end
  else
    s.add_dependency(%q<rdoc>, ["~> 3.10"])
    s.add_dependency(%q<rake-compiler>, ["~> 0.8.1"])
    s.add_dependency(%q<hoe>, ["~> 3.5"])
  end
end
