#include "utils.h"

char * itoa(char * buf, int16_t x) {
    // buf is at least char[8];
    uint8_t i;
    buf[7] = '\0';

    i = 6;
    do {
        buf[i--] = (x % 10) + '0';
        x /= 10;
    } while(x);

    return buf + i + 1;
}

uint32_t lex_hash(char * buf) {
    uint32_t prod = 1;
    for(; *buf; buf ++)
        prod *= LETTER_TO_PRIME_BY_FREQ[*buf - 'A'];
    return prod;
}
