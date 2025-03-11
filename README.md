nLab software
=============

The software underlying the [nLab](https://ncatlab.org/nlab/show/HomePage) is a heavily modified fork of [Instiki](https://github.com/parasew/instiki).
However, the code has moved quite far away from the original Instiki and now heavily relies on Python scripts that are called from Ruby.

Installation
============

We have reverse-engineered [installation instructions](INSTALL.md).

Joining in
==========

All help is very welcome!
Get in touch on the [nForum](https://nforum.ncatlab.org/).

The codebase is in maintenance mode and not actively developed.
We are generally happy to merge pull requests on the user interface as long as:
* the users like it (find out on the nForum),
* the code changes do not make the codebase more complicated to maintain.

License
=======

The original Instiki is licensed under the [same license as Ruby](https://www.ruby-lang.org/en/about/license.txt).
All code which is written by Richard Williamson, for example all code under `script/src`, is made available without any restriction whatsoever, except that this unrestricted availability is not permitted to be superseded: anybody is free to use, license, or refer to the code however they wish, except that it is not permitted to supersede the unrestricted availability of the original code referred to herewith.
