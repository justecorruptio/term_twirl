#ifndef GAME_H
#define GAME_H

#include <Arduboy2.h>

#define STAGE_TITLE 1
#define STAGE_LOAD 2
#define STAGE_PLAY 3
#define STAGE_NEXT 4
#define STAGE_GAME_OVER 5

#define EEPROM_MAGIC 0x90C5

class Game {
    public:

    int reset();
    int checkSolved(int index, char setIfUnset);

    uint8_t stage = STAGE_TITLE;
    uint16_t solved_mask[2] = {0, 0};
    char num_solved = 0;
    char target_solved = 0;
    uint16_t time_left;

    void highScore();

    uint16_t score = 0;
    uint16_t high_score = 0;

};

#endif
