# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{file_signature}
  s.version = "1.2.0"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = [%q{distler}, %q{robacarp}, %q{Joel Parker Henderson @ SixArm}]
  s.date = %q{2012-10-01}
  s.description = %q{Monkeypatches File and IO to include a '''magic_number_type''' method which returns a symbol, and a '''mime_type''' method which returns a string, representing the mime type guessed.}
  s.email = [%q{distler@golem.ph.utexas.edu}, %q{codemonkey@robacarp.com}, %q{joel@sixarm.com}]
  s.homepage = %q{http://github.com/robacarp/file_signature}
  s.require_paths = [%q{lib}]
  s.rubygems_version = %q{1.8.6}
  s.summary = %q{File signature adds the ability to inspect the first few bytes of a file to guess at mime-type.}

  if s.respond_to? :specification_version then
    s.specification_version = 3

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
    else
    end
  else
  end
end
