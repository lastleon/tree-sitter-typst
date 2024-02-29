# Architecture Design Records

### 000: LAST_TOKEN_WORD and LAST_TOKEN_NON_WORD
TODO

### 001: Strong and Italic in external scanner
TODO

### 002: heading_prefix and equalsigns in external scanner
Problem:
If `heading_prefix` has lexical precedence over `equalsign`:
```typst
======9
```
=> Treesitter thinks this is a wrongly formatted heading, but it is a valid beginning of a line.


If `equalsign` has lexical precedence over `heading_prefix`:
```typst
====== 9
```
=> Treesitter thinks this is a valid beginning of a line, but it should be a heading

This would be solvable in treesitter if we could specify that it should use another rule instead of erroring.

### 003: Label in external scanner and heading edge case
**Label in external scanner**: Same problem as in #002, TS thinks a valid rule is an error in another rule because of precedence (e.g. Word < bla> is valid, but seen as an error).
This may be solvable using some form of precedence, most likely dynamic precedence and conflict rules, but I don't know how to do it.

**Heading edge case**: The following edge case exists: ```=== Heading <label> Line```. Here, the line after the label is interpreted as a line (as it should be), but it is a child node
of the heading. This is not really clean, but in my opinion good enough for now. This alos means that the heading has to be highlighted using heading_prefix and heading_content.
