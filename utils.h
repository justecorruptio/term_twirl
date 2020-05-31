#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

const uint8_t LETTER_TO_PRIME_BY_FREQ [] = {
    5, 71, 43, 29, 2, 41, 53, 19, 11, 89, 79, 31, 47,
    13, 7, 61, 97, 23, 17, 3, 37, 73, 67, 83, 59, 101
};

void reverse(char * buf, uint8_t len);
char * itoa(char * buf, int16_t x);
uint32_t lex_hash(char * buf);

#endif
