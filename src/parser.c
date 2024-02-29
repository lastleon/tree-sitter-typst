#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 35
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 25
#define ALIAS_COUNT 0
#define TOKEN_COUNT 11
#define EXTERNAL_TOKEN_COUNT 5
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum {
  aux_sym_newline_token1 = 1,
  aux_sym_whitespace_token1 = 2,
  aux_sym_word_token1 = 3,
  aux_sym_special_token1 = 4,
  sym_heading_prefix = 5,
  sym_last_token_non_word = 6,
  sym_last_token_word = 7,
  sym_strong_open = 8,
  sym_strong_close = 9,
  sym___error_canary = 10,
  sym_markup_block = 11,
  sym__markup_content = 12,
  sym_newline = 13,
  sym_whitespace = 14,
  sym_word = 15,
  sym_special = 16,
  sym_strong = 17,
  sym_heading = 18,
  sym_heading_whitespace = 19,
  sym_heading_content = 20,
  aux_sym_markup_block_repeat1 = 21,
  aux_sym_whitespace_repeat1 = 22,
  aux_sym_special_repeat1 = 23,
  aux_sym_heading_content_repeat1 = 24,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym_newline_token1] = "newline_token1",
  [aux_sym_whitespace_token1] = "whitespace_token1",
  [aux_sym_word_token1] = "word_token1",
  [aux_sym_special_token1] = "special_token1",
  [sym_heading_prefix] = "heading_prefix",
  [sym_last_token_non_word] = "last_token_non_word",
  [sym_last_token_word] = "last_token_word",
  [sym_strong_open] = "strong_open",
  [sym_strong_close] = "strong_close",
  [sym___error_canary] = "__error_canary",
  [sym_markup_block] = "markup_block",
  [sym__markup_content] = "_markup_content",
  [sym_newline] = "newline",
  [sym_whitespace] = "whitespace",
  [sym_word] = "word",
  [sym_special] = "special",
  [sym_strong] = "strong",
  [sym_heading] = "heading",
  [sym_heading_whitespace] = "heading_whitespace",
  [sym_heading_content] = "heading_content",
  [aux_sym_markup_block_repeat1] = "markup_block_repeat1",
  [aux_sym_whitespace_repeat1] = "whitespace_repeat1",
  [aux_sym_special_repeat1] = "special_repeat1",
  [aux_sym_heading_content_repeat1] = "heading_content_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym_newline_token1] = aux_sym_newline_token1,
  [aux_sym_whitespace_token1] = aux_sym_whitespace_token1,
  [aux_sym_word_token1] = aux_sym_word_token1,
  [aux_sym_special_token1] = aux_sym_special_token1,
  [sym_heading_prefix] = sym_heading_prefix,
  [sym_last_token_non_word] = sym_last_token_non_word,
  [sym_last_token_word] = sym_last_token_word,
  [sym_strong_open] = sym_strong_open,
  [sym_strong_close] = sym_strong_close,
  [sym___error_canary] = sym___error_canary,
  [sym_markup_block] = sym_markup_block,
  [sym__markup_content] = sym__markup_content,
  [sym_newline] = sym_newline,
  [sym_whitespace] = sym_whitespace,
  [sym_word] = sym_word,
  [sym_special] = sym_special,
  [sym_strong] = sym_strong,
  [sym_heading] = sym_heading,
  [sym_heading_whitespace] = sym_heading_whitespace,
  [sym_heading_content] = sym_heading_content,
  [aux_sym_markup_block_repeat1] = aux_sym_markup_block_repeat1,
  [aux_sym_whitespace_repeat1] = aux_sym_whitespace_repeat1,
  [aux_sym_special_repeat1] = aux_sym_special_repeat1,
  [aux_sym_heading_content_repeat1] = aux_sym_heading_content_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_newline_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_whitespace_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_word_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_special_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_heading_prefix] = {
    .visible = true,
    .named = true,
  },
  [sym_last_token_non_word] = {
    .visible = true,
    .named = true,
  },
  [sym_last_token_word] = {
    .visible = true,
    .named = true,
  },
  [sym_strong_open] = {
    .visible = true,
    .named = true,
  },
  [sym_strong_close] = {
    .visible = true,
    .named = true,
  },
  [sym___error_canary] = {
    .visible = false,
    .named = true,
  },
  [sym_markup_block] = {
    .visible = true,
    .named = true,
  },
  [sym__markup_content] = {
    .visible = false,
    .named = true,
  },
  [sym_newline] = {
    .visible = true,
    .named = true,
  },
  [sym_whitespace] = {
    .visible = true,
    .named = true,
  },
  [sym_word] = {
    .visible = true,
    .named = true,
  },
  [sym_special] = {
    .visible = true,
    .named = true,
  },
  [sym_strong] = {
    .visible = true,
    .named = true,
  },
  [sym_heading] = {
    .visible = true,
    .named = true,
  },
  [sym_heading_whitespace] = {
    .visible = true,
    .named = true,
  },
  [sym_heading_content] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_markup_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_whitespace_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_special_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_heading_content_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 7,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 6,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 16,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 5,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 22,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(5);
      if (lookahead == '=') ADVANCE(16);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(12);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(6);
      if (lookahead == '\r') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(9);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '*') ADVANCE(13);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '\r') SKIP(2)
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(10);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      END_STATE();
    case 4:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(11);
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '*') ADVANCE(13);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(aux_sym_newline_token1);
      if (lookahead == '\n') ADVANCE(6);
      if (lookahead == '\r') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(9);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(aux_sym_newline_token1);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(10);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(aux_sym_newline_token1);
      if (lookahead == '\n') ADVANCE(8);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(aux_sym_whitespace_token1);
      if (lookahead == '\n') ADVANCE(6);
      if (lookahead == '\r') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(9);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(aux_sym_whitespace_token1);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(10);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(aux_sym_whitespace_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(11);
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(15);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(aux_sym_word_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(aux_sym_special_token1);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(aux_sym_special_token1);
      if (lookahead == '\n') ADVANCE(6);
      if (lookahead == '\r') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '*' &&
          (lookahead < '0' || '9' < lookahead) &&
          (lookahead < 'A' || 'Z' < lookahead) &&
          lookahead != '_' &&
          (lookahead < 'a' || 'z' < lookahead)) ADVANCE(13);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(aux_sym_special_token1);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(11);
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '*' &&
          (lookahead < '0' || '9' < lookahead) &&
          (lookahead < 'A' || 'Z' < lookahead) &&
          lookahead != '_' &&
          (lookahead < 'a' || 'z' < lookahead)) ADVANCE(13);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_heading_prefix);
      if (lookahead == '=') ADVANCE(16);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0, .external_lex_state = 2},
  [2] = {.lex_state = 1, .external_lex_state = 3},
  [3] = {.lex_state = 1, .external_lex_state = 3},
  [4] = {.lex_state = 4, .external_lex_state = 3},
  [5] = {.lex_state = 1, .external_lex_state = 4},
  [6] = {.lex_state = 1, .external_lex_state = 3},
  [7] = {.lex_state = 1, .external_lex_state = 5},
  [8] = {.lex_state = 1, .external_lex_state = 3},
  [9] = {.lex_state = 1, .external_lex_state = 3},
  [10] = {.lex_state = 1, .external_lex_state = 3},
  [11] = {.lex_state = 1, .external_lex_state = 5},
  [12] = {.lex_state = 4, .external_lex_state = 5},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 1, .external_lex_state = 3},
  [17] = {.lex_state = 4, .external_lex_state = 3},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 1, .external_lex_state = 3},
  [20] = {.lex_state = 4, .external_lex_state = 3},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 1, .external_lex_state = 3},
  [23] = {.lex_state = 1, .external_lex_state = 3},
  [24] = {.lex_state = 4, .external_lex_state = 3},
  [25] = {.lex_state = 0, .external_lex_state = 2},
  [26] = {.lex_state = 3},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0, .external_lex_state = 6},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0, .external_lex_state = 7},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0, .external_lex_state = 7},
};

