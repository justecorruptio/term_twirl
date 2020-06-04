#ifndef JAYLIB_H
#define JAYLIB_H

#include <Arduboy2.h>
#include <avr/power.h>

#include "jay_sprites.h"

class Jaylib: public Arduboy2Base {
    public:
    void drawBand(int x, int y, const uint8_t * sprite, uint8_t cols);

    void smallPrint(int x, int y, const uint8_t * str);
    void largePrint(int x, int y, const uint8_t * str, int kern = 1);
};

#endif
