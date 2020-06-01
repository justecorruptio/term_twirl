#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduboy2.h>
#include "jaylib.h"
#include "utils.h"
#include "dawg.h"
#include "guess.h"
#include "game.h"

class Display {
    public:
    Display(Jaylib &arg_jay, Dawg &arg_dawg, Guess &arg_guess, Game &arg_game);

    int render();

    int renderDawgResults();
    int renderChrome();
    int renderTime();
    int renderGuess();

    int renderTitle();
    int renderCursor();

    Jaylib &jay;
    Dawg &dawg;
    Guess &guess;
    Game &game;

    int setMessage(char* msg, uint16_t arg_messageTTL = 50);
    int renderMessage();
    char * message_ptr;
    uint16_t messageTTL;

    uint16_t cursor_counter = 0;
};

#endif