enum {
  ts_external_token_last_token_non_word = 0,
  ts_external_token_last_token_word = 1,
  ts_external_token_strong_open = 2,
  ts_external_token_strong_close = 3,
  ts_external_token___error_canary = 4,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_last_token_non_word] = sym_last_token_non_word,
  [ts_external_token_last_token_word] = sym_last_token_word,
  [ts_external_token_strong_open] = sym_strong_open,
  [ts_external_token_strong_close] = sym_strong_close,
  [ts_external_token___error_canary] = sym___error_canary,
};

static const bool ts_external_scanner_states[8][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_last_token_non_word] = true,
    [ts_external_token_last_token_word] = true,
    [ts_external_token_strong_open] = true,
    [ts_external_token_strong_close] = true,
    [ts_external_token___error_canary] = true,
  },
  [2] = {
    [ts_external_token_last_token_non_word] = true,
  },
  [3] = {
    [ts_external_token_strong_open] = true,
  },
  [4] = {
    [ts_external_token_last_token_word] = true,
    [ts_external_token_strong_open] = true,
  },
  [5] = {
    [ts_external_token_last_token_non_word] = true,
    [ts_external_token_strong_open] = true,
  },
  [6] = {
    [ts_external_token_last_token_word] = true,
    [ts_external_token_strong_close] = true,
  },
  [7] = {
    [ts_external_token_strong_close] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [aux_sym_word_token1] = ACTIONS(1),
    [sym_heading_prefix] = ACTIONS(1),
    [sym_last_token_non_word] = ACTIONS(1),
    [sym_last_token_word] = ACTIONS(1),
    [sym_strong_open] = ACTIONS(1),
    [sym_strong_close] = ACTIONS(1),
    [sym___error_canary] = ACTIONS(1),
  },
  [1] = {
    [sym_markup_block] = STATE(33),
    [sym__markup_content] = STATE(21),
    [sym_heading] = STATE(21),
    [aux_sym_markup_block_repeat1] = STATE(21),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_heading_prefix] = ACTIONS(5),
    [sym_last_token_non_word] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(9), 1,
      aux_sym_newline_token1,
    ACTIONS(11), 1,
      aux_sym_whitespace_token1,
    ACTIONS(14), 1,
      aux_sym_word_token1,
    ACTIONS(17), 1,
      aux_sym_special_token1,
    ACTIONS(20), 1,
      sym_strong_open,
    STATE(9), 1,
      aux_sym_special_repeat1,
    STATE(10), 1,
      aux_sym_whitespace_repeat1,
    STATE(2), 5,
      sym_whitespace,
      sym_word,
      sym_special,
      sym_strong,
      aux_sym_heading_content_repeat1,
  [29] = 8,
    ACTIONS(23), 1,
      aux_sym_newline_token1,
    ACTIONS(25), 1,
      aux_sym_whitespace_token1,
    ACTIONS(27), 1,
      aux_sym_word_token1,
    ACTIONS(29), 1,
      aux_sym_special_token1,
    ACTIONS(31), 1,
      sym_strong_open,
    STATE(9), 1,
      aux_sym_special_repeat1,
    STATE(10), 1,
      aux_sym_whitespace_repeat1,
    STATE(2), 5,
      sym_whitespace,
      sym_word,
      sym_special,
      sym_strong,
      aux_sym_heading_content_repeat1,
  [58] = 8,
    ACTIONS(25), 1,
      aux_sym_whitespace_token1,
    ACTIONS(27), 1,
      aux_sym_word_token1,
    ACTIONS(29), 1,
      aux_sym_special_token1,
    ACTIONS(31), 1,
      sym_strong_open,
    STATE(9), 1,
      aux_sym_special_repeat1,
    STATE(10), 1,
      aux_sym_whitespace_repeat1,
    STATE(26), 1,
      sym_heading_content,
    STATE(3), 5,
      sym_whitespace,
      sym_word,
      sym_special,
      sym_strong,
      aux_sym_heading_content_repeat1,
  [87] = 3,
    ACTIONS(35), 1,
      sym_last_token_word,
    ACTIONS(37), 1,
      sym_strong_open,
    ACTIONS(33), 4,
      aux_sym_newline_token1,
      aux_sym_whitespace_token1,
      aux_sym_word_token1,
      aux_sym_special_token1,
  [100] = 4,
    ACTIONS(41), 1,
      aux_sym_whitespace_token1,
    ACTIONS(44), 1,
      sym_strong_open,
    STATE(6), 1,
      aux_sym_whitespace_repeat1,
    ACTIONS(39), 3,
      aux_sym_newline_token1,
      aux_sym_word_token1,
      aux_sym_special_token1,
  [115] = 3,
    ACTIONS(48), 1,
      sym_last_token_non_word,
    ACTIONS(50), 1,
      sym_strong_open,
    ACTIONS(46), 4,
      aux_sym_newline_token1,
      aux_sym_whitespace_token1,
      aux_sym_word_token1,
      aux_sym_special_token1,
  [128] = 4,
    ACTIONS(54), 1,
      aux_sym_special_token1,
    ACTIONS(57), 1,
      sym_strong_open,
    STATE(8), 1,
      aux_sym_special_repeat1,
    ACTIONS(52), 3,
      aux_sym_newline_token1,
      aux_sym_whitespace_token1,
      aux_sym_word_token1,
  [143] = 4,
    ACTIONS(29), 1,
      aux_sym_special_token1,
    ACTIONS(61), 1,
      sym_strong_open,
    STATE(8), 1,
      aux_sym_special_repeat1,
    ACTIONS(59), 3,
      aux_sym_newline_token1,
      aux_sym_whitespace_token1,
      aux_sym_word_token1,
  [158] = 4,
    ACTIONS(25), 1,
      aux_sym_whitespace_token1,
    ACTIONS(65), 1,
      sym_strong_open,
    STATE(6), 1,
      aux_sym_whitespace_repeat1,
    ACTIONS(63), 3,
      aux_sym_newline_token1,
      aux_sym_word_token1,
      aux_sym_special_token1,
  [173] = 3,
    ACTIONS(69), 1,
      sym_last_token_non_word,
    ACTIONS(71), 1,
      sym_strong_open,
    ACTIONS(67), 4,
      aux_sym_newline_token1,
      aux_sym_whitespace_token1,
      aux_sym_word_token1,
      aux_sym_special_token1,
  [186] = 3,
    ACTIONS(50), 1,
      sym_strong_open,
    ACTIONS(73), 1,
      sym_last_token_non_word,
    ACTIONS(46), 3,
      aux_sym_whitespace_token1,
      aux_sym_word_token1,
      aux_sym_special_token1,
  [198] = 3,
    ACTIONS(5), 1,
      sym_heading_prefix,
    ACTIONS(75), 1,
      ts_builtin_sym_end,
    STATE(14), 3,
      sym__markup_content,
      sym_heading,
      aux_sym_markup_block_repeat1,
  [210] = 3,
    ACTIONS(77), 1,
      ts_builtin_sym_end,
    ACTIONS(79), 1,
      sym_heading_prefix,
    STATE(14), 3,
      sym__markup_content,
      sym_heading,
      aux_sym_markup_block_repeat1,
  [222] = 5,
    ACTIONS(82), 1,
      aux_sym_newline_token1,
    ACTIONS(84), 1,
      aux_sym_whitespace_token1,
    STATE(4), 1,
      sym_heading_whitespace,
    STATE(17), 1,
      aux_sym_whitespace_repeat1,
    STATE(29), 1,
      sym_newline,
  [238] = 2,
    ACTIONS(44), 1,
      sym_strong_open,
    ACTIONS(39), 4,
      aux_sym_newline_token1,
      aux_sym_whitespace_token1,
      aux_sym_word_token1,
      aux_sym_special_token1,
  [248] = 3,
    ACTIONS(88), 1,
      sym_strong_open,
    STATE(20), 1,
      aux_sym_whitespace_repeat1,
    ACTIONS(86), 3,
      aux_sym_whitespace_token1,
      aux_sym_word_token1,
      aux_sym_special_token1,
  [260] = 3,
    ACTIONS(5), 1,
      sym_heading_prefix,
    ACTIONS(90), 1,
      ts_builtin_sym_end,
    STATE(13), 3,
      sym__markup_content,
      sym_heading,
      aux_sym_markup_block_repeat1,
  [272] = 2,
    ACTIONS(94), 1,
      sym_strong_open,
    ACTIONS(92), 4,
      aux_sym_newline_token1,
      aux_sym_whitespace_token1,
      aux_sym_word_token1,
      aux_sym_special_token1,
  [282] = 4,
    ACTIONS(44), 1,
      sym_strong_open,
    ACTIONS(96), 1,
      aux_sym_whitespace_token1,
    STATE(20), 1,
      aux_sym_whitespace_repeat1,
    ACTIONS(39), 2,
      aux_sym_word_token1,
      aux_sym_special_token1,
  [296] = 3,
    ACTIONS(5), 1,
      sym_heading_prefix,
    ACTIONS(90), 1,
      ts_builtin_sym_end,
    STATE(14), 3,
      sym__markup_content,
      sym_heading,
      aux_sym_markup_block_repeat1,
  [308] = 2,
    ACTIONS(101), 1,
      sym_strong_open,
    ACTIONS(99), 4,
      aux_sym_newline_token1,
      aux_sym_whitespace_token1,
      aux_sym_word_token1,
      aux_sym_special_token1,
  [318] = 2,
    ACTIONS(57), 1,
      sym_strong_open,
    ACTIONS(52), 4,
      aux_sym_newline_token1,
      aux_sym_whitespace_token1,
      aux_sym_word_token1,
      aux_sym_special_token1,
  [328] = 2,
    ACTIONS(44), 1,
      sym_strong_open,
    ACTIONS(39), 3,
      aux_sym_whitespace_token1,
      aux_sym_word_token1,
      aux_sym_special_token1,
  [337] = 2,
    ACTIONS(105), 1,
      sym_last_token_non_word,
    ACTIONS(103), 2,
      ts_builtin_sym_end,
      sym_heading_prefix,
  [345] = 2,
    ACTIONS(107), 1,
      aux_sym_newline_token1,
    STATE(27), 1,
      sym_newline,
  [352] = 1,
    ACTIONS(109), 2,
      ts_builtin_sym_end,
      sym_heading_prefix,
  [357] = 1,
    ACTIONS(111), 2,
      ts_builtin_sym_end,
      sym_heading_prefix,
  [362] = 1,
    ACTIONS(113), 2,
      ts_builtin_sym_end,
      sym_heading_prefix,
  [367] = 2,
    ACTIONS(37), 1,
      sym_strong_close,
    ACTIONS(115), 1,
      sym_last_token_word,
  [374] = 2,
    ACTIONS(117), 1,
      aux_sym_word_token1,
    STATE(32), 1,
      sym_word,
  [381] = 1,
    ACTIONS(119), 1,
      sym_strong_close,
  [385] = 1,
    ACTIONS(121), 1,
      ts_builtin_sym_end,
  [389] = 1,
    ACTIONS(101), 1,
      sym_strong_close,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 29,
  [SMALL_STATE(4)] = 58,
  [SMALL_STATE(5)] = 87,
  [SMALL_STATE(6)] = 100,
  [SMALL_STATE(7)] = 115,
  [SMALL_STATE(8)] = 128,
  [SMALL_STATE(9)] = 143,
  [SMALL_STATE(10)] = 158,
  [SMALL_STATE(11)] = 173,
  [SMALL_STATE(12)] = 186,
  [SMALL_STATE(13)] = 198,
  [SMALL_STATE(14)] = 210,
  [SMALL_STATE(15)] = 222,
  [SMALL_STATE(16)] = 238,
  [SMALL_STATE(17)] = 248,
  [SMALL_STATE(18)] = 260,
  [SMALL_STATE(19)] = 272,
  [SMALL_STATE(20)] = 282,
  [SMALL_STATE(21)] = 296,
  [SMALL_STATE(22)] = 308,
  [SMALL_STATE(23)] = 318,
  [SMALL_STATE(24)] = 328,
  [SMALL_STATE(25)] = 337,
  [SMALL_STATE(26)] = 345,
  [SMALL_STATE(27)] = 352,
  [SMALL_STATE(28)] = 357,
  [SMALL_STATE(29)] = 362,
  [SMALL_STATE(30)] = 367,
  [SMALL_STATE(31)] = 374,
  [SMALL_STATE(32)] = 381,
  [SMALL_STATE(33)] = 385,
  [SMALL_STATE(34)] = 389,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_markup_block, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [9] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_heading_content_repeat1, 2),
  [11] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading_content_repeat1, 2), SHIFT_REPEAT(7),
  [14] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading_content_repeat1, 2), SHIFT_REPEAT(5),
  [17] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading_content_repeat1, 2), SHIFT_REPEAT(11),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_heading_content_repeat1, 2), SHIFT_REPEAT(31),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_heading_content, 1),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_word, 1),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_word, 1),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_whitespace_repeat1, 2),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_whitespace_repeat1, 2), SHIFT_REPEAT(7),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_whitespace_repeat1, 2),
  [46] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_whitespace_repeat1, 1),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_whitespace_repeat1, 1),
  [52] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_special_repeat1, 2),
  [54] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_special_repeat1, 2), SHIFT_REPEAT(11),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_special_repeat1, 2),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_special, 1),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_special, 1),
  [63] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_whitespace, 1),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_whitespace, 1),
  [67] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_special_repeat1, 1),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_special_repeat1, 1),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_markup_block, 2),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_markup_block_repeat1, 2),
  [79] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_markup_block_repeat1, 2), SHIFT_REPEAT(15),
  [82] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [84] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_heading_whitespace, 1),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heading_whitespace, 1),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_markup_block, 1),
  [92] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_strong, 3),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_strong, 3),
  [96] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_whitespace_repeat1, 2), SHIFT_REPEAT(12),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_word, 2),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_word, 2),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_newline, 1),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heading, 4),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_newline, 2),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heading, 2),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [121] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_typst_external_scanner_create(void);
void tree_sitter_typst_external_scanner_destroy(void *);
bool tree_sitter_typst_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_typst_external_scanner_serialize(void *, char *);
void tree_sitter_typst_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_typst(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_typst_external_scanner_create,
      tree_sitter_typst_external_scanner_destroy,
      tree_sitter_typst_external_scanner_scan,
      tree_sitter_typst_external_scanner_serialize,
      tree_sitter_typst_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
