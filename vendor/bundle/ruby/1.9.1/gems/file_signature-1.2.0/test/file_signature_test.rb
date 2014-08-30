# -*- coding: utf-8 -*-
#
# to run test:
#  - gem install minitest
#  - from gem root directory:
#    - `ruby test/file_signature_test.rb`
#

$LOAD_PATH << File.expand_path("#{File.dirname(__FILE__)}/../lib")

require 'rubygems'
require 'minitest/autorun'
require 'file_signature'

describe File do

  FILE_TO_MAGIC_NUMBER_MAP = {
    'sample.fit' => [:fits, 'image/fits'],
    'sample.gif' => [:gif, 'image/gif'],
    'sample.jpg' => [:jpeg, 'image/jpeg'],
    'sample.png' => [:png, 'image/png'],
    'sample.jp2' => [:jpeg2000, 'image/jp2'],
    'sample.webp' => [:webp, 'image/webp'],
    'sample.mid' => [:midi, 'audio/midi'],
    'sample.ps' => [:postscript, 'application/postscript'],
    'sample.ras' => [:sun_rasterfile, 'image/x-cmu-raster'],
    'sample.sgi' => [:iris_rgb, 'application/octet-stream'],
    'sample.tiff' => [:tiff, 'image/tiff'],
    'sample.rar' => [:rar, 'application/x-rar-compressed'],
    'sample.xcf.bz2' => [:bzip2, 'application/x-bzip2'],
    'sample.xcf.gz' => [:gzip, 'application/x-gzip'],
    'sample.xcf.zip' => [:pkzip, 'application/zip'],
    'sample.xcf.7z' => [:p7zip, 'application/x-7z-compressed'],
    'sample.tar' => [:tar, 'application/x-tar'],
    'sample.tar.gz' => [:gzip, 'application/x-gzip'],
    'sample.xcf.Z' => [:compress, 'application/x-compress'],
    'sample.ppt' => [:ppt, 'application/vnd.ms-powerpoint'],
    'sample2.ppt' => [:ppt, 'application/vnd.ms-powerpoint'],
    'sample.pptx' => [:pptx, 'application/vnd.openxmlformats-officedocument.presentationml.presentation'],
    'sample.xls' => [:xls, 'application/vnd.ms-excel'],
    'sample2.xls' => [:xls, 'application/vnd.ms-excel'],
    'sample.xlsx' => [:xlsx, 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet'],
    'sample.ico' => [:ico, 'image/vnd.microsoft.icon'],
    'sample.mp3' => [:mp3, 'audio/mpeg'],
    'sample.mp4' => [:mp4, 'video/mp4'],
    'sample.m4a' => [:m4a, 'audio/mp4a-latm'],
    'sample.m4v' => [:m4v, 'video/x-m4v'],
    'sample.mov' => [:quicktime, 'video/quicktime'],
    'sample.ogg' => [:ogg, 'application/ogg'],
    'sample.spx' => [:ogg, 'application/ogg'],
    'sample.webm' => [:webm, 'video/webm'],
    'sample.avi' => [:avi, 'video/x-msvideo'],
    'sample.3gp' => [:video_3gpp, 'video/3gpp'],
    'sample.3g2' => [:video_3gpp2, 'video/3gpp2'],
    'sample.m3u8' => [:m3u8, 'application/vnd.apple.mpegURL'],
    'sample.fig' => [:xfig, 'application/x-fig'],
    'sample.xcf' => [:gimp_xcf, 'image/xcf'],
    'sample.exe' => [:exe, 'application/x-msdownload'],
    'sample.bc' => [:bitcode, 'application/octet-stream'],
    'sample.bmp' => [:bitmap, 'image/bmp'],
    'sample.xpm' => [:xpm, 'image/x-xpixmap'],
    'sample.doc' => [:docfile, 'application/msword'],
    'sample2.doc' => [:docfile, 'application/msword'],
    'sample.pdf' => [:pdf, 'application/pdf'],
    'sample.rtf' => [:rtf, 'text/rtf'],
    'sample.jar' => [:jar, 'application/java-archive'],
    'sample.wav' => [:wave, 'audio/wave'],
    'sample.flac' => [:flac, 'audio/flac'],
    'sample.aif' => [:aiff, 'audio/x-aiff'],
    'sample.elf' => [:unix_elf, 'application/octet-stream'],
    'sample.gpg' => [:pgp_encrypted_data, 'application/octet-stream'],
    'sample.pubring.gpg' => [:gnupg_public_ring, 'application/x-pgp-keyring'],
    'sample.skr' => [:pgp_secret_ring, 'application/x-pgp-keyring'],
    'sample.sh' => [:shebang, 'text/plain']
  }

  FILE_TO_MAGIC_NUMBER_MAP.each_pair do |file_name, v|
    type = v[0]
    mime = v[1]
    path = File.join("test","file_signature_test",file_name)

    it "guesses the expected magic number type by filename and path for #{type.to_s}" do
      File.magic_number_type(path).must_equal type
    end

    it "guesses the expected mime type by filename and path for #{mime}" do
      File.mime_type(path).must_equal mime
    end

    f = File.open(path)

    it "when called from an IO object for #{type.to_s}" do
      f.magic_number_type.must_equal type
    end

    it "when called from an IO object for #{mime}" do
      f.mime_type.must_equal mime
    end

    it "when called from an IO object...a second time for #{type.to_s}" do
      #test it twice for the memo
      f.magic_number_type.must_equal type
    end

    it "when called from an IO object...a second time for #{mime}" do
      #test it twice for the memo
      f.mime_type.must_equal mime
    end

  end
end
