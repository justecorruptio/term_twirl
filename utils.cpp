#include "utils.h"

void reverse(char * buf, uint8_t len) {
    uint8_t i, t;
    for(i = 0; i < (len >> 1); i++) {
        t = buf[i];
        buf[i] = buf[len - i - 1];
        buf[len - i - 1] = t;
    }
}

char * itoa(char * buf, int32_t x) {
    uint8_t i;
    if(x == 0) {
        buf[0] = '0', buf[1] = '\0';
        return;
    }
    else if(x < 0)
        x = -x, *(buf++) = '-';

    for(i = 0; x; i ++, x /= 10)
        buf[i] = (x % 10) + '0';

    reverse(buf, i);
    buf[i] = '\0';
    return buf;
}

uint32_t lex_hash(char * buf) {
    uint32_t prod = 1;
    for(; *buf; buf ++)
        prod *= LETTER_TO_PRIME_BY_FREQ[*buf - 'A'];
    return prod;
}
