#ifndef JAYLIB_H
#define JAYLIB_H

#include <Arduboy2.h>
#include <avr/power.h>

#include "jay_sprites.h"

typedef union {
    uint16_t v;
    struct { uint8_t l, h; };
} half_t;

class Jaylib: public Arduboy2Base {
    public:
    void drawBand(int x, int y, const uint8_t * sprite, const uint16_t mask, uint8_t cols);

    void smallPrint(const uint8_t * str);
    void largePrint(const uint8_t * str, int kern);
    void largePrint(const uint8_t * str);
    void setCursor(int x, int y);

    protected:
    int cursor_x, cursor_y;
};

#endif
