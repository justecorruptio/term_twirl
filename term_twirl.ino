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
    "NICE!", "GREAT!", "AWESOME!", "BRILLIANT!"
};

void load() {
    uint32_t word_hash;

    dawg.setup(OP_MODE_SELECT, random(1, dawg.target_count - 1));
    dawg.traverse();
    word_hash = lex_hash(dawg.results[0]);

    guess.reset(dawg.results[0]);

    dawg.setup(OP_MODE_LOAD, word_hash);
    dawg.traverse();
    dawg.sort_results();

    game.reset();
}

void setup() {
    jay.boot();
    jay.invert(1);
    jay.clear();
    dawg.init();
    game.stage = STAGE_TITLE;

    game.loadHighScore();
}

void loop() {
    int res, len;
    char solved;
    char word_buf[8];

    if(!jay.nextFrame()) return;

    jay.pollButtons();
    jay.clear();

    switch(game.stage) {
        case STAGE_TITLE:
        if(jay.justPressed(A_BUTTON) || jay.justPressed(B_BUTTON)) {
            jay.initRandomSeed();
            load();
            game.score = 0;
            game.stage = STAGE_PLAY;
        }
        break;

        case STAGE_PLAY:
        if(jay.justPressed(LEFT_BUTTON))
            guess.cursorLeft();
        if(jay.justPressed(RIGHT_BUTTON))
            guess.cursorRight();
        if(jay.justPressed(UP_BUTTON))
            guess.handleSelect();
        if(jay.justPressed(DOWN_BUTTON))
            guess.handleDelete();
        if(jay.justPressed(B_BUTTON))
            guess.handleReturnShuffle();
        if(jay.justPressed(A_BUTTON)) {
            res = dawg.checkWord(guess.getWord(word_buf));
            len = strlen(word_buf);
            solved = 0;
            if(res == -1) {
                display.setMessage("NOT A WORD!");
            } else if (res == -2) {
                display.setMessage("TOO SHORT!");
            } else if (res == -3) {
            } else if(!game.checkSolved(res, 1)) {
                solved = 1;
            } else {
                display.setMessage("IT'S THERE.");
            }

            if(solved) {
                game.num_solved ++;
                if(len == 6) {
                    game.target_solved = 1;
                }
                if(game.num_solved == dawg.results_ptr) {
                    game.score += 50;
                    game.stage = STAGE_NEXT;
                }
                display.setMessage(MESSAGES[len - 3]);
                game.score += (len - 2) * (len - 2);
                if (game.score > game.high_score) {
                    game.high_score = game.score;
                    game.setHighScore();
                }
            }
        }
        if(game.time_left == 0) {
            if(game.target_solved) {
                game.stage = STAGE_NEXT;
            } else {
                game.stage = STAGE_GAME_OVER;
            }
        }
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
    //jay.setCursor(100, 55);
    //jay.smallPrint(itoa(display_buf, jay.cpuLoad()));

    if(game.time_left > 0) game.time_left --;

    display.render();
    jay.display();
}

// vim:syntax=c
