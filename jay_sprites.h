#ifndef JAY_SPRITES_H
#define JAY_SPRITES_H

PROGMEM const uint8_t PRINTABLE_CHARS [] = {


    /* --- Symbols Pt.1 (16 glyphs) --- */

    // #32 Symbol ' ' (space). Used for in game messages.
    0x00,    // ░░░░░░░░
    0x00,    // ░░░░░░░░
    0x00,    // ░░░░░░░░

    // #33 Symbol '!' (exclamation mark). Used for in game messages.
    0x00,    // ░░░░░░░░
    0x17,    // ░░░▓░▓▓▓
    0x00,    // ░░░░░░░░

    // #34 Symbol '"' (double quotes).
    0x03,    // ░░░░░░▓▓
    0x00,    // ░░░░░░░░
    0x03,    // ░░░░░░▓▓

    // #35 Symbol '#' (hash or pound sign).
    0x1F,    // ░░░▓▓▓▓▓
    0x0A,    // ░░░░▓░▓░
    0x1F,    // ░░░▓▓▓▓▓

    // #36 Symbol '$' (dollar).
    0x16,    // ░░░▓░▓▓░
    0x1F,    // ░░░▓▓▓▓▓
    0x0A,    // ░░░░▓░▓░

    // #37 Symbol '%' (percentage sign).
    0x19,    // ░░░▓▓░░▓
    0x04,    // ░░░░░▓░░
    0x13,    // ░░░▓░░▓▓

    // #38 Symbol '&' (ampersand).
    0x0A,    // ░░░░▓░▓░
    0x15,    // ░░░▓░▓░▓
    0x12,    // ░░░▓░░▓░

    // #39 Symbol ''' (apostrophe). Used for in game messages.
    0x00,    // ░░░░░░░░
    0x03,    // ░░░░░░▓▓
    0x00,    // ░░░░░░░░

    // #40 Symbol '(' (left parenthesis).
    0x0E,    // ░░░░▓▓▓░
    0x1B,    // ░░░▓▓░▓▓
    0x11,    // ░░░▓░░░▓

    // #41 Symbol ')' (right parenthesis).
    0x11,    // ░░░▓░░░▓
    0x1B,    // ░░░▓▓░▓▓
    0x0E,    // ░░░░▓▓▓░

    // #42 Symbol '×' (multiply sign).
    0x0A,    // ░░░░▓░▓░
    0x04,    // ░░░░░▓░░
    0x0A,    // ░░░░▓░▓░

    // #43 Symbol '+' (plus sign).
    0x04,    // ░░░░░▓░░
    0x0E,    // ░░░░▓▓▓░
    0x04,    // ░░░░░▓░░

    // #44 Symbol ',' (comma).
    0x00,    // ░░░░░░░░
    0x18,    // ░░░▓▓░░░
    0x00,    // ░░░░░░░░

    // #45 Symbol '-' (hyphen).
    0x04,    // ░░░░░▓░░
    0x04,    // ░░░░░▓░░
    0x04,    // ░░░░░▓░░

    // #46 Symbol '.' (period).
    0x00,    // ░░░░░░░░
    0x10,    // ░░░▓░░░░
    0x00,    // ░░░░░░░░

    // #47 Symbol '/' (forward slash).
    0x18,    // ░░░▓▓░░░
    0x04,    // ░░░░░▓░░
    0x03,    // ░░░░░░▓▓


    /* --- Numbers (10 glyphs) --- */

    // #48 Number '0' (zero).
    0x1F,    // ░░░▓▓▓▓▓
    0x11,    // ░░░▓░░░▓
    0x1F,    // ░░░▓▓▓▓▓

    // #49 Number '1' (one).
    0x12,    // ░░░▓░░▓░
    0x1F,    // ░░░▓▓▓▓▓
    0x10,    // ░░░▓░░░░

    // #50 Number '2' (two).
    0x19,    // ░░░▓▓░░▓
    0x15,    // ░░░▓░▓░▓
    0x12,    // ░░░▓░░▓░

    // #51 Number '3' (three).
    0x15,    // ░░░▓░▓░▓
    0x15,    // ░░░▓░▓░▓
    0x0A,    // ░░░░▓░▓░

    // #52 Number '4' (four).
    0x03,    // ░░░░░░▓▓
    0x04,    // ░░░░░▓░░
    0x1F,    // ░░░▓▓▓▓▓

    // #53 Number '5' (five).
    0x17,    // ░░░▓░▓▓▓
    0x15,    // ░░░▓░▓░▓
    0x0D,    // ░░░░▓▓░▓

    // #54 Number '6' (six).
    0x1E,    // ░░░▓▓▓▓░
    0x15,    // ░░░▓░▓░▓
    0x1D,    // ░░░▓▓▓░▓

    // #55 Number '7' (seven).
    0x01,    // ░░░░░░░▓
    0x19,    // ░░░▓▓░░▓
    0x07,    // ░░░░░▓▓▓

    // #56 Number '8' (eight).
    0x1F,    // ░░░▓▓▓▓▓
    0x15,    // ░░░▓░▓░▓
    0x1F,    // ░░░▓▓▓▓▓

    // #57 Number '9' (nine).
    0x07,    // ░░░░░▓▓▓
    0x15,    // ░░░▓░▓░▓
    0x0F,    // ░░░░▓▓▓▓


    /* --- Symbols Pt.2 (7 glyphs) --- */

    // #58 Symbol ':' (colon). Used for score board and time.
    0x00,    // ░░░░░░░░
    0x0A,    // ░░░░▓░▓░
    0x00,    // ░░░░░░░░

    // #59 Symbol ';' (semi-colon).
    0x00,    // ░░░░░░░░
    0x1A,    // ░░░▓▓░▓░
    0x00,    // ░░░░░░░░

    // #60 Symbol '<' (left angle bracket).
    0x04,    // ░░░░░▓░░
    0x0A,    // ░░░░▓░▓░
    0x11,    // ░░░▓░░░▓

    // #61 Symbol '=' (equals sign).
    0x0A,    // ░░░░▓░▓░
    0x0A,    // ░░░░▓░▓░
    0x0A,    // ░░░░▓░▓░

    // #62 Symbol '>' (right angle bracket). Used for level select arrow.
    0x11,    // ░░░▓░░░▓
    0x0A,    // ░░░░▓░▓░
    0x04,    // ░░░░░▓░░

    // #63 Symbol '?' (question mark). Used in game to conceal letters of hidden words.
    0x01,    // ░░░░░░░▓
    0x15,    // ░░░▓░▓░▓
    0x02,    // ░░░░░░▓░

    // #64 Symbol '■' (full black square in place of an '@' at-sign).
    0x1F,    // ░░░▓▓▓▓▓
    0x1F,    // ░░░▓▓▓▓▓
    0x1F,    // ░░░▓▓▓▓▓


    /* --- Letters (26 glyphs) --- */

    // #65 Letter 'A'.
    0x1E,    // ░░░▓▓▓▓░
    0x05,    // ░░░░░▓░▓
    0x1E,    // ░░░▓▓▓▓░

    // #66 Letter 'B'.
    0x1F,    // ░░░▓▓▓▓▓
    0x15,    // ░░░▓░▓░▓
    0x1A,    // ░░░▓▓░▓░

    // #67 Letter 'C'.
    0x0E,    // ░░░░▓▓▓░
    0x11,    // ░░░▓░░░▓
    0x11,    // ░░░▓░░░▓

    // #68 Letter 'D'.
    0x1F,    // ░░░▓▓▓▓▓
    0x11,    // ░░░▓░░░▓
    0x0E,    // ░░░░▓▓▓░

    // #69 Letter 'E'.
    0x1F,    // ░░░▓▓▓▓▓
    0x15,    // ░░░▓░▓░▓
    0x11,    // ░░░▓░░░▓

    // #70 Letter 'F'.
    0x1F,    // ░░░▓▓▓▓▓
    0x05,    // ░░░░░▓░▓
    0x01,    // ░░░░░░░▓

    // #71 Letter 'G'.
    0x0E,    // ░░░░▓▓▓░
    0x11,    // ░░░▓░░░▓
    0x1D,    // ░░░▓▓▓░▓

    // #72 Letter 'H'.
    0x1F,    // ░░░▓▓▓▓▓
    0x04,    // ░░░░░▓░░
    0x1F,    // ░░░▓▓▓▓▓

    // #73 Letter 'I'.
    0x11,    // ░░░▓░░░▓
    0x1F,    // ░░░▓▓▓▓▓
    0x11,    // ░░░▓░░░▓

    // #74 Letter 'J'.
    0x09,    // ░░░░▓░░▓
    0x11,    // ░░░▓░░░▓
    0x1F,    // ░░░▓▓▓▓▓

    // #75 Letter 'K'.
    0x1F,    // ░░░▓▓▓▓▓
    0x04,    // ░░░░░▓░░
    0x1B,    // ░░░▓▓░▓▓

    // #76 Letter 'L'.
    0x1F,    // ░░░▓▓▓▓▓
    0x10,    // ░░░▓░░░░
    0x10,    // ░░░▓░░░░

    // #77 Letter 'M'.
    0x1F,    // ░░░▓▓▓▓▓
    0x03,    // ░░░░░░▓▓
    0x1F,    // ░░░▓▓▓▓▓

    // #78 Letter 'N'.
    0x1F,    // ░░░▓▓▓▓▓
    0x01,    // ░░░░░░░▓
    0x1E,    // ░░░▓▓▓▓░

    // #79 Letter 'O'.
    0x0E,    // ░░░░▓▓▓░
    0x11,    // ░░░▓░░░▓
    0x0E,    // ░░░░▓▓▓░

    // #80 Letter 'P'.
    0x1F,    // ░░░▓▓▓▓▓
    0x05,    // ░░░░░▓░▓
    0x02,    // ░░░░░░▓░

    // #81 Letter 'Q'.
    0x0E,    // ░░░░▓▓▓░
    0x19,    // ░░░▓▓░░▓
    0x16,    // ░░░▓░▓▓░

    // #82 Letter 'R'.
    0x1F,    // ░░░▓▓▓▓▓
    0x05,    // ░░░░░▓░▓
    0x1A,    // ░░░▓▓░▓░

    // #83 Letter 'S'.
    0x16,    // ░░░▓░▓▓░
    0x15,    // ░░░▓░▓░▓
    0x0D,    // ░░░░▓▓░▓

    // #84 Letter 'T'.
    0x01,    // ░░░░░░░▓
    0x1F,    // ░░░▓▓▓▓▓
    0x01,    // ░░░░░░░▓

    // #85 Letter 'U'.
    0x0F,    // ░░░░▓▓▓▓
    0x10,    // ░░░▓░░░░
    0x1F,    // ░░░▓▓▓▓▓

    // #86 Letter 'V'.
    0x0F,    // ░░░░▓▓▓▓
    0x10,    // ░░░▓░░░░
    0x0F,    // ░░░░▓▓▓▓

    // #87 Letter 'W'.
    0x1F,    // ░░░▓▓▓▓▓
    0x18,    // ░░░▓▓░░░
    0x1F,    // ░░░▓▓▓▓▓

    // #88 Letter 'X'.
    0x1B,    // ░░░▓▓░▓▓
    0x04,    // ░░░░░▓░░
    0x1B,    // ░░░▓▓░▓▓

    // #89 Letter 'Y'.
    0x03,    // ░░░░░░▓▓
    0x1C,    // ░░░▓▓▓░░
    0x03,    // ░░░░░░▓▓

    // #90 Letter 'Z'.
    0x19,    // ░░░▓▓░░▓
    0x15,    // ░░░▓░▓░▓
    0x13     // ░░░▓░░▓▓

};


