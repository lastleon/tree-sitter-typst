const PREC = {
  STAR: -2,
  UNDERSCORE: -2,
}

WORD = /(?:[a-zA-Z0-9])+/

// Reference token
// A reference name can only contain the chars listed in REF_VALID_NAME, and additionally a colon
// if at least one of the chars in REF_VALID_NAME follows it
REF_VALID_NAME = "(?:[a-zA-Z0-9\\-_])+"
REFERENCE_NAME_REGEX = new RegExp(`${REF_VALID_NAME}(?::${REF_VALID_NAME})*`)


module.exports = grammar({
  name: 'typst',

  externals: $ => [
    $.last_token_non_word,
    $.last_token_word,

    $.strong_open,
    $.strong_close,

    $.italic_open,
    $.italic_close,

    // Needed because heading starts are ambiguous
    $.heading_prefix,
    $.equalsigns,

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
    special: $ => prec.right(repeat1(seq(choice(/[^\w \t\*=@]/, $.equalsigns), optional($.last_token_non_word)))), // \w contains underscore, so we do not need to list it seperately
    star: $ => prec(PREC.STAR, seq("*", optional($.last_token_non_word))),
    underscore: $ => prec(PREC.UNDERSCORE, seq("_", optional($.last_token_non_word))),

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
      $.reference,
      $.star,
      $.underscore,
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
      $.reference,
      $.star,
      $.underscore,
      $.newline,
    )),

    // HEADING
    heading: $ => seq(
      $.heading_prefix,
      optional(seq(
        $.heading_whitespace,
        optional($.heading_content),
      )),
      $.newline
    ),
    heading_whitespace: $ => prec.left(repeat1(seq(/[ \t]/, optional($.last_token_non_word)))),

    heading_content: $ => repeat1(choice(
      $.word,
      $.special,
      $.whitespace,
      $.strong,
      $.italic,
      $.reference,
      $.star,
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
        $.reference,
        $.star,
        $.underscore,
    )),

    // REFERENCE
    reference: $ => seq("@", REFERENCE_NAME_REGEX, optional($.last_token_word)),

    // COMMENT
    comment: $ => choice(
      $.line_comment,
      // $.block_comment,
    ),

    line_comment: $ => /\/\/[^\n(?:\r\n)]*/,
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
