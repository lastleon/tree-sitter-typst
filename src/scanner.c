#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <wchar.h>
#include "tree_sitter/parser.h"

typedef enum {
  // ...
  LAST_TOKEN_NON_WORD,
  LAST_TOKEN_WORD,

  STRONG_OPEN,
  STRONG_CLOSE,

  ERROR,
} TokenType;

// typedef struct {
//   bool inside_strong;
// } Scanner;

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

  printf("\033[1;31mSCANNER: lookahead %d\033[0m\n\n", lexer->lookahead);
  if (valid_symbols[ERROR]) {
    printf("\033[1;31mSCANNER: ERROR SYMBOL VALID (%d), aborting!\033[0m\n\n", valid_symbols[ERROR]);

    printf("\033[1;31mSCANNER: LAST_TOKEN_NON_WORD %d\033[0m\n", valid_symbols[LAST_TOKEN_NON_WORD]);
    printf("\033[1;31mSCANNER: STRONG_OPEN %d\033[0m\n", valid_symbols[STRONG_OPEN]);
    printf("\033[1;31mSCANNER: STRONG_CLOSE %d\033[0m\n", valid_symbols[STRONG_CLOSE]);
    printf("\033[1;31mSCANNER: ERROR %d\033[0m\n", valid_symbols[ERROR]);
    printf("\033[1;31m==============================\033[0m\n");
    return false;
  }

  printf("\033[1;31mSCANNER: LAST_TOKEN_NON_WORD %d\033[0m\n", valid_symbols[LAST_TOKEN_NON_WORD]);
  printf("\033[1;31mSCANNER: STRONG_OPEN %d\033[0m\n", valid_symbols[STRONG_OPEN]);
  printf("\033[1;31mSCANNER: STRONG_CLOSE %d\033[0m\n", valid_symbols[STRONG_CLOSE]);
  // printf("\033[1;31mSCANNER: inside_strong %d\033[0m\n", s->inside_strong);
  printf("\033[1;31m==============================\033[0m\n");
  
  ////  STRONG_OPEN
  const bool STRONG_VALID = valid_symbols[STRONG_OPEN] || valid_symbols[STRONG_CLOSE];
  const bool EMPH_POSSIBLE = valid_symbols[LAST_TOKEN_WORD] || valid_symbols[LAST_TOKEN_NON_WORD];

  if (STRONG_VALID
      && EMPH_POSSIBLE
      && !lexer->eof(lexer)
      && lexer->lookahead == '*'
  ) {
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


  // // STRONG_CLOSE
  // if (s->inside_strong
  //     && valid_symbols[STRONG_CLOSE]
  //     && !lexer->eof(lexer)
  //     && lexer->lookahead == '*') {
  //   
  //   printf("\033[1;31mFOUND STRONG_CLOSE\033[0m\n");
  //   s->inside_strong = false;
  //   lexer->advance(lexer, false);
  //
  //   lexer->result_symbol = STRONG_CLOSE;
  //   return true;
  // }


  return false;

  // printf("SCANNERDBG: LAST_TOKEN_NON_WORD %d\n", valid_symbols[LAST_TOKEN_NON_WORD]);
  // printf("SCANNERDBG: TEST %d\n", valid_symbols[TEST]);
  // printf("SCANNERDBG: ERROR %d\n", valid_symbols[ERROR]);
  //
  // printf("SCANNERDBG: lookahead %c\n", lexer->lookahead);
  // lexer->advance(lexer, false);
  // printf("SCANNERDBG: lookahead %c\n", lexer->lookahead);
  // printf("==============================================\n");
}
