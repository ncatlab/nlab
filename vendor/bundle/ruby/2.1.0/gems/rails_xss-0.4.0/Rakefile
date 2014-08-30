require 'rubygems'
require 'rake'

begin
  require 'jeweler'
  Jeweler::Tasks.new do |gem|
    gem.name = "rails_xss"
    gem.summary = %Q{A plugin for rails 2.3 apps which switches the default to escape by default}
    gem.description = %Q{This plugin replaces the default ERB template handlers with erubis, and switches the behaviour to escape by default rather than requiring you to escape. This is consistent with the behaviour in Rails 3.0.}
    gem.email = "joloudov@gmail.com"
    gem.homepage = "http://github.com/joloudov/rails_xss"
    gem.authors = ["joloudov"]
    gem.add_development_dependency "erubis", ">= 2.6.5"
    gem.files = [
      '[A-Z]*',
      '*.rb',
      'lib/*.rb',
      'lib/**/*.rb',
      'rails/**/*.rb',
      'lib/**/*.rake',
    ]
  end
  Jeweler::GemcutterTasks.new
rescue LoadError
  puts "Jeweler (or a dependency) not available. Install it with: gem install jeweler"
end

require 'rake/testtask'
Rake::TestTask.new(:test) do |test|
  test.libs << 'lib' << 'test'
  test.pattern = 'test/**/test_*.rb'
  test.verbose = true
end

begin
  require 'rcov/rcovtask'
  Rcov::RcovTask.new do |test|
    test.libs << 'test'
    test.pattern = 'test/**/test_*.rb'
    test.verbose = true
  end
rescue LoadError
  task :rcov do
    abort "RCov is not available. In order to run rcov, you must: sudo gem install spicycode-rcov"
  end
end

task :test => :check_dependencies

task :default => :test

require 'rdoc/task'
Rake::RDocTask.new do |rdoc|
  version = File.exist?('VERSION') ? File.read('VERSION') : ""

  rdoc.rdoc_dir = 'rdoc'
  rdoc.title = "rails_xss #{version}"
  rdoc.rdoc_files.include('README*')
  rdoc.rdoc_files.include('lib/**/*.rb')
end
