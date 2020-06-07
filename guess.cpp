#include "guess.h"

int Guess::reset(char * input_letters) {
    strcpy(letters, input_letters);

    guess_ptr = 0;
    guess[0] = '\0';
    guess_word[0] = '\0';

    handleReturnShuffle();
}

int Guess::cursorMove(uint8_t step) {
    cursor_pos +=step;
    cursor_pos %= 6;
}

int Guess::handleSelect() {
    if(letters[cursor_pos] == ' ')
        return;

    guess_word[guess_ptr] = letters[cursor_pos];
    letters[cursor_pos] = ' ';
    guess[guess_ptr] = cursor_pos;

    guess_word[++ guess_ptr] = '\0';
}

int Guess::handleDelete() {
    if (guess_ptr <= 0)
        return;

    guess_ptr --;
    letters[guess[guess_ptr]] = guess_word[guess_ptr];
    guess_word[guess_ptr] = '\0';
}

int Guess::handleReturnShuffle() {
    uint8_t i, a, b;
    char t;
    if(guess_ptr) {
        while(guess_ptr) {
            handleDelete();
        }
    } else {
        a = 0;
        for(i = 0; i < 16; i++) {
            b = random(0, 6);
            t = letters[a];
            letters[a] = letters[b];
            letters[b] = t;
            a = b;
        }
    }
}
