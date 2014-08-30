# Iconv

[![Build Status](https://travis-ci.org/nurse/iconv.png)](https://travis-ci.org/nurse/iconv)

iconv wrapper, used to be ext/iconv

## Abstract

Iconv is a wrapper class for the UNIX 95 <code>iconv()</code> function family,
which translates string between various encoding systems.

See Open Group's on-line documents for more details.
* <code>iconv.h</code>:       http://www.opengroup.org/onlinepubs/007908799/xsh/iconv.h.html
* <code>iconv_open()</code>:  http://www.opengroup.org/onlinepubs/007908799/xsh/iconv_open.html
* <code>iconv()</code>:       http://www.opengroup.org/onlinepubs/007908799/xsh/iconv.html
* <code>iconv_close()</code>: http://www.opengroup.org/onlinepubs/007908799/xsh/iconv_close.html

Which coding systems are available is platform-dependent.

## Installation

Add this line to your application's Gemfile:

    gem 'iconv'

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install iconv

## Usage

1. Simple conversion between two charsets.

     converted_text = Iconv.conv('iso-8859-15', 'utf-8', text)

2. Instantiate a new Iconv and use method Iconv#iconv.

     cd = Iconv.new(to, from)
     begin
       input.each { |s| output << cd.iconv(s) }
       output << cd.iconv(nil)                   # Don't forget this!
     ensure
       cd.close
     end

3. Invoke Iconv.open with a block.

     Iconv.open(to, from) do |cd|
       input.each { |s| output << cd.iconv(s) }
       output << cd.iconv(nil)
     end

4. Shorthand for (3).

     Iconv.iconv(to, from, *input.to_a)

## Attentions

Even if some extentions of implementation dependent are useful,
DON'T USE those extentions in libraries and scripts to widely distribute.
If you want to use those feature, use String#encode.

## Contributing

1. Fork it
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request

## License

Ruby License/2-clause BSDL
