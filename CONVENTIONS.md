# Formatting and Style Conventions

The AsciiDoc formatting and style conventions adopted in _The Hugo Book_.


-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3" -->

- [Introduction](#introduction)
- [Footnotes](#footnotes)
    - [Handling Identical Footnotes](#handling-identical-footnotes)
    - [Footnotes in Table Cells](#footnotes-in-table-cells)
- [Title Casing](#title-casing)
- [Hugo Code](#hugo-code)
    - [Indentation Conventions](#indentation-conventions)
    - [Syntax Highlighting](#syntax-highlighting)
        - [Escapes in File Paths](#escapes-in-file-paths)
        - [Unsupported Asciidoctor Features](#unsupported-asciidoctor-features)

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
A paragraph with footnotes{fn1} via custom attributes.{fn2}
```

This allows to access all footnotes in a chapter at once, without having to sift the document to find them.

The footnote attributes of every document are named starting from 1 (`:fn1:`) regardless of the actual note number in the final document (Asciidoctor will take care of that).

For more info:

- [Asciidoctor Manual: §61. Footnotes]
- [Asciidoctor Manual: §61.1. Externalizing a Footnote]

## Handling Identical Footnotes

The book contains various notes with identical text, but we opted to keep each note independent, for various reasons (although Asciidoctor supports shared footnotes references).

The main reason for this choice was in consideration of HTML-based documents (web pages, ePub, CHM Help, etc.) where notes numbers appearing in the text are actual links that take the reader to the footnote — usually placed at the end of the chapter or document, depending on the format.
Each footnote number is also a link back to the text position where the note was encountered.

If we had chosen to use a single footnote to represent identical notes, the back-link would always point to the first occurrence of the note in the book, regardless of where it was encountered, thus risking that the reader might not be able to resume reading the main text after inspecting the footnote.

Although on printed paper it might have been more elegant to avoid identical footnotes, we decided that preventing disruption of the reading experience in HTML-based formats had the priority.

For more info:

- [hugo-book/#24][#24] — Handling Identical Footnotes
- [Asciidoctor Manual: §61. Footnotes]


## Footnotes in Table Cells

Numerous notes occur inside table cells.
Currently, Asciidoctor doesn't always handle them as expected, sometimes placing the footnote at the end of the cell, instead of placing it with the rest of the footnotes ([See #22][#22]).

This is a known issue with Asciidoctor and it happens when the cell is styled as AsciiDoc (`a`), which gets treated as an embedded document.
A solution has already been planned, introducing a new `b` cell style for "block-level content" (See [asciidoctor/#2352]), so we just have to wait.

When the new `b` feature will be available, all occurrences of `a` styled cells will have to be changed in the _Hugo Book_ sources.

For more info:

- [hugo-book/#22][#22] — Footnotes inside Tables
- [asciidoctor/#2352] — Introduce a new type of AsciiDoc table cell.
- [asciidoctor/#2350] — Footnotes in tables.
- [asciidoctor/#1705] — Placement of footnotes in tables.

# Title Casing

For title capitalization I've adopted the conventions of _[The Chicago Manual of Style]_ (CMS).
The following online title capitalization tool was used (_Chicago_ option):

* https://capitalizemytitle.com/#Chicago

In the original book, all level one titles were in all-caps.
I've opted to adopt conventional title capitalization since the original all-caps can easily be achieved via templates styles, whereas there is no easy way to automatically reverse all-caps.

# Hugo Code

The following conventions, notes and considerations apply to Hugo code snippets, examples and syntax definitions across the book.

## Indentation Conventions

In the various Hugo code snippets and examples in the book, we've opted to use four-spaces indentation, except for Hugo Library excerpts (and other official boilerplates, like `sample.hug` and `shell.hug`) where we've preserved the original eight-spaces indentation.

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
Hugo code blocks display this problem are given the `noescapes` role:

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

The problem at point 2 should be resolved by an upcoming Asciidoctor feature (see [asciidoctor/#2352]).

Any help in solving the above problems would be much appreciated; in the meantime, any commits that would break the book using [Highlight] can't be merged in, even though they might work with other highlighters.

Of course, if another (static and cross platform) syntax highlighter for Hugo becomes available, without the above limitations, we'll be happy to adopt it as a replacement for Highlight.

<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

[externalized]: https://asciidoctor.org/docs/user-manual/#externalizing-a-footnote "See Asciidoctor Manual on externalizing footnote"

[The Chicago Manual of Style]: https://www.chicagomanualofstyle.org "Go to The Chicago Manual of Style website"

<!-- Issues: Hugo Book -->

[#16]: https://github.com/tajmone/hugo-book/issues/16 "Issue #16: Re-Write Highlight Extension for Asciidoctor 2.0"
[#22]: https://github.com/tajmone/hugo-book/issues/22 "Issue #22: Footnotes inside Tables"
[#24]: https://github.com/tajmone/hugo-book/issues/24 "Issue #24: Handling Identical Footnotes"
[#33]: https://github.com/tajmone/hugo-book/issues/33 "Issue #33: Highlighting Filepath Strings: Prevent Escapes"

[Highlight]: http://www.andre-simon.de/ "Visit Highlight website"

<!-- Asciidoctor ------------------------------------------------------------>

[Asciidoctor]: https://asciidoctor.org/ "Visit Asciidoctor website"

<!-- Asciidoctor Issues -->

[asciidoctor/#2352]: https://github.com/asciidoctor/asciidoctor/issues/2352
[asciidoctor/#2350]: https://github.com/asciidoctor/asciidoctor/issues/2350
[asciidoctor/#1705]: https://github.com/asciidoctor/asciidoctor/issues/1705

<!-- Asciidoctor Manual -->

[Asciidoctor Manual: §61. Footnotes]: https://asciidoctor.org/docs/user-manual/#user-footnotes
[Asciidoctor Manual: §61.1. Externalizing a Footnote]: https://asciidoctor.org/docs/user-manual/#externalizing-a-footnote

[callouts]: https://asciidoctor.org/docs/user-manual/#callouts "Learn more about Asciidoctor callouts"
[subs]: https://asciidoctor.org/docs/user-manual/#applying-substitutions "Learn more about Asciidoctor substitutions"

<!-- people ------------------------------------------------------------------>

[André Simon]: https://gitlab.com/saalen "View André Simon's GitLab profile"

<!-- EOF -->
