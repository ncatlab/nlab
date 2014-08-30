# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{rdoc}
  s.version = "3.9.1"

  s.required_rubygems_version = Gem::Requirement.new(">= 1.3") if s.respond_to? :required_rubygems_version=
  s.authors = [%q{Eric Hodel}, %q{Dave Thomas}, %q{Phil Hagelberg}, %q{Tony Strauss}]
  s.cert_chain = [%q{-----BEGIN CERTIFICATE-----
MIIDNjCCAh6gAwIBAgIBADANBgkqhkiG9w0BAQUFADBBMRAwDgYDVQQDDAdkcmJy
YWluMRgwFgYKCZImiZPyLGQBGRYIc2VnbWVudDcxEzARBgoJkiaJk/IsZAEZFgNu
ZXQwHhcNMDcxMjIxMDIwNDE0WhcNMDgxMjIwMDIwNDE0WjBBMRAwDgYDVQQDDAdk
cmJyYWluMRgwFgYKCZImiZPyLGQBGRYIc2VnbWVudDcxEzARBgoJkiaJk/IsZAEZ
FgNuZXQwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCbbgLrGLGIDE76
LV/cvxdEzCuYuS3oG9PrSZnuDweySUfdp/so0cDq+j8bqy6OzZSw07gdjwFMSd6J
U5ddZCVywn5nnAQ+Ui7jMW54CYt5/H6f2US6U0hQOjJR6cpfiymgxGdfyTiVcvTm
Gj/okWrQl0NjYOYBpDi+9PPmaH2RmLJu0dB/NylsDnW5j6yN1BEI8MfJRR+HRKZY
mUtgzBwF1V4KIZQ8EuL6I/nHVu07i6IkrpAgxpXUfdJQJi0oZAqXurAV3yTxkFwd
g62YrrW26mDe+pZBzR6bpLE+PmXCzz7UxUq3AE0gPHbiMXie3EFE0oxnsU3lIduh
sCANiQ8BAgMBAAGjOTA3MAkGA1UdEwQCMAAwCwYDVR0PBAQDAgSwMB0GA1UdDgQW
BBS5k4Z75VSpdM0AclG2UvzFA/VW5DANBgkqhkiG9w0BAQUFAAOCAQEAHagT4lfX
kP/hDaiwGct7XPuVGbrOsKRVD59FF5kETBxEc9UQ1clKWngf8JoVuEoKD774dW19
bU0GOVWO+J6FMmT/Cp7nuFJ79egMf/gy4gfUfQMuvfcr6DvZUPIs9P/TlK59iMYF
DIOQ3DxdF3rMzztNUCizN4taVscEsjCcgW6WkUJnGdqlu3OHWpQxZBJkBTjPCoc6
UW6on70SFPmAy/5Cq0OJNGEWBfgD9q7rrs/X8GGwUWqXb85RXnUVi/P8Up75E0ag
14jEc90kN+C7oI/AGCBN0j6JnEtYIEJZibjjDJTSMWlUKKkj30kq7hlUC2CepJ4v
x52qPcexcYZR7w==
-----END CERTIFICATE-----
}]
  s.date = %q{2011-07-31}
  s.description = %q{RDoc produces HTML and command-line documentation for Ruby projects.  RDoc
includes the +rdoc+ and +ri+ tools for generating and displaying online
documentation.

See RDoc for a description of RDoc's markup and basic use.}
  s.email = [%q{drbrain@segment7.net}, %q{}, %q{technomancy@gmail.com}, %q{tony.strauss@designingpatterns.com}]
  s.executables = [%q{rdoc}, %q{ri}]
  s.extra_rdoc_files = [%q{History.txt}, %q{LICENSE.txt}, %q{Manifest.txt}, %q{README.txt}, %q{RI.txt}, %q{Rakefile}]
  s.files = [%q{bin/rdoc}, %q{bin/ri}, %q{History.txt}, %q{LICENSE.txt}, %q{Manifest.txt}, %q{README.txt}, %q{RI.txt}, %q{Rakefile}]
  s.homepage = %q{http://docs.seattlerb.org/rdoc}
  s.post_install_message = %q{Depending on your version of ruby, you may need to install ruby rdoc/ri data:

<= 1.8.6 : unsupported
 = 1.8.7 : gem install rdoc-data; rdoc-data --install
 = 1.9.1 : gem install rdoc-data; rdoc-data --install
>= 1.9.2 : nothing to do! Yay!
}
  s.rdoc_options = [%q{--main}, %q{README.txt}]
  s.require_paths = [%q{lib}]
  s.required_ruby_version = Gem::Requirement.new(">= 1.8.7")
  s.rubyforge_project = %q{rdoc}
  s.rubygems_version = %q{1.8.6}
  s.summary = %q{RDoc produces HTML and command-line documentation for Ruby projects}

  if s.respond_to? :specification_version then
    s.specification_version = 3

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_development_dependency(%q<minitest>, [">= 2.3.1"])
      s.add_development_dependency(%q<minitest>, ["~> 2"])
      s.add_development_dependency(%q<isolate>, ["~> 3"])
      s.add_development_dependency(%q<ZenTest>, ["~> 4"])
      s.add_development_dependency(%q<hoe>, ["~> 2.9"])
    else
      s.add_dependency(%q<minitest>, [">= 2.3.1"])
      s.add_dependency(%q<minitest>, ["~> 2"])
      s.add_dependency(%q<isolate>, ["~> 3"])
      s.add_dependency(%q<ZenTest>, ["~> 4"])
      s.add_dependency(%q<hoe>, ["~> 2.9"])
    end
  else
    s.add_dependency(%q<minitest>, [">= 2.3.1"])
    s.add_dependency(%q<minitest>, ["~> 2"])
    s.add_dependency(%q<isolate>, ["~> 3"])
    s.add_dependency(%q<ZenTest>, ["~> 4"])
    s.add_dependency(%q<hoe>, ["~> 2.9"])
  end
end
