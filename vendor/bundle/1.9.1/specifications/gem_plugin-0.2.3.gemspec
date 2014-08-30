# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{gem_plugin}
  s.version = "0.2.3"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = [%q{Zed A. Shaw}]
  s.cert_chain = [%q{-----BEGIN CERTIFICATE-----
MIIDUDCCAjigAwIBAgIBADANBgkqhkiG9w0BAQUFADBOMRwwGgYDVQQDDBNtb25n
cmVsLWRldmVsb3BtZW50MRkwFwYKCZImiZPyLGQBGRYJcnVieWZvcmdlMRMwEQYK
CZImiZPyLGQBGRYDb3JnMB4XDTA3MDkxNjEwMzI0OVoXDTA4MDkxNTEwMzI0OVow
TjEcMBoGA1UEAwwTbW9uZ3JlbC1kZXZlbG9wbWVudDEZMBcGCgmSJomT8ixkARkW
CXJ1Ynlmb3JnZTETMBEGCgmSJomT8ixkARkWA29yZzCCASIwDQYJKoZIhvcNAQEB
BQADggEPADCCAQoCggEBAMb9v3B01eOHk3FyypbQgKXzJplUE5P6dXoG+xpPm0Lv
P7BQmeMncOwqQ7zXpVQU+lTpXtQFTsOE3vL7KnhQFJKGvUAkbh24VFyopu1I0yqF
mGu4nRqNXGXVj8TvLSj4S1WpSRLAa0acLPNyKhGmoV9+crqQypSjM6XKjBeppifo
4eBmWGjiJEYMIJBvJZPJ4rAVDDA8C6CM1m3gMBGNh8ELDhU8HI9AP3dMIkTI2Wx9
9xkJwHdroAaS0IFFtYChrwee4FbCF1FHDgoTosMwa47DrLHg4hZ6ojaKwK5QVWEV
XGb6ju5UqpktnSWF2W+Lvl/K0tI42OH2CAhebT1gEVUCAwEAAaM5MDcwCQYDVR0T
BAIwADALBgNVHQ8EBAMCBLAwHQYDVR0OBBYEFGHChyMSZ16u9WOzKhgJSQ9lqDc5
MA0GCSqGSIb3DQEBBQUAA4IBAQA/lfeN2WdB1xN+82tT7vNS4HOjRQw6MUh5yktu
GQjaGqm0UB+aX0Z9y0B0qpfv9rj7nmIvEGiwBmDepNWYCGuW15JyqpN7QVVnG2xS
Mrame7VqgjM7A+VGDD5In5LtWbM/CHAATvvFlQ5Ph13YE1EdnVbZ65c+KQv+5sFY
Q+zEop74d878uaC/SAHHXS46TiXneocaLSYw1CEZs/MAIy+9c4Q5ESbGpgnfg1Ad
6lwl7k3hsNHO/+tZzx4HJtOXDI1yAl3+q6T9J0yI3z97EinwvAKhS1eyOI2Y5eeT
tbQaNYkU127B3l/VNpd8fQm3Jkl/PqCCmDBQjUszFrJEODug
-----END CERTIFICATE-----
}, %q{-----BEGIN CERTIFICATE-----
MIIDPzCCAiegAwIBAgIBADANBgkqhkiG9w0BAQUFADBOMRwwGgYDVQQDDBNtb25n
cmVsLWRldmVsb3BtZW50MRkwFwYKCZImiZPyLGQBGRYJcnVieWZvcmdlMRMwEQYK
CZImiZPyLGQBGRYDb3JnMB4XDTA3MDkxNjEwMzMwMFoXDTA4MDkxNTEwMzMwMFow
PTENMAsGA1UEAwwEZXZhbjEYMBYGCgmSJomT8ixkARkWCGNsb3VkYnVyMRIwEAYK
CZImiZPyLGQBGRYCc3QwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDk
LQijz2fICmev4+9s0WB71WzJFYCUYFQQxqGlenbxWut9dlPSsBbskGjg+UITeOXi
cTh3MTqAB0i1LJyNOiyvDsAivn7GjKXhVvflp2/npMhBBe83P4HOWqeQBjkk3QJI
FFNBvqbFLeEXIP+HiqAOiyNHZEVXMepLEJLzGrg3Ly7M7A6L5fK7jDrt8jkm+c+8
zGquVHV5ohAebGd/vpHMLjpA7lCG5+MBgYZd33rRfNtCxDJMNRgnOu9PsB05+LJn
MpDKQq3x0SkOf5A+MVOcadNCaAkFflYk3SUcXaXWxu/eCHgqfW1m76RNSp5djpKE
CgNPK9lGIWpB3CHzDaVNAgMBAAGjOTA3MAkGA1UdEwQCMAAwCwYDVR0PBAQDAgSw
MB0GA1UdDgQWBBT5aonPfFBdJ5rWFG+8dZwgyB54LjANBgkqhkiG9w0BAQUFAAOC
AQEAiKbzWgMcvZs/TPwJxr8tJ+7mSGz7+zDkWcbBl8FpQq1DtRcATh1oyTkQT7t+
rFEBYMmb0FxbbUnojQp8hIFgFkUwFpStwWBL/okLSehntzI2iwjuEtfj4ac9Q3Y2
uSdbmZqsQTuu+lEUc5C4qLK7YKwToaul+cx7vWxyk1YendcVwRlFLIBqA5cPrwo3
yyGLTHlRYn2c9PSbM1B63Yg+LqSSAa4QSU3Wv9pNdffVpvwHPVEQpO7ZDo5slQFL
Gf6+gbD/eZAvhpvmn8JlXb+LxKaFVMs2Yvrk1xOuT76SsPjEGWxkr7jZCIpsYfgQ
ALN3mi/9z0Mf1YroliUgF0v5Yw==
-----END CERTIFICATE-----
}]
  s.date = %q{2007-10-26}
  s.description = %q{A plugin system based on rubygems that uses dependencies only}
  s.email = %q{}
  s.executables = [%q{gpgen}]
  s.files = [%q{bin/gpgen}]
  s.homepage = %q{}
  s.require_paths = [%q{lib}]
  s.rubyforge_project = %q{mongrel}
  s.rubygems_version = %q{1.8.6}
  s.summary = %q{A plugin system based on rubygems that uses dependencies only}

  if s.respond_to? :specification_version then
    s.specification_version = 2

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
    else
    end
  else
  end
end
