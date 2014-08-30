#  Ruby module for itex2MML
#
#  Installation
#  ------------
#    1. You need SWIG (>= 1.3) and GNU Make to install
#       the Ruby module.
#    2. Then type:
#            make ruby
#             make test_ruby
#            make install_ruby
#    3. This module can then be invoked like:
#
#            require 'itextomml'
#            
#            itex = Itex2MML::Parser.new
#            itex.html_filter(string)
#
#  Usage
#  -----
#
#      There are four public methods
#
#       itex.html_filter(a_string)
#               converts all itex equations in a_string to MathML, passing the
#               rest of a_string unmodified. Returns the converted string. 
#
#       itex.filter(a_string)
#               converts all itex equations in a_string to MathML. Returns just
#               the MathML equation(s), as a string.
#
#       itex.inline_filter(a_string)
#               treats a_string as an inline equation (automatically supplies
#               the surrounding $...$, so you don't have to) and converts it
#               MathML. Returns the MathML inline equation, as a string.
#
#       itex.block_filter(a_string)
#               treats a_string as a block equation (automatically supplies
#               the surrounding $$...$$, so you don't have to) and converts it
#               MathML. Returns the MathML block equation, as a string.
#
#  Authors: Justin Bonnar <jbonnar@berkeley.edu>
#           Jacques Distler <distler@golem.ph.utexas.edu>
#
#  Placed in the Public Domain

require 'itex2MML'
require 'thread'

module Itex2MML
  class Error < RuntimeError; end
 
  class Parser
    def self.semaphore
      @semaphore ||= Mutex.new
    end
   
    def html_filter(string)
      parse(string, :itex2MML_html_filter)
    end
   
    def filter(string)
      parse(string, :itex2MML_filter)
    end
 
    def inline_filter(string)
      parse("\$#{string}\$", :itex2MML_filter)
    end
 
    def block_filter(string)
      parse("\$\$#{string}\$\$", :itex2MML_filter)
    end
 
  private
 
    def parse(string, message)
      str = as_bytes(string.to_str)
      self.class.semaphore.synchronize do
        raise Itex2MML::Error unless Itex2MML.send(message, str, str.length) == 0
        as_utf8(Itex2MML.itex2MML_output)
      end
    end
    
    if "".respond_to?(:force_encoding)
      def as_bytes(string)
        string.force_encoding("ASCII-8BIT")
      end
      def as_utf8(string)
        string.force_encoding("UTF-8")
      end
    else
      def as_bytes(string)
        string
      end
      def as_utf8(string)
        string
      end
    end

  end
end

