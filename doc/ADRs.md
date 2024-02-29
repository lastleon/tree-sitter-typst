# Architecture Design Records

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
