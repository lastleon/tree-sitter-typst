const PREC = {
  COMMENT: 20,
  HEADING: 10,
  STRONG: 5,
}
const ALPHANUM_CHARS = "[a-zA-Z0-9]";
const NON_ALPHANUM_CHARS = "[^a-zA-Z0-9]";

module.exports = grammar({
  name: 'typst',

  extras: $ => [
    $.comment,
    $.line_comment,
    // $.block_comment
  ],

  rules: {
    // content
    markup_block: $ => repeat(choice($.line, $._emptyline)),
    
    line: $ => seq(
      choice(
        $.heading,
        $._line_content
      ),
      $._newline,
    ),
    _emptyline: $ => $._newline, // TODO: Maybe use alias?
    _newline: $ => /\n|\r\n?/,

    // Headings
    heading: $ => seq(
      $._heading_prefix,
      alias($._line_content, $.heading_text),
    ),
    _heading_prefix: $ => token(prec(PREC.HEADING, /=+[ |\t]+/)), // at least one tab or space needed to be recognized as heading TODO: Capture group for ===?

    // Markup
    _line_content: $ => repeat1(choice(
      $.strong,
      $._text,
    )),


    // _text: $ => /[^\n]/,
    _text: $ => choice(
      new RegExp(`${ALPHANUM_CHARS}+`), // alphanum characters can be consumed as much as they want to TODO: Expand to ä, etc.
      new RegExp(`${NON_ALPHANUM_CHARS}`), // non-alphanum chars not because of strong / emph / ...
    ),

    strong: $ => seq(
      $._strong_delim_opn,
      $._line_content,
      $._strong_delim_cls,
    ),
    _strong_delim_opn: $ => token(prec(PREC.STRONG, new RegExp(`${NON_ALPHANUM_CHARS}\\\*`))),
    _strong_delim_cls: $ => prec(PREC.STRONG, new RegExp(`\\\*${NON_ALPHANUM_CHARS}`)),

    // Comments
    comment: $ => choice(
      $.line_comment,
      // $.block_comment,
    ),

    line_comment: $ => token(prec(PREC.COMMENT, /\/\/.*/)),
    // block_comment: $ => seq(
    //   "/*", 
    //   // /[.*\n]*.*/,
    //   /[^*]*\*+([^/*][^*]*\*+)*/, // TODO, taken from java grammar
    //   //"*/", 
    //   "/", 
    // ),
  }
});

