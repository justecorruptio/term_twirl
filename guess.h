#ifndef GUESS_H
#define GUESS_H

#include <Arduboy2.h>

class Guess {
    public:

    char letters[8];
    char guess[8];
    char guess_word[8] = "";
    uint8_t guess_ptr = 0;

    uint8_t cursor_pos = 0;

    int reset(char * input_letters);

    int cursorMove(uint8_t step);

    int handleSelect();
    int handleDelete();

    int handleReturnShuffle();
};

#endif
