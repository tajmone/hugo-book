# Hugo Book AsciiDoc Sources

This folder contains the AsciiDoc source files of the _The Hugo Book_.

- [HTML Live Preview] — _The Hugo Book_ in a single HTML document.

-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3" -->

- [Folder Contents](#folder-contents)
- [Book Preview and Status](#book-preview-and-status)

<!-- /MarkdownTOC -->

-----

# Folder Contents


- [hugo-book.asciidoc] — the main AsciiDoc source file that imports all contents:
    + [hugo-book1.asciidoc] — imports chapters of _Book I_:
        * hugo-book1_??.asciidoc — individual chapters from _Book I_.
    + [hugo-book2.asciidoc] — imports chapters of _Book II_:
        * hugo-book2_??.asciidoc — individual chapters from _Book II_.
        * [hugo-book_tokens-list.csv] — list of Hugo tokens in CSV format, used to populate the table in _§15.1. Tokens_.
- [preview.sh] — generates a quick HTML preview of the book:
    + [hugo-book.html] ( [HTML Live Preview] ) — no syntax highlighting, no custom template.

# Book Preview and Status

The tasks list below indicates the current status of the initial Word-to-AsciiDoc porting stage.

Every chapter in the list provides an [HTML Live Preview] link to quickly jump to its position in the single-file online preview.


- [ ]  [_COLOPHON_][COLOPHON]
- [ ]  [_AUTHOR'S FOREWORD_][FOREWORD]
- [ ]  [BOOK 1. **THE HUGO PROGRAMMING MANUAL**][Book I]
    + [ ]  [1. _INTRODUCTION_][Ch1]
    + [ ]  [2. _A FIRST LOOK AT HUGO_][Ch2]
    + [ ]  [3. _OBJECTS_][Ch3]
    + [ ]  [4. _HUGO PROGRAMMING_][Ch4]
    + [ ]  [5. _ROUTINES AND EVENTS_][Ch5]
    + [ ]  [6. _FUSES, DAEMONS, AND SCRIPTS_][Ch6]
    + [ ]  [7. _GRAMMAR AND PARSING_][Ch7]
    + [ ]  [8. _JUNCTION ROUTINES_][Ch8]
    + [ ]  [9. _THE GAME LOOP_][Ch9]
    + [ ]  [10. _USING THE OBJECT LIBRARY_][Ch10]
    + [ ]  [11. _ADVANCED FEATURES_][Ch11]
    + [ ]  [12. _RESOURCES_][Ch12]
    + [ ]  [APP. A. _SUMMARY OF KEYWORDS AND COMMANDS_][AppA]
    + [ ]  [APP. B. _THE HUGO LIBRARY_][AppB]
    + [ ]  [APP. C. _LIMIT SETTINGS_][AppC]
    + [ ]  [APP. D. _HUGOFIX AND THE HUGO DEBUGGER_][AppD]
    + [ ]  [APP. E. _PRECOMPILED HEADERS_][AppE]
    + [ ]  [APP. F. _HUGO VERSIONS_][AppF]
    + [ ]  [APP. G. _ADDITIONAL RESOURCES_][AppG]
- [ ]  [BOOK 2. **TECHNICAL SYSTEM SPECIFICATION**][Book II]
    + [x]  [13. _INTRODUCTION_][Ch13]
    + [x]  [14. _ORGANIZATION OF THE .HEX FILE_][Ch14]
    + [ ]  [15. _TOKENS AND DATA TYPES_][Ch15]
    + [ ]  [16. _ENGINE PARSING_][Ch16]
    + [ ]  [17. _GRAMMAR_][Ch17]
    + [ ]  [18. _EXECUTABLE CODE_][Ch18]
    + [ ]  [19. _ENCODING TEXT_][Ch19]
    + [ ]  [20. _THE OBJECT TABLE_][Ch20]
    + [ ]  [21. _THE PROPERTY TABLE_][Ch21]
    + [ ]  [22. _THE EVENT TABLE_][Ch22]
    + [ ]  [23. _THE DICTIONARY AND SPECIAL WORDS_][Ch23]
    + [ ]  [24. _RESOURCEFILES_][Ch24]
    + [x]  [25. _THE HUGO COMPILER AND HOW IT WORKS_][Ch25]
    + [x]  [26. _THE HUGO ENGINE AND HOW IT WORKS_][Ch26]
    + [ ]  [27. _DARK SECRETS OF THE HUGO DEBUGGER_][Ch27]
    + [ ]  [APP. H. _CODE PATTERNS_][AppH]
- [ ] _INDEX_ (supported only in PDF format)

Once all chapter are fuly ported, the whole book needs to be checked over again, from scratch, to ensure that formatting and sytles are consistent.

<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

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

[hugo-book.html]: ./hugo-book.html "View source file"
[preview.sh]: ./preview.sh "View source file"

<!-- ADoc sources -->

[hugo-book.asciidoc]: ./hugo-book.asciidoc "View source file"
[hugo-book1.asciidoc]: ./hugo-book1.asciidoc "View source file"
[hugo-book2.asciidoc]: ./hugo-book2.asciidoc "View source file"

[hugo-book_tokens-list.csv]: ./hugo-book_tokens-list.csv "View CSV source file"


<!-- EOF -->
