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
- [ ] **FOOTNOTES** — Proofread, format and fix all footnotes. (see [#21], [#24] and [milestone 4])
- [ ] **TITLE CASE** — Enforce [_Chicago_ style title capitalization]  (see [#13]):
    + [ ] All chapters and appendices titles (from all-caps).
    + [ ] All sections.
    + [ ] All captions (tables, figures, etc.).
- [ ] **XREFS** — Restore all XRefs and create custom anchors.
- [ ] **CODE BLOCKS:**
    + [ ] Hugo code:
        * [ ] Enforce consistent indentation.
        * [ ] Fix Hugo syntax examples (requires _ad hoc_ Highlight syntax).
- [ ] Solve all annotated problems.


## Chapters Status and Previews

The tasks list below indicates the status of the pending tasks after the initial Word-to-AsciiDoc porting stage.

Every chapter in the list provides an [HTML Live Preview] link to quickly jump to its position in the single-file online preview.

- [ ]  [_COLOPHON_][COLOPHON]:
    + [ ]  Custom styling and adaptation to HTML5 version.
- [ ]  [_AUTHOR'S FOREWORD_][FOREWORD]:
    + [ ]  Custom styling and adaptation to HTML5 version.
    + [ ]  Fix all XRefs.
- [ ]  [BOOK 1. **THE HUGO PROGRAMMING MANUAL**][Book I]
    + [ ]  [1. _INTRODUCTION_][Ch1]
        * [ ]  Fix all XRefs.
        * [x]  Fix footnotes (**3**).
    + [ ]  [2. _A FIRST LOOK AT HUGO_][Ch2]
        * [ ]  Fix all XRefs.
        * [x]  Fix footnotes (**7**);
            - [x]  1 footnote inside code.
    + [ ]  [3. _OBJECTS_][Ch3]
        * [ ]  Fix all XRefs.
        * [ ]  Fix footnotes (**10**):
            - [ ]  3 footnotes inside table.
            - [ ]  1 footnote inside code.
    + [ ]  [4. _HUGO PROGRAMMING_][Ch4]
        * [ ]  Fix all XRefs.
        * [x]  Fix footnotes (**9**):
            - [x]  1 footnote inside code.
    + [ ]  [5. _ROUTINES AND EVENTS_][Ch5]
        * [ ]  Fix all XRefs.
        * [x]  Fix footnotes (**10**).
    + [ ]  [6. _FUSES, DAEMONS, AND SCRIPTS_][Ch6]
        * [ ]  Fix all XRefs.
        * [x]  Fix footnotes (**1**).
    + [ ]  [7. _GRAMMAR AND PARSING_][Ch7]
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
    + [ ]  [8. _JUNCTION ROUTINES_][Ch8]
        * [ ]  Fix all XRefs.
        * [x]  Fix footnotes (**6**).
    + [ ]  [9. _THE GAME LOOP_][Ch9]
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
    + [ ]  [10. _USING THE OBJECT LIBRARY_][Ch10]
        * [ ]  Fix all XRefs.
        * [x]  Fix footnotes (**10**):
            - [x]  2 footnotes inside code.
     + [ ]  [11. _ADVANCED FEATURES_][Ch11]
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
    + [ ]  [12. _RESOURCES_][Ch12]
        * [ ]  Fix all XRefs.
        * [x]  Fix footnotes (**2**).
    + [ ]  [APP. A. _SUMMARY OF KEYWORDS AND COMMANDS_][AppA]
        * [ ]  _needs to be proof-read once more, carefully!_
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
    + [ ]  [APP. B. _THE HUGO LIBRARY_][AppB]
        * [ ]  _needs to be proof-read once more, carefully!_
        * [ ]  Fix all XRefs.
        * [ ]  Fix footnotes (**2**):
            - [ ]  2 footnotes inside tables.
    + [ ]  [APP. C. _LIMIT SETTINGS_][AppC]
        * [ ]  _needs to be proof-read once more, carefully!_
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
    + [ ]  [APP. D. _HUGOFIX AND THE HUGO DEBUGGER_][AppD]
        * [ ]  _needs to be proof-read once more, carefully!_
        * [ ]  Fix all XRefs.
        * [x]  Fix footnotes (**2**).
    + [ ]  [APP. E. _PRECOMPILED HEADERS_][AppE]
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
    + [ ]  [APP. F. _HUGO VERSIONS_][AppF]
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
    + [ ]  [APP. G. _ADDITIONAL RESOURCES_][AppG]
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
- [ ]  [BOOK 2. **TECHNICAL SYSTEM SPECIFICATION**][Book II]
    + [ ]  [13. _INTRODUCTION_][Ch13]
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
    + [ ]  [14. _ORGANIZATION OF THE .HEX FILE_][Ch14]
        * [ ]  Fix all XRefs.
        * [ ]  Fix footnotes (**6**):
            - [ ]  5 footnotes inside tables.
    + [ ]  [15. _TOKENS AND DATA TYPES_][Ch15]
        * [ ]  Fix all XRefs.
        * [ ]  Fix footnotes (**1**).
    + [ ]  [16. _ENGINE PARSING_][Ch16]
        * [ ]  Fix all XRefs.
        * [x]  Fix footnotes (**1**).
    + [ ]  [17. _GRAMMAR_][Ch17]
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
    + [ ]  [18. _EXECUTABLE CODE_][Ch18]
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
    + [ ]  [19. _ENCODING TEXT_][Ch19]
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
    + [ ]  [20. _THE OBJECT TABLE_][Ch20]
        * [ ]  Fix all XRefs.
        * [x]  Fix footnotes (**2**).
    + [ ]  [21. _THE PROPERTY TABLE_][Ch21]
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
    + [ ]  [22. _THE EVENT TABLE_][Ch22]
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
    + [ ]  [23. _THE DICTIONARY AND SPECIAL WORDS_][Ch23]
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
    + [ ]  [24. _RESOURCEFILES_][Ch24]
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
    + [ ]  [25. _THE HUGO COMPILER AND HOW IT WORKS_][Ch25]
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
    + [ ]  [26. _THE HUGO ENGINE AND HOW IT WORKS_][Ch26]
        * [ ]  Fix all XRefs.
        * [ ]  Fix footnotes (**1**):
            - [ ]  1 footnote inside tables.
    + [ ]  [27. _DARK SECRETS OF THE HUGO DEBUGGER_][Ch27]
        * [ ]  Fix all XRefs.
        *  (_No footnotes_).
    + [ ]  [APP. H. _CODE PATTERNS_][AppH]
        * [ ]  _needs to be proof-read once more, carefully!_
        * [ ]  Fix all XRefs.
        * [ ]  Fix footnotes (**11**)
            - [ ]  11 footnotes inside tables (many duplicate notes):
                * [ ]  9 of these footnotes are inside code-blocks.
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
[#24]: https://github.com/tajmone/hugo-book/issues/24
[milestone 4]: https://github.com/tajmone/hugo-book/milestone/4

<!-- EOF -->
