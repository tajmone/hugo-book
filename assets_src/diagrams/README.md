# Hugo Book Diagram

Source files to generate the diagram images in SVG using [Dia].

-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3" -->

- [Folder Contents](#folder-contents)
- [Diagrams Preview](#diagrams-preview)
    - [Hugo Engine Diagram](#hugo-engine-diagram)
- [System Requirements](#system-requirements)
- [Diagrams Editing Notes](#diagrams-editing-notes)

<!-- /MarkdownTOC -->

-----


# Folder Contents

- [`build.bat`](./build.bat) — Create SVG images from Dia sourcefile.
- [`deploy.bat`](./deploy.bat) — Copy built SVGs to `//docs_src/`.
- `hugo-book2_14_flowchart-engine.dia` — Dia sourcefile.
- [`hugo-book2_14_flowchart-engine.svg`][FC2:14]— Converted diagram in SVG format.


# Diagrams Preview

## Hugo Engine Diagram

- `hugo-book2_14_flowchart-engine.dia`
- `hugo-book2_14_flowchart-engine.svg`

Used in [§26. THE HUGO ENGINE AND HOW IT WORKS].

![Hugo Engine Diagram][FC2:14]

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

[§25. THE HUGO COMPILER AND HOW IT WORKS]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_the_hugo_compiler_and_how_it_works "Live HTML Preview"
[§26. THE HUGO ENGINE AND HOW IT WORKS]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_the_hugo_engine_and_how_it_works "Live HTML Preview"
[§27. DARK SECRETS OF THE HUGO DEBUGGER]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_dark_secrets_of_the_hugo_debugger "Live HTML Preview"
[§3.2. The Object Tree]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_code_patterns "Live HTML Preview"

<!-- project files -->

[FC2:14]: ./hugo-book2_14_flowchart-engine.svg

<!-- EOF -->
