const PREC = {
  STAR: -2,
  UNDERSCORE: -2,
  LESS_THAN: -2,
  MORE_THAN: -2,
}

WORD = /(?:[a-zA-Z0-9])+/

// Reference token
// A reference name can only contain the chars listed in REF_VALID_NAME, and additionally multiple colons
// if at least one of the chars in REF_VALID_NAME follows it
REF_VALID_NAME = "(?:[a-zA-Z0-9\\-_])+" // TODO: This also applies to language names in code blocks, i think this is more general
REFERENCE_NAME_REGEX = new RegExp(`${REF_VALID_NAME}(?::+${REF_VALID_NAME})*`) // TODO: Rename so it is more general and applies to label and reference


module.exports = grammar({
  name: 'typst',

  externals: $ => [
    $.last_token_non_word, // TODO: Think about whether this token is really needed
    $.last_token_word, 

    $.strong_open,
    $.strong_close,

    $.italic_open,
    $.italic_close,

    $.label_open,
    $.label_close,

    // Raw
    $.raw_single_open,
    $.raw_single_close,
    
    $.raw_multiple_open,
    $.raw_multiple_close,

    $.raw_language_type,
    $.raw_single_content,
    $.raw_multiple_content__language,
    $.raw_multiple_content__no_language,

    // Needed because heading starts are ambiguous
    $.heading_prefix,
    $.equalsigns,

    // Needs to be external as token changes based on what follows
    $.linebreak,
    $.escape_backslash,
    $.unicode_escape_internal,

    $.__error_canary // This is never used in the grammar and exists solely to indicate to scanner.c that tree-sitter is in error mode
  ],

  extras: $ => [
    $.comment,
    $.line_comment,
    // $.block_comment
  ], // Needed because otherwise tree-sitter consumes characters that are needed, e.g. some newlines, ...

  rules: {
    markup_block: $ => seq(optional($.last_token_non_word), repeat($._markup_content)),

    _markup_content: $ => seq(
      optional($.markup_leading_whitespace), // The amount of whitespace at the beginning of a line does not matter in typst..

      choice(
        $.heading,
        $.line,
        $.newline,
    )),

    markup_leading_whitespace: $ => seq(repeat1(/(?:[ \t])+/), optional($.last_token_non_word)), // Matches as many whitespaces and tabs as possible

    // GENERAL
    newline: $ => seq(/\r?\n/, optional($.last_token_non_word)),
    whitespace: $ => prec.right(repeat1(seq(/[ \t]/, optional($.last_token_non_word)))), // prec.right => match rule as long as possible

    word: $ => seq(WORD, optional($.last_token_word)),
    special: $ => prec.right(repeat1(seq(choice(/[^\w \t\*=@<>\\`]/, $.equalsigns), optional($.last_token_non_word)))), // \w contains underscore, so we do not need to list it seperately
    star: $ => prec(PREC.STAR, seq("*", optional($.last_token_non_word))),
    underscore: $ => prec(PREC.UNDERSCORE, seq("_", optional($.last_token_non_word))),
    less_than: $ => prec(PREC.LESS_THAN, seq("<", optional($.last_token_non_word))),
    more_than: $ => prec(PREC.MORE_THAN, seq(">", optional($.last_token_non_word))),

    escaped_character: $ => seq(
      $.escape_backslash,
      choice(
        seq(/[a-zA-Z0-9]/, optional($.last_token_word)),
        seq(/[^a-zA-Z0-9]/, optional($.last_token_non_word)),
      )
    ),

    unicode_escape: $ => seq($.unicode_escape_internal, optional($.last_token_non_word)),

    // STRONG
    strong: $ => seq(
      seq($.strong_open, optional($.last_token_non_word)),
      optional($.strong_content),
      seq($.strong_close, optional($.last_token_non_word)),
    ),
    strong_content: $ => repeat1(choice(
      $.word,
      $.special,
      $.whitespace,
      $.italic,
      $.label,
      $.reference,
      $.linebreak,
      $.escaped_character,
      $.unicode_escape,
      $.star,
      $.underscore,
      $.less_than,
      $.more_than,
      $.raw,
      $.newline,
    )),

    // ITALIC
    italic: $ => seq(
      seq($.italic_open, optional($.last_token_non_word)),
      optional($.italic_content),
      seq($.italic_close, optional($.last_token_non_word)),
    ),
    italic_content: $ => repeat1(choice(
      $.word,
      $.special,
      $.whitespace,
      $.strong,
      $.label,
      $.reference,
      $.linebreak,
      $.escaped_character,
      $.unicode_escape,
      $.star,
      $.underscore,
      $.less_than,
      $.more_than,
      $.raw,
      $.newline,
    )),

    // HEADING
    heading: $ => seq(
      $.heading_prefix,
      optional(seq(
        $.heading_whitespace,
        optional($.heading_content),
      )),
      choice(
        $.newline,
        seq( // Edge case when writing label in headline TODO: Maybe change how this is done? But don't know how
          $.label,
          $.line
        )
      ),
      
    ),
    heading_whitespace: $ => seq(/(?:[ \t])+/, optional($.last_token_non_word)),

    heading_content: $ => repeat1(choice(
      $.word,
      $.special,
      $.whitespace,
      $.strong,
      $.italic,
      // NOT $.label
      $.reference,
      $.linebreak,
      $.escaped_character,
      $.unicode_escape,
      $.star,
      $.less_than,
      $.more_than,
      $.raw,
      $.underscore,
    )),

    // LINE
    line: $ => seq(
      $.line_content,
      $.newline,
    ),

    line_content: $ => repeat1(
      choice(
        $.word,
        $.special,
        $.whitespace,
        $.strong,
        $.italic,
        $.label,
        $.reference,
        $.linebreak,
        $.escaped_character,
        $.unicode_escape,
        $.star,
        $.underscore,
        $.less_than,
        $.more_than,
        $.raw,
    )),

    // LABEL
    label: $ => seq(
      $.label_open,
      alias(REFERENCE_NAME_REGEX, $.label_content),
      $.label_close,
      optional($.last_token_non_word),
    ),

    // REFERENCE
    reference: $ => seq("@", REFERENCE_NAME_REGEX, optional($.last_token_word)),

    // RAW BLOCK
    raw: $ => seq(
      choice(
        seq(
          $.raw_single_open,
          optional($.raw_single_content),
          $.raw_single_close,
        ), 
        seq(
          $.raw_multiple_open,
          // $.raw_single_content, // TODO: Remove this and use the commented code. raw_language_type must also be an external symbol, because if one choice is external the scanner is always called, meaning we can't get higher precedence for raw_language_type if we keep the token in here. Also remember to consider all special cases of raw_multiple_content, such as backtick inside raw_multiple_content.
          choice(
            seq($.raw_language_type, optional($.raw_multiple_content__language)), // two types of multiple_content tokens are needed because parsing changes slightly based on whether there is a language or not
            $.raw_multiple_content__no_language, // TODO: maybe alias both types of content tokens if possible?
          ),
          $.raw_multiple_close,
        ),
      ),
      optional($.last_token_non_word) // unsure if this is enough or $.last_token_word should be added
    ),

    // COMMENT
    comment: $ => choice(
      $.line_comment,
      // $.block_comment,
    ),

    line_comment: $ => /\/\/[^\n]*/, // TODO: Improve this, only works for non DOS formatted files (I think)
    // block_comment: $ => /\*[.\n\r]*\*\//,
    // block_comment: $ => seq(
    //   "/*", 
    //   // /[.*\n]*.*/,
    //   /[^*]*\*+([^/*][^*]*\*+)*/, // TODO, taken from java grammar
    //   //"*/", 
    //   "/", 
    // ),
  },

});
