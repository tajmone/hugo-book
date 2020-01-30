# Hugo Book Diagrams

Source files to generate the diagram images in SVG using [Dia].

-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3" -->

- [Folder Contents](#folder-contents)
- [Diagrams Previews](#diagrams-previews)
    - [Object Tree Diagrams](#object-tree-diagrams)
        - [1st Diagram](#1st-diagram)
        - [2nd Diagram](#2nd-diagram)
        - [3rd Diagram](#3rd-diagram)
    - [Hugo Compiler Flowchart](#hugo-compiler-flowchart)
    - [Hugo Engine Flowchart](#hugo-engine-flowchart)
    - [Hugo Debugger Flowchart](#hugo-debugger-flowchart)
- [System Requirements](#system-requirements)
- [Diagrams Editing Notes](#diagrams-editing-notes)
    - [Object Trees Fonts and Colours](#object-trees-fonts-and-colours)
    - [Flowcharts Fonts and Colours](#flowcharts-fonts-and-colours)
    - [Text Overlays](#text-overlays)
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

Object Tree diagrams ([Book I: §3.2][§3.2]):

- `hugo-book1_03_object-tree1.dia`
- [`hugo-book1_03_object-tree1.svg`][OT1]
- `hugo-book1_03_object-tree2.dia`
- [`hugo-book1_03_object-tree2.svg`][OT2]
- `hugo-book1_03_object-tree3.dia`
- [`hugo-book1_03_object-tree3.svg`][OT3]

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

## Object Tree Diagrams

Used in [§3.2. The Object Tree][§3.2].

### 1st Diagram

- `hugo-book1_03_object-tree1.dia`
- [`hugo-book1_03_object-tree1.svg`][OT1]

![Object Tree example 1][OT1]

-------------------------------------------------------------------------------

### 2nd Diagram

- `hugo-book1_03_object-tree2.dia`
- [`hugo-book1_03_object-tree2.svg`][OT2]

![Object Tree example 2][OT2]

-------------------------------------------------------------------------------

### 3rd Diagram

- `hugo-book1_03_object-tree3.dia`
- [`hugo-book1_03_object-tree3.svg`][OT3]

![Object Tree example 3][OT3]

-------------------------------------------------------------------------------

## Hugo Compiler Flowchart

- `hugo-book2_13_flowchart-compiler.dia`
- [`hugo-book2_13_flowchart-compiler.svg`][FC2:13]

Used in [§25. The Hugo Compiler and How It Works][§25].

![Hugo Compiler Diagram][FC2:13]

-------------------------------------------------------------------------------

## Hugo Engine Flowchart

- `hugo-book2_14_flowchart-engine.dia`
- [`hugo-book2_14_flowchart-engine.svg`][FC2:14]

Used in [§26. The Hugo Engine and How It Works][§26].

![Hugo Engine Diagram][FC2:14]

-------------------------------------------------------------------------------

## Hugo Debugger Flowchart

- `hugo-book2_15_flowchart-debugger.dia`
- [`hugo-book2_15_flowchart-debugger.svg`][FC2:15]

Used in [§27. Dark Secrets of the Hugo Debugger][§27].

![Hugo Debugger Diagram][FC2:15]

-------------------------------------------------------------------------------

# System Requirements

In order to edit the diagram's sourcefile, or to run the scripts in this folder, you'll need to install [Dia Diagram Editor], a free and open source cross platform tool for editing diagrams.


# Diagrams Editing Notes

Some annotations on Dia assets and settings used in the creation of the SVG diagrams sources.

> **NOTE** — The __Courier New__ font was chosen because it's a universally safe font that should be available on all OSs, including smart phones and tablets.
>
> Attempts to use "monospace" instead of a specific font name didn't turn out to provide reliable cross-browser behaviour, and was deemed as potentially unsafe to use with other backends.
>
> __Courier New__ is expected to be supported by all conversion backends as well as being properly previewed in all formats on all OSs.

## Object Trees Fonts and Colours

For the Object Trees diagrams, I've used Dia's built-in [Flowchart Shapes].

And the following fonts:

- __Courier New__ (bold), 28 pt.

## Flowcharts Fonts and Colours

For the flowchart diagrams, I've used Dia's built-in [Flowchart Shapes].

And the following fonts:

- __Courier New__ (normal, bold), 28 pt.

Text colour variations:

|    element    | text colour | description |
|---------------|-------------|-------------|
| Element Title | `#2660BF`   | Medium Blue |
| Ref. Number   | `#BA3925`   | Dark Red    |

For the diagrams shapes background colours, I've used the same colour scheme adopted by [VisualParadigm Online Diagrams]:

|   symbol   | bg-colour |
|------------|-----------|
| Terminator | `#F8CECC` |
| Process    | `#FFE599` |
| Decision   | `#FFCE9F` |
| Data       | `#D4E1F5` |

## Text Overlays

In order to achieve special alignments in the same diagram box, an extra text overlay was used in some places, positioned on top of the main box to ensure that right aligned texts (usually, file names) will be preserved.

This was necessary due to multiple spaces being treated as one, and the impossibility of using special spaces with the __Courier New__ font (e.g. non-breaking spaces or numeric spaces).

When editing the diagrams, be mindful of the presence of these text boxes.

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

[§3.2]: https://tajmone.github.io/hugo-book/#sec_3-2 "Live HTML Preview"
[§25]: https://tajmone.github.io/hugo-book/#chapter_25 "Live HTML Preview"
[§26]: https://tajmone.github.io/hugo-book/#chapter_26 "Live HTML Preview"
[§27]: https://tajmone.github.io/hugo-book/#chapter_27 "Live HTML Preview"

<!-- project files -->

[OT1]: ./hugo-book1_03_object-tree1.svg
[OT2]: ./hugo-book1_03_object-tree2.svg
[OT3]: ./hugo-book1_03_object-tree3.svg

[FC2:13]: ./hugo-book2_13_flowchart-compiler.svg
[FC2:14]: ./hugo-book2_14_flowchart-engine.svg
[FC2:15]: ./hugo-book2_15_flowchart-debugger.svg

<!-- EOF -->
