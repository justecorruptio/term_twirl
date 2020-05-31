#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduboy2.h>
#include "jaylib.h"
#include "utils.h"
#include "dawg.h"
#include "guess.h"

class Display {
    public:
    Display(Jaylib &arg_jay, Dawg &arg_dawg, Guess &arg_guess);

    int renderDawgResults(uint16_t *solved_mask);
    int renderChrome(uint32_t cur_score, uint32_t high_score);
    int renderTime(uint32_t time_left);
    int renderGuess();

    int renderTitle();
    int renderCursor();

    int renderNext();
    int renderGameOver();

    Jaylib &jay;
    Dawg &dawg;
    Guess &guess;

    int setMessage(char* msg);
    int renderMessage();
    char * message_ptr;
    uint32_t messageTTL;
};

#endif
