# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{rdoc}
  s.version = "4.1.0"

  s.required_rubygems_version = Gem::Requirement.new(">= 1.3") if s.respond_to? :required_rubygems_version=
  s.authors = [%q{Eric Hodel}, %q{Dave Thomas}, %q{Phil Hagelberg}, %q{Tony Strauss}]
  s.cert_chain = [%q{-----BEGIN CERTIFICATE-----
MIIDeDCCAmCgAwIBAgIBATANBgkqhkiG9w0BAQUFADBBMRAwDgYDVQQDDAdkcmJy
YWluMRgwFgYKCZImiZPyLGQBGRYIc2VnbWVudDcxEzARBgoJkiaJk/IsZAEZFgNu
ZXQwHhcNMTMwMjI4MDUyMjA4WhcNMTQwMjI4MDUyMjA4WjBBMRAwDgYDVQQDDAdk
cmJyYWluMRgwFgYKCZImiZPyLGQBGRYIc2VnbWVudDcxEzARBgoJkiaJk/IsZAEZ
FgNuZXQwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCbbgLrGLGIDE76
LV/cvxdEzCuYuS3oG9PrSZnuDweySUfdp/so0cDq+j8bqy6OzZSw07gdjwFMSd6J
U5ddZCVywn5nnAQ+Ui7jMW54CYt5/H6f2US6U0hQOjJR6cpfiymgxGdfyTiVcvTm
Gj/okWrQl0NjYOYBpDi+9PPmaH2RmLJu0dB/NylsDnW5j6yN1BEI8MfJRR+HRKZY
mUtgzBwF1V4KIZQ8EuL6I/nHVu07i6IkrpAgxpXUfdJQJi0oZAqXurAV3yTxkFwd
g62YrrW26mDe+pZBzR6bpLE+PmXCzz7UxUq3AE0gPHbiMXie3EFE0oxnsU3lIduh
sCANiQ8BAgMBAAGjezB5MAkGA1UdEwQCMAAwCwYDVR0PBAQDAgSwMB0GA1UdDgQW
BBS5k4Z75VSpdM0AclG2UvzFA/VW5DAfBgNVHREEGDAWgRRkcmJyYWluQHNlZ21l
bnQ3Lm5ldDAfBgNVHRIEGDAWgRRkcmJyYWluQHNlZ21lbnQ3Lm5ldDANBgkqhkiG
9w0BAQUFAAOCAQEAOflo4Md5aJF//EetzXIGZ2EI5PzKWX/mMpp7cxFyDcVPtTv0
js/6zWrWSbd60W9Kn4ch3nYiATFKhisgeYotDDz2/pb/x1ivJn4vEvs9kYKVvbF8
V7MV/O5HDW8Q0pA1SljI6GzcOgejtUMxZCyyyDdbUpyAMdt9UpqTZkZ5z1sicgQk
5o2XJ+OhceOIUVqVh1r6DNY5tLVaGJabtBmJAYFVznDcHiSFybGKBa5n25Egql1t
KDyY1VIazVgoC8XvR4h/95/iScPiuglzA+DBG1hip1xScAtw05BrXyUNrc9CEMYU
wgF94UVoHRp6ywo8I7NP3HcwFQDFNEZPNGXsng==
-----END CERTIFICATE-----
}]
  s.date = %q{2013-12-26}
  s.description = %q{RDoc produces HTML and command-line documentation for Ruby projects.  RDoc
includes the +rdoc+ and +ri+ tools for generating and displaying documentation
from the command-line.}
  s.email = [%q{drbrain@segment7.net}, %q{}, %q{technomancy@gmail.com}, %q{tony.strauss@designingpatterns.com}]
  s.executables = [%q{rdoc}, %q{ri}]
  s.extra_rdoc_files = [%q{CONTRIBUTING.rdoc}, %q{CVE-2013-0256.rdoc}, %q{ExampleMarkdown.md}, %q{ExampleRDoc.rdoc}, %q{History.rdoc}, %q{LEGAL.rdoc}, %q{LICENSE.rdoc}, %q{Manifest.txt}, %q{README.rdoc}, %q{RI.rdoc}, %q{TODO.rdoc}, %q{Rakefile}]
  s.files = [%q{bin/rdoc}, %q{bin/ri}, %q{CONTRIBUTING.rdoc}, %q{CVE-2013-0256.rdoc}, %q{ExampleMarkdown.md}, %q{ExampleRDoc.rdoc}, %q{History.rdoc}, %q{LEGAL.rdoc}, %q{LICENSE.rdoc}, %q{Manifest.txt}, %q{README.rdoc}, %q{RI.rdoc}, %q{TODO.rdoc}, %q{Rakefile}]
  s.homepage = %q{http://docs.seattlerb.org/rdoc}
  s.licenses = [%q{Ruby}]
  s.post_install_message = %q{Depending on your version of ruby, you may need to install ruby rdoc/ri data:

<= 1.8.6 : unsupported
 = 1.8.7 : gem install rdoc-data; rdoc-data --install
 = 1.9.1 : gem install rdoc-data; rdoc-data --install
>= 1.9.2 : nothing to do! Yay!
}
  s.rdoc_options = [%q{--main}, %q{README.rdoc}]
  s.require_paths = [%q{lib}]
  s.required_ruby_version = Gem::Requirement.new(">= 1.8.7")
  s.rubyforge_project = %q{rdoc}
  s.rubygems_version = %q{1.8.6}
  s.summary = %q{RDoc produces HTML and command-line documentation for Ruby projects}

  if s.respond_to? :specification_version then
    s.specification_version = 4

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_runtime_dependency(%q<json>, ["~> 1.4"])
      s.add_development_dependency(%q<kpeg>, ["~> 0.9"])
      s.add_development_dependency(%q<minitest>, ["~> 5.0"])
      s.add_development_dependency(%q<rdoc>, ["~> 4.0"])
      s.add_development_dependency(%q<racc>, ["!= 1.4.10", "~> 1.4"])
      s.add_development_dependency(%q<hoe>, ["~> 3.7"])
    else
      s.add_dependency(%q<json>, ["~> 1.4"])
      s.add_dependency(%q<kpeg>, ["~> 0.9"])
      s.add_dependency(%q<minitest>, ["~> 5.0"])
      s.add_dependency(%q<rdoc>, ["~> 4.0"])
      s.add_dependency(%q<racc>, ["!= 1.4.10", "~> 1.4"])
      s.add_dependency(%q<hoe>, ["~> 3.7"])
    end
  else
    s.add_dependency(%q<json>, ["~> 1.4"])
    s.add_dependency(%q<kpeg>, ["~> 0.9"])
    s.add_dependency(%q<minitest>, ["~> 5.0"])
    s.add_dependency(%q<rdoc>, ["~> 4.0"])
    s.add_dependency(%q<racc>, ["!= 1.4.10", "~> 1.4"])
    s.add_dependency(%q<hoe>, ["~> 3.7"])
  end
end
