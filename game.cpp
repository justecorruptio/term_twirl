#include "game.h"

int Game::reset() {
    solved_mask[0] = 0;
    solved_mask[1] = 0;
    num_solved = 0;
    target_solved = 0;
    time_left = 9999;
}

int Game::checkSolved(int index, char setIfUnset) {
    uint8_t solved_ptr;
    uint16_t mask;

    solved_ptr = index / 16;
    mask = 1 << (index % 16);

    if (solved_mask[solved_ptr] & mask)
        return 1;

    if (setIfUnset)
        solved_mask[solved_ptr] |= mask;

    return 0;
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
