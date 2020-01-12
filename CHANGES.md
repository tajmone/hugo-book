# List of Changes

This document lists all the contents changes that theAsciiDoc edition has introduced in _The Hugo Book_.


-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3,4" -->

- [Introduction](#introduction)
    - [Text Corrections](#text-corrections)
    - [Aesthetic and Functional Changes](#aesthetic-and-functional-changes)
    - [Library Code Updates](#library-code-updates)
- [Changes List](#changes-list)
    - [Book I](#book-i)
        - [1. Introduction](#1-introduction)
            - [1.5. _Packing List_](#15-packing-list)
            - [1.10. _Limit Settings_](#110-limit-settings)
        - [2. A First Look at Hugo](#2-a-first-look-at-hugo)
            - [2.4. _Multiple Lines_](#24-multiple-lines)
        - [4. Hugo Programming](#4-hugo-programming)
            - [4.8. _What Should I Be Able to Do Now?_](#48-what-should-i-be-able-to-do-now)
        - [5. Routines and Events](#5-routines-and-events)
            - [5.3. _Before And After Routines_](#53-before-and-after-routines)
        - [9. The Game Loop](#9-the-game-loop)
            - [9.2. _What Should I Be Able to Do Now?_](#92-what-should-i-be-able-to-do-now)
        - [10. Using the Object Library](#10-using-the-object-library)
            - [10.5. _Doors_](#105-doors)
            - [10.6. _Vehicles_](#106-vehicles)
        - [12. Resources](#12-resources)
            - [12.2. _Pictures_](#122-pictures)
            - [12.3. _Sound and Music_](#123-sound-and-music)
        - [App. A. Summary of Keywords and Commands](#app-a-summary-of-keywords-and-commands)

<!-- /MarkdownTOC -->

-----

# Introduction

The AsciiDoc edition was created by [Tristano Ajmone] from a Word document supplied by [Kent Tessman].
The original Word document was the latest version of _The Hugo Book_ by the original author.

The main motivation for porting _The Hugo Book_ to AsciiDoc is twofold:

1. Historical preservation.
2. Providing a format-agnostic version of the document convertible to different output formats.

The main motivation for porting _The Hugo Book_ to AsciiDoc is its historical preservation.
Providing a format-agnostic version of the document, which can convert to different output formats, is an added benefit.

With preservation being the main goal, this edition doesn't aim at updating the book contents, bur rather stick to the original text as faithful as possible.

## Text Corrections

This project was privileged by the participation of Kent Tessman, who followed its development and actively engaged in any questions and discussion when crucial editing decisions needed to be taken.
This has been a great opportunity for it offered the chance to consult the original author when text amendments were necessary.

Therefore, I opted to point out to Kent any problems with the original text (small inconsistencies, missing text, typos, etc.) so that he might suggest amendments, or approve any of my proposed changes.
These problems were very few in number, and most likely due to editing accidents like partial undoing, or accidental deletion of text selections; for the original document was well polished and thoroughly checked.

In any case, all significant changes to the original text have been annotated in this document, so that end users can look them up and compare the with the [latest PDF version of _The Hugo Book_ deposited on the IF Archive].
Just bare in mind that the Word document from which the AsciiDoc version was derived might contain some text updates by the original author that were never published.

## Aesthetic and Functional Changes

The switch for Word to AsciiDoc called for some aesthetic adaptations — e.g. converting notes within parentheses to admonition blocks — as well as some functional changes — e.g. adding captions to tables and figures, to allow direct linking via anchors or providing an index of tables and figures in those output formats that support this feature (e.g. PDF) — which are more inline with the overall AsciiDoc philosophy on how documents should be organized in order to maximize fruition across different formats and media, and to allow end users full control over customization of the look and feel of the various parts of a document.

Aesthetic changes include resorting to colour and bigger font sizes to highlight key elements in lists or tables, and similar visual enhancements that can be easily controlled (and even suppressed, if so desired) via custom stylesheets or templates.

For the sake of better game transcripts emulation, in some places inline transcripts where substituted with block elements, which also required removing surrounding quotes.
The rationale for this was that using _ad hoc_ styled for transcripts examples would have a higher visual impact (especially on the HTML document, which uses colours) and simplify quick reading through chapters and finding required references.

The text of cross references was also slightly adapted to better fit the AsciiDoc model.
Occurrences like "The section Sec. 4.5" or "Section Sec. 4.5" were all adapted to "Sec. 4.5", in order to fit a standard cross reference model.

Dead links in the original book were fixed wherever possible, pointing either to the new URL where these resources are currently hosted, or to their archived copy on Wayback Machine in case of no longer available websites and services.
The original URLs were kept in the text, for the sake of historical preservation, but clicking on them redirects to their updated URL of destination.

None of these changes disrupt the original contents of the book; and I believe they serve well the original author intentions.

## Library Code Updates

The book contains some code excerpts from the Hugo Library.
I've replaced them with the same excerpts from the latest official Hugo Library (v3.1.03.2) so that the reader will be able to match the text of the book against the current Hugo Library.

The differences in the original and update code are usually very small, if any, and I've gone to great length to ensure they won't affect the reading experience (e.g. in case some references changed).
All the changes that I've encountered where improvements on the original code, none of which affect backward compatibility nor the context in which the book mentions them.

I believe that these small changes are in line with the original author intention of matching the latest version of _The Hugo Book_ with the latest version of the Hugo Library, and therefore desirable.

The source files of the Hugo Library v3.1.03.2 that I've used can be found here:

- https://github.com/tajmone/hugo-library

# Changes List

Here's the list of all significant changes to the book contents, which are worth mentioning.
These changes fall under two main categories:

- Text adaptations to better exploit the new AsciiDoc format, or to provide a more readable text.
- Fixes to minor typos in text or code.

By "significant changes" we mean those changes which would be worth mentioning in an _Errata_.
Minor typos and other obvious fixes are not listed here, but they have been annotated in the documents sources comments nonetheless, for historical accuracy.

## Book I

List of changes to [Book I: _The Hugo Programming Manual_][Book1].

### 1. Introduction

List of changes to Chapter [1. _Introduction_][Ch1].

#### 1.5. _Packing List_

<!-- Issue #28 --------------------------------------------------------------->

In _[§1.5. Packing List]_:

> Additionally, you're probably want to download *shell.hug*,

was amended into:

> Additionally, you're going to want to download *shell.hug*,

(See [Issue #28])

#### 1.10. _Limit Settings_

<!-- Issue #20 --------------------------------------------------------------->

In _[§1.10. Limit Settings]_, the following admonition block:

> Users of Unix or similar systems (including OS X, BeOS, and others) may, depending on the shell being used, need to escape special tokens like `$` or enclose these arguments in single quotes (e.g. `\$list` and `\$<setting>=<new limit>` or `'list'`, `'$<setting>=<new limit>'`, etc.) to override the shell's parsing of those tokens in the compiler invocation line.

was missing the `$` symbol in `'list'`, and was fixed to:

> (e.g. `\$list` and `\$<setting>=<new limit>` or `'$list'`,

(See [Issue #20])

### 2. A First Look at Hugo

List of changes to Chapter [2. _A First Look at Hugo_][Ch2].

#### 2.4. _Multiple Lines_

<!-- Issue #17 --------------------------------------------------------------->

In _[§2.4. Multiple Lines]_, inside the tip admonition on how to preserve a double space when splitting a string across multiple lines, the original text:

> since normally, if the `/` were omitted after “…​on one line.”,

was changed to:

> since normally, if the ` \` were omitted after “…​on one line.”,

(See [Issue #17])


### 4. Hugo Programming

List of changes to Chapter [4. _Hugo Programming_][Ch4].

#### 4.8. _What Should I Be Able to Do Now?_

<!-- Issue #6  --------------------------------------------------------------->

In _[§4.8. What Should I Be Able to Do Now?]_, the _Mixing Text Styles_ example:

```hugo
! Sample to print various typefaces/colors:

#include "hugolib.h"

routine main
{
    print "Text may be printed in \Bboldface\b,
        \Iitalics\i, \Uunderlined\u, or
        \Pproportional\p typefaces."
    color RED               ! or color 4
    print "\nGet ready. ";
    color YELLOW            ! color 14
    print "Get set. ";
    color GREEN             ! color 2
    print "Go!"
}
```

was edited by removing the proportional typeface, since game transcripts are all in proportional font throughout the book:

```hugo
! Sample to print various typefaces/colors:

#include "hugolib.h"

routine main
{
    print "Text may be printed in \Bboldface\b,
        \Iitalics\i, or \Uunderlined\u typefaces."
    color RED               ! or color 4
    print "\nGet ready. ";
    color YELLOW            ! color 14
    print "Get set. ";
    color GREEN             ! color 2
    print "Go!"
}
```

The output transcript was also changed accordingly.

The rationale was that it was better to discard the proportional font example instead of having to use a monospace font as the base typeface for this transcript only, thus breaking consistency with the rest of the transcripts.
Using a monospace font for all transcripts would have been counter-productive, for most IF games today use proportional fonts as the base typeface.
Furthermore, monospace fonts are already used in code examples and syntax definitions, so using a proportional font for transcripts renders the book more readable.

(See [Issue #6])


### 5. Routines and Events

List of changes to Chapter [5. _Routines and Events_][Ch5].

#### 5.3. _Before And After Routines_

<!-- Issue #14 --------------------------------------------------------------->

In _[§5.3. Before And After Routines]_, toward the section end, there was a paragraph where some ending text went lost:

> A drawback of this non-specification is that all verbroutines are matched — both verbs and xverbs.
> This can be particularly undesirable in the case of location `before`/`after` properties, where you may wish to be circumventing any action the player tries to perform in that location, but where the non-specific response will be triggered even for `save`, `restore`, etc. (i.e.,

The paragraph end was amended by Kent Tessman to:

> [...] for `save`, `restore`, etc. (i.e., xverbs).


(See [Issue #14])


### 9. The Game Loop

List of changes to Chapter [9. _The Game Loop_][Ch9].

#### 9.2. _What Should I Be Able to Do Now?_

<!-- Issue #38 --------------------------------------------------------------->

In _[§9.2. What Should I Be Able to Do Now?]_, the following code:

```hugo
case 1
    print CThe(player); \
        MatchPlural(player, "doesn't, "don't"); \
        need to use the word \""; \
        parse$; "\"."
```

was missing the opening quote and a space before `need to use`, and was fixed to:

```hugo
case 1
    print CThe(player); \
        MatchPlural(player, "doesn't", "don't"); \
        " need to use the word \""; \
        parse$; "\"."
```

(See [Issue #38])


### 10. Using the Object Library

List of changes to Chapter [10. _Using the Object Library_][Ch10].

#### 10.5. _Doors_

<!-- Issue #19 --------------------------------------------------------------->

In _[§10.5. Doors]_:

> The `between` property takes care of making the room available in both locations

"room" was changed with "door":

> The `between` property takes care of making the door available in both locations

(See [Issue #19])


#### 10.6. _Vehicles_

<!-- Issue #18 --------------------------------------------------------------->

In _[§10.6. Vehicles]_, the accidentally damaged sentence:

> It is also necessary to provide grammar to relate the words in the `vehicle_verb` list to the object library's `DoMoveInVehicle` routine.Grammar he following is recommended:

was fixed by Kent Tessman to:

> It is also necessary to provide grammar to relate the words in the `vehicle_verb` list to the object library’s `DoMoveInVehicle` routine.
> Grammar such as the following is recommended:

(See [Issue #18])

-------------------------------------------------------------------------------

<!-- Issue #30 --------------------------------------------------------------->

In _[§10.6. Vehicles]_, the sentence:

> The `preposition` property defaults in the `vehicle` class itself defaults to "in" and "out", but in the case of a horse should be changed to the more suitable "on" and "off".

was hard to read due to the double occurring "defaults", which introduced ambiguity as to which one was a verb.
It was rephrased to:

> In the `vehicle` class the `preposition` property defaults to "in" and "out", but in the case of a horse it should be changed to the more suitable "on" and "off".

which is smoother on the reader (and shorter too).

(See [Issue #30])


### 12. Resources

List of changes to Chapter [12. _Resources_][Ch12].

#### 12.2. _Pictures_

<!-- Issue #36 --------------------------------------------------------------->

In _[§12.2. Pictures]_, the syntax definition:

```hugo
LoadPicture("resourcefile", "picture")
LoadPicture("picture")
PictureinText("file", "pic", width, height, preserve)
PictureinText("picture", width, height, preserve)
```

was edited to make it consistent with other syntax definitions:

```hugo
LoadPicture("<resourcefile>", "<picture>")
LoadPicture("<picture>")

PictureinText("<file>", "<pic>", <width>, <height>[, <preserve>])
PictureinText("<picture>", <width>, <height>[, <preserve>])
```

(See [Issue #36])


#### 12.3. _Sound and Music_

<!-- Issue #36 --------------------------------------------------------------->

In _[§12.3. Sound and Music]_, the syntax definition:

```hugo
PlaySound(resourcefile, sample, loop, force)
PlayMusic(resourcefile, song, loop, force)
```

was amended to include some missing parameters and to make it consistent with other syntax definitions:

```hugo
PlaySound(<resourcefile>, <sample>[, <volume>[, <loop>[, <force>]]])
PlayMusic(<resourcefile>, <song>[, <volume>[, <loop>[, <force>]]])
```


(See [Issue #36])

### App. A. Summary of Keywords and Commands

List of changes to Appendix [A. _Summary of Keywords and Commands_][AppA].


---

<!-- Issue #27 --------------------------------------------------------------->

In the definition of `color`, the cross reference to a specific page number:

> Standard color values for `<foreground>` and `<background>` with constants defined in **hugolib.h** (see page 64) are:

was changed to the section number containing that page number (in the original Word/PDF document) instead:

> Standard color values for `<foreground>` and `<background>` with constants defined in **hugolib.h** (see [Sec. 4.3]) are:

where "[Sec. 4.3]" is a link pointing to the relevant paragraph on the topic through a custom anchor (`hugolib-colors`).

This was necessary because not all output formats have page numbers (HTML documents, ePub, CHM Help files, etc., either don't have real page numbers or can't handle them well in cross references).

(See [Issue #27])


---

<!-- Issue #28 --------------------------------------------------------------->

In the definition of `print`, after the `print <output>` syntax:

> where `<output>` can consist of both test strings enclosed in quotation marks (`"…​"`), and values representing dictionary addresses

"test strings" was changed to "text strings":

> where `<output>` can consist of both text strings enclosed in quotation marks (`"…​"`), and values representing dictionary addresses


(See [Issue #28])


<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

[latest PDF version of _The Hugo Book_ deposited on the IF Archive]: https://www.ifarchive.org/if-archive/programming/hugo/manuals/hugo_book.pdf "'The Hugo Book' in PDF format at the IF Archive"

<!-- people -->

[Kent Tessman]: https://github.com/tessman "View Kent Tessman's GitHub profile"
[Tristano Ajmone]: https://github.com/tajmone "View Tristano Ajmone's GitHub profile"

<!-- Issues -->

[Issue #6]: https://github.com/tajmone/hugo-book/issues/6 "View Issue #6 regarding this text amendment"
[Issue #14]: https://github.com/tajmone/hugo-book/issues/14 "View Issue #14 regarding this text amendment"
[Issue #17]: https://github.com/tajmone/hugo-book/issues/17 "View Issue #17 regarding this text amendment"
[Issue #18]: https://github.com/tajmone/hugo-book/issues/18 "View Issue #18 regarding this text amendment"
[Issue #19]: https://github.com/tajmone/hugo-book/issues/19 "View Issue #19 regarding this text amendment"
[Issue #20]: https://github.com/tajmone/hugo-book/issues/20 "View Issue #20 regarding this text amendment"
[Issue #27]: https://github.com/tajmone/hugo-book/issues/27 "View Issue #27 regarding this text amendment"
[Issue #28]: https://github.com/tajmone/hugo-book/issues/28 "View Issue #28 regarding this text amendment"
[Issue #30]: https://github.com/tajmone/hugo-book/issues/30 "View Issue #30 regarding this text amendment"
[Issue #36]: https://github.com/tajmone/hugo-book/issues/36 "View Issue #36 regarding this text amendment"
[Issue #38]: https://github.com/tajmone/hugo-book/issues/38 "View Issue #38 regarding this text amendment"

<!-- Live HTML Links -->

[Book1]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#book1 "Jump to Live HTML Preview of: Book I"

[Ch1]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#chapter_1 "Jump to Live HTML Preview of: Book I » 1. INTRODUCTION"
[Ch2]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#chapter_2 "Jump to Live HTML Preview of: Book I » 2. A FIRST LOOK AT HUGO"
[Ch3]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#chapter_3 "Jump to Live HTML Preview of: Book I » 3. OBJECTS"
[Ch4]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#chapter_4 "Jump to Live HTML Preview of: Book I » 4. HUGO PROGRAMMING"
[Ch5]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#chapter_5 "Jump to Live HTML Preview of: Book I » 5. ROUTINES AND EVENTS"
[Ch6]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#chapter_6 "Jump to Live HTML Preview of: Book I » 6. FUSES, DAEMONS, AND SCRIPTS"
[Ch9]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#chapter_9 "Jump to Live HTML Preview of: Book I » 9. THE GAME LOOP"
[Ch10]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#chapter_10 "Jump to Live HTML Preview of: Book I » 10. USING THE OBJECT LIBRARY"
[Ch12]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#chapter_12 "Jump to Live HTML Preview of: Book I » 12. RESOURCES"
[AppA]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#appendix_a "Jump to Live HTML Preview of: Book I » Appendix A: SUMMARY OF KEYWORDS AND COMMANDS"

[§1.5. Packing List]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#sec_1-5 "Live HTML Preview"
[§1.10. Limit Settings]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#sec_1-10 "Live HTML Preview"
[§2.4. Multiple Lines]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#sec_2-4 "Live HTML Preview"
[§4.8. What Should I Be Able to Do Now?]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#sec_4-8 "Live HTML Preview"
[§5.3. Before And After Routines]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#sec_5-3 "Live HTML Preview"
[§9.2. What Should I Be Able to Do Now?]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#sec_9-2 "Live HTML Preview"
[§10.5. Doors]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#sec_10-5 "Live HTML Preview"
[§10.6. Vehicles]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#sec_10-6 "Live HTML Preview"
[§12.2. Pictures]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#sec_12-2 "Live HTML Preview"
[§12.3. Sound and Music]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#sec_12-3 "Live HTML Preview"

[Sec. 4.3]: http://htmlpreview.github.io/?https://github.com/tajmone/hugo-book/blob/draft/docs/hugo-book.html#hugolib-colors "Live HTML Preview"



<!-- EOF -->
