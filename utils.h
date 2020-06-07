#ifndef UTILS_H
#define UTILS_H

#include <string.h>
#include <stdint.h>

char * itoa(int16_t x);
uint32_t lex_hash(char * buf);

uint8_t is_subset(char * a, char * b);

#endif
