#include "guess.h"

int Guess::reset(char * input_letters) {
    strcpy(letters, input_letters);

    guess_mask = 0x0;
    guess_ptr = 0;
    guess[0] = '\0';
    cursor_counter = 0;

    handleReturnShuffle();
}

char* Guess::getWord(char* buf) {
    int i;
    for(i = 0; i < guess_ptr; i++)
        buf[i] = letters[guess[i]];
    buf[i] = '\0';
    return buf;
}

int Guess::cursorLeft() {
    cursor_pos --;
    if (cursor_pos < 0) cursor_pos = 5;
}
int Guess::cursorRight() {
    cursor_pos ++;
    if (cursor_pos >= 6) cursor_pos = 0;
}

int Guess::handleSelect() {
    if(guess_mask & (1 << cursor_pos) || guess_ptr >= 6)
        return;

    guess[guess_ptr ++] = cursor_pos;
    guess_mask |= (1 << cursor_pos);
}

int Guess::handleDelete() {
    if (guess_ptr <= 0)
        return;

    guess_mask &= ~(1 << guess[-- guess_ptr]);
}

int Guess::handleReturnShuffle() {
    int i, a, b;
    char t;
    if(guess_ptr > 0) {
        while(guess_ptr) {
            handleDelete();
        }
    } else {
        for(i = 0; i < 11; i++) {
            a = random(0, 6);
            b = random(0, 6);
            t = letters[a];
            letters[a] = letters[b];
            letters[b] = t;
        }
    }
}
