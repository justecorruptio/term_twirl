#include "game.h"

int Game::reset() {
    solved_mask[0] = 0;
    solved_mask[1] = 0;
    num_solved = 0;
    target_solved = 0;
    time_left = 9999;
}

int Game::checkSolved(int index, char setIfUnset) {
    int solved_ptr = 0;
    uint16_t mask;

    if (index >= 16) {
        solved_ptr = 1;
        index -= 16;
    }

    mask = 1 << index;
    if (!(solved_mask[solved_ptr] & mask)) {
        if (setIfUnset)
            solved_mask[solved_ptr] |= mask;
        return 0;
    }
    return 1;
}

void Game::highScore() {
    struct{
        uint16_t magic;
        uint16_t hs;
    } v;

    EEPROM.get(256, v);
    if(v.magic != EEPROM_MAGIC) {
        v.magic = EEPROM_MAGIC;
        v.hs = 0;
    }
    if (score > v.hs)
        v.hs = score;
    EEPROM.put(256, v);

    high_score = v.hs;
}
