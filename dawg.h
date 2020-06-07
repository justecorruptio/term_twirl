#ifndef DAWG_H
#define DAWG_H

#include <Arduboy2.h>
#include "generated_data/dict_dawg.h"

#include "utils.h"

#define TARGET_LENGTH 6

#define OP_MODE_SELECT 1
#define OP_MODE_LOAD 2

class Dawg {
    public:

    int process(uint8_t mode);
    int traverse(uint16_t ptr, uint8_t buf_ptr=0);

    int sort_results();
    int checkWord(char* word);

    char results[32][8];
    uint8_t results_ptr;

    //private:
    char buffer[8];
    char op_word[8];
    uint8_t op_mode;
    uint32_t op_param;
    uint8_t dict_ptr;

    uint8_t easy_mode = 1;

};

#endif
