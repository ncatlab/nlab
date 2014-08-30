= MySQL/Ruby Interface

* http://github.com/luislavena/mysql-gem

== DESCRIPTION

This is the MySQL API module for Ruby. It provides the same functions for Ruby
programs that the MySQL C API provides for C programs.

This package is offered as gem for easy installation using RubyGems. It wraps
unmodified tmtm's mysql-ruby extension into a proper gem.

Please note that tmtm (Tomita Mashahiro) has deprecated development of this
extension and only update it for bug fixes.

=== Warning about incompatible MySQL versions under Windows

Mixing MySQL versions will generate segmentation faults.

Running the binary version of this gem against a different version of MySQL
shared library <tt>libMySQL.dll</tt> will generate segmentation faults and
terminate your application.

Please use the exact same MAJOR.MINOR version of MySQL, see History.txt for
specific version of MySQL used to build the binaries.
