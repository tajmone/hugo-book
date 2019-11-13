# Highlight Resources

This directory tree contains assets for customizing usage of [André Simon]’s [Highlight] tool, employed to provide syntax highlighting in Asciidoctor conversion to HTML of the project documents.


-----

**Table of Contents**


<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3,4" -->

- [Folder Contents](#folder-contents)
- [Hugo Syntax Tests and Samples](#hugo-syntax-tests-and-samples)
    - [Syntax Tests](#syntax-tests)
    - [Preview Samples](#preview-samples)
- [Credits and Licenses](#credits-and-licenses)
    - [Base16 Color Schemes](#base16-color-schemes)
    - [Hugo Library](#hugo-library)

<!-- /MarkdownTOC -->

-----

# Folder Contents

- [`/langDefs/`][langDefs] — overrides Highlight default langDefs folder:
    + [`hugo.lang`][hugo.lang] v1.0.0 — Hugo syntax definition by Tristano Ajmone.
- [`base16_eighties.theme`][b16_80s] — Highlight theme: "Base16 Eighties".
- [`highlight.css`][HL.css] — Generated CSS theme from "Base16 Eighties".
- [`hugolib.h`][hugolib.h] — Sample Hugo file.
- [`hugolib.h.html`][hugolib.htm] — Sample Hugo file, highlighted output.
- [`syntax_test_all-tokens.hug`][st_all-tokens.hug] — Highlight test file.
- [`syntax_test_all-tokens.hug.html`][st_all-tokens.htm] — Highlight test file, highlighted output.
- [`test.sh`][test.sh] — Bash script to execute tests and convert source to highlighted HTML.
- [`tokens-list.hug`][tokensL.hug] — Sample of all Hugo tokens covered by the syntax.
- [`tokens-list.hug.html`][tokensL.htm] — Sample of all Hugo tokens, highlighted output.

# Hugo Syntax Tests and Samples

This folder, beside containing the required assets for the _Hugo Book_ HTML conversion toolchain, also contains some tests and sample for the Hugo syntax.

To execute the tests and convert the sample to HTML, run:

- [`test.sh`][test.sh]

The script will convert all Hugo sources in this folder to syntax highlighted HTML documents, using the custom Hugo syntax from [`langDefs/hugo.lang`][hugo.lang] and the "Base16 Eighties" theme from this folder:

- [`base16_eighties.theme`][b16_80s]

The theme file was manually edited to match the actual scheme used in _The Hugo Book_ HTML template.

## Syntax Tests

The following files contain syntax test directive to verify that tokens are highlighted as expected:

- [`syntax_test_all-tokens.hug`][st_all-tokens.hug]/[`.html`][st_all-tokens.htm] — Contains full list of tokens covered by the Hugo syntax.

If any errors are encountered during the tests, a file named `errors.log` will be created in this folder.

## Preview Samples

The following files don't contain any Highlight tests, and they are intended for previewing how syntax highlighting of Hugo code look like:

- [`hugolib.h`][hugolib.h]/[`.html`][hugolib.htm] — Sample from the Hugo Library.
- [`tokens-list.hug`][tokensL.hug]/[`.html`][tokensL.htm] — Sample of all Hugo tokens covered by the syntax.

Here are [HTML Live Preview] links for the above files (in case you're viewing this on GitHub):

- [`hugolib.h.html`][hugolib.live]
- [`tokens-list.hug.html`][tokensL.live]

The hugolib sample is intended to provide a real-case example of the look and feel of highlighted code.
The tokens lists sample allows visual inspection of all the tokens covered by the Hugo syntax, to check that they are rendered correctly and that no tokens are missing.

> __NOTE__ — The `tokens-list.hug` file is auto-generated from `syntax_test_all-tokens.hug` by `test.sh` via SED.
> It's just a copy of `syntax_test_all-tokens.hug` with all test directives lines stripped out, to make the preview more readable.
>
> Don't edit the `syntax_test_all-tokens.hug` file! All changes would be overwritten and lost at each execution of `test.sh`.


# Credits and Licenses

## Base16 Color Schemes

- [`base16_eighties.theme`][b16_80s]
- [`highlight.css`][HL.css]

The Highlight theme uses the following __Base16__ color scheme:

- _Base16 Eighties_ — by [Chris Kempson], MIT License.

The __Base16__ project was created by Chris Kempson:

- http://chriskempson.com/projects/base16/

The [`base16_eighties.theme`][b16_80s] was taken from [André Simon]’s __[Highlight]__ project:

- https://gitlab.com/saalen/highlight/blob/master/themes/base16/eighties.theme

It was then tweaked to match the colors asignments scheme used in _The Hugo Book_.

The original Highlight theme was converted from YAML by [Tristano Ajmone].

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
The MIT License

Copyright (c) 2018 Tristano Ajmone
Copyright (c) Chris Kempson (http://chriskempson.com)

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
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

## Hugo Library

- [`hugolib.h`][hugolib.h]

The above sample files were taken from the __Hugo Library__ repository on GitHub:

- https://github.com/tajmone/hugo-library

The __Hugo Library__ was created by [Ken Tessman] and released as part of the __Hugo Interactive Fiction__ project under BSD 2-Clause License:

- http://www.generalcoffee.com/hugo/gethugo.html

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
BSD 2-Clause License

Copyright (c) 2011 by Kent Tessman
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

[HTML Live Preview]: http://htmlpreview.github.io/ "Visit the GitHub & BitBucket HTML Preview service website"

<!-- project files & folders -->

[langDefs]:    ./langDefs/ "Navigate to folder"
[hugo.lang]: ./langDefs/hugo.lang "View source file of the Hugo syntax definition"

[b16_80s]: ./base16_eighties.theme "View Highlight theme source"
[HL.css]: ./highlight.css "View CSS file"

[test.sh]: ./test.sh "View source script"

[hugolib.h]: ./hugolib.h "View source file"
[hugolib.htm]: ./hugolib.h.html "View HTML document"
[hugolib.live]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/assets/hl/hugolib.h.html "View document via GitHub & BitBucket HTML Preview"
[st_all-tokens.hug]: ./syntax_test_all-tokens.hug "View source file"
[st_all-tokens.htm]: ./syntax_test_all-tokens.hug.html "View HTML document"
[tokensL.hug]: ./tokens-list.hug "View source file"
[tokensL.htm]: ./tokens-list.hug.html "View HTML document"
[tokensL.live]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/assets/hl/tokens-list.hug.html "View document via GitHub & BitBucket HTML Preview"

<!-- 3rd party resources -->

[Highlight]: http://www.andre-simon.de/doku/highlight/en/highlight.php "Visit Highlight website"

<!-- people -->

[André Simon]: http://www.andre-simon.de "Visit André Simon's website"
[Chris Kempson]: http://chriskempson.com "Visit Chris Kempson's website"
[Ken Tessman]: https://github.com/tessman "View Ken Tessman's GitHub profile"
[Tristano Ajmone]: https://github.com/tajmone "View Tristano Ajmone's GitHub profile"

<!-- EOF -->
