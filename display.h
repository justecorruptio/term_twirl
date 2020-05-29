#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduboy2.h>
#include "jaylib.h"
#include "dawg.h"
#include "guess.h"

class Display {

    public:


    Display(Jaylib &arg_jay, Dawg &arg_dawg, Guess &arg_guess);

    int renderDawgResults(uint16_t *solved_mask);
    int renderChrome();
    int renderGuess();

    int renderTitle();
    int renderCursor();

    Jaylib &jay;
    Dawg &dawg;
    Guess &guess;

};

#endif
