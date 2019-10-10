# Hugo Book Diagrams

Source files to generate the diagram images in SVG using [Dia].

-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3" -->

- [Folder Contents](#folder-contents)
- [Diagrams Previews](#diagrams-previews)
    - [Hugo Engine Flowchart](#hugo-engine-flowchart)
    - [Hugo Debugger Flowchart](#hugo-debugger-flowchart)
- [System Requirements](#system-requirements)
- [Diagrams Editing Notes](#diagrams-editing-notes)

<!-- /MarkdownTOC -->

-----


# Folder Contents

- [`build.sh`](./build.sh) — Create SVG images from Dia sourcefiles.
- [`deploy.sh`](./deploy.sh) — Copy built SVG images to `../../docs_src/`.

Hugo Engine flowchart ([Book II: §26][§26]):

- `hugo-book2_14_flowchart-engine.dia`
- [`hugo-book2_14_flowchart-engine.svg`][FC2:14]

Hugo Debugger flowchart ([Book II: §27][§27]):

- `hugo-book2_15_flowchart-debugger.dia`
- [`hugo-book2_15_flowchart-debugger.svg`][FC2:15]


# Diagrams Previews

## Hugo Engine Flowchart

- `hugo-book2_14_flowchart-engine.dia`
- [`hugo-book2_14_flowchart-engine.svg`][FC2:14]

Used in [§26. THE HUGO ENGINE AND HOW IT WORKS][§26].

![Hugo Engine Diagram][FC2:14]

## Hugo Debugger Flowchart

- `hugo-book2_15_flowchart-debugger.dia`
- [`hugo-book2_15_flowchart-debugger.svg`][FC2:15]

Used in [§27. DARK SECRETS OF THE HUGO DEBUGGER][§27].

![Hugo Debugger Diagram][FC2:15]


# System Requirements

In order to edit the diagram's sourcefile, or to run the scripts in this folder, you'll need to install [Dia Diagram Editor], a free and open source cross platform tool for editing diagrams.


# Diagrams Editing Notes

In order to preserve multiple-spaces for indentation purposes, use the [Figure-space] character (`&numsp;`) instead of ordinary spaces or non-breaking spaces.

Since [Dia] doesn't allow insertion of special characters via numeric keypad alt-codes (Win OS), you'll need to copy and paste any required special characters from some plain text file.

Below is a table with some characters that were employed in the diagrams.
Every character representation can be copied to the clipbloard from the _sample_ column — including invisible characters like spaces.

|   char name    | xml entity |  sample |
|----------------|------------|---------|
| [Figure-space] | `&numsp;`  | &numsp; |

<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

[Dia]: http://dia-installer.de/ "Visit Dia's website"
[Dia Diagram Editor]: http://dia-installer.de/ "Visit Dia's website"
[Figure-space]: https://en.wikipedia.org/wiki/Figure_space "See Wikipedia page on Figure space"

<!-- Live HTML Previews Links -->

[§25]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_the_hugo_compiler_and_how_it_works "Live HTML Preview"
[§26]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_the_hugo_engine_and_how_it_works "Live HTML Preview"
[§27]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_dark_secrets_of_the_hugo_debugger "Live HTML Preview"
[§3.2]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_code_patterns "Live HTML Preview"

<!-- project files -->

[FC2:14]: ./hugo-book2_14_flowchart-engine.svg
[FC2:15]: ./hugo-book2_15_flowchart-debugger.svg

<!-- EOF -->
