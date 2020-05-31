#ifndef GAME_H
#define GAME_H

#include <Arduboy2.h>

#define STAGE_TITLE 1
#define STAGE_LOAD 2
#define STAGE_PLAY 3
#define STAGE_NEXT 4
#define STAGE_GAME_OVER 5

class Game {
    public:

    int reset();
    int checkSolved(int index, char setIfUnset);

    int stage = STAGE_TITLE;
    uint16_t solved_mask[2] = {0, 0};
    uint32_t num_solved = 0;
    char target_solved = 0;
    uint32_t time_left;

    void loadHighScore();
    void setHighScore();

    uint32_t score = 0;
    uint32_t high_score = 0;

};

#endif
