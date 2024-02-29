module.exports = grammar({
  name: 'typst',

  externals: $ => [
    $.last_token_non_word,
    $.last_token_word,

    $.strong_open,
    $.strong_close,

    $.__error_canary // This is never used in the grammar and exists solely to indicate to scanner.c that tree-sitter is in error mode
  ],

  rules: {
    markup_block: $ => seq(optional($.last_token_non_word), repeat($._markup_content)),

    _markup_content: $ => choice(
      $.heading,
    ),

    // GENERAL
    newline: $ => seq(/\n/, optional($.last_token_non_word)),
    whitespace: $ => prec.right(repeat1(seq(/[ \t]/, optional($.last_token_non_word)))), // prec.right => match rule as long as possible

    // word: $ => /\w((\w|(\w\*\w))*\w)?/,
    word: $ => seq(/\w+/, optional($.last_token_word)),
    special: $ => prec.right(repeat1(seq(/[^\w \t\*]/, optional($.last_token_non_word)))),

    strong: $ => seq(
      $.strong_open,
      $.word,
      $.strong_close
    ),

    // HEADING
    heading: $ => seq(
      $.heading_prefix,
      optional(seq(
        $.heading_whitespace,
        $.heading_content,
      )),
      $.newline
    ),
    heading_prefix: $ => /=+/,
    heading_whitespace: $ => prec.left(repeat1(seq(/[ \t]/, optional($.last_token_non_word)))),

    heading_content: $ => repeat1(choice(
      $.word,
      $.special,
      $.whitespace,
      $.strong,
      // alias(token(prec(-2, "*")), $.star)
    )),

    // // LINE
    // line: $ => seq(
    //   $.line_content,
    //   $.parbreak,
    // ),
    //
    // line_content: $ => repeat1(choice(
    //   $.word,
    //   $.special,
    //   $.whitespace,
    // )),
  },

});
