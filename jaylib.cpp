#include "jaylib.h"
#include "utils.h"

void Jaylib::drawBand(int x, int y, const uint8_t * sprite, const uint16_t mask, uint8_t cols) {
    half_t s, m;
    int8_t i;
    int p = (y >> 3) * WIDTH + i + x;
    uint8_t h = y & 7;

    if(cols + x >= WIDTH) cols = WIDTH - x;

    for(i = 0; i < cols; i ++, p ++) {
        s.v = pgm_read_byte(sprite + i) << h;
        m.v = mask << h;

        sBuffer[p] = sBuffer[p] & ~m.l | s.l & m.l;
        sBuffer[p + WIDTH] = sBuffer[p + WIDTH] & ~m.h | s.h & m.h;
    }
}

void Jaylib::smallPrint(int x, int y, const uint8_t * str) {
    char c;
    for(;c = *str ++;) {
        c -= 32;
        drawBand(x, y, PRINTABLE_CHARS + 3 * c, 0x3F, 3);
        x += 4;
    }
}

void Jaylib::largePrint(int x, int y, const uint8_t * str, int kern) {
    char c;
    for(;c = *str ++;) {
        c &= 0x1F; // Lucky that SPACE % 32 == 0
        drawBand(x, y, PRINTABLE_CHARS_LARGE + 5 * c, 0xFF, 5);
        x += 5 + kern;
    }
}
