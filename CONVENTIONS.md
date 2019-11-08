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

The book contains various notes with identical text, but we opted to keep each note independent, for various reasons (although Asciidoctor supports shared notes references).

The main reason for this choice was in consideration of HTML-based documents (web pages, ePub, CHM Help, etc.) where notes numbers appearing in the text are actual links that take the reader to the footnote — usually placed at the end of the chapter or document, depending on the format.
Each footnote number is also a link back to the text position where the note was encountered.

If we had chosen to use a single footnote to represent identical notes, the back-link would always point to the first occurrence of the note, thus risking that the reader might not be able to resume reading after reading the note.

Although on printed paper it might have been a wise choice to avoid identical footnotes, we decided that prevent reading disruption in digital formats had higher priority.

### Footnotes in Table Cells

There are numerous notes that occur inside table cells.
Currently, Asciidoctor doesn't always handle them as expected, sometimes placing the footnote at the end of the cell, instead of placing it with the rest of the footnotes.

This is a known issue with Asciidoctor and it happens when the cell is styled as AsciiDoc (`a`).
This is something that will be fixed soon in Asciidoctor, so we only have to wait — probably the style of these cells might need to be changed in the _Hugo Book_ sources, depending on whether the fix for this would apply to the `a` style or require using a new cell style.

<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>



<!-- EOF -->
