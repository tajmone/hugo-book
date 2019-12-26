# Asciidoctor Assets

This directory tree contains assets required by the Asciidoctor conversion toolchain.

-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3" -->

- [Directory Contents](#directory-contents)
- [Credits](#credits)
    - [Highlight Extension](#highlight-extension)
        - [AsciiDoc Coalescer](#asciidoc-coalescer)
    - [Haml Templates](#haml-templates)

<!-- /MarkdownTOC -->

-----

# Directory Contents

- [`/haml/`][haml] — customized Haml templates.
- [`highlight-treeprocessor_mod.rb`][HL.rb] v1.3.0 — extension for [Highlight] integration.

# Credits

## Highlight Extension

The [`highlight-treeprocessor_mod.rb`][HL.rb] file was adapted by Tristano Ajmone from the original file [`highlight-treeprocessor.rb`][rb upstream] taken from the __[Asciidoctor Extensions Lab]__ (commit [18bdf62]), Copyright (C) 2014-2016 [The Asciidoctor Project], released under MIT License:

    The MIT License

    Copyright (C) 2018 Tristano Ajmone.
    Copyright (C) 2014-2016 The Asciidoctor Project

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.

### AsciiDoc Coalescer

- [`asciidoc-coalescer.rb`][coalescer.rb]

The AsciiDoc coalescer script was downloaded from the __[Asciidoctor Extensions Lab]__ project (commit [b617f44], 2019/08/31):

- https://github.com/asciidoctor/asciidoctor-extensions-lab/blob/master/scripts/asciidoc-coalescer.rb

Released under MIT License:

```
The MIT License

Copyright (C) 2014-2016 The Asciidoctor Project

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
```

## Haml Templates

The files inside the [`/haml/`][haml] folder were adapted by Tristano Ajmone from the original [Haml HTML5 templates] taken from the __[Asciidoctor Backends]__ project, Copyright (C) 2012-2016 Dan Allen and the Asciidoctor Project, released under MIT License:

    The MIT License

    Copyright (C) 2018 Tristano Ajmone.
    Copyright (C) 2012-2016 Dan Allen and the Asciidoctor Project

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.



<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

[Highlight]: http://www.andre-simon.de/ "Visit Highlight website"
[AsciiDoctor]: https://asciidoctor.org/ "Visita Asciidoctor website"


<!-- proj folders -->

[haml]: ./haml "Navigate to folder"

<!-- proj files -->

[HL.rb]: ./highlight-treeprocessor_mod.rb "View Ruby source file"
[coalescer.rb]: ./asciidoc-coalescer.rb "View Ruby source file"

<!-- third party -->

[rb upstream]: https://github.com/asciidoctor/asciidoctor-extensions-lab/blob/18bdf62/lib/highlight-treeprocessor.rb
[Asciidoctor Extensions Lab]: https://github.com/asciidoctor/asciidoctor-extensions-lab/ "Visit the Asciidoctor Extensions Lab project"

[Asciidoctor Backends]: https://github.com/asciidoctor/asciidoctor-backends "Visit the Asciidoctor Backends project"
[Haml HTML5 templates]: https://github.com/asciidoctor/asciidoctor-backends/tree/master/haml/html5

[18bdf62]: https://github.com/asciidoctor/asciidoctor-extensions-lab/commit/18bdf628f46d9c98920c20413d8d99bf5ea622a8
[b617f44]: https://github.com/asciidoctor/asciidoctor-extensions-lab/commit/b617f4422ad7ccfa5716ba1301fb2f4773f4e0d3

<!-- organizations -->

[The Asciidoctor Project]: https://github.com/orgs/asciidoctor/people "View the profile of The Asciidoctor Project on GitHub"

<!-- EOF -->