PROGMEM const uint8_t PRINTABLE_CHARS_LARGE [] = {
    
    // #32 Symbol ' ' (space).
    0x00,    // ░░░░░░░░
    0x00,    // ░░░░░░░░
    0x00,    // ░░░░░░░░
    0x00,    // ░░░░░░░░
    0x00,    // ░░░░░░░░
    
    // #65 Letter 'A'.
    0x7E,    // ░▓▓▓▓▓▓░
    0x09,    // ░░░░▓░░▓
    0x09,    // ░░░░▓░░▓
    0x09,    // ░░░░▓░░▓
    0x7E,    // ░▓▓▓▓▓▓░

    // #66 Letter 'B'.
    0x7F,    // ░▓▓▓▓▓▓▓
    0x49,    // ░▓░░▓░░▓
    0x49,    // ░▓░░▓░░▓
    0x49,    // ░▓░░▓░░▓
    0x36,    // ░░▓▓░▓▓░

    // #67 Letter 'C'.
    0x3E,    // ░░▓▓▓▓▓░
    0x41,    // ░▓░░░░░▓
    0x41,    // ░▓░░░░░▓
    0x41,    // ░▓░░░░░▓
    0x22,    // ░░▓░░░▓░

    // #68 Letter 'D'.
    0x7F,    // ░▓▓▓▓▓▓▓
    0x41,    // ░▓░░░░░▓
    0x41,    // ░▓░░░░░▓
    0x22,    // ░░▓░░░▓░
    0x1C,    // ░░░▓▓▓░░

    // #69 Letter 'E'.
    0x7F,    // ░▓▓▓▓▓▓▓
    0x49,    // ░▓░░▓░░▓
    0x49,    // ░▓░░▓░░▓
    0x49,    // ░▓░░▓░░▓
    0x41,    // ░▓░░░░░▓

    // #70 Letter 'F'.
    0x7F,    // ░▓▓▓▓▓▓▓
    0x09,    // ░░░░▓░░▓
    0x09,    // ░░░░▓░░▓
    0x09,    // ░░░░▓░░▓
    0x01,    // ░░░░░░░▓

    // #71 Letter 'G'.
    0x3E,    // ░░▓▓▓▓▓░
    0x41,    // ░▓░░░░░▓
    0x41,    // ░▓░░░░░▓
    0x49,    // ░▓░░▓░░▓
    0x3A,    // ░░▓▓▓░▓░

    // #72 Letter 'H'.
    0x7F,    // ░▓▓▓▓▓▓▓
    0x08,    // ░░░░▓░░░
    0x08,    // ░░░░▓░░░
    0x08,    // ░░░░▓░░░
    0x7F,    // ░▓▓▓▓▓▓▓

    // #73 Letter 'I'.
    0x00,    // ░░░░░░░░
    0x41,    // ░▓░░░░░▓
    0x7F,    // ░▓▓▓▓▓▓▓
    0x41,    // ░▓░░░░░▓
    0x00,    // ░░░░░░░░

    // #74 Letter 'J'.
    0x30,    // ░░▓▓░░░░
    0x40,    // ░▓░░░░░░
    0x41,    // ░▓░░░░░▓
    0x41,    // ░▓░░░░░▓
    0x3F,    // ░░▓▓▓▓▓▓

    // #75 Letter 'K'.
    0x7F,    // ░▓▓▓▓▓▓▓
    0x08,    // ░░░░▓░░░
    0x04,    // ░░░░░▓░░
    0x1A,    // ░░░▓▓░▓░
    0x61,    // ░▓▓░░░░▓

    // #76 Letter 'L'.
    0x7F,    // ░▓▓▓▓▓▓▓
    0x40,    // ░▓░░░░░░
    0x40,    // ░▓░░░░░░
    0x40,    // ░▓░░░░░░
    0x40,    // ░▓░░░░░░

    // #77 Letter 'M'.
    0x7F,    // ░▓▓▓▓▓▓▓
    0x02,    // ░░░░░░▓░
    0x0C,    // ░░░░▓▓░░
    0x02,    // ░░░░░░▓░
    0x7F,    // ░▓▓▓▓▓▓▓

    // #78 Letter 'N'.
    0x7F,    // ░▓▓▓▓▓▓▓
    0x02,    // ░░░░░░▓░
    0x04,    // ░░░░░▓░░
    0x08,    // ░░░░▓░░░
    0x7F,    // ░▓▓▓▓▓▓▓

    // #79 Letter 'O'.
    0x3E,    // ░░▓▓▓▓▓░
    0x41,    // ░▓░░░░░▓
    0x41,    // ░▓░░░░░▓
    0x41,    // ░▓░░░░░▓
    0x3E,    // ░░▓▓▓▓▓░

    // #80 Letter 'P'.
    0x7F,    // ░▓▓▓▓▓▓▓
    0x09,    // ░░░░▓░░▓
    0x09,    // ░░░░▓░░▓
    0x09,    // ░░░░▓░░▓
    0x06,    // ░░░░░▓▓░

    // #81 Letter 'Q'.
    0x3E,    // ░░▓▓▓▓▓░
    0x41,    // ░▓░░░░░▓
    0x51,    // ░▓░▓░░░▓
    0x21,    // ░░▓░░░░▓
    0x5E,    // ░▓░▓▓▓▓░

    // #82 Letter 'R'.
    0x7F,    // ░▓▓▓▓▓▓▓
    0x09,    // ░░░░▓░░▓
    0x19,    // ░░░▓▓░░▓
    0x29,    // ░░▓░▓░░▓
    0x46,    // ░▓░░░▓▓░

    // #83 Letter 'S'.
    0x26,    // ░░▓░░▓▓░
    0x49,    // ░▓░░▓░░▓
    0x49,    // ░▓░░▓░░▓
    0x49,    // ░▓░░▓░░▓
    0x32,    // ░░▓▓░░▓░

    // #84 Letter 'T'.
    0x01,    // ░░░░░░░▓
    0x01,    // ░░░░░░░▓
    0x7F,    // ░▓▓▓▓▓▓▓
    0x01,    // ░░░░░░░▓
    0x01,    // ░░░░░░░▓

    // #85 Letter 'U'.
    0x3F,    // ░░▓▓▓▓▓▓
    0x40,    // ░▓░░░░░░
    0x40,    // ░▓░░░░░░
    0x40,    // ░▓░░░░░░
    0x3F,    // ░░▓▓▓▓▓▓

    // #86 Letter 'V'.
    0x0F,    // ░░░░▓▓▓▓
    0x30,    // ░░▓▓░░░░
    0x40,    // ░▓░░░░░░
    0x30,    // ░░▓▓░░░░
    0x0F,    // ░░░░▓▓▓▓

    // #87 Letter 'W'.
    0x3F,    // ░░▓▓▓▓▓▓
    0x40,    // ░▓░░░░░░
    0x38,    // ░░▓▓▓░░░
    0x40,    // ░▓░░░░░░
    0x3F,    // ░░▓▓▓▓▓▓

    // #88 Letter 'X'.
    0x63,    // ░▓▓░░░▓▓
    0x14,    // ░░░▓░▓░░
    0x08,    // ░░░░▓░░░
    0x14,    // ░░░▓░▓░░
    0x63,    // ░▓▓░░░▓▓

    // #89 Letter 'Y'.
    0x03,    // ░░░░░░▓▓
    0x04,    // ░░░░░▓░░
    0x78,    // ░▓▓▓▓░░░
    0x04,    // ░░░░░▓░░
    0x03,    // ░░░░░░▓▓

    // #90 Letter 'Z'.
    0x61,    // ░▓▓░░░░▓
    0x51,    // ░▓░▓░░░▓
    0x49,    // ░▓░░▓░░▓
    0x45,    // ░▓░░░▓░▓
    0x43     // ░▓░░░░▓▓
    
};

#endif
