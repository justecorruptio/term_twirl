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

    void drawSprite(int x, int y, const uint8_t * sprite, uint8_t rev);
    void drawBand(int x, int y, const uint8_t * sprite, const uint8_t * mask, uint8_t cols, uint8_t rev);

    void drawFastVLine(int16_t x, int16_t y, uint8_t h, uint8_t color);

    void poll(uint8_t rate); // repeat rate in frames
    uint8_t held(uint8_t buttons);
    uint8_t on(uint8_t buttons);

    void smallPrint(const uint8_t * str);
    void largePrint(const uint8_t * str, int kern);
    void largePrint(const uint8_t * str);
    void setCursor(int x, int y);

    protected:

    uint8_t buttons = 0, buttonsHeld = 0, buttonsEdge = 0, buttonsCount = 0;
    int cursor_x, cursor_y;

};


#endif
