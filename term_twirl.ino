#include "jaylib.h"
#include "dawg.h"
#include "utils.h"
#include "guess.h"

#include "display.h"

#define STAGE_TITLE 1
#define STAGE_LOAD 2
#define STAGE_PLAY 3
#define STAGE_NEXT 4
#define STAGE_GAME_OVER 5

const char* MESSAGES [] = {
    "NICE!", "GREAT!", "AWESOME!", "BRILLIANT!"
};

const uint32_t EEPROM_MAGIC = 0xF6E290C4;

Jaylib jay;
Dawg dawg;
Guess guess;

Display display = Display(jay, dawg, guess);

int stage;
uint32_t counter = 0;
char display_buf[16];

uint16_t solved_mask[2] = {0, 0};
uint32_t num_solved = 0;
char target_solved = 0;
uint32_t score = 0;
uint32_t high_score = 0;
uint32_t word_hash;
char word_buf[8];
uint32_t time_left;

void loadHighScore() {
    uint32_t v;
    EEPROM.get(256, v);
    if(v != EEPROM_MAGIC) {
        EEPROM.put(256, EEPROM_MAGIC);
        high_score = 0;
        setHighScore();
        return;
    }
    EEPROM.get(264, high_score);
}

void setHighScore() {
    EEPROM.put(264, high_score);
}

void load() {
    dawg.setup(OP_MODE_SELECT, random(1, dawg.target_count - 1));
    dawg.traverse();
    word_hash = lex_hash(dawg.results[0]);

    guess.reset(dawg.results[0]);

    dawg.setup(OP_MODE_LOAD, word_hash);
    dawg.traverse();
    dawg.sort_results();

    solved_mask[0] = 0;
    solved_mask[1] = 0;
    num_solved = 0;
    target_solved = 0;

    time_left = 9999;
}

void setup() {
    jay.boot();

    jay.invert(1);
    jay.clear();

    dawg.init();

    stage = STAGE_TITLE;
    //stage = STAGE_PLAY;
}


void loop() {
    int res, len;
    char solved;
    if(!jay.nextFrame()) return;
    //jay.poll(2);
    jay.pollButtons();
    jay.clear();

    switch(stage) {
        case STAGE_TITLE:
        display.renderTitle();
        if(jay.justPressed(A_BUTTON) || jay.justPressed(B_BUTTON)) {
            jay.initRandomSeed();
            load();
            score = 0;
            loadHighScore();
            stage = STAGE_PLAY;
        }
        break;

        case STAGE_PLAY:
        display.renderChrome();
        display.renderDawgResults(solved_mask);
        display.renderScores(score, high_score);
        display.renderTime(time_left);
        display.renderGuess();
        display.renderCursor();
        display.renderMessage();
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
            } else if (res < 16) {
                if (!(solved_mask[0] & (1 << res))) {
                    solved_mask[0] |= (1 << res);
                    solved = 1;
                } else {
                    display.setMessage("IT'S THERE.");
                }
            } else {
                if (!(solved_mask[1] & (1 << (res - 16)))) {
                    solved_mask[1] |= (1 << (res - 16));
                    solved = 1;
                } else {
                    display.setMessage("IT'S THERE.");
                }
            }
            if(solved) {
                num_solved ++;
                if(len == 6) {
                    target_solved = 1;
                }
                display.setMessage(MESSAGES[len - 3]);
                score += (len - 2) * (len - 2);
                if (score > high_score) {
                    high_score = score;
                    setHighScore();
                }
            }
        }
        if(time_left == 0) {
            if(target_solved) {
                stage = STAGE_NEXT;
            } else {
                stage = STAGE_GAME_OVER;
            }
        }
        if(num_solved == dawg.results_ptr){
            score += 50;
            if (score > high_score) {
                high_score = score;
                setHighScore();
            }
            stage = STAGE_NEXT;
        }
        break;

        case STAGE_NEXT:
        solved_mask[0] = 0xFFFF;
        solved_mask[1] = 0xFFFF;
        display.renderChrome();
        display.renderDawgResults(solved_mask);
        display.renderScores(score, high_score);
        display.renderNext();
        if(jay.justPressed(A_BUTTON)) {
            load();
            stage = STAGE_PLAY;
        }
        break;

        case STAGE_GAME_OVER:
        solved_mask[0] = 0xFFFF;
        solved_mask[1] = 0xFFFF;
        display.renderChrome();
        display.renderDawgResults(solved_mask);
        display.renderScores(score, high_score);
        display.renderGameOver();
        if(jay.justPressed(A_BUTTON)) {
            stage = STAGE_TITLE;
        }
        break;
    }

    //jay.setCursor(100, 55);
    //jay.smallPrint(itoa(display_buf, jay.cpuLoad()));

    jay.display();
    counter ++;

    if(time_left > 0) time_left --;
}

// vim:syntax=c
