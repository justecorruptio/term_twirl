#ifndef GUESS_H
#define GUESS_H

#include <Arduboy2.h>

class Guess {
    public:

    char letters[8];
    char guess[8];
    char guess_word[8] = "";
    int guess_ptr = 0;

    int cursor_pos = 0;

    int reset(char * input_letters);

    int cursorLeft();
    int cursorRight();

    int handleSelect();
    int handleDelete();

    int handleReturnShuffle();

};

#endif
