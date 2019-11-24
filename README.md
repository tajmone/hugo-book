[![CC BY-NC-SA 4.0 License][license badge]][CC BY-NC-SA 4.0]&nbsp;
![project status][status badge]&nbsp;
![build status][travis badge]


# The Hugo Book

AsciiDoc port of _[The Hugo Book]_, written by [Kent Tessman], 2004.

Released under [CC BY-NC-SA 4.0] license with explicit permission by Kent Tessman.

Project created by [Tristano Ajmone] in 2019/09/29.


-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3" -->

- [About](#about)
- [Why AsciiDoc?](#why-asciidoc)
- [License](#license)
- [Acknowledgements](#acknowledgements)
- [Credits](#credits)
    - [Base16 Color Schemes](#base16-color-schemes)
    - [The Asciidoctor Project](#the-asciidoctor-project)
        - [Asciidoctor Extensions Lab](#asciidoctor-extensions-lab)
    - [Asciidoctor Backends](#asciidoctor-backends)
- [External Links](#external-links)

<!-- /MarkdownTOC -->

-----

# About

_[The Hugo Book]_ is the official manual for the [Hugo Interactive Fiction] authoring system (1995–2006), a cross platform system for creating and playing text adventures with advanced multimedia support, created by Kent Tessman and released under BSD 2-Clause License.

Historically, _The Hugo Book_ was distributed in PDF format, which can be downloaded in the Hugo section of the [IF Archive]:

- https://www.ifarchive.org/indexes/if-archive/programming/hugo/manuals/

I wanted to port the book to AsciiDoc using an open source license, so I e-mailed [Kent Tessman]; he kindly granted his permission to do so under [CC BY-NC-SA 4.0], and sent me his latest Word document of the _The Hugo Book_.

I chose not to share the original Word document in the repository due to the potential leaks of personal information associated with MS Word files.
For comparison between the AsciiDoc version and the original book, please refer to the PDF version from the IF Archive.

# Why AsciiDoc?

These are the main reasons why I wanted to make _The Hugo Book_ available in AsciiDoc format (via the [Asciidoctor] Ruby implementation).

- __Multiple output formats support__

    AsciiDoc source documents are very versatile when it comes to their final use, for they can be converted to a variety of output formats beside PDF, including HTML based formats (websites, ePub, Mobi/Kindle, Microsoft CHM Help), and many other formats.

    For example, someone wishing to create a dedicated Hugo IDE could reuse these sources to include _The Hugo Book_ as a CHM Help file.
    Someone wishing to create a website dedicated to IF documents could just drop these sources into the CMS sources folder and be up and running.

    Many CMSs and static website generators support AsciiDoc, which means that these sources can be simply dropped in the sources folder and they're ready to be served online as website pages.

    The list of supported output formats will grow in time, as the AsciiDoc projects evolve.
    Since the advent of the [Asciidoctor] implementation we've seen a new wave of interest in the AsciiDoc format, and many new projects have come into being, including new backends for output formats.

- __Separation between styles and contents__.

    By separating contents from styles, AsciiDoc allows end users to decide how to customize the final look of the output document via custom templates.
    Also, AsciiDoc allows end users to choose which syntax highlighter to employ for beautifying the code examples of the document, thus greatly simplifying the task of colouring the Hugo code examples of the book, across different output formats.

- __Collaborative editing.__

    Being a text-based syntax, AsciiDoc documents can be version controlled like any other source files, which makes it simple to edit documents collaboratively via tools like Git, Fossil, Mercurial, etc.

    Since [Hugo] is an open source software, people might wish to take on its development, or create new derivative tools based on the Hugo code-base.
    In such cases, having access to _The Hugo Book_ in AsciiDoc source format is going to be a blessing for the sake of documenting the project.

    The ability to version-control the book also simplifies translating it to other languages by working directly overt the original English sources and being able to easily track changes, resolve conflicts, and undo changes.

- __Inter-document and cross-project operativity.__

    Having access to the AsciiDoc sources of _The Hugo Book_ is going to simplify including the book (or parts of it) in other documents or projects.
    This is going to be very helpful in projects aiming to collect various IF-related documents and books under one umbrella (e.g. documentation websites, IF wikis and encyclopaedias, etc.).

- __Long-term document preservation.__

    The AsciiDoc standard is well established enough to grant that in the future it will always be possible to reproduce or recover an AsciiDoc document.
    Unlike proprietary document file formats, AsciiDoc is both open source and text-based, which is a guarantee that there will always be a backward compatible tool capable of parsing AsciiDoc sources.
    Since AsciiDoc sources only deal with contents and their semantics, it's going to be easy to convert them to other formats in a lossless manner.

    Hopefully, this will contribute to the preservation of _The Hugo Book_ legacy in Interactive Fiction.

- __Privacy and security concerns.__

    Unlike proprietary document formats like Word and PDF — which [embed private user- and machine-details that pose a privacy and security threat]  — the AsciiDoc format doesn't leak any private information unintended for public disclosure.
    Being a text-based document format, there here are no hidden tags and metadata containing private information — what you see in the source document is all there is to it.

I strongly believe that AsciiDoc is an excellent format for sharing documents, and I hope that in the future we'll see more IF-related documents being ported to AsciiDoc, which could greatly simplify preservation and maintenance of the IF literature and its re-usability across different projects and output formats.

# License

- [`./LICENSE/`][LICENSE]

Explicit permission was granted from [Kent Tessman] to republish _The Hugo Book_ under the terms of the [CC BY-NC-SA 4.0] license.

> The Hugo Book (c) by Kent Tessman, 2004.
>
> The Hugo Book is licensed under a
> Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
>
> You should have received a copy of the license along with this
> work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.

# Acknowledgements

I would like to thank...

- __[Kent Tessman]__ for creating Hugo and donating it to the mankind by open sourcing it, and for having granted me permission to republish _The Hugo Book_ under an open source license.
Hugo is a beautiful tool, as well an historical pillar of the Interactive Fiction history.

- __[The people at the IF Archive]__, for their constant struggle and support in the quest for the preservation of IF historical material and heritage.

- __[Dan Allen]__ and the __[Asciidoctor Project team]__, for their relentless dedication to the development of [Asciidoctor] and the AsciiDoc echo-system.

# Credits

This project also employs resources created by third parties.

## Base16 Color Schemes

- [`/assets_src/sass/`](./assets_src/sass/)

For the Sass/CSS themes this project uses the following Base16 color schemes:

- _Base16 Eighties_ — by [Chris Kempson]  (MIT License).

The __Base16__ project (MIT License) was created by Chris Kempson:

- http://chriskempson.com/projects/base16

The Base16 SCSS schemes are taken from the __Base16 Sass__ project by [Tristano Ajmone]:

- https://github.com/tajmone/Base16-Sass

__Base16 Sass__ is released under MIT License:

    MIT License

    Copyright (c) 2019 Tristano Ajmone <tajmone@gmail.com>
    https://github.com/tajmone/Base16-Sass

    Copyright (c) 2012 Chris Kempson (http://chriskempson.com)
    https://github.com/chriskempson/base16-builder

For more details and the full license text, see:

- [`/assets_src/sass/README.md`](./assets_src/sass/README.md#credits)

## The Asciidoctor Project

This project employs various assets taken from [The Asciidoctor Project], mostly in adapted form. For more details and the full license texts, see:

- [`/assets/adoc/README.md`](./assets/adoc/README.md#credits)

### Asciidoctor Extensions Lab

- [`/assets/adoc/highlight-treeprocessor_mod.rb`][HL rb]

The __Highlight TreeProcessor__ Asciidoctor extension (Ruby) was adapted by [Tristano Ajmone] from the original [`highlight-treeprocessor.rb`][rb upstream] file from the __Asciidoctor Extensions Lab__:

- https://github.com/asciidoctor/asciidoctor-extensions-lab

Released under MIT License:

    The MIT License

    Copyright (C) 2014-2016 The Asciidoctor Project

## Asciidoctor Backends

- [`/assets/adoc/haml/`][haml]

The files inside the [`/haml/`][haml] folder were adapted by [Tristano Ajmone] from the original [Haml HTML5 templates] taken from the
__Asciidoctor Backends__ project:

- https://github.com/asciidoctor/asciidoctor-backends

Released under MIT License:

    The MIT License

    Copyright (C) 2012-2016 Dan Allen and the Asciidoctor Project


# External Links

- [Hugo website]
- [IFWiki » Hugo]
- [IF Archive » Hugo]
    + _[The Hugo Book]_ (PDF) — for Hugo v3.1, by Kent Tessman, 2004.
- [curiousdannii/hugo] — Hugo sources on GitHub, courtesy of [Dannii Willis].
- [Awesome IF » Hugo]
- [Not Dead Hugo] — an active blog with precious news on Hugo.

<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

[embed private user- and machine-details that pose a privacy and security threat]: https://www.sans.org/reading-room/whitepapers/privacy/document-metadata-silent-killer-32974 "Read Larry Pesce's paper 'Document Metadata, the Silent Killer...' (2008)"

<!-- CC BY-NC-SA 4.0 -->

[CC BY-NC-SA 4.0]: https://creativecommons.org/licenses/by-nc-sa/4.0/ "View the CC BY-NC-SA 4.0 License at Creative Commons"

<!-- badges -->

[license badge]: https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-00b5da.svg
[status badge]: https://img.shields.io/badge/status-WIP-orange "Currently being ported to AsciiDoc in dev branch"
[travis badge]: https://travis-ci.org/tajmone/hugo-book.svg?branch=draft "Travis CI Build Status for Asciidoctor Build and EditorConfig Validation"

<!-- 3rd party links -->

[Asciidoctor]: https://asciidoctor.org/ "Visit Asciidoctor website"
[IF Archive]: https://www.ifarchive.org/ "Visit the IF Archive"

<!-- 3rd party upstream links -->

[Haml HTML5 templates]: https://github.com/asciidoctor/asciidoctor-backends/tree/master/haml/html5
[rb upstream]: https://github.com/asciidoctor/asciidoctor-extensions-lab/blob/18bdf62/lib/highlight-treeprocessor.rb "View original source file"

<!-- Hugo links official -->

[Hugo]: https://www.generalcoffee.com/hugo/gethugo.html "Visit the Hugo website"
[Hugo Interactive Fiction]: https://www.generalcoffee.com/hugo/gethugo.html "Visit the Hugo website"
[Hugo website]: https://www.generalcoffee.com/hugo/gethugo.html "Visit the Hugo website"

<!-- Hugo links 3rd party -->

[Awesome IF » Hugo]: https://github.com/tajmone/awesome-interactive-fiction#hugo "View Hugo entry at the Awesome Interactive Fiction repository"
[curiousdannii/hugo]: https://github.com/curiousdannii/hugo "Visit the Hugo sources repository on GitHub, maintained by Dannii Willis"
[IF Archive » Hugo]: https://www.ifarchive.org/indexes/if-archive/programming/hugo/ "Visit the IF Archive section on Hugo"
[IFWiki » Hugo]: http://ifwiki.org/index.php/Hugo "Go to the Hugo page on IFWiki"
[Not Dead Hugo]: http://notdeadhugo.blogspot.com/ "Visit the 'Not Dead Hugo' blog"
[The Hugo Book]: https://www.ifarchive.org/if-archive/programming/hugo/manuals/hugo_book.pdf "Download 'The Hugo Book' (PDF) for Hugo v3.1"

<!-- project files -->

[HL rb]: ./assets/adoc/highlight-treeprocessor_mod.rb "View source file"
[LICENSE]: ./LICENSE "View License file"

<!-- project folders -->

[haml]: ./assets/adoc/haml/ "Navigate to the Haml HTML5 templates folder"

<!-- people -->

[Chris Kempson]: http://chriskempson.com "Visit Chris Kempson's website"
[Dan Allen]: https://github.com/mojavelinux "View Dan Allen's GitHub profile"
[Dannii Willis]: https://github.com/curiousdannii "View Dannii Willis's GitHub profile"
[Kent Tessman]: https://github.com/tessman "View Kent Tessman's GitHub profile"
[Tristano Ajmone]: https://github.com/tajmone "View Tristano Ajmone's GitHub profile"

<!-- organizations -->

[Asciidoctor Project team]: https://github.com/orgs/asciidoctor/people "View the profile of The Asciidoctor Project on GitHub"
[The Asciidoctor Project]: https://github.com/orgs/asciidoctor/people "View the profile of The Asciidoctor Project on GitHub"
[The people at the IF Archive]: https://www.ifarchive.org/misc/about.html "Learn more about the people behind the IF Archive"


<!-- EOF -->
