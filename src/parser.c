#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 24
#define LARGE_STATE_COUNT 7
#define SYMBOL_COUNT 17
#define ALIAS_COUNT 1
#define TOKEN_COUNT 8
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 2

enum {
  sym__newline = 1,
  sym__heading_prefix = 2,
  aux_sym__text_token1 = 3,
  aux_sym__text_token2 = 4,
  sym__strong_delim_opn = 5,
  aux_sym__strong_delim_cls_token1 = 6,
  sym_line_comment = 7,
  sym_markup_block = 8,
  sym__emptyline = 9,
  sym_heading = 10,
  aux_sym__line_content = 11,
  sym__text = 12,
  sym_strong = 13,
  sym__strong_delim_cls = 14,
  sym_comment = 15,
  aux_sym_markup_block_repeat1 = 16,
  alias_sym_heading_text = 17,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__newline] = "_newline",
  [sym__heading_prefix] = "_heading_prefix",
  [aux_sym__text_token1] = "_text_token1",
  [aux_sym__text_token2] = "_text_token2",
  [sym__strong_delim_opn] = "_strong_delim_opn",
  [aux_sym__strong_delim_cls_token1] = "_strong_delim_cls_token1",
  [sym_line_comment] = "line_comment",
  [sym_markup_block] = "markup_block",
  [sym__emptyline] = "_emptyline",
  [sym_heading] = "heading",
  [aux_sym__line_content] = "_line_content",
  [sym__text] = "_text",
  [sym_strong] = "strong",
  [sym__strong_delim_cls] = "_strong_delim_cls",
  [sym_comment] = "comment",
  [aux_sym_markup_block_repeat1] = "markup_block_repeat1",
  [alias_sym_heading_text] = "heading_text",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__newline] = sym__newline,
  [sym__heading_prefix] = sym__heading_prefix,
  [aux_sym__text_token1] = aux_sym__text_token1,
  [aux_sym__text_token2] = aux_sym__text_token2,
  [sym__strong_delim_opn] = sym__strong_delim_opn,
  [aux_sym__strong_delim_cls_token1] = aux_sym__strong_delim_cls_token1,
  [sym_line_comment] = sym_line_comment,
  [sym_markup_block] = sym_markup_block,
  [sym__emptyline] = sym__emptyline,
  [sym_heading] = sym_heading,
  [aux_sym__line_content] = aux_sym__line_content,
  [sym__text] = sym__text,
  [sym_strong] = sym_strong,
  [sym__strong_delim_cls] = sym__strong_delim_cls,
  [sym_comment] = sym_comment,
  [aux_sym_markup_block_repeat1] = aux_sym_markup_block_repeat1,
  [alias_sym_heading_text] = alias_sym_heading_text,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym__newline] = {
    .visible = false,
    .named = true,
  },
  [sym__heading_prefix] = {
    .visible = false,
    .named = true,
  },
  [aux_sym__text_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__text_token2] = {
    .visible = false,
    .named = false,
  },
  [sym__strong_delim_opn] = {
    .visible = false,
    .named = true,
  },
  [aux_sym__strong_delim_cls_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_line_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_markup_block] = {
    .visible = true,
    .named = true,
  },
  [sym__emptyline] = {
    .visible = false,
    .named = true,
  },
  [sym_heading] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__line_content] = {
    .visible = false,
    .named = false,
  },
  [sym__text] = {
    .visible = false,
    .named = true,
  },
  [sym_strong] = {
    .visible = true,
    .named = true,
  },
  [sym__strong_delim_cls] = {
    .visible = false,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_markup_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_heading_text] = {
    .visible = true,
    .named = true,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [1] = alias_sym_heading_text,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  aux_sym__line_content, 2,
    aux_sym__line_content,
    alias_sym_heading_text,
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 4,
  [6] = 3,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 8,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 13,
  [17] = 11,
  [18] = 15,
  [19] = 7,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(6);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '*') ADVANCE(13);
      if (lookahead == '/') ADVANCE(11);
      if (lookahead == '=') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(9);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(16);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '*') ADVANCE(13);
      if (lookahead == '/') ADVANCE(11);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(9);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 3:
      if (lookahead == '/') ADVANCE(11);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(9);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 4:
      if (lookahead == '=') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == ' ' ||
          lookahead == '|') ADVANCE(8);
      END_STATE();
    case 5:
      if (eof) ADVANCE(6);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '/') ADVANCE(11);
      if (lookahead == '=') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(9);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym__newline);
      if (lookahead == '*') ADVANCE(14);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym__heading_prefix);
      if (lookahead == '\t' ||
          lookahead == ' ' ||
          lookahead == '|') ADVANCE(8);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(aux_sym__text_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(9);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(aux_sym__text_token2);
      if (lookahead == '*') ADVANCE(14);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(aux_sym__text_token2);
      if (lookahead == '*') ADVANCE(14);
      if (lookahead == '/') ADVANCE(1);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(aux_sym__text_token2);
      if (lookahead == '*') ADVANCE(14);
      if (lookahead == '=') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == ' ' ||
          lookahead == '|') ADVANCE(8);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(aux_sym__text_token2);
      if (lookahead == '*') ADVANCE(14);
      if (lookahead != 0 &&
          (lookahead < '0' || '9' < lookahead) &&
          (lookahead < 'A' || 'Z' < lookahead) &&
          (lookahead < 'a' || 'z' < lookahead)) ADVANCE(15);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym__strong_delim_opn);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(aux_sym__strong_delim_cls_token1);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_line_comment);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 5},
  [3] = {.lex_state = 5},
  [4] = {.lex_state = 2},
  [5] = {.lex_state = 2},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 5},
  [8] = {.lex_state = 3},
  [9] = {.lex_state = 3},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 5},
  [12] = {.lex_state = 3},
  [13] = {.lex_state = 5},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 5},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 2},
  [18] = {.lex_state = 2},
  [19] = {.lex_state = 2},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {(TSStateId)(-1)},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym_comment] = STATE(0),
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym__newline] = ACTIONS(1),
    [sym__heading_prefix] = ACTIONS(1),
    [aux_sym__text_token1] = ACTIONS(1),
    [aux_sym__text_token2] = ACTIONS(1),
    [sym__strong_delim_opn] = ACTIONS(1),
    [aux_sym__strong_delim_cls_token1] = ACTIONS(1),
    [sym_line_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_markup_block] = STATE(22),
    [sym__emptyline] = STATE(20),
    [sym_heading] = STATE(20),
    [sym_comment] = STATE(1),
    [aux_sym_markup_block_repeat1] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym__newline] = ACTIONS(7),
    [sym__heading_prefix] = ACTIONS(9),
    [sym_line_comment] = ACTIONS(3),
  },
  [2] = {
    [aux_sym__line_content] = STATE(3),
    [sym__text] = STATE(13),
    [sym_strong] = STATE(13),
    [sym_comment] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(11),
    [sym__newline] = ACTIONS(13),
    [sym__heading_prefix] = ACTIONS(11),
    [aux_sym__text_token1] = ACTIONS(15),
    [aux_sym__text_token2] = ACTIONS(17),
    [sym__strong_delim_opn] = ACTIONS(19),
    [sym_line_comment] = ACTIONS(3),
  },
  [3] = {
    [aux_sym__line_content] = STATE(3),
    [sym__text] = STATE(13),
    [sym_strong] = STATE(13),
    [sym_comment] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(21),
    [sym__newline] = ACTIONS(23),
    [sym__heading_prefix] = ACTIONS(21),
    [aux_sym__text_token1] = ACTIONS(25),
    [aux_sym__text_token2] = ACTIONS(28),
    [sym__strong_delim_opn] = ACTIONS(31),
    [sym_line_comment] = ACTIONS(3),
  },
  [4] = {
    [aux_sym__line_content] = STATE(6),
    [sym__text] = STATE(16),
    [sym_strong] = STATE(16),
    [sym__strong_delim_cls] = STATE(19),
    [sym_comment] = STATE(4),
    [aux_sym__text_token1] = ACTIONS(34),
    [aux_sym__text_token2] = ACTIONS(36),
    [sym__strong_delim_opn] = ACTIONS(38),
    [aux_sym__strong_delim_cls_token1] = ACTIONS(40),
    [sym_line_comment] = ACTIONS(3),
  },
  [5] = {
    [aux_sym__line_content] = STATE(6),
    [sym__text] = STATE(16),
    [sym_strong] = STATE(16),
    [sym__strong_delim_cls] = STATE(7),
    [sym_comment] = STATE(5),
    [aux_sym__text_token1] = ACTIONS(34),
    [aux_sym__text_token2] = ACTIONS(36),
    [sym__strong_delim_opn] = ACTIONS(38),
    [aux_sym__strong_delim_cls_token1] = ACTIONS(42),
    [sym_line_comment] = ACTIONS(3),
  },
  [6] = {
    [aux_sym__line_content] = STATE(6),
    [sym__text] = STATE(16),
    [sym_strong] = STATE(16),
    [sym_comment] = STATE(6),
    [aux_sym__text_token1] = ACTIONS(44),
    [aux_sym__text_token2] = ACTIONS(47),
    [sym__strong_delim_opn] = ACTIONS(50),
    [aux_sym__strong_delim_cls_token1] = ACTIONS(23),
    [sym_line_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(7), 1,
      sym_comment,
    ACTIONS(55), 2,
      sym__newline,
      aux_sym__text_token2,
    ACTIONS(53), 4,
      ts_builtin_sym_end,
      sym__heading_prefix,
      aux_sym__text_token1,
      sym__strong_delim_opn,
  [17] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(34), 1,
      aux_sym__text_token1,
    ACTIONS(36), 1,
      aux_sym__text_token2,
    ACTIONS(38), 1,
      sym__strong_delim_opn,
    STATE(4), 1,
      aux_sym__line_content,
    STATE(8), 1,
      sym_comment,
    STATE(16), 2,
      sym__text,
      sym_strong,
  [40] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(15), 1,
      aux_sym__text_token1,
    ACTIONS(17), 1,
      aux_sym__text_token2,
    ACTIONS(19), 1,
      sym__strong_delim_opn,
    STATE(2), 1,
      aux_sym__line_content,
    STATE(9), 1,
      sym_comment,
    STATE(13), 2,
      sym__text,
      sym_strong,
  [63] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(7), 1,
      sym__newline,
    ACTIONS(9), 1,
      sym__heading_prefix,
    ACTIONS(57), 1,
      ts_builtin_sym_end,
    STATE(10), 1,
      sym_comment,
    STATE(14), 1,
      aux_sym_markup_block_repeat1,
    STATE(20), 2,
      sym__emptyline,
      sym_heading,
  [86] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(11), 1,
      sym_comment,
    ACTIONS(61), 2,
      sym__newline,
      aux_sym__text_token2,
    ACTIONS(59), 4,
      ts_builtin_sym_end,
      sym__heading_prefix,
      aux_sym__text_token1,
      sym__strong_delim_opn,
  [103] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(34), 1,
      aux_sym__text_token1,
    ACTIONS(36), 1,
      aux_sym__text_token2,
    ACTIONS(38), 1,
      sym__strong_delim_opn,
    STATE(5), 1,
      aux_sym__line_content,
    STATE(12), 1,
      sym_comment,
    STATE(16), 2,
      sym__text,
      sym_strong,
  [126] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(13), 1,
      sym_comment,
    ACTIONS(65), 2,
      sym__newline,
      aux_sym__text_token2,
    ACTIONS(63), 4,
      ts_builtin_sym_end,
      sym__heading_prefix,
      aux_sym__text_token1,
      sym__strong_delim_opn,
  [143] = 6,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(67), 1,
      ts_builtin_sym_end,
    ACTIONS(69), 1,
      sym__newline,
    ACTIONS(72), 1,
      sym__heading_prefix,
    STATE(14), 2,
      sym_comment,
      aux_sym_markup_block_repeat1,
    STATE(20), 2,
      sym__emptyline,
      sym_heading,
  [164] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(15), 1,
      sym_comment,
    ACTIONS(77), 2,
      sym__newline,
      aux_sym__text_token2,
    ACTIONS(75), 4,
      ts_builtin_sym_end,
      sym__heading_prefix,
      aux_sym__text_token1,
      sym__strong_delim_opn,
  [181] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(16), 1,
      sym_comment,
    ACTIONS(63), 2,
      aux_sym__text_token1,
      sym__strong_delim_opn,
    ACTIONS(65), 2,
      aux_sym__text_token2,
      aux_sym__strong_delim_cls_token1,
  [196] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(17), 1,
      sym_comment,
    ACTIONS(59), 2,
      aux_sym__text_token1,
      sym__strong_delim_opn,
    ACTIONS(61), 2,
      aux_sym__text_token2,
      aux_sym__strong_delim_cls_token1,
  [211] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(18), 1,
      sym_comment,
    ACTIONS(75), 2,
      aux_sym__text_token1,
      sym__strong_delim_opn,
    ACTIONS(77), 2,
      aux_sym__text_token2,
      aux_sym__strong_delim_cls_token1,
  [226] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(19), 1,
      sym_comment,
    ACTIONS(53), 2,
      aux_sym__text_token1,
      sym__strong_delim_opn,
    ACTIONS(55), 2,
      aux_sym__text_token2,
      aux_sym__strong_delim_cls_token1,
  [241] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(20), 1,
      sym_comment,
    ACTIONS(79), 3,
      ts_builtin_sym_end,
      sym__newline,
      sym__heading_prefix,
  [253] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(21), 1,
      sym_comment,
    ACTIONS(81), 3,
      ts_builtin_sym_end,
      sym__newline,
      sym__heading_prefix,
  [265] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(83), 1,
      ts_builtin_sym_end,
    STATE(22), 1,
      sym_comment,
  [275] = 1,
    ACTIONS(85), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(7)] = 0,
  [SMALL_STATE(8)] = 17,
  [SMALL_STATE(9)] = 40,
  [SMALL_STATE(10)] = 63,
  [SMALL_STATE(11)] = 86,
  [SMALL_STATE(12)] = 103,
  [SMALL_STATE(13)] = 126,
  [SMALL_STATE(14)] = 143,
  [SMALL_STATE(15)] = 164,
  [SMALL_STATE(16)] = 181,
  [SMALL_STATE(17)] = 196,
  [SMALL_STATE(18)] = 211,
  [SMALL_STATE(19)] = 226,
  [SMALL_STATE(20)] = 241,
  [SMALL_STATE(21)] = 253,
  [SMALL_STATE(22)] = 265,
  [SMALL_STATE(23)] = 275,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_markup_block, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heading, 2, .production_id = 1),
  [13] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_heading, 2, .production_id = 1),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__line_content, 2),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__line_content, 2),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__line_content, 2), SHIFT_REPEAT(11),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__line_content, 2), SHIFT_REPEAT(11),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__line_content, 2), SHIFT_REPEAT(12),
  [34] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [36] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [38] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [40] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [42] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [44] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__line_content, 2), SHIFT_REPEAT(17),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__line_content, 2), SHIFT_REPEAT(17),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__line_content, 2), SHIFT_REPEAT(8),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_strong, 3),
  [55] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_strong, 3),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_markup_block, 1),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__text, 1),
  [61] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__text, 1),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__line_content, 1),
  [65] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__line_content, 1),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_markup_block_repeat1, 2),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_markup_block_repeat1, 2), SHIFT_REPEAT(21),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_markup_block_repeat1, 2), SHIFT_REPEAT(9),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__strong_delim_cls, 1),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__strong_delim_cls, 1),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_markup_block_repeat1, 1),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__emptyline, 1),
  [83] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1),
};

#ifdef __cplusplus
extern "C" {
#endif
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
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
