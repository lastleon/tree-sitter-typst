#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 27
#define LARGE_STATE_COUNT 6
#define SYMBOL_COUNT 18
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
  sym_line = 9,
  sym__emptyline = 10,
  sym_heading = 11,
  aux_sym__line_content = 12,
  sym__text = 13,
  sym_strong = 14,
  sym__strong_delim_cls = 15,
  sym_comment = 16,
  aux_sym_markup_block_repeat1 = 17,
  alias_sym_heading_text = 18,
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
  [sym_line] = "line",
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
  [sym_line] = sym_line,
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
  [sym_line] = {
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
  [6] = 6,
  [7] = 7,
  [8] = 7,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 10,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 17,
  [21] = 16,
  [22] = 18,
  [23] = 19,
  [24] = 24,
  [25] = 25,
  [26] = 26,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(8);
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == '\r') ADVANCE(11);
      if (lookahead == '*') ADVANCE(18);
      if (lookahead == '/') ADVANCE(16);
      if (lookahead == '=') ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      if (lookahead != 0) ADVANCE(15);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == '\r') ADVANCE(11);
      if (lookahead == '/') ADVANCE(16);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      if (lookahead != 0) ADVANCE(15);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(9);
      if (lookahead == '\r') ADVANCE(10);
      if (lookahead == '/') ADVANCE(5);
      END_STATE();
    case 3:
      if (lookahead == '*') ADVANCE(18);
      if (lookahead == '/') ADVANCE(16);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      if (lookahead != 0) ADVANCE(15);
      END_STATE();
    case 4:
      if (lookahead == '/') ADVANCE(16);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      if (lookahead != 0) ADVANCE(15);
      END_STATE();
    case 5:
      if (lookahead == '/') ADVANCE(21);
      END_STATE();
    case 6:
      if (lookahead == '=') ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == ' ' ||
          lookahead == '|') ADVANCE(13);
      END_STATE();
    case 7:
      if (eof) ADVANCE(8);
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == '\r') ADVANCE(11);
      if (lookahead == '/') ADVANCE(16);
      if (lookahead == '=') ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      if (lookahead != 0) ADVANCE(15);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym__newline);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym__newline);
      if (lookahead == '\n') ADVANCE(9);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym__newline);
      if (lookahead == '\n') ADVANCE(9);
      if (lookahead == '*') ADVANCE(19);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym__newline);
      if (lookahead == '*') ADVANCE(19);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym__heading_prefix);
      if (lookahead == '\t' ||
          lookahead == ' ' ||
          lookahead == '|') ADVANCE(13);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(aux_sym__text_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(aux_sym__text_token2);
      if (lookahead == '*') ADVANCE(19);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(aux_sym__text_token2);
      if (lookahead == '*') ADVANCE(19);
      if (lookahead == '/') ADVANCE(21);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(aux_sym__text_token2);
      if (lookahead == '*') ADVANCE(19);
      if (lookahead == '=') ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == ' ' ||
          lookahead == '|') ADVANCE(13);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(aux_sym__text_token2);
      if (lookahead == '*') ADVANCE(19);
      if (lookahead != 0 &&
          (lookahead < '0' || '9' < lookahead) &&
          (lookahead < 'A' || 'Z' < lookahead) &&
          (lookahead < 'a' || 'z' < lookahead)) ADVANCE(20);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym__strong_delim_opn);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(aux_sym__strong_delim_cls_token1);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(21);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 7},
  [2] = {.lex_state = 7},
  [3] = {.lex_state = 7},
  [4] = {.lex_state = 3},
  [5] = {.lex_state = 3},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 3},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 4},
  [11] = {.lex_state = 7},
  [12] = {.lex_state = 7},
  [13] = {.lex_state = 4},
  [14] = {.lex_state = 7},
  [15] = {.lex_state = 4},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 3},
  [21] = {.lex_state = 3},
  [22] = {.lex_state = 3},
  [23] = {.lex_state = 3},
  [24] = {.lex_state = 2},
  [25] = {.lex_state = 0},
  [26] = {(TSStateId)(-1)},
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
    [sym_markup_block] = STATE(25),
    [sym_line] = STATE(11),
    [sym__emptyline] = STATE(11),
    [sym_heading] = STATE(24),
    [aux_sym__line_content] = STATE(6),
    [sym__text] = STATE(16),
    [sym_strong] = STATE(16),
    [sym_comment] = STATE(1),
    [aux_sym_markup_block_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym__newline] = ACTIONS(7),
    [sym__heading_prefix] = ACTIONS(9),
    [aux_sym__text_token1] = ACTIONS(11),
    [aux_sym__text_token2] = ACTIONS(13),
    [sym__strong_delim_opn] = ACTIONS(15),
    [sym_line_comment] = ACTIONS(3),
  },
  [2] = {
    [sym_line] = STATE(11),
    [sym__emptyline] = STATE(11),
    [sym_heading] = STATE(24),
    [aux_sym__line_content] = STATE(6),
    [sym__text] = STATE(16),
    [sym_strong] = STATE(16),
    [sym_comment] = STATE(2),
    [aux_sym_markup_block_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(17),
    [sym__newline] = ACTIONS(19),
    [sym__heading_prefix] = ACTIONS(22),
    [aux_sym__text_token1] = ACTIONS(25),
    [aux_sym__text_token2] = ACTIONS(28),
    [sym__strong_delim_opn] = ACTIONS(31),
    [sym_line_comment] = ACTIONS(3),
  },
  [3] = {
    [sym_line] = STATE(11),
    [sym__emptyline] = STATE(11),
    [sym_heading] = STATE(24),
    [aux_sym__line_content] = STATE(6),
    [sym__text] = STATE(16),
    [sym_strong] = STATE(16),
    [sym_comment] = STATE(3),
    [aux_sym_markup_block_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(34),
    [sym__newline] = ACTIONS(7),
    [sym__heading_prefix] = ACTIONS(9),
    [aux_sym__text_token1] = ACTIONS(11),
    [aux_sym__text_token2] = ACTIONS(13),
    [sym__strong_delim_opn] = ACTIONS(15),
    [sym_line_comment] = ACTIONS(3),
  },
  [4] = {
    [aux_sym__line_content] = STATE(7),
    [sym__text] = STATE(21),
    [sym_strong] = STATE(21),
    [sym__strong_delim_cls] = STATE(23),
    [sym_comment] = STATE(4),
    [aux_sym__text_token1] = ACTIONS(36),
    [aux_sym__text_token2] = ACTIONS(38),
    [sym__strong_delim_opn] = ACTIONS(40),
    [aux_sym__strong_delim_cls_token1] = ACTIONS(42),
    [sym_line_comment] = ACTIONS(3),
  },
  [5] = {
    [aux_sym__line_content] = STATE(7),
    [sym__text] = STATE(21),
    [sym_strong] = STATE(21),
    [sym__strong_delim_cls] = STATE(19),
    [sym_comment] = STATE(5),
    [aux_sym__text_token1] = ACTIONS(36),
    [aux_sym__text_token2] = ACTIONS(38),
    [sym__strong_delim_opn] = ACTIONS(40),
    [aux_sym__strong_delim_cls_token1] = ACTIONS(44),
    [sym_line_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(11), 1,
      aux_sym__text_token1,
    ACTIONS(13), 1,
      aux_sym__text_token2,
    ACTIONS(15), 1,
      sym__strong_delim_opn,
    ACTIONS(46), 1,
      sym__newline,
    STATE(6), 1,
      sym_comment,
    STATE(8), 1,
      aux_sym__line_content,
    STATE(16), 2,
      sym__text,
      sym_strong,
  [26] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(48), 1,
      aux_sym__text_token1,
    ACTIONS(51), 1,
      aux_sym__text_token2,
    ACTIONS(54), 1,
      sym__strong_delim_opn,
    ACTIONS(57), 1,
      aux_sym__strong_delim_cls_token1,
    STATE(7), 2,
      aux_sym__line_content,
      sym_comment,
    STATE(21), 2,
      sym__text,
      sym_strong,
  [50] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(57), 1,
      sym__newline,
    ACTIONS(59), 1,
      aux_sym__text_token1,
    ACTIONS(62), 1,
      aux_sym__text_token2,
    ACTIONS(65), 1,
      sym__strong_delim_opn,
    STATE(8), 2,
      aux_sym__line_content,
      sym_comment,
    STATE(16), 2,
      sym__text,
      sym_strong,
  [74] = 8,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(11), 1,
      aux_sym__text_token1,
    ACTIONS(13), 1,
      aux_sym__text_token2,
    ACTIONS(15), 1,
      sym__strong_delim_opn,
    ACTIONS(68), 1,
      sym__newline,
    STATE(8), 1,
      aux_sym__line_content,
    STATE(9), 1,
      sym_comment,
    STATE(16), 2,
      sym__text,
      sym_strong,
  [100] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(36), 1,
      aux_sym__text_token1,
    ACTIONS(38), 1,
      aux_sym__text_token2,
    ACTIONS(40), 1,
      sym__strong_delim_opn,
    STATE(5), 1,
      aux_sym__line_content,
    STATE(10), 1,
      sym_comment,
    STATE(21), 2,
      sym__text,
      sym_strong,
  [123] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(11), 1,
      sym_comment,
    ACTIONS(72), 2,
      sym__newline,
      aux_sym__text_token2,
    ACTIONS(70), 4,
      ts_builtin_sym_end,
      sym__heading_prefix,
      aux_sym__text_token1,
      sym__strong_delim_opn,
  [140] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(12), 1,
      sym_comment,
    ACTIONS(76), 2,
      sym__newline,
      aux_sym__text_token2,
    ACTIONS(74), 4,
      ts_builtin_sym_end,
      sym__heading_prefix,
      aux_sym__text_token1,
      sym__strong_delim_opn,
  [157] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(11), 1,
      aux_sym__text_token1,
    ACTIONS(13), 1,
      aux_sym__text_token2,
    ACTIONS(15), 1,
      sym__strong_delim_opn,
    STATE(9), 1,
      aux_sym__line_content,
    STATE(13), 1,
      sym_comment,
    STATE(16), 2,
      sym__text,
      sym_strong,
  [180] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(14), 1,
      sym_comment,
    ACTIONS(80), 2,
      sym__newline,
      aux_sym__text_token2,
    ACTIONS(78), 4,
      ts_builtin_sym_end,
      sym__heading_prefix,
      aux_sym__text_token1,
      sym__strong_delim_opn,
  [197] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(36), 1,
      aux_sym__text_token1,
    ACTIONS(38), 1,
      aux_sym__text_token2,
    ACTIONS(40), 1,
      sym__strong_delim_opn,
    STATE(4), 1,
      aux_sym__line_content,
    STATE(15), 1,
      sym_comment,
    STATE(21), 2,
      sym__text,
      sym_strong,
  [220] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(16), 1,
      sym_comment,
    ACTIONS(82), 2,
      sym__newline,
      aux_sym__text_token2,
    ACTIONS(84), 2,
      aux_sym__text_token1,
      sym__strong_delim_opn,
  [235] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(17), 1,
      sym_comment,
    ACTIONS(86), 2,
      sym__newline,
      aux_sym__text_token2,
    ACTIONS(88), 2,
      aux_sym__text_token1,
      sym__strong_delim_opn,
  [250] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(18), 1,
      sym_comment,
    ACTIONS(90), 2,
      sym__newline,
      aux_sym__text_token2,
    ACTIONS(92), 2,
      aux_sym__text_token1,
      sym__strong_delim_opn,
  [265] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(19), 1,
      sym_comment,
    ACTIONS(94), 2,
      sym__newline,
      aux_sym__text_token2,
    ACTIONS(96), 2,
      aux_sym__text_token1,
      sym__strong_delim_opn,
  [280] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(20), 1,
      sym_comment,
    ACTIONS(86), 2,
      aux_sym__text_token2,
      aux_sym__strong_delim_cls_token1,
    ACTIONS(88), 2,
      aux_sym__text_token1,
      sym__strong_delim_opn,
  [295] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(21), 1,
      sym_comment,
    ACTIONS(82), 2,
      aux_sym__text_token2,
      aux_sym__strong_delim_cls_token1,
    ACTIONS(84), 2,
      aux_sym__text_token1,
      sym__strong_delim_opn,
  [310] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(22), 1,
      sym_comment,
    ACTIONS(90), 2,
      aux_sym__text_token2,
      aux_sym__strong_delim_cls_token1,
    ACTIONS(92), 2,
      aux_sym__text_token1,
      sym__strong_delim_opn,
  [325] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(23), 1,
      sym_comment,
    ACTIONS(94), 2,
      aux_sym__text_token2,
      aux_sym__strong_delim_cls_token1,
    ACTIONS(96), 2,
      aux_sym__text_token1,
      sym__strong_delim_opn,
  [340] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(98), 1,
      sym__newline,
    STATE(24), 1,
      sym_comment,
  [350] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(100), 1,
      ts_builtin_sym_end,
    STATE(25), 1,
      sym_comment,
  [360] = 1,
    ACTIONS(102), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(6)] = 0,
  [SMALL_STATE(7)] = 26,
  [SMALL_STATE(8)] = 50,
  [SMALL_STATE(9)] = 74,
  [SMALL_STATE(10)] = 100,
  [SMALL_STATE(11)] = 123,
  [SMALL_STATE(12)] = 140,
  [SMALL_STATE(13)] = 157,
  [SMALL_STATE(14)] = 180,
  [SMALL_STATE(15)] = 197,
  [SMALL_STATE(16)] = 220,
  [SMALL_STATE(17)] = 235,
  [SMALL_STATE(18)] = 250,
  [SMALL_STATE(19)] = 265,
  [SMALL_STATE(20)] = 280,
  [SMALL_STATE(21)] = 295,
  [SMALL_STATE(22)] = 310,
  [SMALL_STATE(23)] = 325,
  [SMALL_STATE(24)] = 340,
  [SMALL_STATE(25)] = 350,
  [SMALL_STATE(26)] = 360,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_markup_block, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_markup_block_repeat1, 2),
  [19] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_markup_block_repeat1, 2), SHIFT_REPEAT(14),
  [22] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_markup_block_repeat1, 2), SHIFT_REPEAT(13),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_markup_block_repeat1, 2), SHIFT_REPEAT(17),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_markup_block_repeat1, 2), SHIFT_REPEAT(17),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_markup_block_repeat1, 2), SHIFT_REPEAT(10),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_markup_block, 1),
  [36] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [38] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [40] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [42] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [44] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [46] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__line_content, 2), SHIFT_REPEAT(20),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__line_content, 2), SHIFT_REPEAT(20),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__line_content, 2), SHIFT_REPEAT(15),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__line_content, 2),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__line_content, 2), SHIFT_REPEAT(17),
  [62] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__line_content, 2), SHIFT_REPEAT(17),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__line_content, 2), SHIFT_REPEAT(10),
  [68] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_heading, 2, .production_id = 1),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_markup_block_repeat1, 1),
  [72] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_markup_block_repeat1, 1),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_line, 2),
  [76] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_line, 2),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__emptyline, 1),
  [80] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__emptyline, 1),
  [82] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__line_content, 1),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__line_content, 1),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__text, 1),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__text, 1),
  [90] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__strong_delim_cls, 1),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__strong_delim_cls, 1),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_strong, 3),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_strong, 3),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [100] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1),
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
