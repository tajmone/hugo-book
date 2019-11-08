# Formatting and Style Conventions

The AsciiDoc formatting and style conventions adopted in _The Hugo Book_.


-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3" -->

- [Introduction](#introduction)
- [Footnotes](#footnotes)
    - [Handling Identical Footnotes](#handling-identical-footnotes)
    - [Footnotes in Table Cells](#footnotes-in-table-cells)

<!-- /MarkdownTOC -->

-----

# Introduction

The following notes document the choices made in the adaptation of the book from MS Word to AsciiDoc format.
These might be useful to those interested in covering new output formats, to ensure that styles are rendered as expected in that format (via templates, stylesheets, or whatever the format uses to handle them).
And they might be even more useful to anyone wishing to further develop the book, to ensure consistency in added contents.

# Footnotes

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

<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

<!-- Issues: Hugo Book -->

[#22]: https://github.com/tajmone/hugo-book/issues/22 "Issue #22: Footnotes inside Tables"
[#24]: https://github.com/tajmone/hugo-book/issues/24 "Issue #24: Handling Identical Footnotes"

<!-- Issues: Asciidoctor -->

[asciidoctor/#2352]: https://github.com/asciidoctor/asciidoctor/issues/2352
[asciidoctor/#2350]: https://github.com/asciidoctor/asciidoctor/issues/2350
[asciidoctor/#1705]: https://github.com/asciidoctor/asciidoctor/issues/1705

<!-- Asciidoctor Manual -->

[Asciidoctor Manual: §61. Footnotes]: https://asciidoctor.org/docs/user-manual/#user-footnotes

<!-- EOF -->
