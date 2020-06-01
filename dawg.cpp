#include "dawg.h"


int Dawg::process(int mode, uint32_t param) {
    op_mode = mode;
    op_param = param;

    ((uint32_t *)buffer)[0] = 0;
    ((uint32_t *)buffer)[1] = 0;
    results_ptr = 0;
    if(mode == OP_MODE_SELECT) {
        if(easy_mode) {
            op_param = random(1, DICT_DAWG_EASY_NUM_TARGETS - 1);
        } else {
            op_param = random(1,
                DICT_DAWG_EASY_NUM_TARGETS +
                DICT_DAWG_HARD_NUM_TARGETS - 1
            );
        }
    }
    dict_dawg = DICT_DAWG_EASY;
    traverse(DICT_DAWG_EASY_START_PTR * 3, 0, 1);

    if(easy_mode) return;

    dict_dawg = DICT_DAWG_HARD;
    traverse(DICT_DAWG_HARD_START_PTR * 3, 0, 1);
}

int Dawg::traverse(uint16_t ptr, int buf_ptr, uint32_t hash) {
    union {
        uint32_t whole;
        struct {
            // IMPORTANT! Never more that 2 ^ 16 nodes
            uint16_t child_offset;
            char high;
        };
    } w;
    uint32_t next_hash;

    do {
        w.whole = pgm_read_dword(dict_dawg + ptr);

        // Though the DAWG spec allows the character to be '\0',
        // it never is base on how the dawg is generated.
        buffer[buf_ptr] = (w.high >> 2) + 'A' - 1;
        next_hash = hash * (LETTER_TO_PRIME_BY_FREQ - 'A')[buffer[buf_ptr]];

        if (w.high & 0x1) { // Word End
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

        if (w.child_offset)
            traverse(w.child_offset * 3, buf_ptr + 1, next_hash);

        ptr += 3;
    } while (! (w.high & 0x2)); // List End

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
