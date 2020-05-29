#include "dawg.h"


int Dawg::init() {
    target_count = 0;
    setup(OP_MODE_SELECT, 0xFF);
    traverse();
}

int Dawg::setup(int mode, uint32_t param) {
    op_mode = mode;
    op_param = param;

    ((uint32_t *)buffer)[0] = 0;
    ((uint32_t *)buffer)[1] = 0;
    results_ptr = 0;
}

int Dawg::traverse(uint32_t ptr, int buf_ptr, uint32_t hash) {
    union {
        uint32_t whole;
        struct {
            // IMPORTANT! Never more that 2 ^ 16 nodes
            uint16_t child_offset;
            char high;
        };
    } w;
    char c;
    uint32_t next_hash = hash;

    do {
        w.whole = pgm_read_dword(DICT_DAWG + ptr);

        // current character
        if (w.high & 0x7C) {
            c = (w.high >> 2) - 1;
            next_hash = hash * LETTER_TO_PRIME_BY_FREQ[c];
            buffer[buf_ptr] = c + 'A';
        }

        if (w.high & 0x1) { // Word End
            switch (op_mode) {
                case OP_MODE_SELECT:
                if(buf_ptr + 1 == TARGET_LENGTH) {
                    counter += 1;
                    if(op_param == 0xFF) {
                        if(counter > target_count)
                            target_count = counter;
                    } else if (counter == op_param){
                        strcpy(results[0], buffer);
                        return 0;
                    }
                }
                break;

                case OP_MODE_LOAD:
                if(op_param % next_hash == 0) {
                    strcpy(results[results_ptr ++], buffer);
                }
                break;

            }
        }

        if (w.child_offset) {
            if(! traverse(w.child_offset * 3, buf_ptr + 1, next_hash))
                return 0;
        }

        ptr += 3;
    } while (! (w.high & 0x2)); // List End

    buffer[buf_ptr] = 0;
    return 1;
}

int Dawg::traverse() {
    counter = 0;
    return traverse(pgm_read_word(
        DICT_DAWG + DICT_DAWG_LENGTH - 3
    ) * 3, 0, 1);
}

int Dawg::sort_results() {
    char i, j, k, t, *a, *b, al, bl;
    for(i = results_ptr; i > 0; i --) {
        for(j = 0; j < i - 1; j ++) {
            a = results[j];
            b = results[j + 1];
            al = strlen(a);
            bl = strlen(b);
            if(al > bl || (al == bl && strcmp(a, b) > 0)) {
                for(k = 0; k < 8; k++){
                    t = a[k];
                    a[k] = b[k];
                    b[k] = t;
                }
            }
        }
    }
}

int Dawg::checkWord(char* word) {
    // Returns word position or -1
    int i;
    for(i = 0; i < results_ptr; i++) {
        if(strcmp(word, results[i]) == 0)
            return i;
    }
    return -1;
}
