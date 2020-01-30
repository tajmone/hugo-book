[![CC BY-NC-SA 4.0 License][license badge]][CC BY-NC-SA 4.0]&nbsp;
![book version][release badge]&nbsp;
![build status][travis badge]

# The Hugo Book

AsciiDoc port of _[The Hugo Book]_, written by [Kent Tessman], 2004.

Released under [CC BY-NC-SA 4.0] license with explicit permission by Kent Tessman.

Project created by [Tristano Ajmone] in 2019/09/29.

- https://github.com/tajmone/hugo-book

To read _The Hugo Book_ on-line, as a single HTML document:

- https://git.io/hugo-book

-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3" -->

- [Project Contents](#project-contents)
- [About](#about)
    - [AsciiDoc Sources](#asciidoc-sources)
    - [Single-File AsciDoc Version](#single-file-ascidoc-version)
    - [HTML Version](#html-version)
    - [Converting to Other Formats](#converting-to-other-formats)
    - [Releases and Versioning](#releases-and-versioning)
- [Why AsciiDoc?](#why-asciidoc)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)
- [Credits](#credits)
    - [Base16 Colour Schemes](#base16-colour-schemes)
    - [Base2Tone Colour Schemes](#base2tone-colour-schemes)
    - [The Asciidoctor Project](#the-asciidoctor-project)
        - [Asciidoctor Extensions Lab](#asciidoctor-extensions-lab)
        - [Asciidoctor Backends](#asciidoctor-backends)
- [External Links](#external-links)

<!-- /MarkdownTOC -->

-----

# Project Contents

- [`/assets/`][assets] — resources required to build the book.
- [`/assets_src/`][assets_src] — sources of buildable assets.
- [`/docs/`][docs] — HTML version of _The Hugo Book_, served online via [GitHub Pages].
- [`/docs_src/`][docs_src] — AsciiDoc sources and build scripts.
- [`CHANGES.md`][CHANGES.md] — list of changes from the original book.
- [`CONVENTIONS.md`][CONVENTIONS.md] — formatting, styles and code conventions.
- [`hugo-book.asciidoc`][HB Adoc] — standalone preprocessed AsciiDoc version of _The Hugo Book_.
- [`hugo-book.html`][HB HTML] — _The Hugo Book_, HTML release.
- [`LICENSE`][LICENSE] —  [CC BY-NC-SA 4.0] license.
- [`validate.sh`][validate.sh] — [EditorConfig] code styles validation via [EClint].


# About

_[The Hugo Book]_ is the official manual for the [Hugo Interactive Fiction] authoring system (1995–2006), a cross platform system for creating and playing text adventures with advanced multimedia support, created by [Kent Tessman] and released under BSD 2-Clause License.

Historically, _The Hugo Book_ was distributed in PDF format, which can be downloaded in the Hugo section of the [IF Archive]:

- https://www.ifarchive.org/indexes/if-archive/programming/hugo/manuals/

I wanted to port the book to AsciiDoc using an open source license, so I e-mailed [Kent Tessman]; he kindly granted his permission to do so under [CC BY-NC-SA 4.0], and sent me his latest Word document of the _The Hugo Book_.

I chose not to share the original Word document in the repository due to the [potential leaks of personal information associated with MS Word files].
For comparison between the AsciiDoc version and the original book, please refer to the [PDF version from the IF Archive].

Having the chance and honour to consult directly the original author, I grabbed the opportunity to fix a few typos and propose some minor edits here and there, all of which were supervised and approved by [Kent Tessman] — all changes are listed in the [`CHANGES.md`][CHANGES.md] document, with links to the repository Issues were these changes were proposed, discussed and approved.

None of these changes are significant beyond what might be part of an _Errata_, so this AsciiDoc port of _The Hugo Book_ still qualifies as the _first edition_, but was revised in January, 2020 with the author's supervision.

## AsciiDoc Sources

- [`/docs_src/`][docs_src] — AsciiDoc sources and build scripts.

_The Hugo Book_ was split into multiple AsciiDoc files to simplify maintainance as well as to allow republishing single chapters individually.

To convert the AsciiDoc sources into HTML, run the [`docs_src/build.sh`][build.sh] script.

## Single-File AsciDoc Version

For convenience, the [`docs_src/build.sh`][build.sh] script also creates a single-file AsciiDoc version, by preprocessing the source files via the __[AsciiDoc Coalescer]__:

- [`hugo-book.asciidoc`][HB Adoc]

This standalone version is provided for simplifying handling the book as a single source in external projects —

> __WARNING__ — _Do not edit the preprocessed file, for all changes would be lost on the next build!_
> All changes must be submitted to the sources in the [`/docs_src/`][docs_src] folder.

## HTML Version

Currently _The Hugo Book_ is available only in HTML format in this project:

- [`hugo-book.html`][HB HTML]

We're planning to add more output formats to the build toolchain, at some point in the future — any help on this front is highly appreciated.

## Converting to Other Formats

AsciiDoc being format-agnostic, you should be able to build the book with any Asciidoctor backend, out of the box.

To optimize the final look of the book, you might have to tweak the template used by the backend/converter to cover the custom styles adopted in this project (see [`CONVENTIONS.md`][CONVENTIONS.md]).
Furthermore, to beautify the Hugo code examples you'll probably have to create your own Hugo syntax definition for the syntax highlighter employed by the specific backend/converter.

If you've converted _The Hugo Book_ to other formats, please let use know about it.

## Releases and Versioning

The project adopts [Semantic Versioning 2.0.0]  (aka _SemVer_) as its releases versioning scheme.
Release versions refer to the AsciiDoc sources of _The Hugo Book_, for these constitute the core of the project — all other assets (templates, stylesheets, etc.) and converted documents (HTML, etc.) are just added bonuses.

Any changes to the AsciiDoc sources will result in a version change and a new tagged release, whereas changes to other contents won't.
Commits on `master` branch are not limited to tagged releases, therefore all contents except AsciiDoc sources might undergo any number of changes between tagged releases (including _Hugo Book_ documents in formats like HTML, which might undergo template and stylesheets updates).

End users who rely on this repository for their own projects can count on the following expectations:

- `master` branch will always provide:
    + the latest version of the AsciiDoc book.
    + the most up-to-date HTML version of the book.
- Tags can be used to checkout specific versions of the AsciiDoc book, to ensure compatibility with your project tool chain.


# Why AsciiDoc?

These are the main reasons why I wanted to make _The Hugo Book_ available in AsciiDoc format (via the [Asciidoctor] Ruby implementation).

- __Multiple output formats support__

    AsciiDoc source documents are very versatile when it comes to their final use, for they can be converted to a variety of output formats beside PDF, including HTML based formats (websites, ePub, Mobi/Kindle, Microsoft CHM Help), and many other formats.

    For example, someone wishing to create a dedicated Hugo IDE could reuse these sources to include _The Hugo Book_ as a CHM Help file.

    Many CMSs and static website generators support AsciiDoc, which means that someone wishing to create a website dedicated to IF documents could just drop these sources into the CMS sources folder and be up and running.

    The list of supported output formats will grow in time, as the AsciiDoc projects evolve.
    Since the advent of the [Asciidoctor] implementation we've seen a new wave of interest in the AsciiDoc format, and many new projects have come into being, including new output formats backends.

- __Separation between styles and contents__.

    By separating contents from styles, AsciiDoc allows end users to decide how to customize the final look of the output document via custom templates.
    Also, AsciiDoc allows end users to choose which syntax highlighter to employ for beautifying the code examples of the document, thus greatly simplifying the task of colouring the Hugo code examples of the book, across different output formats.

- __Collaborative editing.__

    Being a text-based syntax, AsciiDoc documents can be version controlled like any other source files, which makes it simple to edit documents collaboratively via tools like Git, Fossil, Mercurial, etc.

    Since [Hugo] is an open source software, people might wish to take on its development, or create new derivative tools based on the Hugo sources.
    In such cases, having access to _The Hugo Book_ in AsciiDoc format is going to be a blessing for the sake of documenting the project.

    The ability to version-control the book also simplifies translating it to other languages by working directly overt the original English sources and being able to easily track changes, resolve conflicts, and undo changes.

- __Inter-document and cross-project operativity.__

    Having access to the AsciiDoc sources of _The Hugo Book_ is going to simplify including the book (or parts of it) in other documents or projects.
    This is going to be very helpful in projects aiming to collect various IF-related documents and books under one umbrella (e.g. documentation websites, IF wikis and encyclopaedias, etc.).

- __Long-term document preservation.__

    The AsciiDoc standard is well established enough to grant that in the future it should always be possible to reproduce or recover an AsciiDoc document.
    Unlike proprietary document file formats, AsciiDoc is both open source and text-based, which is a guarantee that there will always be a backward compatible tool capable of parsing AsciiDoc sources.
    Since AsciiDoc sources only deal with contents and their semantics, it's going to be easy to convert them to other formats in a lossless manner.

    Hopefully, this will contribute to the preservation of _The Hugo Book_ legacy in Interactive Fiction.

- __Privacy and security concerns.__

    Unlike proprietary document formats like Word and PDF — which [embed private user- and machine-details that pose a privacy and security threat]  — the AsciiDoc format doesn't leak any private information unintended for public disclosure.
    Being a text-based document format, there here are no hidden tags and metadata containing private information — what you see in the source document is all there is to it.

I strongly believe that AsciiDoc is an excellent format for sharing documents, and I hope that in the future we'll see more IF-related documents being ported to AsciiDoc, which could greatly simplify preservation and maintenance of the IF literature and its re-usability across different projects and output formats.

# Contributing

The project is open to contributions.
All pull requested should be made to the [`dev`][dev] branch.

Just ensure that your pull request passes the Travis CI build tests, which you can verify locally by running the [`validate.sh`][validate.sh] script, before submitting the PR.

There are no plans to update the book contents, so contributions should be limited to AsciiDoc formatting and styling, the build chain, supporting new output formats, improving existing templates, and similar enhancements that don't affect the actual text of the book.

If you really want to work on the book contents, you should do so in a fork of this repository, because the goal of this project is to provide the latest _Hugo Book_ edition officially approved by the original author, [Kent Tessman].

# License

- [`LICENSE`][LICENSE]

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
For the full licenses text, see the README file in the folders hosting the specific resources — below is just a quick credits summary.

## Base16 Colour Schemes

- [`/assets_src/sass/`](./assets_src/sass/)

For the Sass/CSS themes this project uses the following Base16 colour schemes:

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

## Base2Tone Colour Schemes

- [`/assets_src/sass/`](./assets_src/sass/)

For the Sass/CSS themes this project uses the following Base2Tone colour schemes:

- _Base2Tone Lake_ — by [Bram de Haan]  (MIT License).

The __Base2Tone__ project was created by Bram de Haan ([@atelierbram]), based on [Simurai]'s __[Duotone Themes]__ for the [Atom editor]:

- https://github.com/atelierbram/Base2Tone

The project is released under MIT License:

    The MIT License (MIT)

    Copyright (c) 2016 Bram de Haan

For more details and the full license text, see:

- [`/assets_src/sass/README.md`](./assets_src/sass/README.md#credits)


## The Asciidoctor Project

This project employs various assets taken from [The Asciidoctor Project], mostly in adapted form. For more details and the full license texts, see:

- [`/assets/adoc/README.md`](./assets/adoc/README.md#credits)

### Asciidoctor Extensions Lab

- https://github.com/asciidoctor/asciidoctor-extensions-lab

The following Asciidoctor extensions and scripts were taken from the __[Asciidoctor Extensions Lab]__:

- [`/assets/adoc/asciidoc-coalescer.rb`][coalescer.rb] — __AsciiDoc Coalescer__.
- [`/assets/adoc/highlight-treeprocessor_mod.rb`][HL rb] — __Highlight TreeProcessor__.

Released under MIT License:

    The MIT License

    Copyright (C) 2014-2016 The Asciidoctor Project

The __Highlight TreeProcessor__ Asciidoctor extension (Ruby) was adapted by [Tristano Ajmone] from the original [`highlight-treeprocessor.rb`][rb upstream] file.

### Asciidoctor Backends

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
- [Awesome IF » Hugo]
- [Not Dead Hugo] — an active blog with precious news on Hugo.

Other Hugo-related projects on GitHub:

- Hugo sources:
    + [curiousdannii/hugo] — courtesy of [Dannii Willis].
    + [tajmone/hugo] — my edited fork of curiousdannii/hugo.
- [tajmone/hugo-library] — The Hugo Library.
- [tajmone/sublime-hugo-if] — A WIP Hugo syntax for [Sublime Text 3].

<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

[potential leaks of personal information associated with MS Word files]: https://www.sans.org/reading-room/whitepapers/privacy/document-metadata-silent-killer-32974 "Read Larry Pesce's paper 'Document Metadata, the Silent Killer...' (2008)"
[embed private user- and machine-details that pose a privacy and security threat]: https://www.sans.org/reading-room/whitepapers/privacy/document-metadata-silent-killer-32974 "Read Larry Pesce's paper 'Document Metadata, the Silent Killer...' (2008)"

[PDF version from the IF Archive]: https://www.ifarchive.org/if-archive/programming/hugo/manuals/hugo_book.pdf "'The Hugo Book' in PDF format at the IF Archive"

<!-- CC BY-NC-SA 4.0 -->

[CC BY-NC-SA 4.0]: https://creativecommons.org/licenses/by-nc-sa/4.0/ "View the CC BY-NC-SA 4.0 License at Creative Commons"

<!-- badges -->

[license badge]: https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-00b5da.svg
[release badge]: https://img.shields.io/badge/release-1.0.0-brightgreen "AsciiDoc book version"
[travis badge]: https://travis-ci.org/tajmone/hugo-book.svg?branch=master "Travis CI Build Status for Asciidoctor Build and EditorConfig Validation"

<!-- 3rd party links -->

[Asciidoctor]: https://asciidoctor.org/ "Visit Asciidoctor website"
[Atom editor]: https://atom.io "Visit Atom website"
[Duotone Themes]: http://simurai.com/projects/2016/01/01/duotone-themes
[EClint]: https://www.npmjs.com/package/eclint "Visit EClint page at NPM"
[EditorConfig]: https://editorconfig.org/ "Visit EditorConfig website"
[GitHub Pages]: https://pages.github.com/ "Visit GitHub Pages website"
[IF Archive]: https://www.ifarchive.org/ "Visit the IF Archive"
[Semantic Versioning 2.0.0]: https://semver.org/ "Lear more about Semantic Versioning at semver.org"
[Sublime Text 3]: https://www.sublimetext.com/ "Visit Sublime Text website"

<!-- 3rd party upstream links -->

[Asciidoctor Extensions Lab]: https://github.com/asciidoctor/asciidoctor-extensions-lab "Visit the Asciidoctor Extensions Lab project on GitHub"
[Haml HTML5 templates]: https://github.com/asciidoctor/asciidoctor-backends/tree/master/haml/html5
[rb upstream]: https://github.com/asciidoctor/asciidoctor-extensions-lab/blob/18bdf62/lib/highlight-treeprocessor.rb "View original source file"

<!-- Hugo links official -->

[Hugo]: https://www.generalcoffee.com/hugo/gethugo.html "Visit the Hugo website"
[Hugo Interactive Fiction]: https://www.generalcoffee.com/hugo/gethugo.html "Visit the Hugo website"
[Hugo website]: https://www.generalcoffee.com/hugo/gethugo.html "Visit the Hugo website"

<!-- Hugo links 3rd party -->

[Awesome IF » Hugo]: https://github.com/tajmone/awesome-interactive-fiction#hugo "View Hugo entry at the Awesome Interactive Fiction repository"
[IF Archive » Hugo]: https://www.ifarchive.org/indexes/if-archive/programming/hugo/ "Visit the IF Archive section on Hugo"
[IFWiki » Hugo]: http://ifwiki.org/index.php/Hugo "Go to the Hugo page on IFWiki"
[Not Dead Hugo]: http://notdeadhugo.blogspot.com/ "Visit the 'Not Dead Hugo' blog"
[The Hugo Book]: https://www.ifarchive.org/if-archive/programming/hugo/manuals/hugo_book.pdf "Download 'The Hugo Book' (PDF) for Hugo v3.1"

<!-- Hugo GitHub -->

[curiousdannii/hugo]: https://github.com/curiousdannii/hugo "Visit the Hugo sources repository on GitHub, maintained by Dannii Willis"
[tajmone/hugo]: https://github.com/tajmone/hugo "Visit the Hugo sources repository on GitHub, maintained by Tristano Ajmone"
[tajmone/hugo-library]: https://github.com/tajmone/hugo-library "Visit the Hugo Library repository on GitHub, maintained by Tristano Ajmone"
[tajmone/sublime-hugo-if]: https://github.com/tajmone/sublime-hugo-if "Visit the Sublime Hugo IF repository on GitHub"

<!-- project files -->

[build.sh]: ./docs_src/build.sh "View script source"
[CHANGES.md]: ./CHANGES.md "View file"
[coalescer.rb]: ./assets/adoc/asciidoc-coalescer.rb "View Ruby source file"
[CONVENTIONS.md]: ./CONVENTIONS.md "View file"
[HB Adoc]: ./hugo-book.asciidoc "View the Hugo Book single-file AsciiDoc preprocessed version"
[HB HTML]: ./hugo-book.html "View the Hugo Book in HTML format"
[HL rb]: ./assets/adoc/highlight-treeprocessor_mod.rb "View Ruby source file"
[LICENSE]: ./LICENSE "View file"
[LICENSE]: ./LICENSE "View License file"
[validate.sh]: ./validate.sh "View script source"

[AsciiDoc Coalescer]: ./assets/adoc/asciidoc-coalescer.rb "View the AsciiDoc Coalescer script (Ruby)"

<!-- project folders -->

[assets]: ./assets/ "Navigate to folder"
[assets_src]: ./assets_src/ "Navigate to folder"
[docs]: ./docs/ "Navigate to folder"
[docs_src]: ./docs_src/ "Navigate to folder"
[haml]: ./assets/adoc/haml/ "Navigate to the Haml HTML5 templates folder"

<!-- repo links -->

[dev]: https://github.com/tajmone/hugo-book/tree/dev "View the 'dev' branch of the 'hugo-book' repository"

<!-- people -->

[@atelierbram]: https://github.com/atelierbram "View @atelierbram's GitHub profile"
[Bram de Haan]: https://github.com/atelierbram "View Bram de Haan's GitHub profile"
[Chris Kempson]: http://chriskempson.com "Visit Chris Kempson's website"
[Dan Allen]: https://github.com/mojavelinux "View Dan Allen's GitHub profile"
[Dannii Willis]: https://github.com/curiousdannii "View Dannii Willis's GitHub profile"
[Kent Tessman]: https://github.com/tessman "View Kent Tessman's GitHub profile"
[Simurai]: https://github.com/simurai "View simurai's GitHub profile"
[Tristano Ajmone]: https://github.com/tajmone "View Tristano Ajmone's GitHub profile"

<!-- organizations -->

[Asciidoctor Project team]: https://github.com/orgs/asciidoctor/people "View the profile of The Asciidoctor Project on GitHub"
[The Asciidoctor Project]: https://github.com/orgs/asciidoctor/people "View the profile of The Asciidoctor Project on GitHub"
[The people at the IF Archive]: https://www.ifarchive.org/misc/about.html "Learn more about the people behind the IF Archive"


<!-- EOF -->
