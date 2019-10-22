# List of Changes

This document lists all the contents changes that theAsciiDoc edition has undergone.


-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3" -->

- [Introduction](#introduction)
    - [Text Corrections](#text-corrections)
    - [Aesthetic Changes](#aesthetic-changes)
    - [Library Code Updates](#library-code-updates)
- [List of Text Corrections](#list-of-text-corrections)

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

# List of Text Corrections

<!-- Issue #14 (approved) ---------------------------------------------------->

In §5.3, toward the section end, there was a paragraph where some text ending text had gone lost:

> A drawback of this non-specification is that all verbroutines are matched — both verbs and xverbs.
> This can be particularly undesirable in the case of location `before`/`after` properties, where you may wish to be circumventing any action the player tries to perform in that location, but where the non-specific response will be triggered even for `save`, `restore`, etc. (i.e.,

The paragraph end was amended by Kent Tessman to:

> [...] for `save`, `restore`, etc. (i.e., xverbs).


<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

<!-- people -->

[Kent Tessman]: https://github.com/tessman "View Kent Tessman's GitHub profile"
[Tristano Ajmone]: https://github.com/tajmone "View Tristano Ajmone's GitHub profile"

<!-- EOF -->
