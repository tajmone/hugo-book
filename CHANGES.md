# List of Changes

This document lists all the contents changes that theAsciiDoc edition has undergone.


-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3" -->

- [Introduction](#introduction)
    - [Text Corrections](#text-corrections)
    - [Aesthetic Changes](#aesthetic-changes)
    - [Library Code Updates](#library-code-updates)
- [List of Text Adaptations](#list-of-text-adaptations)
- [List of Text and Code Corrections](#list-of-text-and-code-corrections)

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
This has been a great opportunity for it offered the chance to consult the original authors when text amendments where necessary.

Therefore, I opted to point out to Kent any problems with the original text (small inconsistencies, missing text, typos, etc.) so that he might suggest amendments, or approve any of my proposed changes.
These problems were very few in number, and most likely due to editing accidents like partial undoing, or accidental deletion of text selections; for the original document was well polished and thoroughly checked.

In any case, all significant changes to the original text have been annotated in this document, so that end users can look them up and compare the with the latest PDF version of _The Hugo Book_ deposited on the IF Archive.

## Aesthetic Changes

The switch for Word to AsciiDoc called for some aesthetic adaptations — e.g. moving comments within parentheses to admonition blocks — which are more inline with the overall AsciiDoc philosophy on how documents should be organized in order to maximize fruition across different formats and media, and to allow end users full control on customizing the look and feel of the various parts of a document.
None of these changes disrupt the original contents of the book; and I believe they serve well the original author intentions.

## Library Code Updates

The book contains some code excerpts from the Hugo Library.
I've replaced them with the same excerpts from the latest official Hugo Library (v3.1.03.2) so that the reader will be able to match the text of the book against the current Hugo Library.

The differences in the original and update code are usually very small, if any, and I've gone to great length to ensure they won't affect the reading experience (e.g. in case some references changed).
All the changes that I've encountered where improvements on the original code, none of which affect backward compatibility nor the context in which the book mentioned them.

I believe that these small changes are in line with the original author intention of matching the latest version of _The Hugo Book_ with the latest version of the Hugo Library, and therefore desirable.

The source files of the Hugo Library v3.1.03.2 that I've used can be found here:

- https://github.com/tajmone/hugo-library

# List of Text Adaptations

Some text adaptations that were required to better exploit the new AsciiDoc format or to provide a more readable text.

----

<!-- Issue #6 (approved) ----------------------------------------------------->

In _§4.8. What Should I Be Able to Do Now?_, the _Mixing Text Styles_ example:

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

----

<!-- Issue #30 (approved) ---------------------------------------------------->

In _§10.6. Vehicles_, the sentence:

> The `preposition` property defaults in the `vehicle` class itself defaults to "in" and "out", but in the case of a horse should be changed to the more suitable "on" and "off".

was hard to read due to the double occurring "defaults", which introduced ambiguity as to which one was a verb.
It was rephrased to:

> In the `vehicle` class the `preposition` property defaults to "in" and "out", but in the case of a horse it should be changed to the more suitable "on" and "off".

which is smoother on the reader (and shorter too).

----

<!-- Issue #36 (pending approval) -------------------------------------------->

In _§12.2. Pictures_, the the syntax definition:

```hugo
LoadPicture("resourcefile", "picture")
LoadPicture("picture")
PictureinText("file", "pic", width, height, preserve)
PictureinText("picture", width, height, preserve)
```

was edited to make it consistent with the other syntax definitions:

```hugo
LoadPicture("<resourcefile>", "<picture>")
LoadPicture("<picture>")

PictureinText("<file>", "<pic>", <width>, <height>[, <preserve>])
PictureinText("<picture>", <width>, <height>[, <preserve>])
```

----

<!-- Issue #36 (pending approval) -------------------------------------------->

In _§12.3. Sound and Music_, the the syntax definition:

```hugo
PlaySound(resourcefile, sample, loop, force)
PlayMusic(resourcefile, song, loop, force)
```

was edited to make it consistent with the other syntax definitions:

```hugo
PlaySound(<resourcefile>, <sample>, <loop>, <force>)
PlayMusic(<resourcefile>, <song>, <loop>, <force>)
```


----

<!-- Issue #27 (approved) ---------------------------------------------------->

In _App. A: Summary of Keywords and Commands_, the cross reference text to a specific page number:

> Standard color values for `<foreground>` and `<background>` with constants defined in **hugolib.h** (see page 64) are:

was changed to the section number instead:

> Standard color values for `<foreground>` and `<background>` with constants defined in **hugolib.h** (see Sec. 4.3) are:

where "Sec. 4.3" is a link pointing to relevant paragraph on the topic.

This was necessary because not all output formats have page numbers (HTML documents, ePub, CHM Help files, etc., either don't have real page numbers or can't handle them well in cross references).


# List of Text and Code Corrections

Small typos in text or code that were detected and fixed.

-------------------------------------------------------------------------------

<!-- Issue #20 (approved) ---------------------------------------------------->

In _§1.10. Limit Settings_, the following admonition block:

> Users of Unix or similar systems (including OS X, BeOS, and others) may, depending on the shell being used, need to escape special tokens like `$` or enclose these arguments in single quotes (e.g. `\$list` and `\$<setting>=<new limit>` or `'list'`, `'$<setting>=<new limit>'`, etc.) to override the shell's parsing of those tokens in the compiler invocation line.

was a missing the `$` symbol in `'list'`, and was fixed to:

> (e.g. `\$list` and `\$<setting>=<new limit>` or `'$list'`,

----

<!-- Issue #28 (approved) ---------------------------------------------------->

In _§1.5. Packing List_:

> Additionally, you're probably want to download *shell.hug*,

was amended into:

> Additionally, you're going to want to download *shell.hug*,


<!-- Issue #17 (approved) ---------------------------------------------------->

In _§2.4. Multiple Lines_, inside the tip admonition on how to preserve a double space when splitting a string over multiple line, the original text:

> since normally, if the `/` were omitted after “…​on one line.”,

was changed to:

> since normally, if the ` \` were omitted after “…​on one line.”,

----

<!-- Issue #14 (approved) ---------------------------------------------------->

In _§5.3. Before And After Routines_, toward the section end, there was a paragraph where some text ending text had gone lost:

> A drawback of this non-specification is that all verbroutines are matched — both verbs and xverbs.
> This can be particularly undesirable in the case of location `before`/`after` properties, where you may wish to be circumventing any action the player tries to perform in that location, but where the non-specific response will be triggered even for `save`, `restore`, etc. (i.e.,

The paragraph end was amended by Kent Tessman to:

> [...] for `save`, `restore`, etc. (i.e., xverbs).

----

<!-- Issue #38 (approved) ---------------------------------------------------->

In _§9.2. What Should I Be Able to Do Now?_, the following code:

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

----

<!-- Issue #19 (approved) ---------------------------------------------------->

In _§10.5. Doors_:

> The `between` property takes care of making the room available in both locations

"room" was changed with "door":

> The `between` property takes care of making the room available in both locations

----

<!-- Issue #18 (approved) ---------------------------------------------------->

In _§10.6. Vehicles_, the accidentally damaged sentence:

> It is also necessary to provide grammar to relate the words in the `vehicle_verb` list to the object library's `DoMoveInVehicle` routine.Grammar he following is recommended:

was fixed by Kent Tessman to:

> It is also necessary to provide grammar to relate the words in the `vehicle_verb` list to the object library’s `DoMoveInVehicle` routine.
> Grammar such as the following is recommended:

----

<!-- Issue #28 (pending approval) -------------------------------------------->

In _Appendix A_, regarding the syntax of `print <output>`:

> where `<output>` can consist of both test strings enclosed in quotation marks (`"…​"`), and values representing dictionary addresses

"test strings" was changed to "text strings"

> where `<output>` can consist of both text strings enclosed in quotation marks (`"…​"`), and values representing dictionary addresses

<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

<!-- people -->

[Kent Tessman]: https://github.com/tessman "View Kent Tessman's GitHub profile"
[Tristano Ajmone]: https://github.com/tajmone "View Tristano Ajmone's GitHub profile"

<!-- EOF -->
