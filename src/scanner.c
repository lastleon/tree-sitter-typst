#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "tree_sitter/parser.h"

typedef enum {
  // ...
  LAST_TOKEN_NON_WORD,
  LAST_TOKEN_WORD,

  STRONG_OPEN,
  STRONG_CLOSE,

  ITALIC_OPEN,
  ITALIC_CLOSE,

  LABEL_OPEN,
  LABEL_CLOSE,

  RAW_SINGLE_OPEN,
  RAW_SINGLE_CLOSE,
  
  RAW_MULTIPLE_OPEN,
  RAW_MULTIPLE_CLOSE,

  RAW_LANGUAGE_TYPE,
  RAW_SINGLE_CONTENT,
  RAW_MULTIPLE_CONTENT,

  HEADING_PREFIX,
  EQUALSIGNS,

  LINEBREAK,
  ESCAPE_BACKSLASH,
  UNICODE_ESCAPE,

  ERROR,
} TokenType;

typedef struct {
  // uint32_t num_backticks_in_open_token;
  char num_backticks_in_open_token;
} Scanner;

bool decide_heading_or_equalsigns(TSLexer *lexer, const bool *valid_symbols) {
  // At this point we already know that the next char is =, so no need to check
  do {
    lexer->advance(lexer, false);
  } while (!lexer->eof(lexer) && lexer->lookahead == '='); // consume all = signs

  if (lexer->eof(lexer)) {
    lexer->result_symbol = HEADING_PREFIX; // If nothing follow, it must be a prefix

    return true;
  }
  
  switch (lexer->lookahead) {
    case ' ':
    case '\t':
    case '\r':
    case '\n':
      lexer->result_symbol = HEADING_PREFIX;

      return true;
    default:
      lexer->result_symbol = EQUALSIGNS;

      return true;
  }
  
}

bool parse_strong(TSLexer *lexer, const bool *valid_symbols) {
  const bool STRONG_VALID = valid_symbols[STRONG_OPEN] || valid_symbols[STRONG_CLOSE];
  const bool EMPH_POSSIBLE = valid_symbols[LAST_TOKEN_WORD] || valid_symbols[LAST_TOKEN_NON_WORD];

  if (!(STRONG_VALID && EMPH_POSSIBLE)) {
    return false;
  }

  // we need to check if it is a delimiter
  lexer->advance(lexer, false);

  // if LAST_TOKEN_NON_WORD, then the star is a delimiter
  // otherwise: only way it is not a delimiter is if the last token
  // was a word and the next one also is
  if (valid_symbols[LAST_TOKEN_WORD]
      && !lexer->eof(lexer)
      && isalnum((char) lexer->lookahead)) { // TODO: IMPROVE SUPPORT FOR NON-LATIN CHARACTERS
    return false;
  }

  if (valid_symbols[STRONG_OPEN]) {
    lexer->result_symbol = STRONG_OPEN;
  } else if (valid_symbols[STRONG_CLOSE]) {
    lexer->result_symbol = STRONG_CLOSE;
  }

  return true;

}

bool parse_italic(TSLexer *lexer, const bool *valid_symbols) {
  const bool ITALIC_VALID = valid_symbols[ITALIC_OPEN] || valid_symbols[ITALIC_CLOSE];
  const bool EMPH_POSSIBLE = valid_symbols[LAST_TOKEN_WORD] || valid_symbols[LAST_TOKEN_NON_WORD];

  if (!(ITALIC_VALID && EMPH_POSSIBLE)) {
    return false;
  }

  // we need to check if it is a delimiter
  lexer->advance(lexer, false);


  // if LAST_TOKEN_NON_WORD, then the underscore is a delimiter
  // otherwise: only way it is not a delimiter is if the last token
  // was a word and the next one also is
  if (valid_symbols[LAST_TOKEN_WORD]
      && !lexer->eof(lexer)
      && isalnum((char) lexer->lookahead)) { // TODO: IMPROVE SUPPORT FOR NON-LATIN CHARACTERS
    return false;
  }

  if (valid_symbols[ITALIC_OPEN]) {
    lexer->result_symbol = ITALIC_OPEN;
  } else if (valid_symbols[ITALIC_CLOSE]) {
    lexer->result_symbol = ITALIC_CLOSE;
  }

  return true;
}


