#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <wchar.h>
#include "tree_sitter/parser.h"

typedef enum {
  // ...
  LAST_TOKEN_NON_WORD,
  LAST_TOKEN_WORD,

  STRONG_OPEN,
  STRONG_CLOSE,

  HEADING_PREFIX,
  EQUALSIGNS,

  ERROR,
} TokenType;

// typedef struct {
//   bool inside_strong;
// } Scanner;

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

  if (STRONG_VALID && EMPH_POSSIBLE) {

    // we need to check if it is a delimiter
    lexer->advance(lexer, false);

    bool is_delimiter = true;

    // if LAST_TOKEN_NON_WORD, then the star is a delimiter
    // otherwise: only way it is not a delimiter is if the last token
    // was a word and the next one also is
    if (valid_symbols[LAST_TOKEN_WORD]
        && !lexer->eof(lexer)
        && isalnum((char) lexer->lookahead)) { // TODO: IMPROVE SUPPORT FOR NON-LATIN CHARACTERS
      is_delimiter = false;
    }

    if (is_delimiter) {
      if (valid_symbols[STRONG_OPEN]) {
        lexer->result_symbol = STRONG_OPEN;
      } else if (valid_symbols[STRONG_CLOSE]) {
        lexer->result_symbol = STRONG_CLOSE;
      }

      return true;
    }
  }

  return false;
}


void * tree_sitter_typst_external_scanner_create() {
 //  Scanner *s = (Scanner *)malloc(sizeof(Scanner));
	// return s;
  return NULL;
}

void tree_sitter_typst_external_scanner_destroy(void *payload) {
  // Scanner *s = (Scanner *)payload;
  // free(s);
}

unsigned tree_sitter_typst_external_scanner_serialize(
  void *payload,
  char *buffer
) {
  // Scanner *s = (Scanner *)payload;
  // unsigned bytes_written = 0;
  //
  // buffer[bytes_written++] = (char)s->inside_strong;
  //
  // return bytes_written;
  return 0;
}

void tree_sitter_typst_external_scanner_deserialize(
  void *payload,
  char *buffer,
  unsigned length
) {
  // Scanner *s = (Scanner *)payload;
  //
  // // Erase state variables before deserialization (see docs)
  // s->inside_strong = 0;
  //
  // // Deserialization
  // if (length > 0) {
  //   s->inside_strong = buffer[0];
  // }
}

bool tree_sitter_typst_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  // Scanner *s = (Scanner *)payload;

  // printf("\033[1;31mSCANNER: LAST_TOKEN_NON_WORD %d\033[0m\n", valid_symbols[LAST_TOKEN_NON_WORD]);
  // printf("\033[1;31mSCANNER: LAST_TOKEN_WORD %d\033[0m\n", valid_symbols[LAST_TOKEN_WORD]);
  // printf("\033[1;31mSCANNER: STRONG_OPEN %d\033[0m\n", valid_symbols[STRONG_OPEN]);
  // printf("\033[1;31mSCANNER: STRONG_CLOSE %d\033[0m\n", valid_symbols[STRONG_CLOSE]);
  // printf("\033[1;31m==============================\033[0m\n");

  if (valid_symbols[ERROR]) {
    // printf("\033[1;31mSCANNER: ERROR SYMBOL VALID (%d), aborting!\033[0m\n\n", valid_symbols[ERROR]);
    return false;
  }
  
  if (lexer->eof(lexer)) {
    return false;
  }

  if (lexer->lookahead == '=') {

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

  } else if (lexer->lookahead == '*') {

    return parse_strong(lexer, valid_symbols);

  }

  return false;
}
