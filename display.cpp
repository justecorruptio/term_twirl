#include "display.h"

Display::Display(Jaylib &arg_jay, Dawg &arg_dawg, Guess &arg_guess):
jay(arg_jay), dawg(arg_dawg), guess(arg_guess){
}

int Display::renderDawgResults(uint16_t *solved_mask) {
    int i, len;
    int num = dawg.results_ptr;
    int col_len, cur_x = 1;
    char q[8] = "???????";
    for(i = 0; i < dawg.results_ptr; i++) {
        len = strlen(dawg.results[i]);
        jay.setCursor(cur_x, 1 + 6 * (i % 10));
        if ((i < 16) ? (solved_mask[0] & (1 << i)) : (solved_mask[1] & ((1 << (i - 16))))) {
            jay.smallPrint(dawg.results[i]);
        } else {
            q[len] = '\0';
            jay.smallPrint(q);
            q[len] = '?';
        }
        if ((i % 10 == 9) && (i < dawg.results_ptr - 1)) {
            cur_x += 4 * len + 5;
        }
    }
}

int Display::renderChrome() {
    jay.drawFastVLine(76, 0, 36, 1);
    jay.drawFastHLine(76, 36, 52, 1);

    jay.drawFastVLine(76, 50, 14, 1);
    jay.drawFastHLine(76, 50, 52, 1);
}

int Display::renderTitle() {
    jay.setCursor(33, 20);
    jay.largePrint("TERM TWIRL");
    jay.drawFastHLine(33, 28, 59, 1);
    jay.drawFastHLine(37, 30, 51, 1);
}

int Display::renderGuess() {
    int i;
    char buf[8] = "\0\0\0\0\0\0\0\0";
    for(i = 0; guess.letters[i]; i++) {
        if(guess.guess_mask & (1 << i)){
            buf[i] = ' ';
        } else {
            buf[i] = guess.letters[i];
        }
    }
    jay.setCursor(80, 54);
    jay.largePrint(buf, 3);

    jay.setCursor(80, 40);
    jay.largePrint(guess.getWord(buf), 3);
}

int Display::renderCursor() {
    int i;
    guess.cursor_counter ++;

    for(i = 0; i < 9; i++){
        jay.drawPixel(78 + 8 * guess.cursor_pos + i, 52,
            (i - guess.cursor_counter / 4) % 4 == 0);
        jay.drawPixel(78 + 8 * guess.cursor_pos + i, 62,
            (i + guess.cursor_counter / 4 + 2) % 4 == 0);
    }

    for(i = 0; i < 11; i++){
        jay.drawPixel(78 + 8 * guess.cursor_pos, 52 + i,
            (i + guess.cursor_counter / 4) % 4 == 0);
        jay.drawPixel(86 + 8 * guess.cursor_pos, 52 + i,
            (i - guess.cursor_counter / 4) % 4 == 0);
    }

}
