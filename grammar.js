const PREC = {
  STAR: -2,
}

module.exports = grammar({
  name: 'typst',

  externals: $ => [
    $.last_token_non_word,
    $.last_token_word,

    $.strong_open,
    $.strong_close,

    // Ambiguous heading start
    $.heading_prefix,
    $.equalsigns,

    $.__error_canary // This is never used in the grammar and exists solely to indicate to scanner.c that tree-sitter is in error mode
  ],

  extras: $ => [], // Needed because otherwise tree-sitter consumes characters that are needed, e.g. some newlines, ...

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

    word: $ => seq(/\w+/, optional($.last_token_word)),
    special: $ => prec.right(repeat1(seq(choice(/[^\w \t\*=]/, $.equalsigns), optional($.last_token_non_word)))), // prec.right => match rule as long as possible
    star: $ => prec(PREC.STAR, seq("*", optional($.last_token_non_word))),

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
      $.star,
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
      $.star,
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
        $.star,
    )),
  },

});
