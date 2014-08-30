# -*- encoding: utf-8 -*-
# stub: file_signature 1.2.0 ruby lib

Gem::Specification.new do |s|
  s.name = "file_signature"
  s.version = "1.2.0"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.require_paths = ["lib"]
  s.authors = ["distler", "robacarp", "Joel Parker Henderson @ SixArm"]
  s.date = "2012-10-01"
  s.description = "Monkeypatches File and IO to include a '''magic_number_type''' method which returns a symbol, and a '''mime_type''' method which returns a string, representing the mime type guessed."
  s.email = ["distler@golem.ph.utexas.edu", "codemonkey@robacarp.com", "joel@sixarm.com"]
  s.homepage = "http://github.com/robacarp/file_signature"
  s.rubygems_version = "2.2.2"
  s.summary = "File signature adds the ability to inspect the first few bytes of a file to guess at mime-type."

  s.installed_by_version = "2.2.2" if s.respond_to? :installed_by_version
end
