#include "dawg.h"

const uint8_t * DICT_DAWG [] = {
    DICT_DAWG_EASY,
    DICT_DAWG_HARD
};
const uint8_t * DICT_DAWG_CHARS [] = {
    DICT_DAWG_EASY_CHARS,
    DICT_DAWG_HARD_CHARS
};
const uint16_t DICT_DAWG_START_PTR [] = {
    DICT_DAWG_EASY_START_PTR,
    DICT_DAWG_HARD_START_PTR
};
const uint16_t DICT_DAWG_NUM_TARGETS [] = {
    DICT_DAWG_EASY_NUM_TARGETS,
    DICT_DAWG_HARD_NUM_TARGETS
};


int Dawg::process(int mode, uint32_t param) {
    op_mode = mode;

    ((uint32_t *)buffer)[0] = 0;
    ((uint32_t *)buffer)[1] = 0;
    results_ptr = 0;
    if(mode == OP_MODE_SELECT) {
        if (easy_mode)
            op_param = random(1, DICT_DAWG_NUM_TARGETS[0] - 1);
        else
            op_param = random(1,
                DICT_DAWG_NUM_TARGETS[0] + DICT_DAWG_NUM_TARGETS[1] - 1
            );
    }else{
        op_param = param;
    }
    dict_dawg = DICT_DAWG[0];
    dict_dawg_chars = DICT_DAWG_CHARS[0];
    traverse(DICT_DAWG_START_PTR[0]);

    if(easy_mode) return;

    dict_dawg = DICT_DAWG[1];
    dict_dawg_chars = DICT_DAWG_CHARS[1];
    traverse(DICT_DAWG_START_PTR[1]);
}

int Dawg::traverse(uint16_t ptr, int buf_ptr, uint32_t hash) {
    uint16_t child_offset; // IMPORTANT! Never more that 2 ^ 16 nodes
    char high;
    uint32_t next_hash;
    uint16_t a, b, c;

    do {
        //child_offset = pgm_read_word(dict_dawg + ptr * 2);
        if ((ptr % 4) == 3) {
            a = pgm_read_word(dict_dawg + (ptr / 4) * 3 * 2 + 0);
            b = pgm_read_word(dict_dawg + (ptr / 4) * 3 * 2 + 2);
            c = pgm_read_word(dict_dawg + (ptr / 4) * 3 * 2 + 4);
            child_offset = (
                ((a >> 12) & 0x000F) | ((b >> 8) & 0x00F0) | ((c >> 4) & 0x0F00)
            );
        } else {
            child_offset = pgm_read_word(dict_dawg + ((ptr / 4) * 3 + (ptr % 4)) * 2) & 0x0FFF;
        }

        high = pgm_read_byte(dict_dawg_chars + ptr);

        // Though the DAWG spec allows the character to be '\0',
        // it never is base on how the dawg is generated.
        buffer[buf_ptr] = (high >> 2) + 'A' - 1;
        next_hash = hash * (LETTER_TO_PRIME_BY_FREQ - 'A')[buffer[buf_ptr]];

        if (high & 0x1) { // Word End
            if(op_mode == OP_MODE_SELECT) {
                if((buf_ptr + 1 == TARGET_LENGTH) && (--op_param == 0)){
                    strcpy(results[0], buffer);
                }
            } else if(op_param % next_hash == 0) {
                // This should never overflow since the generator
                // script doesn't allow more than 30 subanagrams.
                strcpy(results[results_ptr ++], buffer);
            }
        }

        if (child_offset)
            traverse(child_offset, buf_ptr + 1, next_hash);

        ptr ++;
    } while (! (high & 0x2)); // List End

    buffer[buf_ptr] = 0;
}

int Dawg::sort_results() {
    char i, j, k, t, *a, *b, al, bl;
    for(i = results_ptr; i --;) {
        for(j = 0; j < i; j ++) {
            a = results[j], b = results[j + 1];
            al = strlen(a), bl = strlen(b);
            if(al > bl || (al == bl && strcmp(a, b) > 0)) {
                for(k = 8; k--;)
                    t = a[k], a[k] = b[k], b[k] = t;
            }
        }
    }
}

int Dawg::checkWord(char* word) {
    // Returns word position or negative number
    int i, len = strlen(word);
    if(len == 0) return -3;
    if(len < 3) return -2;
    for(i = 0; i < results_ptr; i++) {
        if(strcmp(word, results[i]) == 0)
            return i;
    }
    return -1;
}
