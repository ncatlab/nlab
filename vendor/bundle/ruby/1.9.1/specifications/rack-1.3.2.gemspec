# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{rack}
  s.version = "1.3.2"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = [%q{Christian Neukirchen}]
  s.date = %q{2011-07-26}
  s.description = %q{Rack provides minimal, modular and adaptable interface for developing
web applications in Ruby.  By wrapping HTTP requests and responses in
the simplest way possible, it unifies and distills the API for web
servers, web frameworks, and software in between (the so-called
middleware) into a single method call.

Also see http://rack.rubyforge.org.
}
  s.email = %q{chneukirchen@gmail.com}
  s.executables = [%q{rackup}]
  s.extra_rdoc_files = [%q{README.rdoc}, %q{KNOWN-ISSUES}]
  s.files = [%q{bin/rackup}, %q{README.rdoc}, %q{KNOWN-ISSUES}]
  s.homepage = %q{http://rack.rubyforge.org}
  s.require_paths = [%q{lib}]
  s.rubyforge_project = %q{rack}
  s.rubygems_version = %q{1.8.6}
  s.summary = %q{a modular Ruby webserver interface}

  if s.respond_to? :specification_version then
    s.specification_version = 3

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_development_dependency(%q<bacon>, [">= 0"])
      s.add_development_dependency(%q<rake>, [">= 0"])
      s.add_development_dependency(%q<fcgi>, [">= 0"])
      s.add_development_dependency(%q<memcache-client>, [">= 0"])
      s.add_development_dependency(%q<mongrel>, [">= 0"])
      s.add_development_dependency(%q<thin>, [">= 0"])
    else
      s.add_dependency(%q<bacon>, [">= 0"])
      s.add_dependency(%q<rake>, [">= 0"])
      s.add_dependency(%q<fcgi>, [">= 0"])
      s.add_dependency(%q<memcache-client>, [">= 0"])
      s.add_dependency(%q<mongrel>, [">= 0"])
      s.add_dependency(%q<thin>, [">= 0"])
    end
  else
    s.add_dependency(%q<bacon>, [">= 0"])
    s.add_dependency(%q<rake>, [">= 0"])
    s.add_dependency(%q<fcgi>, [">= 0"])
    s.add_dependency(%q<memcache-client>, [">= 0"])
    s.add_dependency(%q<mongrel>, [">= 0"])
    s.add_dependency(%q<thin>, [">= 0"])
  end
end
