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
- [Book Status](#book-status)
    - [List of Book-Wide Task](#list-of-book-wide-task)
    - [Chapters Status and Previews](#chapters-status-and-previews)
- [Annotations Convention](#annotations-convention)
- [XRefs](#xrefs)
    - [Chapters, Appendices and Sections](#chapters-appendices-and-sections)
    - [Custom Anchors](#custom-anchors)
- [Custom IDs](#custom-ids)
    - [Chapters, Appendices and Sections](#chapters-appendices-and-sections-1)
    - [Tables, Figures, Etc.](#tables-figures-etc)
- [System Requirements](#system-requirements)

<!-- /MarkdownTOC -->

-----

# Folder Contents

## Book Sources

List of _The Hugo Book_ AsciiDoc sources and contents-assets:

- [`docinfo.html`][docinfo.html] — [docinfo file] with custom CSS ([generated via Sass]).
- [`hugo-book.asciidoc`][HB] — the main AsciiDoc source file (contains _[Colophon]_ and _[Foreword]_) that imports all contents:
    + [`hugo-book0_preamble.asciidoc`][HB:Preamble] — Document Preamble.
    + [`hugo-book0_colophon.asciidoc`][HB:Colophon] — [_COLOPHON_][COLOPHON]
    + [`hugo-book0_preface.asciidoc`][HB:Preface] — [_AUTHOR'S FOREWORD_][FOREWORD]
    + [`hugo-book1.asciidoc`][HB1] — imports chapters of _Book I_:
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
    + [`hugo-book2.asciidoc`][HB2] — imports chapters of _Book II_:
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

- [`build.sh`][build.sh] — (***slow***) generates final HTML version of the book:
    + [`hugo-book.html`][HB.html] ( [HTML Live Preview] ) — fully standalone, embedded graphics, syntax highlighted, custom CSS.
- [`preview.sh`][preview.sh] — (***fast***) generates a quick HTML preview of the book:
    + `preview.html` — no syntax highlighting, no embedded graphics, use default template. (ignored by Git)

> __NOTE 1__ — Since the overhead introduced by using the external Highlight tool is considerable on a big document like this one, the `preview.sh` script is very handy when editing the document, for it provides a very fast-updating preview of the changes (without syntax highlighting).
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


# Book Status

The initial Word-to-AsciiDoc porting stage is now completed: all the basic style elements are in place, and the whole text as been proofread.

There's still a lot of work to be done in terms of enforcing consistent styles, _ad hoc_ customizations, and solving various problems.

## List of Book-Wide Task

- [x] Word to AsciiDoc porting and basic formatting and styles clean-up.
- [x] **XREFS** — Restore all XRefs and create custom anchors ([milestone 6], [#25]).
- [ ] **FOOTNOTES:** ([milestone 4])
    + [x] Proofread and format all footnotes. ([#21])
    + [x] Decide how to handle:
        * [x] Identical footnotes. ([#24])
        * [x] Footnotes inside tables. ([#22])
- [ ] **TITLE CASE** — Enforce [_Chicago_ style title capitalization]  ([#13]):
    + [x] All chapters and appendices titles (from all-caps).
    + [x] All sections.
    + [ ] All captions (tables, figures, etc.).
- [ ] **CODE BLOCKS:**
    + [ ] __Hugo code__:
        * [ ] Enforce consistent indentation:
            - [ ] 4 spaces in book examples.
            - [ ] original indentation (8 spaces) in hugolib and other sources.
        * [ ] Fix Hugo syntax examples (requires _ad hoc_ Highlight syntax).
    + [ ] __Hugo syntax__ definitions ([#35]):
        * [ ] Covert from `source` to `literal, role="hugosyntax"` blocks.
        * [ ] Customize CSS.
- [ ] Solve all annotated problems.


## Chapters Status and Previews

The tasks list below indicates the status of the pending tasks after the initial Word-to-AsciiDoc porting stage.

Every chapter in the list provides an [HTML Live Preview] link to quickly jump to its position in the single-file online preview.

- [ ]  [_COLOPHON_][COLOPHON]:
    + [ ]  Custom styling and adaptation to HTML5 version.
- [ ]  [_AUTHOR'S FOREWORD_][FOREWORD]:
    + [ ]  Custom styling and adaptation to HTML5 version.
- [ ]  [BOOK I. **THE HUGO PROGRAMMING MANUAL**][Book I]
    + [ ]  [1. _INTRODUCTION_][Ch1]
        * No Hugo code to check.
    + [x]  [2. _A FIRST LOOK AT HUGO_][Ch2]
        * [x]  Check/Fix Hugo code indentation.
        * [x]  Convert Hugo syntax definitions to `literal, role="hugosyntax"` blocks.
    + [x]  [3. _OBJECTS_][Ch3]
        * [x]  Check/Fix Hugo code indentation.
        * [x]  Convert Hugo syntax definitions to `literal, role="hugosyntax"` blocks.
    + [ ]  [4. _HUGO PROGRAMMING_][Ch4]
        * [ ]  Check/Fix Hugo code indentation.
        * [ ]  Convert Hugo syntax definitions to `literal, role="hugosyntax"` blocks.
    + [ ]  [5. _ROUTINES AND EVENTS_][Ch5]
        * [ ]  Check/Fix Hugo code indentation.
        * [ ]  Convert Hugo syntax definitions to `literal, role="hugosyntax"` blocks.
    + [ ]  [6. _FUSES, DAEMONS, AND SCRIPTS_][Ch6]
        * [ ]  Check/Fix Hugo code indentation.
        * [ ]  Convert Hugo syntax definitions to `literal, role="hugosyntax"` blocks.
    + [ ]  [7. _GRAMMAR AND PARSING_][Ch7]
        * [ ]  Check/Fix Hugo code indentation.
        * [ ]  Convert Hugo syntax definitions to `literal, role="hugosyntax"` blocks.
    + [ ]  [8. _JUNCTION ROUTINES_][Ch8]
        * [ ]  Check/Fix Hugo code indentation.
        * [ ]  Convert Hugo syntax definitions to `literal, role="hugosyntax"` blocks.
    + [ ]  [9. _THE GAME LOOP_][Ch9]
        * [ ]  Check/Fix Hugo code indentation.
        * [ ]  Convert Hugo syntax definitions to `literal, role="hugosyntax"` blocks.
    + [ ]  [10. _USING THE OBJECT LIBRARY_][Ch10]
        * [ ]  Check/Fix Hugo code indentation.
        * [ ]  Convert Hugo syntax definitions to `literal, role="hugosyntax"` blocks.
    + [ ]  [11. _ADVANCED FEATURES_][Ch11]
        * [ ]  Check/Fix Hugo code indentation.
        * [ ]  Convert Hugo syntax definitions to `literal, role="hugosyntax"` blocks.
    + [ ]  [12. _RESOURCES_][Ch12]
        * [ ]  Check/Fix Hugo code indentation.
        * [ ]  Convert Hugo syntax definitions to `literal, role="hugosyntax"` blocks.
    + [ ]  [APP. A. _SUMMARY OF KEYWORDS AND COMMANDS_][AppA]
        * [ ]  _needs to be proof-read once more, carefully!_
        * [ ]  Check/Fix Hugo code indentation.
        * [ ]  Convert Hugo syntax definitions to `literal, role="hugosyntax"` blocks.
    + [ ]  [APP. B. _THE HUGO LIBRARY_][AppB]
        * [ ]  _needs to be proof-read once more, carefully!_
        * [ ]  Check/Fix Hugo code indentation.
        * [ ]  Convert Hugo syntax definitions to `literal, role="hugosyntax"` blocks.
    + [ ]  [APP. C. _LIMIT SETTINGS_][AppC]
        * [ ]  _needs to be proof-read once more, carefully!_
        * [ ]  Check/Fix Hugo code indentation.
    + [ ]  [APP. D. _HUGOFIX AND THE HUGO DEBUGGER_][AppD]
        * [ ]  _needs to be proof-read once more, carefully!_
        * [ ]  Check/Fix Hugo code indentation.
        * [ ]  Convert Hugo syntax definitions to `literal, role="hugosyntax"` blocks.
    + [ ]  [APP. E. _PRECOMPILED HEADERS_][AppE]
        * [ ]  Check/Fix Hugo code indentation.
    + [ ]  [APP. F. _HUGO VERSIONS_][AppF]
        * [ ]  Check/Fix Hugo code indentation.
    + [ ]  [APP. G. _ADDITIONAL RESOURCES_][AppG]
        * [ ]  Check/Fix Hugo code indentation.
- [ ]  [BOOK II. **TECHNICAL SYSTEM SPECIFICATION**][Book II]
    + [ ]  [13. _INTRODUCTION_][Ch13]
        * [ ]  Check/Fix Hugo code indentation.
    + [ ]  [14. _ORGANIZATION OF THE .HEX FILE_][Ch14]
        * [ ]  Check/Fix Hugo code indentation.
    + [ ]  [15. _TOKENS AND DATA TYPES_][Ch15]
        * [ ]  Check/Fix Hugo code indentation.
    + [ ]  [16. _ENGINE PARSING_][Ch16]
        * [ ]  Check/Fix Hugo code indentation.
    + [ ]  [17. _GRAMMAR_][Ch17]
        * [ ]  Check/Fix Hugo code indentation.
    + [ ]  [18. _EXECUTABLE CODE_][Ch18]
        * [ ]  Check/Fix Hugo code indentation.
    + [ ]  [19. _ENCODING TEXT_][Ch19]
        * [ ]  Check/Fix Hugo code indentation.
    + [ ]  [20. _THE OBJECT TABLE_][Ch20]
        * [ ]  Check/Fix Hugo code indentation.
    + [ ]  [21. _THE PROPERTY TABLE_][Ch21]
        * [ ]  Check/Fix Hugo code indentation.
    + [ ]  [22. _THE EVENT TABLE_][Ch22]
        * [ ]  Check/Fix Hugo code indentation.
    + [ ]  [23. _THE DICTIONARY AND SPECIAL WORDS_][Ch23]
        * [ ]  Check/Fix Hugo code indentation.
    + [ ]  [24. _RESOURCEFILES_][Ch24]
        * Title capitalization: _no sections._
        *  (_no XRefs_).
        *  (_No footnotes_).
    + [ ]  [25. _THE HUGO COMPILER AND HOW IT WORKS_][Ch25]
        * [ ]  Check/Fix Hugo code indentation.
    + [ ]  [26. _THE HUGO ENGINE AND HOW IT WORKS_][Ch26]
        * [ ]  Check/Fix Hugo code indentation.
    + [ ]  [27. _DARK SECRETS OF THE HUGO DEBUGGER_][Ch27]
        * [ ]  Check/Fix Hugo code indentation.
    + [ ]  [APP. H. _CODE PATTERNS_][AppH]
        * [ ]  _needs to be proof-read once more, carefully!_
        * [ ]  Check/Fix Hugo code indentation.
- [ ] _INDEX_ (supported only in PDF format)


# Annotations Convention

In the AsciiDoc sources of the book I've added comments to annotate contents changes, pending tasks, and other points of interest.
To simplify looking up these notes via editors S&R functionality, I've adopted a formal annotation convention:

|   comment start   |                     indicates                      |
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

<!--
| `// @xxx`     | xxx.                                                |
-->

Most of these notes pertain work in progress and will be deleted on final release, while other might be left in the sources for the benefit of other contributors.

# XRefs

The following tables list all the cross references currently used in _The Hugo Book_, and the number of times they occur (__Qt.__ column).

## Chapters, Appendices and Sections

All the cross-references to chapters, appendices and sections:

|                    Section                    | Qt. |                         XRef ID                          |
|-----------------------------------------------|-----|----------------------------------------------------------|
| _The Hugo Programming Manual_                 |   5 | `hugo-book1#book1`                                       |
| 1.5. Packing List                             |   1 | `packing_list`                                           |
| 1.9. Compiler Switches                        |   1 | `compiler_switches`                                      |
| 1.10. Limit Settings                          |   1 | `limit_settings`                                         |
| 1.11. Directories                             |   1 | `directories`                                            |
| 2.3. Data Types                               |   2 | `hugo-book1_02#data_types`                               |
| 3.5. Classes                                  |   1 | `classes`                                                |
| 4.5. Operators and Assignments                |   1 | `hugo-book1_04#operators_and_assignments`                |
| 4.7. Conditional Expressions and Program Flow |   2 | `hugo-book1_04#conditional_expressions_and_program_flow` |
| 5.1. Routines                                 |   1 | `hugo-book1_05#routines`                                 |
| 5.3. Before and After Routines                |   1 | `hugo-book1_05#before_and_after_routines`                |
| 7.1. Grammar Definition                       |   1 | `hugo-book1_07#grammar_definition`                       |
| 7.2. The Parser                               |   1 | `hugo-book1_07#the_parser`                               |
| 8.7. Perform                                  |   1 | `hugo-book1_08#perform`                                  |
| 9. The Game Loop                              |   2 | `hugo-book1_09#the_game_loop`                            |
| 11.1. The Display Object                      |   1 | `hugo-book1_11#the_display_object`                       |
| 12. Resources                                 |   1 | `hugo-book1_12#resources`                                |
| App. B: The Hugo Library                      |   3 | `hugo-book1_14#the_hugo_library`                         |
| App. B.4. Constants                           |   1 | `#constants_2`                                           |
| App. C: Limit Settings                        |   1 | `hugo-book1_15#limit_settings_2`                         |
| App. D: HugoFix and the Hugo Debugger         |   5 | `hugo-book1_16#hugofix_and_the_hugo_debugger`            |
| App. E: Precompiled Headers                   |   3 | `hugo-book1_17#precompiled_headers`                      |
| App. F. Hugo Versions                         |   2 | `hugo-book1_18#hugo_versions`                            |
| App. G: Additional Resources                  |   1 | `hugo-book1_19#additional_resources`                     |
| 14.2. The Header                              |   1 | `hugo-book2_02#the_header`                               |
| 15.2. Data Types                              |   1 | `hugo-book2_03#15-2_data_types`                          |
| 23.2. Special Words                           |   1 | `hugo-book2_11#special_words`                            |
| 25.2. The Linker                              |   1 | `hugo-book2_13#the_linker`                               |
| App. H: Code Patterns                         |   2 | `hugo-book2_16#code_patterns`                            |

> __NOTE 1__ — Xrefs not preceded by the file name are internal cross-references to the same document.

<!--  -->

> __NOTE 2__ — To avoid conflicts with same-names sections, in some places I had to introduce a custom ID (eg. `hugo-book2_03#15-2_data_types`).
> Later on, I should customize all referenced Chapters, Sections and Appendices using a standard naming convention for IDs (See [#26]).


## Custom Anchors

These are the custom inline anchors pointing to specific points in the text:

|               XRef ID                | Qt. |          Description           | Section |
|--------------------------------------|-----|--------------------------------|---------|
| `hugo-book1_04#hugolib-colors`       |   1 | Colors defined by Hugo Library | §4.3.   |
| `hugo-book1_12#system_status_values` |   1 | `system_status` return values  | §12.1.  |
| `hugo-book1_14#token-case`           |   1 | Tokens table: `case`           | App. H  |
| `hugo-book1_14#token-if`             |   3 | Tokens table: `if`             | App. H  |

# Custom IDs

Here's a complete list of the custom defined IDs replacing the auto-generated IDs.
Even if not all of them are used by actual XRefs, they provide a consistent naming convention for anchors in HTML based documents.

## Chapters, Appendices and Sections

> __NOTE__ — Missing table, will be added once all the section IDs are customized (see [#26]).

## Tables, Figures, Etc.

All custom IDs for formal tables, figures, and other captioned block-elements.

|  Type |                   Caption                   |               XRef ID                |
|-------|---------------------------------------------|--------------------------------------|
| Table | Standard Colors Defined by the Hugo Library | `hugo-book1_04#table-hugolib-colors` |

# System Requirements

In order to convert _The Hugo Book_ to HTML you'll need to install the following tools on your system:

- [AsciiDoctor]  (Ruby)
- [Highlight]

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

<!-- Live HTML Links -->

[HTML Live Preview]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html "Click here to preview The Hugo Book via GitHub & BitBucket HTML Preview"

[COLOPHON]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_colophon "Jump to Live HTML Preview of: COLOPHON"
[FOREWORD]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_authors_foreword "Jump to Live HTML Preview of: AUTHOR’S FOREWORD"

[Book I]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_book_1_the_hugo_programming_manual "Jump to Live HTML Preview of: Book I"
[Ch1]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_introduction "Jump to Live HTML Preview of: Book I » 1. INTRODUCTION"
[Ch2]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_a_first_look_at_hugo "Jump to Live HTML Preview of: Book I » 2. A FIRST LOOK AT HUGO"
[Ch3]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_objects "Jump to Live HTML Preview of: Book I » 3. OBJECTS"
[Ch4]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_hugo_programming "Jump to Live HTML Preview of: Book I » 4. HUGO PROGRAMMING"
[Ch5]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_routines_and_events "Jump to Live HTML Preview of: Book I » 5. ROUTINES AND EVENTS"
[Ch6]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_fuses_daemons_and_scripts "Jump to Live HTML Preview of: Book I » 6. FUSES, DAEMONS, AND SCRIPTS"
[Ch7]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_grammar_and_parsing "Jump to Live HTML Preview of: Book I » 7. GRAMMAR AND PARSING"
[Ch8]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_junction_routines "Jump to Live HTML Preview of: Book I » 8. JUNCTION ROUTINES"
[Ch9]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_the_game_loop "Jump to Live HTML Preview of: Book I » 9. THE GAME LOOP"
[Ch10]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_using_the_object_library "Jump to Live HTML Preview of: Book I » 10. USING THE OBJECT LIBRARY"
[Ch11]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_advanced_features "Jump to Live HTML Preview of: Book I » 11. ADVANCED FEATURES"
[Ch12]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_resources "Jump to Live HTML Preview of: Book I » 12. RESOURCES"
[AppA]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_summary_of_keywords_and_commands "Jump to Live HTML Preview of: Book I » Appendix A: SUMMARY OF KEYWORDS AND COMMANDS"
[AppB]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_the_hugo_library "Jump to Live HTML Preview of: Book I » Appendix B: THE HUGO LIBRARY"
[AppC]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_limit_settings_2 "Jump to Live HTML Preview of: Book I » Appendix C: LIMIT SETTINGS"
[AppD]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_hugofix_and_the_hugo_debugger "Jump to Live HTML Preview of: Book I » Appendix D: HUGOFIX AND THE HUGO DEBUGGER"
[AppE]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_precompiled_headers "Jump to Live HTML Preview of: Book I » Appendix E: PRECOMPILED HEADERS"
[AppF]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_hugo_versions "Jump to Live HTML Preview of: Book I » Appendix F: HUGO VERSIONS"
[AppG]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_additional_resources "Jump to Live HTML Preview of: Book I » Appendix G: ADDITIONAL RESOURCES"

[Book II]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_book_2_technical_system_specification "Jump to Live HTML Preview of: Book II"
[Ch13]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_introduction_3 "Jump to Live HTML Preview of: Book II » 13. INTRODUCTION"
[Ch14]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_organization_of_the_hex_file "Jump to Live HTML Preview of: Book II » 14. ORGANIZATION OF THE .HEX FILE"
[Ch15]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_tokens_and_data_types "Jump to Live HTML Preview of: Book II » 15. TOKENS AND DATA TYPES"
[Ch16]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_engine_parsing "Jump to Live HTML Preview of: Book II » 16. ENGINE PARSING"
[Ch17]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_grammar "Jump to Live HTML Preview of: Book II » 17. GRAMMAR"
[Ch18]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_executable_code "Jump to Live HTML Preview of: Book II » 18. EXECUTABLE CODE"
[Ch19]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_encoding_text "Jump to Live HTML Preview of: Book II » 19. ENCODING TEXT"
[Ch20]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_the_object_table "Jump to Live HTML Preview of: Book II » 20. THE OBJECT TABLE"
[Ch21]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_the_property_table "Jump to Live HTML Preview of: Book II » 21. THE PROPERTY TABLE"
[Ch22]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_the_event_table "Jump to Live HTML Preview of: Book II » 22. THE EVENT TABLE"
[Ch23]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_the_dictionary_and_special_words "Jump to Live HTML Preview of: Book II » 23. THE DICTIONARY AND SPECIAL WORDS"
[Ch24]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_resourcefiles "Jump to Live HTML Preview of: Book II » 24. RESOURCEFILES"
[Ch25]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_the_hugo_compiler_and_how_it_works "Jump to Live HTML Preview of: Book II » 25. THE HUGO COMPILER AND HOW IT WORKS"
[Ch26]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_the_hugo_engine_and_how_it_works "Jump to Live HTML Preview of: Book II » 26. THE HUGO ENGINE AND HOW IT WORKS"
[Ch27]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_dark_secrets_of_the_hugo_debugger "Jump to Live HTML Preview of: Book II » 27. DARK SECRETS OF THE HUGO DEBUGGER"
[AppH]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs_src/hugo-book.html#_code_patterns "Jump to Live HTML Preview of: Book II » Appendix H: CODE PATTERNS"

<!-- project files -->

[HB.html]: ./hugo-book.html "View HTML file"

[HL rb]: ../assets/adoc/highlight-treeprocessor_mod.rb "View source file"

[build.sh]: ./build.sh "View source script"
[docinfo.html]: ./docinfo.html "View source file"
[preview.sh]: ./preview.sh "View source script"

<!-- project folders -->

[haml src]: ../assets/adoc/haml/ "Navigate to the Haml HTML5 templates folder"
[hl]: ../assets/hl/ "Navigate to the custom Highlight DataDir folder"
[sass src]: ../assets_src/sass/ "Navigate to Sass sources folder"

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

<!-- EOF -->
