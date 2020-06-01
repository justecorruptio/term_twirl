#include "jaylib.h"
#include "dawg.h"
#include "utils.h"
#include "guess.h"

#include "game.h"
#include "display.h"

Jaylib jay;
Dawg dawg;
Guess guess;
Game game;
Display display = Display(jay, dawg, guess, game);

const char* MESSAGES [] = {
    "NOT A WORD!", "TOO SHORT", "",
    "NICE!", "GREAT!", "AWESOME!", "BRILLIANT!",
    "IT'S THERE."
};

void load() {
    uint32_t word_hash;

    jay.initRandomSeed();
    dawg.process(OP_MODE_SELECT, 0);
    word_hash = lex_hash(dawg.results[0]);

    guess.reset(dawg.results[0]);

    dawg.process(OP_MODE_LOAD, word_hash);
    dawg.sort_results();

    game.reset();
}

void setup() {
    jay.boot();
    jay.invert(1);
    jay.clear();

    game.loadHighScore();
}

void loop() {
    int res, len;
    char word_buf[8];
    char solved = 0;

    if(!jay.nextFrame()) return;

    jay.pollButtons();
    jay.clear();

    switch(game.stage) {
        case STAGE_TITLE:
        if(jay.justPressed(A_BUTTON) || jay.justPressed(B_BUTTON)) {
            load();
            game.score = 0;
            game.stage = STAGE_PLAY;
        }
        if(jay.justPressed(UP_BUTTON) || jay.justPressed(DOWN_BUTTON))
            dawg.easy_mode ^= 1;
        break;

        case STAGE_PLAY:
        if(jay.justPressed(LEFT_BUTTON))  guess.cursorLeft();
        if(jay.justPressed(RIGHT_BUTTON)) guess.cursorRight();
        if(jay.justPressed(UP_BUTTON))    guess.handleSelect();
        if(jay.justPressed(DOWN_BUTTON))  guess.handleDelete();
        if(jay.justPressed(B_BUTTON))     guess.handleReturnShuffle();
        if(jay.justPressed(A_BUTTON)) {
            res = dawg.checkWord(guess.getWord(word_buf));
            len = strlen(word_buf);
            if((res >= 0) && (solved = !game.checkSolved(res, 1))) {
                game.num_solved ++;
                if(len == 6) {
                    game.target_solved = 1;
                }
                if(game.num_solved == dawg.results_ptr) {
                    game.score += 50;
                    game.stage = STAGE_NEXT;
                }
                game.score += (len - 2) * (len - 2);
                if (game.score > game.high_score) {
                    game.high_score = game.score;
                    game.setHighScore();
                }
            }
            display.setMessage(MESSAGES[
                res < 0? -res - 1: solved? len: 7
            ]);
        }
        if(game.time_left > 0)
            game.time_left --;
        else if(game.target_solved)
            game.stage = STAGE_NEXT;
        else
            game.stage = STAGE_GAME_OVER;
        break;

        case STAGE_NEXT:
        case STAGE_GAME_OVER:
        game.solved_mask[0] = 0xFFFF;
        game.solved_mask[1] = 0xFFFF;
        if(jay.justPressed(A_BUTTON)) {
            if(game.stage == STAGE_NEXT) {
                load();
                game.stage = STAGE_PLAY;
            } else {
                game.stage = STAGE_TITLE;
            }
        }
        break;
    }

    //char display_buf[16];
    //jay.smallPrint(100, 55, itoa(display_buf, jay.cpuLoad()));

    display.render();
    jay.display();
}

// vim:syntax=c
