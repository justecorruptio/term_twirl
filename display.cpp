#include "display.h"

Display::Display(Jaylib &arg_jay, Dawg &arg_dawg, Guess &arg_guess, Game &arg_game)
:jay(arg_jay), dawg(arg_dawg), guess(arg_guess), game(arg_game) {}

int Display::render() {
    cursor_counter ++;
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
        renderScore();
        renderTime();
        renderMessage();
        break;
    }
}

int Display::renderDawgResults() {
    uint8_t i, len, cur_x = 1, cur_y;
    for(i = 0; i < dawg.results_ptr; i++) {
        len = strlen(dawg.results[i]);
        cur_y = 2 + 6 * (i % 10);
        if(game.checkSolved(i, 0))
            jay.smallPrint(cur_x, cur_y, dawg.results[i]);
        else
            jay.smallPrint(cur_x, cur_y, "??????" + 6 - len);
        if (i % 10 == 9)
            cur_x += 4 * len + 5;
    }
}

int Display::renderChrome() {
    jay.drawFastVLine(76, 0, 36);
    jay.drawFastHLine(76, 13, 52);
    jay.drawFastHLine(76, 36, 52);

    jay.drawFastVLine(76, 50, 14);
    jay.drawFastHLine(76, 50, 52);
}

int Display::renderScore() {
    jay.smallPrint(78, 1, "SCORE:");
    jay.smallPrint(82, 7, "HIGH:");

    jay.smallPrint(102, 1, itoa(game.score));
    jay.smallPrint(102, 7, itoa(game.high_score));
}

int Display::renderTime() {
    jay.smallPrint(82, 15, "TIME:");
    jay.smallPrint(102, 15, itoa(game.time_left / 10));
}

int Display::renderTitle() {
    jay.largePrint(33, 20, "TERM TWIRL");
    jay.drawFastHLine(33, 28, 59);
    jay.drawFastHLine(37, 30, 51);

    jay.smallPrint(46, 34, "EASY MODE");
    jay.smallPrint(46, 40, "HARD MODE");

    jay.smallPrint(
        38 + (cursor_counter / 4) % 4,
        40 - 6 * dawg.easy_mode, ">"
    );
}

int Display::renderGuess() {
    jay.largePrint(80, 54, guess.letters, 3);
    jay.largePrint(80, 40, guess.guess_word, 3);
}

int Display::renderCursor() {
    uint8_t i, j, a, b, x, y;

    x = 78 + 8 * guess.cursor_pos;
    y = 52;

    for(i = (cursor_counter / 4) % 4; i < 36; i += 4){
        j = i % 9;
        switch(i / 9){
            case 0: a = x + j; b = y; break;
            case 1: a = x + 8; b = y + j + 1; break;
            case 2: a = x + 8 - j; b = y + 10; break;
            case 3: a = x; b = y + 9 - j; break;
        }
        jay.drawPixel(a, b);
    }
}

int Display::setMessage(char* msg, uint16_t arg_messageTTL) {
    messageTTL = arg_messageTTL;
    message_ptr = msg;
}

int Display::renderMessage() {
    if (messageTTL == 0)
        return;
    messageTTL --;

    jay.smallPrint(78, 30, message_ptr);
}
