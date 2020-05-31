#include "display.h"

Display::Display(Jaylib &arg_jay, Dawg &arg_dawg, Guess &arg_guess, Game &arg_game)
:jay(arg_jay), dawg(arg_dawg), guess(arg_guess), game(arg_game) {}

int Display::render() {
    switch(game.stage) {
        case STAGE_TITLE:
        renderTitle();
        break;

        case STAGE_PLAY:
        renderGuess();
        renderCursor();

        case STAGE_NEXT:
        case STAGE_GAME_OVER:
        if(game.stage == STAGE_GAME_OVER)
            setMessage("GAME OVER", 1);
        else if(game.stage == STAGE_NEXT)
            setMessage("NEXT ROUND!", 1);
        renderChrome();
        renderDawgResults();
        renderTime();
        renderMessage();
        break;
    }
}

int Display::renderDawgResults() {
    int i, len;
    int num = dawg.results_ptr;
    int col_len, cur_x = 1;
    char q[8] = "???????";
    for(i = 0; i < dawg.results_ptr; i++) {
        len = strlen(dawg.results[i]);
        if(game.checkSolved(i, 0)) {
            jay.smallPrint(cur_x, 1 + 6 * (i % 10), dawg.results[i]);
        } else {
            q[len] = '\0';
            jay.smallPrint(cur_x, 1 + 6 * (i % 10), q);
            q[len] = '?';
        }
        if ((i % 10 == 9) && (i < dawg.results_ptr - 1)) {
            cur_x += 4 * len + 5;
        }
    }
}

int Display::renderChrome() {
    char buf[8];
    jay.drawFastVLine(76, 0, 36, 1);
    jay.drawFastHLine(76, 13, 52, 1);
    jay.drawFastHLine(76, 36, 52, 1);

    jay.drawFastVLine(76, 50, 14, 1);
    jay.drawFastHLine(76, 50, 52, 1);

    jay.smallPrint(78, 1, "SCORE:");
    jay.smallPrint(102, 1, itoa(buf, game.score));

    jay.smallPrint(78, 7, " HIGH:");
    jay.smallPrint(102, 7, itoa(buf, game.high_score));
}

int Display::renderTime() {
    char buf[8];
    jay.smallPrint(78, 15, " TIME:");
    jay.smallPrint(102, 15, itoa(buf, game.time_left / 10));
}

int Display::renderTitle() {
    jay.largePrint(33, 20, "TERM TWIRL");
    jay.drawFastHLine(33, 28, 59, 1);
    jay.drawFastHLine(37, 30, 51, 1);
}

int Display::renderGuess() {
    int i;
    char buf[8] = "\0\0\0\0\0\0\0\0";

    for(i = 0; guess.letters[i]; i++)
        buf[i] = guess.guess_mask & (1 << i) ?  ' ' : guess.letters[i];

    // Order matters here as getWord mutates buf
    jay.largePrint(80, 54, buf, 3);
    jay.largePrint(80, 40, guess.getWord(buf), 3);
}

int Display::renderCursor() {
    int i, t;
    guess.cursor_counter ++;

    for(i = 0; i < 9; i++){
        t = 78 + 8 * guess.cursor_pos + i;
        jay.drawPixel(t, 52,
            (i - guess.cursor_counter / 4) % 4 == 0);
        jay.drawPixel(t, 62,
            (i + guess.cursor_counter / 4 + 2) % 4 == 0);
    }

    for(i = 0; i < 11; i++){
        jay.drawPixel(78 + 8 * guess.cursor_pos, 52 + i,
            (i + guess.cursor_counter / 4) % 4 == 0);
        jay.drawPixel(86 + 8 * guess.cursor_pos, 52 + i,
            (i - guess.cursor_counter / 4) % 4 == 0);
    }

}

int Display::setMessage(char* msg, uint16_t arg_messageTTL) {
    messageTTL = arg_messageTTL;
    message_ptr = msg;
}

int Display::renderMessage() {
    if (! message_ptr || (messageTTL == 0))
        return;
    messageTTL --;

    jay.smallPrint(78, 30, message_ptr);
}
