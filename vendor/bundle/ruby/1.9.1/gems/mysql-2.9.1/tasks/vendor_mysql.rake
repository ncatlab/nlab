require 'rake/clean'
require 'rake/extensioncompiler'

# download mysql library and headers
directory "vendor"

CONNECTOR_DIR = "mysql-connector-c-noinstall-#{CONNECTOR_VERSION}-win32"
CONNECTOR_ZIP = "#{CONNECTOR_DIR}.zip"

file "vendor/#{CONNECTOR_ZIP}" => ['vendor'] do |t|
  url = "http://dev.mysql.com/get/Downloads/Connector-C/#{File.basename(t.name)}/from/#{CONNECTOR_MIRROR}/"
  when_writing "downloading #{t.name}" do
    sh "curl -L #{url} -o #{t.name}"
  end
end

file "vendor/#{CONNECTOR_DIR}/include/mysql.h" => ["vendor/#{CONNECTOR_ZIP}"] do |t|
  full_file = File.expand_path(t.prerequisites.last)
  when_writing "creating #{t.name}" do
    cd "vendor" do
      sh "unzip #{full_file} #{CONNECTOR_DIR}/bin/** #{CONNECTOR_DIR}/include/** #{CONNECTOR_DIR}/lib/**"
    end
    # update file timestamp to avoid Rake perform this extraction again.
    touch t.name
  end
end

# clobber expanded packages
CLOBBER.include("vendor/#{CONNECTOR_ZIP}")
CLOBBER.include("vendor/#{CONNECTOR_DIR}")

# vendor:mysql
task 'vendor:mysql' => ["vendor/#{CONNECTOR_DIR}/include/mysql.h"]

# hook into cross compilation vendored mysql dependency
if RUBY_PLATFORM =~ /mingw|mswin/ then
  Rake::Task['compile'].prerequisites.unshift 'vendor:mysql'
else
  if Rake::Task.tasks.map {|t| t.name }.include? 'cross'
    Rake::Task['cross'].prerequisites.unshift 'vendor:mysql'
  end
end
