# Formatting and Style Conventions

The AsciiDoc formatting and style conventions adopted in _The Hugo Book_.


-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3" -->

- [Introduction](#introduction)
- [Footnotes](#footnotes)
    - [Handling Identical Footnotes](#handling-identical-footnotes)
    - [Footnotes in Table Cells](#footnotes-in-table-cells)
- [Titles, Headings and Captions](#titles-headings-and-captions)
    - [Book Sections](#book-sections)
        - [Sections Numbering](#sections-numbering)
    - [Title Casing](#title-casing)
    - [Sections IDs Customization](#sections-ids-customization)
- [Hugo Code](#hugo-code)
    - [Indentation Conventions](#indentation-conventions)
    - [Syntax Highlighting](#syntax-highlighting)
        - [Escapes in File Paths](#escapes-in-file-paths)
        - [Unsupported Asciidoctor Features](#unsupported-asciidoctor-features)
- [Custom Styles](#custom-styles)
    - [Block Elements](#block-elements)
    - [Inline Elements](#inline-elements)

<!-- /MarkdownTOC -->

-----

# Introduction

The following notes document the choices made in the adaptation of the book from MS Word to AsciiDoc format.
These might be useful to those interested in covering new output formats, to ensure that styles are rendered as expected in that format (via templates, stylesheets, or whatever the format uses to handle them).
And they might be even more useful to anyone wishing to further develop the book, to ensure consistency in added contents, or to update the book in view of new [Asciidoctor] features.

# Footnotes

All footnotes are [externalized] at the beginning of the source document via custom attributes on the form `:fn1:`, `:fn2:`, etc.:

```asciidoc
= Chapter Title

// >>> footnotes definitions >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

:fn1: footnote:[Note text.]

:fn2: pass:q[footnote:[Note with `inline code`.]]

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
```

These are then injected in the main text via attributes substitutions (`{fn1}`, `{fn2}`, etc.):


```asciidoc
A paragraph with footnotes{wj}{fn1} via custom attributes.{wj}{fn2}
```

As the above example shows, each footnote is preceded by a [word-joiner attribute] (`{wj}`) to prevent word wrapping from separating the footnote marker from the text to which it belongs.

This system of placing all footnotes definitions at the beginning of a chapter allows accessing all footnotes at once, without having to sift through the document to find them.

The footnote attributes of every document are named starting from 1 (`:fn1:`) regardless of the actual note number in the final document (Asciidoctor will take care of that).

For more info:

- [Asciidoctor Manual: §61. Footnotes]
- [Asciidoctor Manual: §61.1. Externalizing a Footnote]
- [Asciidoctor Manual: §A.3. Predefined Attributes for Character Replacements]

## Handling Identical Footnotes

The book contains various notes with identical text, but we opted to keep each note independent, for various reasons (although Asciidoctor supports shared footnotes references).

The main reason for this choice was in consideration of HTML-based documents (web pages, ePub, CHM Help, etc.) where notes numbers appearing in the text are actual links that take the reader to the footnote — usually placed at the end of the chapter or document, depending on the format.
Each footnote number is also a link back to the text position where the note was encountered.

If we had chosen to use a single footnote to represent identical notes, the back-link would always point to the first occurrence of the note in the book, regardless of where it was encountered, thus risking that the reader might not be able to resume reading the main text after inspecting the footnote.

Although on printed paper it might have been more elegant to avoid identical footnotes, we decided that preventing disruption of the reading experience in HTML-based formats had the priority.

For more info:

- [hugo-book #24][#24] — Handling Identical Footnotes
- [Asciidoctor Manual: §61. Footnotes]


## Footnotes in Table Cells

Numerous notes occur inside table cells.
Currently, Asciidoctor doesn't always handle them as expected, sometimes placing the footnote at the end of the cell, instead of placing it with the rest of the footnotes ([See #22][#22]).

This is a known issue with Asciidoctor and it happens when the cell is styled as AsciiDoc (`a`), which gets treated as an embedded document.
A solution has already been planned, introducing a new `b` cell style for "block-level content" (See [asciidoctor #2352]), so we just have to wait.

When the new `b` feature will be available, all occurrences of `a` styled cells will have to be changed in the _Hugo Book_ sources.

For more info:

- [hugo-book #22][#22] — Footnotes inside Tables
- [asciidoctor #1705] — Placement of footnotes in tables.
- [asciidoctor #2350] — Footnotes in tables.
- [asciidoctor #2352] — Introduce a new type of AsciiDoc table cell.

<!---------------------------------------------------------------------------->

# Titles, Headings and Captions

## Book Sections

> __NOTE__ — In the Asciidoctor documentation the term "section" refers to any level of titles (parts, chapter, appendices, and their subsections).
> In this document, to avoid confusion, we'll use the term "subsection" to refer to sub-sections of chapters and appendices.

_The Hugo Book_ consists of two parts (_Book I_ and _Book II_), with 12 chapters and 7 appendices in _Book I_ (Chs 1-12, Apps A-F), and 15 chapters and 1 appendix in _Book II_ (Chs 13-27, App A), for a total of 35 book sections (19 + 16) plus the _Colophon_ and the _Author's Foreword_.

### Sections Numbering

In the original PDF edition of _The Hugo Book_ section numbering of chapters and appendices in _Book II_ were independent from _Book I_.
Asciidoctor doesn't currently allow resetting section numbering in book parts, therefore in this new edition of the book chapters and appendices in _Book II_ carry on from _Book I_.

This might be an issue when trying to publish _Book I_ and _Book II_ as independent documents, for in that case section numbering in _Book II_ would start from scratch (like in the original), resulting in inconsistent section numbering across different editions of the book — a rather inconvenient situation for the readers, leading to references confusions (with _Chapter 16_ of _Book II_ becoming _Chapter 4_ in the split-books editions, and _Appendix H_ becoming _Appendix A_).

Ideally, we would have preferred to preserve the original section numbering system, which would prevent similar discrepancies, regardless of the output format and parts-splitting.
Unfortunately, there seems to be no easy way to achieve this right now (at least, not with HTML backend).

Also, section numbering in the original book adopted Roman numerals and letters, whereas AsciiDoc currently enforces Arabic numerals on section numbers.

For more info:

- [hugo-book #4][#4] — Section Numbering in Book II
- [Asciidoctor Manual: §16. Sections]
- [Asciidoctor Manual: §16.7. Numbering]

## Title Casing

For title capitalization I've adopted the conventions of _[The Chicago Manual of Style]_ (CMS).
The following online title capitalization tool was used (with _Chicago_ option):

* https://capitalizemytitle.com/#Chicago

In the original book, all level one titles were in all-caps.
I've opted to adopt conventional title capitalization since the original all-caps can easily be achieved via templates styles, whereas there is no easy way to automatically reverse all-caps.

## Sections IDs Customization

Every section title in the book has been given a custom ID according to the following naming convention:

- **Colophon** — `colophon`.
- **Author's Foreword** — `preface`.
- **Parts** — `book1` and `book2`.
- **Chapters**:
    + **Chapter Titles** — `chapter_1`, `chapter_2`, etc.
    + **Level 3 Subsections** — `sec_1-1`, `sec_1-2`, etc.
    + **Level 4 Subsections** — `sec_1-1-1`, `sec_1-1-2`, etc.
- **Appendices**:
    + **Appendices Titles** — `appendix_a`, `appendix_b`, etc.
    + **Level 3 Subsections** — `sec_a-1`, `sec_a-2`, etc.
    + **Level 4 Subsections** — `sec_a-1-1`, `sec_a-1-2`, etc.

The adopted IDs scheme should be intuitive enough to allow deducing from the above examples how to create a link targeting the anchor of any specific book section.

For more info:

- [hugo-book #26][#26] — Customize IDs of Every Book Sections
- [Asciidoctor Manual: §16. Sections]
- [Asciidoctor Manual: §16.1. Titles as HTML Headings]
- [Asciidoctor Manual: §16.2. Auto-generated IDs]

<!---------------------------------------------------------------------------->

# Hugo Code

The following conventions, notes and considerations apply to Hugo code snippets, examples and syntax definitions across the book.

## Indentation Conventions

In the various Hugo code snippets and examples in the book, I've opted to use four-spaces indentation, except for Hugo Library excerpts (and other official boilerplates, like `sample.hug` and `shell.hug`) where I've preserved the original eight-spaces indentation.

In a couple of places, an exception to the above rule was made in order to show that strings running across multiple lines can be smart-aligned to increase code readability — e.g. in _§2.4. Multiple Lines_:

```hugo
print "The engine will properly
       print this text, assuming a
       single space at the end of each
       line."
```

The adopted indentation width is an arbitrary choice, but the above conventions ensure code consistency across the various snippets in the book.
Adoption of eight-spaces for indenting Hugo Library excerpts should simplify immediately recognizing code from the library, besides honouring its original style.
The few multi-line string exceptions should serve as a reminder to the reader that indentation (and whitespace in general) is flexible in Hugo.

## Syntax Highlighting

For _The Hugo Book_ HTML5 toolchain this project relies on a custom Hugo syntax definition for [Highlight], an open source, cross platform and binary standalone syntax highlighter by [André Simon].

You're free to use other syntax highlighters, but Highlight remains the current highlighter of choice for building and testing _The Hugo Book_ to HTML5 format.

The current syntax definition for Hugo has some known limitations which you should be aware of.

### Escapes in File Paths

The Highlight syntax is currently unable to distinguish between printable strings and file paths, with the result that escape sequences and special characters in file path string could be highlighted as escapes or interpolations.

Currently this issue only affects a single Hugo code block in _§12.1. Creating and Using Resources_ (see [#33]):

```hugo
resource "GAMERES1"
{
    "c:\hugo\graphics\logo.jpg"
    "h:\data\scenic panorama.jpg"
    "h:\data\background.jpg"
    "c:\music\intro_theme.s3m"
    "c:\music\theme2.xm"
    "c:\sounds\sample1.wav"
    "c:\sounds\sample2.wav"
}
```

where the Windows directory separator `\` is matched as a special formatting sequences in some cases (i.e. `\b`, `\i`).

The current workaround for this problem was to introduce an extra `.noescapes` CSS class that would colour escape sequences with the same colour as the string, effectively hiding the problem from view.
Hugo code blocks affected by this problem are given the `noescapes` role:

```asciidoc
[source,hugo,role="noescapes"]
```

### Unsupported Asciidoctor Features

The currently used Asciidoctor extension to integrate Highlight into the HTML toolchain has the following limitations (see [#16]):

1. Doesn't support [callouts] in code blocks.
2. Code blocks inside table cells are not highlighted.
3. Limited and buggy support for substitutions in code blocks via [the `subs` attribute][subs].
4. Risk of becoming unusable in the future, if the API 2.0 breaks support for legacy extensions.

Solving point 1 requires rewriting the current Highlight extension using the new Asciidoctor 2.0 API.

The problem at point 2 should be resolved by an upcoming Asciidoctor feature (see [asciidoctor #2352]).

Any help in solving the above problems would be much appreciated; in the meantime, any commits that would break the book using [Highlight] can't be merged in, even though they might work with other highlighters.

Of course, if another (static and cross platform) syntax highlighter for Hugo becomes available, without the above limitations, we'll be happy to adopt it as a replacement for Highlight.

# Custom Styles

In order to build _The Hugo Book_ to other formats than those covered by this repository, here's a list of custom roles-styles used in the book, which need to be covered by the template system used by the conversion backend.

## Block Elements

Custom roles are assigned to a variety of block elements:

|    Block Type    |          AsciiDoc Styling         |                  Usage                  |
|------------------|-----------------------------------|-----------------------------------------|
| CMD/Shell        | `[literal,role="cmd"]`            | Mock-up Windows command prompt          |
| Game transcript  | `[example,role="gametranscript"]` | Mock-up game sessions                   |
| Hugo source code | `[source,hugo]`                   | Themed syntax highlighting of Hugo code |
| Hugo syntax      | `[literal,role="hugosyntax"]`     | Mock-up Hugo syntax definitions         |

With the exception of `[source,hugo]` (which is handled by the syntax highlighter, and might require separate styling, depending on the backend employed), all elements in the above list require custom styles in the template in order to be coloured.

__Game transcripts__ are rendered in proportional fonts, using smart typography.
Font styles (italic, bold, underlined) and colours may apply if the example requires it.
The idea is to present the reader with a game session as if it was played on a modern IF interpreter capable of handling smart typography (curly quote, em dashes, etc.).

__Hugo syntax__ blocks differ from actual Hugo source code examples for they contain parameter place-holders (e.g. `<file name>`) and various symbols to indicate alternative (i.e. `|`) and optional arguments (e.g. `[, <param2>]`).
They are not treated as code, so they are not syntax highlighted (the presence of those place-holders prevents correct parsing of the syntax), and the custom styling simply provides some default background and foreground colours to simplify visual identification of the element.

__Hugo source code__ examples require syntax highlighting and a custom colour theme.
Different backends will rely on different syntax highlighters, so there's no standard way of syntax colouring Hugo sources.
For this project, we've created a custom Hugo syntax definition for the [Highlight] tool, which supports a variety of output formats and might be useful with different backends.
Some backends might depend on a dedicate highlighter (e.g. the [asciidoctor-fopub] PDF backend relies on [XSLT syntax highlighting]) and therefore require creating a new dedicated definition of the Hugo syntax.

__CMD/Shell__ blocks are just a mock-up of a terminal session, employed to illustrate how to invoke Hugo tools via the command line and their output.
In the default HTML template, we adopted the Windows command prompt colour scheme as a mere convenience to easily associate this element with a command line session, for other OSs don't have a universally standard colour scheme for terminal windows.

## Inline Elements

The following inline styles are used in the book, via the [shorthand dot-notation for inline role assignment]:


|   Style Type   |       AsciiDoc Styling       |                             Usage                             |
|----------------|------------------------------|---------------------------------------------------------------|
| Big            | `[.big]`                     | In [App. B] "The Hugo Library"                                |
| Big + Red      | `[.big.red]`                 | In many places                                                |
| Green          | `[.green]`                   | Once: in [§4.8] "Mixing Text Styles" example                  |
| Red            | `[.red]`                     | In [§4.8] "Mixing Text Styles" example, and many other places |
| Underlined     | `[.underline]`               | Twice: in [§4.4] and in [§4.8] "Mixing Text Styles" example   |
| Yellow         | `[.yellow]`                  | Once: in [§4.8] "Mixing Text Styles" example                  |
| Alt book title | `[.text-center.big.ortitle]` | Secondary book titles in _[Book I]_ and _[Book II]_           |

Some of the above styles are predefined in the default Asciidoctor templates (e.g. `.big.`, `red` and `.text-center`), but others were added to cover specific needs.
Just ensure that your template correctly covers all the above styles, using the CSS stylesheets of the HTML edition of this project as a reference for the desired style results.

In some cases, these styles are mandatory, like the use of `.green`, `.red`, `.yellow` and `.underline` in the of Hugo formatting examples of [§4.4] and [§4.8], where they need to emulate styled output in game transcripts.

In the majority of other cases, these styles were added just to facilitate sifting through the book and quickly detecting key elements of interest.
In these cases, omission of custom styles would not affect the book contents, and often the roles `.big` and `.red` were added along with strong or emphasis formatting, as extra styles.

It's also possible to suppress colours altogether by overriding these styles so that they will be coloured in black (e.g. when targeting a document to be printed in black and white), although usually printer devices should already offer this type of functionality in their drivers advanced settings panel.

<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

[The Chicago Manual of Style]: https://www.chicagomanualofstyle.org "Go to The Chicago Manual of Style website"

<!-- Hugo Book: Issues -->

[#16]: https://github.com/tajmone/hugo-book/issues/16 "Issue #16: Re-Write Highlight Extension for Asciidoctor 2.0"
[#22]: https://github.com/tajmone/hugo-book/issues/22 "Issue #22: Footnotes inside Tables"
[#24]: https://github.com/tajmone/hugo-book/issues/24 "Issue #24: Handling Identical Footnotes"
[#26]: https://github.com/tajmone/hugo-book/issues/26 "Issue #26: Customize IDs of Every Book Sections"
[#33]: https://github.com/tajmone/hugo-book/issues/33 "Issue #33: Highlighting Filepath Strings: Prevent Escapes"
[#4]: https://github.com/tajmone/hugo-book/issues/4 "Issue #4: Section Numbering in Book II"

<!-- Hugo Book Live HTML Links -->

[Book I]: https://tajmone.github.io/hugo-book/#book1 "Live HTML Preview"
[Book II]: https://tajmone.github.io/hugo-book/#book2 "Live HTML Preview"

[§4.4]: https://tajmone.github.io/hugo-book/#sec_4-4 "Live HTML Preview"
[§4.8]: https://tajmone.github.io/hugo-book/#sec_4-8 "Live HTML Preview"

[App. B]: https://tajmone.github.io/hugo-book/#appendix_b "Live HTML Preview"


<!-- Asciidoctor ------------------------------------------------------------>

[Asciidoctor]: https://asciidoctor.org/ "Visit Asciidoctor website"

<!-- Asciidoctor Issues -->

[asciidoctor #2352]: https://github.com/asciidoctor/asciidoctor/issues/2352
[asciidoctor #2350]: https://github.com/asciidoctor/asciidoctor/issues/2350
[asciidoctor #1705]: https://github.com/asciidoctor/asciidoctor/issues/1705

<!-- Asciidoctor Manual -->

[Asciidoctor Manual: §16. Sections]: https://asciidoctor.org/docs/user-manual/#sections
[Asciidoctor Manual: §16.1. Titles as HTML Headings]: https://asciidoctor.org/docs/user-manual/#titles-as-html-headings
[Asciidoctor Manual: §16.2. Auto-generated IDs]: https://asciidoctor.org/docs/user-manual/#auto-generated-ids
[Asciidoctor Manual: §16.7. Numbering]: https://asciidoctor.org/docs/user-manual/#numbering

[Asciidoctor Manual: §61. Footnotes]: https://asciidoctor.org/docs/user-manual/#user-footnotes
[Asciidoctor Manual: §61.1. Externalizing a Footnote]: https://asciidoctor.org/docs/user-manual/#externalizing-a-footnote

[Asciidoctor Manual: §A.3. Predefined Attributes for Character Replacements]: https://asciidoctor.org/docs/user-manual/#charref-attributes

[callouts]: https://asciidoctor.org/docs/user-manual/#callouts "Learn more about Asciidoctor callouts"
[subs]: https://asciidoctor.org/docs/user-manual/#applying-substitutions "Learn more about Asciidoctor substitutions"

[externalized]: https://asciidoctor.org/docs/user-manual/#externalizing-a-footnote "See Asciidoctor Manual on externalizing footnote"
[shorthand dot-notation for inline role assignment]: https://asciidoctor.org/docs/user-manual/#inline-assignment-2 "See Asciidoctor Manual on inline role assignment"
[word-joiner attribute]: https://asciidoctor.org/docs/user-manual/#charref-attributes "See Asciidoctor Manual on predefined attributes for character replacements regarding the use of {wj}"

<!-- 3rd party tools---------------------------------------------------------->

[asciidoctor-fopub]: https://github.com/asciidoctor/asciidoctor-fopub "Visit the asciidoctor-fopub repository on GitHub"
[Highlight]: http://www.andre-simon.de/ "Visit Highlight website"
[XSLT syntax highlighting]: https://sourceforge.net/projects/xslthl/ "Visit the XSLT project at SourceForge"

<!-- people ------------------------------------------------------------------>

[André Simon]: https://gitlab.com/saalen "View André Simon's GitLab profile"

<!-- EOF -->