bool parse_label(TSLexer *lexer, const bool *valid_symbols) {

  // Probably don't need first condition but doesn't hurt either
  if (lexer->lookahead == '<' && valid_symbols[LABEL_OPEN]) {
    lexer->advance(lexer, false);

    if (lexer->eof(lexer)) {
      return false;
    }

    // See regex for label (and reference) in grammer for explanation
    if (isalnum(lexer->lookahead)
        || lexer->lookahead == '-'
        || lexer->lookahead == '_') {

      lexer->result_symbol = LABEL_OPEN;
      return true;
    }
  } else if (lexer->lookahead == '>' && valid_symbols[LABEL_CLOSE]) {
    lexer->advance(lexer, false);

    // If it is valid it is always a LABEL_CLOSE token, regardless of what comes after
    lexer->result_symbol = LABEL_CLOSE;
    return true;
  }

  return false;
}

bool parse_raw(TSLexer *lexer, const bool *valid_symbols, void *payload) {
  // This check is probably not needed, as one of these symbols must be valid if (unescaped) backtick is encountered
  const bool raw_valid = valid_symbols[RAW_SINGLE_OPEN] 
                        || valid_symbols[RAW_SINGLE_CLOSE] 
                        || valid_symbols[RAW_MULTIPLE_OPEN] 
                        || valid_symbols[RAW_MULTIPLE_CLOSE];

  if (!raw_valid) {
    return false;
  }

  Scanner *s = (Scanner *)payload;

  // Currently, we know there is one backtick

  if (valid_symbols[RAW_SINGLE_OPEN] || valid_symbols[RAW_MULTIPLE_OPEN]) {
    lexer->advance(lexer, false);

    // EOF or 'no backtick': No more backticks, so it must be RAW_SINGLE_OPEN
    if (lexer->eof(lexer) || lexer->lookahead != '`') {
      lexer->result_symbol = RAW_SINGLE_OPEN;

      return true;
    }

    // We know there are two backticks, so this could be both a single or multiple raw block open token
    // Need to look ahead, but not consume
    lexer->mark_end(lexer);
    lexer->advance(lexer, false);

    // EOF or 'no backtick': The two backticks were RAW_SINGLE_OPEN and RAW_SINGLE_CLOSE, 
    // but currently we are parsing OPEN so this is what we return
    if (lexer->eof(lexer) || lexer->lookahead != '`') {
      lexer->result_symbol = RAW_SINGLE_OPEN;

      return true;
    }

    // Now we know there are at least three backticks, so this is a RAW_MULTIPLE_OPEN token. We need to count and consume all backticks
    char num_backticks = 2;
    while (!lexer->eof(lexer) && lexer->lookahead == '`') {
      num_backticks++;

      lexer->advance(lexer, false);
    }

    lexer->mark_end(lexer);
    s->num_backticks_in_open_token = num_backticks;

    lexer->result_symbol = RAW_MULTIPLE_OPEN;
    return true;
  }

  if (valid_symbols[RAW_SINGLE_CLOSE]) {
    lexer->advance(lexer, false);

    // EOF or 'no backtick': No more backticks, so it is RAW_SINGLE_CLOSE
    if (lexer->eof(lexer) || lexer->lookahead != '`') {
      lexer->result_symbol = RAW_SINGLE_CLOSE;

      return true;
    }

    // If there are more backticks, this is an error.
    return false;
  }
  

  if (valid_symbols[RAW_MULTIPLE_CLOSE]) {
    lexer->advance(lexer, false);

    // There must be exactly as many backticks as saved in s->num_backticks_in_open_token
    for (int num_backticks = 1; num_backticks < s->num_backticks_in_open_token; num_backticks++) {
      if (lexer->eof(lexer) || lexer->lookahead != '`') {
        return false;
      }

      lexer->advance(lexer, false);
    }

    // backtick: too many backticks
    if (lexer->lookahead == '`') {
      return false;
    }

    s->num_backticks_in_open_token = 0; // I think this is not needed, but better safe than sorry

    lexer->result_symbol = RAW_MULTIPLE_CLOSE;
    return true;
  }
  
  printf("\033[1;31mSCANNER: REACHED IMPOSSIBLE STATE\033[0m\n");

  return false;
}

bool parse_raw_single_content(TSLexer *lexer, const bool *valid_symbols) {
  do {
    lexer->advance(lexer, false);
  } while (!lexer->eof(lexer) && lexer->lookahead != '`');

  lexer->result_symbol = RAW_SINGLE_CONTENT;
  return true;
}

