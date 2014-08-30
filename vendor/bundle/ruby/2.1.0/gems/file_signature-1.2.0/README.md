* Repo: <http://github.com/robacarp/file_signature>
* Email: Jacques Distler, <distler@golem.ph.utexas.edu>
* Email: Robert Carpenter, <coder@robacarp.com>
* Email: Joel Parker Henderson, <joel@sixarm.com>

## Introduction

Magic numbers are patterns in the first few bytes of a file or data stream which (hopefully, uniquely) identify the type of the  file or data stream. For example, a file which starts with "%!PS-Adobe-" is very likely a postscript file, whereas one which starts with the three bytes, 1F 8B 08, is very likely a gzip-compressed file.

This gem allows you to check a file or IO stream against a list of known magic numbers, and thereby determine its type.

Want to help? Feel free to fork it and submit a pull request.


## Install quickstart

Install (for the previous 1.1.x version):

    gem install file_signature

Bundler (for the current 1.2.x version):

    gem "file_signature", :git => 'http://github.com/distler/file_signature.git'

Require:

    require "file_signature"

## Details

This gem infers the content-type based on widespread programming conventions for data file formats. It is tested on MRI 1.8.7 and 1.9.3.  If you test it and find it working on other rubies please share your success.

Our principal guide to these magic numbers is:
http://www.garykessler.net/library/file_sigs.html
But we've also found useful input from [libmagic](https://github.com/glensc/file/tree/master/magic/Magdir) and other sources on the internet.

Typical uses of magic numbers:

  * quickly guess at a file's mime type
  * check if data matches the file's MIME type or extension
  * check if a web form file upload matches its HTTP content type

Compare:

  * MIME::Types ruby library 
  * Unix magic() command for testing files on disk
  * http://shared-mime.rubyforge.org/

## Usage

     require 'file_signature'

The gem adds two class methods to the File class, and two instance methods to the IO class.

     File.magic_number_type('myfile')

and

     f = File.open('myfile')
     f.magic_number_type

both return a symbol (or `nil` if the type is unrecognized) corresponding to the type of file found. Similarly,

     File.mime_type('myfile')

and

     f = File.open('myfile')
     f.mime_type

return a string, which is the corresponding MIME-type ('`application/octet-stream`' if unrecognized).

##TODO

 * This library currently contains some pathetic handful of bytestrings for type identification... see if we can import some /usr/share/file/magic or something to extend this so its actually useful for more people.
 

## Changes

* 2012-03-14 1.0.0 Update docs, tests
* 2012-05-31 1.1.0 Add memo, reformat and rename things for clarity
* 2012-08-10 1.2.0 Many new magic numbers and corrections to existing ones, add methods to retrieve mime_type, *lots* of tests

## License

You may choose any of these open source licenses:

  * Apache License
  * BSD License
  * CreativeCommons License, Non-commercial Share Alike
  * GNU General Public License Version 2 (GPL 2)
  * GNU Lesser General Public License (LGPL)
  * MIT License
  * Perl Artistic License
  * Ruby License

The software is provided "as is", without warranty of any kind, 
express or implied, including but not limited to the warranties of 
merchantability, fitness for a particular purpose and noninfringement. 

In no event shall the authors or copyright holders be liable for any 
claim, damages or other liability, whether in an action of contract, 
tort or otherwise, arising from, out of or in connection with the 
software or the use or other dealings in the software.

This license is for the included software that is created by SixArm;
some of the included software may have its own licenses, copyrights, 
authors, etc. and these do take precedence over the SixArm license.

Copyright (c) 2005-2012 Joel Parker Henderson
