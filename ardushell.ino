#include "jaylib.h"
#include "dawg.h"
#include "utils.h"
#include "guess.h"

#include "display.h"

#define STAGE_TITLE 1
#define STAGE_LOAD 2
#define STAGE_PLAY 3
#define STAGE_GAME_OVER 4


Jaylib jay;
Dawg dawg;
Guess guess;

Display display = Display(jay, dawg, guess);

int stage;
uint32_t counter = 0;
char display_buf[16];

uint16_t solved_mask[2] = {0, 0};
uint32_t num_solved = 0;
uint32_t word_hash;
char word_buf[8];

void load() {
    dawg.setup(OP_MODE_SELECT, 345);
    dawg.traverse();
    word_hash = lex_hash(dawg.results[0]);

    guess.reset(dawg.results[0]);

    dawg.setup(OP_MODE_LOAD, word_hash);
    dawg.traverse();
    dawg.sort_results();

    solved_mask[0] = 0;
    solved_mask[1] = 0;
    num_solved = 0;
}

void setup() {
    jay.boot();

    jay.invert(1);
    jay.clear();

    dawg.init();

    //stage = STAGE_TITLE;
    load();
    stage = STAGE_PLAY;
}


void loop() {
    int res;
    if(!jay.nextFrame()) return;
    //jay.poll(2);
    jay.pollButtons();
    jay.clear();

    switch(stage) {
        case STAGE_TITLE:
        display.renderTitle();
        if(jay.justPressed(A_BUTTON)) {
            load();
            stage = STAGE_PLAY;
        }
        break;

        case STAGE_PLAY:
        display.renderChrome();
        display.renderDawgResults(solved_mask);
        display.renderGuess();
        display.renderCursor();
        if(jay.justPressed(LEFT_BUTTON))
            guess.cursorLeft();
        if(jay.justPressed(RIGHT_BUTTON))
            guess.cursorRight();
        if(jay.justPressed(A_BUTTON))
            guess.handleSelect();
        if(jay.justPressed(B_BUTTON))
            guess.handleDelete();
        if(jay.justPressed(UP_BUTTON)) {
            res = dawg.checkWord(guess.getWord(word_buf));
            if(res == -1) {
            } else if (res < 16) {
                if (!(solved_mask[0] & (1 << res))) {
                    solved_mask[0] |= (1 << res);
                    num_solved ++;
                }
            } else {
                if (!(solved_mask[1] & (1 << (res - 16)))) {
                    solved_mask[1] |= (1 << (res - 16));
                    num_solved ++;
                }
            }
        }
        break;
    }

    //jay.setCursor(100, 55);
    //jay.smallPrint(itoa(display_buf, jay.cpuLoad()));

    jay.display();
    counter ++;
}

// vim:syntax=c