bool parse_escape(TSLexer *lexer, const bool *valid_symbols) {
  // This check is probably not needed, but better safe than sorry
  // TODO: Maybe improve how this is checked?
  if (!(valid_symbols[LINEBREAK]
        || valid_symbols[ESCAPE_BACKSLASH] 
        || valid_symbols[UNICODE_ESCAPE])
  ) {
    return false;
  }

  lexer->advance(lexer, false);

  if (lexer->eof(lexer) || isspace(lexer->lookahead)) {
    // NOTE: isspace recognizes space, \n, \t, \v, \f, and \r. It is unclear whether the
    // will make any problems or not, we'll see
    
    lexer->result_symbol = LINEBREAK;
    return true;
  }

  // At this point, the token is either a simple escape or a unicode escape
  if (lexer->lookahead != 'u') {
    lexer->result_symbol = ESCAPE_BACKSLASH;

    return true;
  }

  // Now the token is either an unicode escape or a normal escape of the character 'u'
  // We need to be careful, because we don't want to match the escaped 'u' if it is a normal escape
  lexer->mark_end(lexer);

  lexer->advance(lexer, false);

  if (lexer->eof(lexer) || lexer->lookahead != '{') {
    lexer->result_symbol = ESCAPE_BACKSLASH;
    return true;
  }

  // Now we know that the token must be an unicode escape!

  // TODO: Maybe check whether chars inside curly braces are valid unicode/hex?
  // For now this will check that there are at most 6 alnum chars inside the braces
  //
  // NOTE: For now unicode escapes can be empty
  
  const int MAX_UNICODE_HEX_LENGTH = 7; // 7 is not a mistake

  for (int i=0; i<MAX_UNICODE_HEX_LENGTH; i++) {
    lexer->advance(lexer, false);

    if (lexer->eof(lexer)) {
      return false;
    }

    if (lexer->lookahead == '}') {
      break;
    }

    if (!isalnum(lexer->lookahead)) {
      return false;
    }
  } 

  if (lexer->lookahead == '}') {
    lexer->advance(lexer, false);
    lexer->mark_end(lexer);

    lexer->result_symbol = UNICODE_ESCAPE;

    return true;
  }

  // More than 6 hex digits were found
  return false;
}


void * tree_sitter_typst_external_scanner_create() {
  Scanner *s = (Scanner *)malloc(sizeof(Scanner));
	return s;
}

void tree_sitter_typst_external_scanner_destroy(void *payload) {
  Scanner *s = (Scanner *)payload;
  free(s);
}

unsigned tree_sitter_typst_external_scanner_serialize(
  void *payload,
  char *buffer
) {
  Scanner *s = (Scanner *)payload;
  unsigned bytes_written = 0;

  buffer[bytes_written++] = (char)s->num_backticks_in_open_token; // TODO: idk??? is this correct?

  return bytes_written;
}

void tree_sitter_typst_external_scanner_deserialize(
  void *payload,
  char *buffer,
  unsigned length
) {
  Scanner *s = (Scanner *)payload;

  // Erase state variables before deserialization (see docs)
  s->num_backticks_in_open_token = 0;

  // Deserialization
  if (length > 0) {
    s->num_backticks_in_open_token = buffer[0];
  }
}

bool tree_sitter_typst_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  if (valid_symbols[ERROR]) {
    return false;
  }
  
  if (lexer->eof(lexer)) {
    return false;
  }

  // special case: RAW_CONTENT
  if (valid_symbols[RAW_SINGLE_CONTENT] && lexer->lookahead != '`') { // Make sure that we don't try to parse raw_content if it could be a delimiter
    return parse_raw_single_content(lexer, valid_symbols);
  }

  switch (lexer->lookahead) {
    case '=':
    if (valid_symbols[HEADING_PREFIX] && valid_symbols[EQUALSIGNS]) {
      return decide_heading_or_equalsigns(lexer, valid_symbols);

    } else if (valid_symbols[EQUALSIGNS]) {

      // if only EQUALSIGNS and not HEADING_PREFIX is valid, it can only be EQUALSIGNS
      lexer->advance(lexer, false);
      lexer->result_symbol = EQUALSIGNS;

      return true;

    } 

    // This should not be possible.
    printf("\033[1;31mSCANNER: REACHED IMPOSSIBLE STATE\033[0m\n");
    return false;

    case '*':
    return parse_strong(lexer, valid_symbols);

    case '_':
    return parse_italic(lexer, valid_symbols);

    case '<':
    case '>':
    return parse_label(lexer, valid_symbols);

    case '`':
    return parse_raw(lexer, valid_symbols, payload);

    case '\\':
    return parse_escape(lexer, valid_symbols);
  }

  return false;
}
