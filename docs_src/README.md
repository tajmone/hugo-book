# Hugo Book AsciiDoc Sources

This folder contains the AsciiDoc source files of the _The Hugo Book_.

- [HTML Live Preview] — _The Hugo Book_ in a single HTML document.

-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3" -->

- [Folder Contents](#folder-contents)
    - [Book Sources](#book-sources)
    - [Build Toolchain](#build-toolchain)
- [Toolchain Dependencies](#toolchain-dependencies)
- [Annotations Conventions](#annotations-conventions)
- [XRefs](#xrefs)
    - [Chapters, Appendices and Sections](#chapters-appendices-and-sections)
    - [Tables and Figures](#tables-and-figures)
    - [Custom Anchors](#custom-anchors)
- [System Requirements](#system-requirements)

<!-- /MarkdownTOC -->

-----

# Folder Contents

## Book Sources

List of _The Hugo Book_ AsciiDoc sources and contents-assets:

- [`docinfo.html`][docinfo.html] — [docinfo file] with custom CSS ([generated via Sass]).
- [`warn-editing.asciidoc`][warn-editing] — a "don't edit me!" notice included in the [standalone AsciiDoc build].
- [`hugo-book.asciidoc`][HB] — the main AsciiDoc source file that imports all contents:
    + [`hugo-book0_preamble.asciidoc`][HB:Preamble] — Document Preamble.
    + [`hugo-book0_colophon.asciidoc`][HB:Colophon] — _[Colophon]_
    + [`hugo-book0_preface.asciidoc`][HB:Preface] — _[Author's Foreword]_
    + [`hugo-book1.asciidoc`][HB1] — imports chapters of _[Book I]_:
        * [`hugo-book1_01.asciidoc`][HB1:01] — [1. _Introduction_][Ch1]
        * [`hugo-book1_02.asciidoc`][HB1:02] — [2. _A First Look at Hugo_][Ch2]
        * [`hugo-book1_03.asciidoc`][HB1:03] — [3. _Objects_][Ch3]
            - [`hugo-book1_03_object-tree1.svg`][HB1:3 objT1.svg] — SVG object tree example 1 ([generated via Dia]).
            - [`hugo-book1_03_object-tree2.svg`][HB1:3 objT2.svg] — SVG object tree example 2 ([generated via Dia]).
            - [`hugo-book1_03_object-tree3.svg`][HB1:3 objT3.svg] — SVG object tree example 3 ([generated via Dia]).
        * [`hugo-book1_04.asciidoc`][HB1:04] — [4. _Hugo Programming_][Ch4]
        * [`hugo-book1_05.asciidoc`][HB1:05] — [5. _Routines and Events_][Ch5]
        * [`hugo-book1_06.asciidoc`][HB1:06] — [6. _Fuses, Daemons, and Scripts_][Ch6]
        * [`hugo-book1_07.asciidoc`][HB1:07] — [7. _Grammar and Parsing_][Ch7]
        * [`hugo-book1_08.asciidoc`][HB1:08] — [8. _Junction Routines_][Ch8]
        * [`hugo-book1_09.asciidoc`][HB1:09] — [9. _The Game Loop_][Ch9]
        * [`hugo-book1_10.asciidoc`][HB1:10] — [10. _Using the Object Library_][Ch10]
        * [`hugo-book1_11.asciidoc`][HB1:11] — [11. _Advanced Features_][Ch11]
        * [`hugo-book1_12.asciidoc`][HB1:12] — [12. _Resources_][Ch12]
        * [`hugo-book1_13.asciidoc`][HB1:13] — [App. A. _Summary of Keywords and Commands_][AppA]
        * [`hugo-book1_14.asciidoc`][HB1:14] — [App. B. _The Hugo Library_][AppB]
        * [`hugo-book1_15.asciidoc`][HB1:15] — [App. C. _Limit Settings_][AppC]
        * [`hugo-book1_16.asciidoc`][HB1:16] — [App. D. _Hugofix and the Hugo Debugger_][AppD]
        * [`hugo-book1_17.asciidoc`][HB1:17] — [App. E. _Precompiled Headers_][AppE]
        * [`hugo-book1_18.asciidoc`][HB1:18] — [App. F. _Hugo Versions_][AppF]
        * [`hugo-book1_19.asciidoc`][HB1:19] — [App. G. _Additional Resources_][AppG]
    + [`hugo-book2.asciidoc`][HB2] — imports chapters of _[Book II]_:
        * [`hugo-book2_01.asciidoc`][HB2:01] — [13. _Introduction_][Ch13]
        * [`hugo-book2_02.asciidoc`][HB2:02] — [14. _Organization of the .HEX File_][Ch14]
        * [`hugo-book2_03.asciidoc`][HB2:03] — [15. _Tokens and Data Types_][Ch15]
            - [`hugo-book2_03_tokens-list.csv`][HB Tokens.csv] — CSV list of Hugo tokens for populating the tokens table.
        * [`hugo-book2_04.asciidoc`][HB2:04] — [16. _Engine Parsing_][Ch16]
        * [`hugo-book2_05.asciidoc`][HB2:05] — [17. _Grammar_][Ch17]
        * [`hugo-book2_06.asciidoc`][HB2:06] — [18. _Executable Code_][Ch18]
        * [`hugo-book2_07.asciidoc`][HB2:07] — [19. _Encoding Text_][Ch19]
        * [`hugo-book2_08.asciidoc`][HB2:08] — [20. _The Object Table_][Ch20]
        * [`hugo-book2_09.asciidoc`][HB2:09] — [21. _The Property Table_][Ch21]
        * [`hugo-book2_10.asciidoc`][HB2:10] — [22. _The Event Table_][Ch22]
        * [`hugo-book2_11.asciidoc`][HB2:11] — [23. _The Dictionary and Special Words_][Ch23]
        * [`hugo-book2_12.asciidoc`][HB2:12] — [24. _Resourcefiles_][Ch24]
        * [`hugo-book2_13.asciidoc`][HB2:13] — [25. _The Hugo Compiler and How It Works_][Ch25]
            - [`hugo-book2_13_flowchart-compiler.svg`][HB2:13 com.svg] — SVG flowchart of Hugo compiler ([generated via Dia]).
        * [`hugo-book2_14.asciidoc`][HB2:14] — [26. _The Hugo Engine and How It Works_][Ch26]
            - [`hugo-book2_14_flowchart-engine.svg`][HB2:14 eng.svg] — SVG flowchart of Hugo engine ([generated via Dia]).
        * [`hugo-book2_15.asciidoc`][HB2:15] — [27. _Dark Secrets of the Hugo Debugger_][Ch27]
            - [`hugo-book2_15_flowchart-debugger.svg`][HB2:15 dbg.svg] — SVG flowchart of Hugo debugger ([generated via Dia]).
        * [`hugo-book2_16.asciidoc`][HB2:16] — [App. H. _Code Patterns_][AppH]

## Build Toolchain

- [`build.sh`][build.sh] — (***slow***) generates three documents:
    1. The HTML release of the book in the root folder — fully standalone, embedded graphics, syntax highlighted, custom CSS:
        * [`../hugo-book.html`][HB.html] ( [HTML Live Preview] )
    2. A renamed copy of the HTML release, inside the [`../docs/`][docs] folder, served on the WWW via [GitHub Pages]:
        * [`../docs/index.html`](../docs/index.html)
    3. A standalone AsciiDoc version of the book as a single file, via the [`asciidoc-coalescer.rb`][coalescer.rb] script:
        * [`../hugo-book.asciidoc`](../hugo-book.asciidoc)
- [`preview.sh`][preview.sh] — (***fast***) generates a quick HTML preview of the book:
    + `preview.html` — (ignored by Git) no syntax highlighting, no embedded graphics, use default template.

> __NOTE 1__ — Since the overhead introduced by using the external Highlight tool is considerable on a big document like this one, the `preview.sh` script is very handy when editing the document, for it provides a very fast-updating preview of the changes (without syntax highlighting and custom style).
>
> Furthermore, the `preview.html` doesn't embed graphics via data-URIs, so you won't need to rebuild the whole document to view changed images, but only refresh the page since images are loaded from disk.

<!---------------------------------------------------------------------------->

> __NOTE 2__ — In the future more build scripts will be added, to create other versions of the book in HTML format (e.g. splitting _Book I_ and _Book II_ into independent files, or dividing the book into single chapters for the WWW), as well as targeting other formats (PDF, CHM, ePub, etc.).

# Toolchain Dependencies

The build process depends on further assets stored elsewhere inside this project:

- [`../assets/adoc/haml/`][haml src] — customized Haml templates.
- [`../assets/adoc/highlight-treeprocessor_mod.rb`][HL rb] — customized Asciidoctor extension to support Highlight.
- [`../assets/adoc/hl/`][hl] — custom Highlight DataDir assets.

These assets are required to introduce support for Hugo highlighting in the [Asciidoctor] toolchain via the external [Highlight] tool and our custom syntax definition for Hugo.


# Annotations Conventions

In the AsciiDoc sources of the book I've added comments to annotate contents changes, pending tasks, and other points of interest.
To simplify looking up these notes via editors S&R functionality, I've adopted a formal convention of comment prefixes:

|   comment prefix  |                     indicates                      |
|-------------------|----------------------------------------------------|
| `// @DELME`       | Commented-out contents to delete on final release. |
| `// @EDITED`      | Changes to the original contents.                  |
| `// @FIXME`       | An issue that needs to be addressed.               |
| `// @FOOTNOTE`    | An issue regarding footnotes.                      |
| `// @HUGO SYNTAX` | Syntax highlighting problems.                      |
| `// @NOTE`        | Generic note of interest.                          |
| `// @TEXT`        | Problem or error in original text.                 |
| `// @TODO`        | A pending task.                                    |
| `// @XREF`        | An issue regarding cross references.               |

Often you'll find these prefixes followed by another keyword which narrows down its context. E.g. `// @XREF INTERNAL`, to mark internal cross references inside tables; `// @EDITED TYPO` and `// @EDITED XREF` to distinguish between typo corrections and amended cross references; and so on.
Again, the idea is to use those added words to simplify filtering annotations via S&R, allowing to target specific sets of annotations.

Since annotation prefixes follow an established convention, it's always possible to check if any prefix is present elsewhere in the project, or you're dealing with an isolate issue of that type.

Some of the above prefixes pertain to work in progress which is usually deleted when merging into `master` branch, while others might be left in the sources for the benefit of other contributors.
In any case, the above system will always be used in development branches, as it simplifies looking up what needs to be done or what is the status for any of the topics associated to these prefixes.

# XRefs

The following tables list all the cross references currently used in _The Hugo Book_, and the number of times they occur (__Qt.__ column).

For more details on the custom IDs conventions adopted in this book, see
[`CONVENTIONS.md`](../CONVENTIONS.md#sections-ids-customization).

## Chapters, Appendices and Sections

All the cross-references to chapters, appendices and sections:

|                    Section                    | Qt. |   XRef ID    |
|-----------------------------------------------|-----|--------------|
| _The Hugo Programming Manual_                 |   5 | `book1`      |
| 1.5. Packing List                             |   1 | `sec_1-5`    |
| 1.9. Compiler Switches                        |   1 | `sec_1-9`    |
| 1.10. Limit Settings                          |   1 | `sec_1-10`   |
| 1.11. Directories                             |   1 | `sec_1-11`   |
| 2.3. Data Types                               |   2 | `sec_2-3`    |
| 3.5. Classes                                  |   1 | `sec_3-5`    |
| 4.5. Operators and Assignments                |   1 | `sec_4-5`    |
| 4.7. Conditional Expressions and Program Flow |   2 | `sec_4-7`    |
| 5.1. Routines                                 |   1 | `sec_5-1`    |
| 5.3. Before and After Routines                |   1 | `sec_5-3`    |
| 7.1. Grammar Definition                       |   1 | `sec_7-1`    |
| 7.2. The Parser                               |   1 | `sec_7-2`    |
| 8.7. Perform                                  |   1 | `sec_8-7`    |
| 9. The Game Loop                              |   2 | `chapter_9`  |
| 11.1. The Display Object                      |   1 | `sec_11-1`   |
| 12. Resources                                 |   1 | `chapter_12` |
| App. B: The Hugo Library                      |   3 | `appendix_b` |
| App. B.4. Constants                           |   1 | `sec_b-4`    |
| App. C: Limit Settings                        |   1 | `appendix_c` |
| App. D: HugoFix and the Hugo Debugger         |   5 | `appendix_d` |
| App. E: Precompiled Headers                   |   3 | `appendix_e` |
| App. F. Hugo Versions                         |   2 | `appendix_f` |
| App. G: Additional Resources                  |   1 | `appendix_g` |
| 14.2. The Header                              |   1 | `sec_14-2`   |
| 15.2. Data Types                              |   1 | `sec_15-2`   |
| 23.2. Special Words                           |   1 | `sec_23-2`   |
| 25.2. The Linker                              |   1 | `sec_25-2`   |
| App. H: Code Patterns                         |   2 | `appendix_h` |

## Tables and Figures

All custom IDs for formal tables, figures, and other captioned block-elements.

|  Sec. |    Type    |                   Caption                   |     File Ref     |           XRef ID            |
|-------|------------|---------------------------------------------|------------------|------------------------------|
| §2.3  | [Table 1]  | List of Hugo Data Types                     | `hugo-book1_02#` | `table-hugo-data-types`      |
| §4.1  | [Table 2]  | Predefined Global Variables                 | `hugo-book1_04#` | `table-engine-variables`     |
| §4.3  | [Table 3]  | Standard Colors Defined by the Hugo Library | `hugo-book1_04#` | `table-hugolib-colors`       |
| §8.1  | [Table 4]  | Predefined Global Variables and Properties  | `hugo-book1_08#` | `table-engine-globals`       |
| §8.3  | [Table 5]  | Default ParseError Responses                | `hugo-book1_08#` | `table-parseerror-responses` |
| §14.1 | [Table 6]  | Memory Map of a .HEX File                   | `hugo-book2_02#` | `table-hex-file-map`         |
| §14.2 | [Table 7]  | Memory Map of a .HEX File Header            | `hugo-book2_02#` | `table-hex-file-header-map`  |
| §25   | [Figure 1] | Flowchart of the Hugo Compiler              | `hugo-book2_13#` | `fig-compiler-flowchart`     |
| §26   | [Figure 2] | Flowchart of the Hugo Engine                | `hugo-book2_14#` | `fig-engine-flowchart`       |
| §27   | [Figure 3] | Flowchart of the Hugo Debugger              | `hugo-book2_15#` | `fig-debugger-flowchart`     |
| §27.2 | [Table 8]  | Memory Map of a .HDX File                   | `hugo-book2_15#` | `table-hdx-file-map`         |

## Custom Anchors

These are the custom inline anchors pointing to specific points in the text:

|     File Ref     |        XRef ID         | Qt. |          Description           | Section |
|------------------|------------------------|-----|--------------------------------|---------|
| `hugo-book1_04#` | `hugolib-colors`       |   1 | Colors defined by Hugo Library | §4.3.   |
| `hugo-book1_07#` | `dynamic-grammars1`    |   1 | Dynamic grammars definitions   | §7.1.   |
| `hugo-book1_12#` | `system_status_values` |   1 | `system_status` return values  | §12.1.  |
| `hugo-book1_14#` | `token-case`           |   1 | Tokens table: `case`           | App. H  |
| `hugo-book1_14#` | `token-if`             |   3 | Tokens table: `if`             | App. H  |
| `hugo-book2_05#` | `dynamic-grammars2`    |   1 | Dynamic grammars definitions   | Ch. 17  |


# System Requirements

In order to convert _The Hugo Book_ to HTML you'll need to install the following tools on your system:

- [AsciiDoctor]  (Ruby) and the following Ruby gems:
    + concurrent-ruby
    + haml
    + tilt
- [Highlight]

This project was build by its maintainer under MS Windows 10 x64, using:

- Asciidoctor 2.0.10
- Ruby 2.7.0p0
- Highlight 3.54

The Travis CI build tests the project against the latest stable versions of these packages, to ensure that any compatibility breaking updates are caught in time.

<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

[_Chicago_ style title capitalization]: https://en.wikipedia.org/wiki/The_Chicago_Manual_of_Style "Chicago Manual of Style Capitalization Rules"
[docinfo file]: https://asciidoctor.org/docs/user-manual/#docinfo-file "Read about docinfo files in Asciidoctor Manual"
[generated via Dia]: ../assets_src/diagrams/ "Navigate to folder of SVG Dia sources"
[generated via Sass]: ../assets_src/sass/ "Navigate to Sass sources folder"

<!-- 3rd party tools -->

[AsciiDoctor]: https://asciidoctor.org/ "Visita Asciidoctor website"
[Highlight]: http://www.andre-simon.de/ "Visit Highlight website"
[GitHub Pages]: https://pages.github.com/ "Visit GitHub Pages website"

<!-- Hugo Book Live HTML Links -->

[HTML Live Preview]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html "Click here to preview The Hugo Book via GitHub & BitBucket HTML Preview"

[Colophon]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#colophon "Jump to Live HTML Preview of: COLOPHON"
[Author's Foreword]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#preface "Jump to Live HTML Preview of: AUTHOR’S FOREWORD"

[Book I]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#book1 "Jump to Live HTML Preview of: Book I"
[Ch1]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_1 "Jump to Live HTML Preview of: Book I » 1. INTRODUCTION"
[Ch2]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_2 "Jump to Live HTML Preview of: Book I » 2. A FIRST LOOK AT HUGO"
[Ch3]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_3 "Jump to Live HTML Preview of: Book I » 3. OBJECTS"
[Ch4]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_4 "Jump to Live HTML Preview of: Book I » 4. HUGO PROGRAMMING"
[Ch5]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_5 "Jump to Live HTML Preview of: Book I » 5. ROUTINES AND EVENTS"
[Ch6]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_6 "Jump to Live HTML Preview of: Book I » 6. FUSES, DAEMONS, AND SCRIPTS"
[Ch7]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_7 "Jump to Live HTML Preview of: Book I » 7. GRAMMAR AND PARSING"
[Ch8]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_8 "Jump to Live HTML Preview of: Book I » 8. JUNCTION ROUTINES"
[Ch9]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_9 "Jump to Live HTML Preview of: Book I » 9. THE GAME LOOP"
[Ch10]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_10 "Jump to Live HTML Preview of: Book I » 10. USING THE OBJECT LIBRARY"
[Ch11]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_11 "Jump to Live HTML Preview of: Book I » 11. ADVANCED FEATURES"
[Ch12]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_12 "Jump to Live HTML Preview of: Book I » 12. RESOURCES"
[AppA]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#appendix_a "Jump to Live HTML Preview of: Book I » Appendix A: SUMMARY OF KEYWORDS AND COMMANDS"
[AppB]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#appendix_b "Jump to Live HTML Preview of: Book I » Appendix B: THE HUGO LIBRARY"
[AppC]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#appendix_c "Jump to Live HTML Preview of: Book I » Appendix C: LIMIT SETTINGS"
[AppD]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#appendix_d "Jump to Live HTML Preview of: Book I » Appendix D: HUGOFIX AND THE HUGO DEBUGGER"
[AppE]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#appendix_e "Jump to Live HTML Preview of: Book I » Appendix E: PRECOMPILED HEADERS"
[AppF]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#appendix_f "Jump to Live HTML Preview of: Book I » Appendix F: HUGO VERSIONS"
[AppG]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#appendix_g "Jump to Live HTML Preview of: Book I » Appendix G: ADDITIONAL RESOURCES"

[Book II]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#book2 "Jump to Live HTML Preview of: Book II"
[Ch13]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_13 "Jump to Live HTML Preview of: Book II » 13. INTRODUCTION"
[Ch14]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_14 "Jump to Live HTML Preview of: Book II » 14. ORGANIZATION OF THE .HEX FILE"
[Ch15]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_15 "Jump to Live HTML Preview of: Book II » 15. TOKENS AND DATA TYPES"
[Ch16]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_16 "Jump to Live HTML Preview of: Book II » 16. ENGINE PARSING"
[Ch17]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_17 "Jump to Live HTML Preview of: Book II » 17. GRAMMAR"
[Ch18]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_18 "Jump to Live HTML Preview of: Book II » 18. EXECUTABLE CODE"
[Ch19]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_19 "Jump to Live HTML Preview of: Book II » 19. ENCODING TEXT"
[Ch20]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_20 "Jump to Live HTML Preview of: Book II » 20. THE OBJECT TABLE"
[Ch21]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_21 "Jump to Live HTML Preview of: Book II » 21. THE PROPERTY TABLE"
[Ch22]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_22 "Jump to Live HTML Preview of: Book II » 22. THE EVENT TABLE"
[Ch23]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_23 "Jump to Live HTML Preview of: Book II » 23. THE DICTIONARY AND SPECIAL WORDS"
[Ch24]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_24 "Jump to Live HTML Preview of: Book II » 24. RESOURCEFILES"
[Ch25]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_25 "Jump to Live HTML Preview of: Book II » 25. THE HUGO COMPILER AND HOW IT WORKS"
[Ch26]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_26 "Jump to Live HTML Preview of: Book II » 26. THE HUGO ENGINE AND HOW IT WORKS"
[Ch27]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#chapter_27 "Jump to Live HTML Preview of: Book II » 27. DARK SECRETS OF THE HUGO DEBUGGER"
[AppH]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#appendix_h "Jump to Live HTML Preview of: Book II » Appendix H: CODE PATTERNS"

[Table 1]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#table-hugo-data-types "Live HTML Preview of captioned Table"
[Table 2]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#table-engine-variables "Live HTML Preview of captioned Table"
[Table 3]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#table-hugolib-colors "Live HTML Preview of captioned Table"
[Table 4]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#table-engine-globals "Live HTML Preview of captioned Table"
[Table 5]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#table-parseerror-responses "Live HTML Preview of captioned Table"
[Table 6]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#table-hex-file-map"Live HTML Preview of captioned Table"
[Table 7]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#table-hex-file-header-map"Live HTML Preview of captioned Table"
[Table 8]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#table-hdx-file-map"Live HTML Preview of captioned Table"

[Figure 1]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#fig-compiler-flowchart "Live HTML Preview of captioned Figure"
[Figure 2]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#fig-engine-flowchart "Live HTML Preview of captioned Figure"
[Figure 3]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/hugo-book.html#fig-debugger-flowchart "Live HTML Preview of captioned Figure"

<!-- project files -->

[HB.html]: ../docs/hugo-book.html "View HTML file"

[HL rb]: ../assets/adoc/highlight-treeprocessor_mod.rb "View source file"

[build.sh]: ./build.sh "View source script"
[docinfo.html]: ./docinfo.html "View source file"
[preview.sh]: ./preview.sh "View source script"
[warn-editing]: ./warn-editing.asciidoc "View source file"
[coalescer.rb]: ../assets/adoc/asciidoc-coalescer.rb "View Ruby source file"

[standalone AsciiDoc build]: ../hugo-book.asciidoc "View the preprocessed standalone AsciiDoc version"

<!-- project folders -->

[haml src]: ../assets/adoc/haml/ "Navigate to the Haml HTML5 templates folder"
[hl]: ../assets/hl/ "Navigate to the custom Highlight DataDir folder"
[sass src]: ../assets_src/sass/ "Navigate to Sass sources folder"
[docs]: ../docs/ "Navigate to website contents folder"

<!-- ADoc sources -->

[HB]: ./hugo-book.asciidoc "View AsciiDoc source"

[HB:Colophon]: ./hugo-book0_colophon.asciidoc "View AsciiDoc source"
[HB:Preamble]: ./hugo-book0_preamble.asciidoc "View AsciiDoc source"
[HB:Preface]: ./hugo-book0_preface.asciidoc "View AsciiDoc source"

[HB1]: ./hugo-book1.asciidoc "View AsciiDoc source"
[HB1:01]: ./hugo-book1_01.asciidoc "View AsciiDoc source"
[HB1:02]: ./hugo-book1_02.asciidoc "View AsciiDoc source"
[HB1:03]: ./hugo-book1_03.asciidoc "View AsciiDoc source"
[HB1:04]: ./hugo-book1_04.asciidoc "View AsciiDoc source"
[HB1:05]: ./hugo-book1_05.asciidoc "View AsciiDoc source"
[HB1:06]: ./hugo-book1_06.asciidoc "View AsciiDoc source"
[HB1:07]: ./hugo-book1_07.asciidoc "View AsciiDoc source"
[HB1:08]: ./hugo-book1_08.asciidoc "View AsciiDoc source"
[HB1:09]: ./hugo-book1_09.asciidoc "View AsciiDoc source"
[HB1:10]: ./hugo-book1_10.asciidoc "View AsciiDoc source"
[HB1:11]: ./hugo-book1_11.asciidoc "View AsciiDoc source"
[HB1:12]: ./hugo-book1_12.asciidoc "View AsciiDoc source"
[HB1:13]: ./hugo-book1_13.asciidoc "View AsciiDoc source"
[HB1:14]: ./hugo-book1_14.asciidoc "View AsciiDoc source"
[HB1:15]: ./hugo-book1_15.asciidoc "View AsciiDoc source"
[HB1:16]: ./hugo-book1_16.asciidoc "View AsciiDoc source"
[HB1:17]: ./hugo-book1_17.asciidoc "View AsciiDoc source"
[HB1:18]: ./hugo-book1_18.asciidoc "View AsciiDoc source"
[HB1:19]: ./hugo-book1_19.asciidoc "View AsciiDoc source"

[HB2]: ./hugo-book2.asciidoc "View AsciiDoc source"
[HB2:01]: ./hugo-book2_01.asciidoc "View AsciiDoc source"
[HB2:02]: ./hugo-book2_02.asciidoc "View AsciiDoc source"
[HB2:03]: ./hugo-book2_03.asciidoc "View AsciiDoc source"
[HB2:04]: ./hugo-book2_04.asciidoc "View AsciiDoc source"
[HB2:05]: ./hugo-book2_05.asciidoc "View AsciiDoc source"
[HB2:06]: ./hugo-book2_06.asciidoc "View AsciiDoc source"
[HB2:07]: ./hugo-book2_07.asciidoc "View AsciiDoc source"
[HB2:08]: ./hugo-book2_08.asciidoc "View AsciiDoc source"
[HB2:09]: ./hugo-book2_09.asciidoc "View AsciiDoc source"
[HB2:10]: ./hugo-book2_10.asciidoc "View AsciiDoc source"
[HB2:11]: ./hugo-book2_11.asciidoc "View AsciiDoc source"
[HB2:12]: ./hugo-book2_12.asciidoc "View AsciiDoc source"
[HB2:13]: ./hugo-book2_13.asciidoc "View AsciiDoc source"
[HB2:14]: ./hugo-book2_14.asciidoc "View AsciiDoc source"
[HB2:15]: ./hugo-book2_15.asciidoc "View AsciiDoc source"
[HB2:16]: ./hugo-book2_16.asciidoc "View AsciiDoc source"

[HB Tokens.csv]: ./hugo-book2_03_tokens-list.csv "View CSV source file"

[HB2:13 com.svg]: ./hugo-book2_13_flowchart-compiler.svg "Open diagram image file"
[HB2:14 eng.svg]: ./hugo-book2_14_flowchart-engine.svg "Open diagram image file"
[HB2:15 dbg.svg]: ./hugo-book2_15_flowchart-debugger.svg "Open diagram image file"

[HB1:3 objT1.svg]: ./hugo-book1_03_object-tree1.svg "Open diagram image file"
[HB1:3 objT2.svg]: ./hugo-book1_03_object-tree2.svg "Open diagram image file"
[HB1:3 objT3.svg]: ./hugo-book1_03_object-tree3.svg "Open diagram image file"

<!-- Issues and milestones -->

[#13]: https://github.com/tajmone/hugo-book/issues/13
[#21]: https://github.com/tajmone/hugo-book/issues/21
[#22]: https://github.com/tajmone/hugo-book/issues/22
[#24]: https://github.com/tajmone/hugo-book/issues/24
[#25]: https://github.com/tajmone/hugo-book/issues/25
[#26]: https://github.com/tajmone/hugo-book/issues/26
[#35]: https://github.com/tajmone/hugo-book/issues/35
[milestone 4]: https://github.com/tajmone/hugo-book/milestone/4
[milestone 6]: https://github.com/tajmone/hugo-book/milestone/6


[All Issues relating to the porting stage]: https://github.com/tajmone/hugo-book/issues?q=is%3Aopen+is%3Aissue+project%3Atajmone%2Fhugo-book%2F1
[All Issues to be handled before 1st release]: https://github.com/tajmone/hugo-book/issues?q=is%3Aopen+is%3Aissue+project%3Atajmone%2Fhugo-book%2F2

<!-- EOF -->
