#ifndef DAWG_H
#define DAWG_H

#include <Arduboy2.h>
#include "dict_dawg.h"

#include "utils.h"

#define TARGET_LENGTH 6

#define OP_MODE_SELECT 1
#define OP_MODE_LOAD 2

class Dawg {
    public:

    int process(int mode, uint32_t param);
    int traverse(uint16_t ptr, int buf_ptr, uint32_t hash);

    int sort_results();
    int checkWord(char* word);

    char results[32][8];
    int results_ptr;

    //private:
    char buffer[8];
    int op_mode;
    uint32_t op_param;
};

#endif
