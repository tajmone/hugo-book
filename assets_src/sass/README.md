# Sass Source Files

The Sass sources to build the custom CSS stylesheets for _The Hugo Book_.


-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3" -->

- [System Requirements](#system-requirements)
    - [Installing Dart Sass](#installing-dart-sass)
- [Credits](#credits)
    - [Base16 Color Schemes](#base16-color-schemes)
    - [Base16 Sass](#base16-sass)

<!-- /MarkdownTOC -->

-----

# System Requirements

This project uses [Dart Sass] to compile the CSS stylesheets, because starting from March 26, 2019 [Ruby Sass] is no longer maintained.

Since Dart Sass behavior is slightly different from Ruby Sass, anyone still working with Ruby Sass must ensure to switch to Dart Sass to avoid creating divergent CSS stylesheets.

## Installing Dart Sass

The easiest way to install Dart Sass on Windows, and keep it always updated, is to install it via [Chocolatey]/[Chocolatey GUI]:

- https://chocolatey.org/packages/sass


# Credits

## Base16 Color Schemes

The Sass/CSS themes use the following Base16 color schemes:

- _Base16 Eighties_ — by [Chris Kempson].

The __Base16__ project was created by Chris Kempson:

- http://chriskempson.com/projects/base16/

The above schemes are imported via the __Base16 Sass__ project (below), which duely credits the upstream __Base16__ project in its license.

## Base16 Sass

The following Base16 SCSS files:

- [`_base16-eighties.scss`][b16 80s]

were taken from the __Base16 Sass__ project by Tristano Ajmone:

- https://github.com/tajmone/Base16-Sass

released under MIT License.


```
MIT License

Copyright (c) 2019 Tristano Ajmone <tajmone@gmail.com>
https://github.com/tajmone/Base16-Sass

Copyright (c) 2012 Chris Kempson (http://chriskempson.com)
https://github.com/chriskempson/base16-builder

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```



<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

<!-- Base16 Sass sources -->

[b16 80s]: ./_base16-eighties.scss "View SCSS source"
[b16 Google]: ./_base16-google-dark.scss "View SCSS source"


<!-- dependencies -->

[Sass]: https://sass-lang.com "Visit Sass website"
[Ruby Sass]: https://github.com/sass/ruby-sass
[Dart Sass]: https://github.com/sass/dart-sass
[Choco Sass]: https://chocolatey.org/packages/sass


[Chocolatey GUI]: https://chocolatey.org/packages/ChocolateyGUI
[Chocolatey]: https://chocolatey.org

<!-- external links -->

[fontface]: https://github.com/magnetikonline/sass-boilerplate/blob/702d924/fontface.scss "View upstream source file"

[base16-builder]: https://github.com/chriskempson/base16-builder

[Base16 Eighties]: https://github.com/chriskempson/base16-builder/blob/master/schemes/eighties.yml "View upstream source file"
[Base16 Google]: https://github.com/chriskempson/base16-builder/blob/master/schemes/google.yml "View upstream source file"

<!-- people -->

[Chris Kempson]: http://chriskempson.com "Visit Chris Kempson's website"
[Seth Wright]:   http://sethawright.com  "Visit Seth Wright's website"

<!-- EOF -->
