# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{daemons}
  s.version = "1.0.10"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = [%q{Thomas Uehlinger}]
  s.autorequire = %q{daemons}
  s.date = %q{2008-03-21}
  s.description = %q{Daemons provides an easy way to wrap existing ruby scripts (for example a self-written server)  to be run as a daemon and to be controlled by simple start/stop/restart commands.  You can also call blocks as daemons and control them from the parent or just daemonize the current process.  Besides this basic functionality, daemons offers many advanced features like exception  backtracing and logging (in case your ruby script crashes) and monitoring and automatic restarting of your processes if they crash.}
  s.email = %q{th.uehlinger@gmx.ch}
  s.extra_rdoc_files = [%q{README}, %q{Releases}, %q{TODO}]
  s.files = [%q{README}, %q{Releases}, %q{TODO}]
  s.homepage = %q{http://daemons.rubyforge.org}
  s.require_paths = [%q{lib}]
  s.rubyforge_project = %q{daemons}
  s.rubygems_version = %q{1.8.6}
  s.summary = %q{A toolkit to create and control daemons in different ways}

  if s.respond_to? :specification_version then
    s.specification_version = 2

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
    else
    end
  else
  end
end
