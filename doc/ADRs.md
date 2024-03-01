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
Maybe there is a way, but I don't really know how.

### 003: Label in external scanner and heading edge case
**Label in external scanner**: Same problem as in #002, TS thinks a valid rule is an error in another rule because of precedence (e.g. Word < bla> is valid, but seen as an error).
This may be solvable using some form of precedence, most likely dynamic precedence and conflict rules, but I don't know how to do it.

**Heading edge case**: The following edge case exists: ```=== Heading <label> Line```. Here, the line after the label is interpreted as a line (as it should be), but it is a child node
of the heading. This is not really clean, but in my opinion good enough for now. This alos means that the heading has to be highlighted using heading_prefix and heading_content.

### 004: Usage of __ERROR token inside parse_raw_multiple_content
In the original multi-backtick raw text grammar rule seen here
```js
seq(
  $.raw_multiple_open,
  choice(
    seq($.raw_language_type, optional($.raw_multiple_content__language)), 
    $.raw_multiple_content__no_language, 
  ),
  $.raw_multiple_close,
)
```
two external tokens can be used after the `$.raw_language_type` token when the input is a multi-backtick raw text block with a language and no content: `$.raw_multiple_content__language` and `$.raw_multiple_close`. In the scanner, the parser for the first token is used to parse the input. Because a language was found in the text block, the first character of the content can be a backtick. But this is ambiguous, as there doesn't have to be content in the raw text block, meaning the backticks could also be the end of the text block, i.e. part of the `$.raw_multiple_close` token. In order to check what kind of backticks they are, the content parser needs to advance to see how many there are. If it turns out they in fact are the end of the raw text block, then the parser should not consume them and only return the content found.

This is where the problem occurs. In the special case mentioned above there is no content, so because of that the parser has to return false. But returning false also indicates to tree-sitter that the `$.raw_multiple_close` could not be found, as it was also valid and should have therefore been checked by the external scanner, which it was not because our scanner is not really designed that way.

The solution to this, although a bit ugly, is not to return false, but to emit a special error token `__ERROR` that does not span any text and is hidden from the resulting tree, and change the grammar rule to this:
```js
seq(
  $.raw_multiple_open,
  choice(
    seq($.raw_language_type, choice($.raw_multiple_content__language, $.__error)), 
    $.raw_multiple_content__no_language, 
  ),
  $.raw_multiple_close,
),
```
This way, the scanner successfully returns a token, regardless of whether content was found or not, and can then be invoked again in order to parse `$.raw_multiple_close`.
