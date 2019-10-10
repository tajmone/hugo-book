# Hugo Book Diagrams

Source files to generate the diagram images in SVG using [Dia].

-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3" -->

- [Folder Contents](#folder-contents)
- [Diagrams Previews](#diagrams-previews)
    - [Hugo Compiler Flowchart](#hugo-compiler-flowchart)
    - [Hugo Engine Flowchart](#hugo-engine-flowchart)
    - [Hugo Debugger Flowchart](#hugo-debugger-flowchart)
- [System Requirements](#system-requirements)
- [Diagrams Editing Notes](#diagrams-editing-notes)
    - [Flowcharts Fonts and Colors](#flowcharts-fonts-and-colors)
    - [Spacing Characters](#spacing-characters)
    - [Special Chars Table](#special-chars-table)
- [External Links](#external-links)
    - [Dia Diagram Editor](#dia-diagram-editor)
    - [Flowcharts](#flowcharts)
    - [SVG Images](#svg-images)
    - [Web Safe Fonts](#web-safe-fonts)

<!-- /MarkdownTOC -->

-----


# Folder Contents

- [`build.sh`](./build.sh) — Create SVG images from Dia sourcefiles.
- [`deploy.sh`](./deploy.sh) — Copy built SVG images to `../../docs_src/`.

Hugo Compiler flowchart ([Book II: §25][§25]):

- `hugo-book2_13_flowchart-compiler.dia`
- [`hugo-book2_13_flowchart-compiler.svg`][FC2:13]

Hugo Engine flowchart ([Book II: §26][§26]):

- `hugo-book2_14_flowchart-engine.dia`
- [`hugo-book2_14_flowchart-engine.svg`][FC2:14]

Hugo Debugger flowchart ([Book II: §27][§27]):

- `hugo-book2_15_flowchart-debugger.dia`
- [`hugo-book2_15_flowchart-debugger.svg`][FC2:15]


# Diagrams Previews

## Hugo Compiler Flowchart

- `hugo-book2_13_flowchart-compiler.dia`
- [`hugo-book2_13_flowchart-compiler.svg`][FC2:13]

Used in [§25. THE HUGO COMPILER AND HOW IT WORKS][§25].

![Hugo Compiler Diagram][FC2:13]

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

Some annotations on Dia assets and settings used in the creation of the SVG diagrams sources. 

## Flowcharts Fonts and Colors

For the Dia flowchart diagrams, I've used the built-in [Flowchart Shapes].

And the following fonts:

- Consolas, 28 pt.

Text color variations:

|    element    | text color | description |
|---------------|------------|-------------|
| Element Title | `#2660BF`  | Medium Blue |
| Ref. Number   | `#BA3925`  | Dark Red    |

For the diagrams shapes background colors, I've used the same color scheme adopted by [VisualParadigm Online Diagrams]:

|   symbol   |  bg-color |
|------------|-----------|
| Terminator | `#F8CECC` |
| Process    | `#FFE599` |
| Decision   | `#FFCE9F` |
| Data       | `#D4E1F5` |

## Spacing Characters

In order to preserve multiple-spaces for indentation purposes, use the [Figure-space] character (`&numsp;`) instead of ordinary spaces or non-breaking spaces.

Since [Dia] doesn't allow insertion of special characters via numeric keypad alt-codes (Win OS), you'll need to copy and paste any required special characters from some plain text file.

## Special Chars Table

Below is a table with some characters that were employed in the diagrams.
Every character representation can be copied to the clipbloard from the _sample_ column — including invisible characters like spaces.

|   char name    | xml entity |  sample |
|----------------|------------|---------|
| [Figure-space] | `&numsp;`  | &numsp; |

# External Links

## Dia Diagram Editor

- [Dia Diagram Editor] — official website and dowloads.
    + [Flowchart Shapes] — details of the flowchart shapes used in this project.

## Flowcharts

- [Wikipedia » Flowchart]
- [VisualParadigm Online Diagrams]:
    + [Flowchart Tutorial]

## SVG Images

- [CSS Tricks » Using Custom Fonts With SVG in an Image Tag] — by Thomas Yip.
- [Vecta.io » Using Fonts in SVG] — by Neel Singh.

## Web Safe Fonts

Resources and articles on which fonts are safe to use based on common OSs' availability (this affects fonts used in SVG images too):

- [CSS Font Stack] — A complete collection of web safe CSS font stacks.
- [MIT.edu » Safe web fonts] — Article by Jacob Morzinski.
- [Lifewire » Make Sure You're Using Web Safe Fonts] — Article by Jennifer Kyrnin.

<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

[Figure-space]: https://en.wikipedia.org/wiki/Figure_space "See Wikipedia page on Figure space"

[Wikipedia » Flowchart]: https://en.wikipedia.org/wiki/Flowchart "See Wikipedia page on 'Flowchart'"

[CSS Font Stack]: https://www.cssfontstack.com/ "Visit website"

<!-- Dia -->

[Dia]: http://dia-installer.de/ "Visit Dia's website"
[Dia Diagram Editor]: http://dia-installer.de/ "Visit Dia's website"
[Flowchart Shapes]: http://dia-installer.de/shapes/Flowchart/index.html "Go to the Flowchart Dia shapes page"

<!-- VisualParadigm -->

[VisualParadigm Online Diagrams]: https://online.visual-paradigm.com/diagrams/ "Visit VP Online Diagrams"
[Flowchart Tutorial]: https://online.visual-paradigm.com/diagrams/tutorials/flowchart-tutorial/ "Flowachart tutorial by VisualParadigm"

<!-- articles -->

[CSS Tricks » Using Custom Fonts With SVG in an Image Tag]: https://css-tricks.com/using-custom-fonts-with-svg-in-an-image-tag/ "Read article"
[Lifewire » Make Sure You're Using Web Safe Fonts]: https://www.lifewire.com/web-safe-fonts-3467430 "Read article"
[MIT.edu » Safe web fonts]: https://web.mit.edu/jmorzins/www/fonts.html "Read article"
[Vecta.io » Using Fonts in SVG]: https://vecta.io/blog/using-fonts-in-svg "Read article"

<!-- Live HTML Previews Links -->

[§25]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_the_hugo_compiler_and_how_it_works "Live HTML Preview"
[§26]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_the_hugo_engine_and_how_it_works "Live HTML Preview"
[§27]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_dark_secrets_of_the_hugo_debugger "Live HTML Preview"
[§3.2]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_code_patterns "Live HTML Preview"

<!-- project files -->

[FC2:13]: ./hugo-book2_13_flowchart-compiler.svg
[FC2:14]: ./hugo-book2_14_flowchart-engine.svg
[FC2:15]: ./hugo-book2_15_flowchart-debugger.svg

<!-- EOF -->
