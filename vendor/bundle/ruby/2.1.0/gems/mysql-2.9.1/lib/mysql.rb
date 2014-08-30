# support multiple ruby version (fat binaries under windows)
begin
  RUBY_VERSION =~ /(\d+.\d+)/
  require "mysql/#{$1}/mysql_api"
rescue LoadError
  require 'mysql/mysql_api'
end

require 'mysql/version'
