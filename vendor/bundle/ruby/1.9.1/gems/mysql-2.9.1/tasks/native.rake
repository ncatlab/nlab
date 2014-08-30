# use rake-compiler for building the extension
require 'rake/extensiontask'

CONNECTOR_VERSION = "6.0.2"
CONNECTOR_MIRROR  = ENV['CONNECTOR_MIRROR'] || "http://mysql.localhost.net.ar"

Rake::ExtensionTask.new('mysql_api', HOE.spec) do |ext|
  # reference where the vendored MySQL got extracted
  mysql_lib = File.expand_path(File.join(File.dirname(__FILE__), '..', 'vendor', "mysql-connector-c-noinstall-#{CONNECTOR_VERSION}-win32"))

  # where native extension will be copied (matches makefile)
  ext.lib_dir = "lib/mysql"

  # define target for extension (supporting fat binaries)
  if RUBY_PLATFORM =~ /mswin|mingw/ then
    ruby_ver = RUBY_VERSION.match(/(\d+\.\d+)/)[1]
    ext.lib_dir = "lib/mysql/#{ruby_ver}"
  end

  # automatically add build options to avoid need of manual input
  if RUBY_PLATFORM =~ /mswin|mingw/ then
    ext.config_options << "--with-mysql-dir=#{mysql_lib}"
  else
    ext.cross_compile = true
    ext.cross_platform = ['i386-mingw32', 'i386-mswin32-60']
    ext.cross_config_options << "--with-mysql-dir=#{mysql_lib}"
    ext.cross_compiling do |gemspec|
      gemspec.post_install_message = <<-POST_INSTALL_MESSAGE

======================================================================================================

  You've installed the binary version of #{gemspec.name}.
  It was built using MySQL Connector/C version #{CONNECTOR_VERSION}.
  It's recommended to use the exact same version to avoid potential issues.

  At the time of building this gem, the necessary DLL files where available
  in the following URL:

  http://dev.mysql.com/get/Downloads/Connector-C/mysql-connector-c-noinstall-#{CONNECTOR_VERSION}-win32.zip/from/pick

  You can put the lib\\libmysql.dll available in this package to your Ruby bin directory.
  E.g. C:\\Ruby\\bin

======================================================================================================

      POST_INSTALL_MESSAGE
    end
  end
end

# ensure things are compiled prior testing
task :test => [:compile]
