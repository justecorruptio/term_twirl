#ifndef GUESS_H
#define GUESS_H

#include <Arduboy2.h>

class Guess {
    public:

    char letters[8];
    char guess[8];
    int guess_ptr = 0;
    uint8_t guess_mask;

    int cursor_pos = 0;
    int cursor_counter = 0;

    int reset(char * input_letters);
    int sortLetters();
    char* getWord(char* buf);

    int cursorLeft();
    int cursorRight();

    int handleSelect();
    int handleDelete();

    int handleReturnShuffle();

};

#endif
