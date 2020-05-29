#include "jaylib.h"
#include "utils.h"

void Jaylib::drawSprite(int x, int y, const uint8_t * sprite, uint8_t rev) {
    uint8_t masked = pgm_read_byte(sprite++);
    uint8_t cols = pgm_read_byte(sprite++);
    uint8_t bands = pgm_read_byte(sprite++);
    if(masked){
        while(bands --) {
            drawBand(x, y, sprite, sprite + cols, cols, rev);
            sprite += cols << 1;
            y += 8;
        }
    }
    else {
        while(bands --) {
            drawBand(x, y, sprite, 0, cols, rev);
            sprite += cols;
            y += 8;
        }
    }
}

void Jaylib::drawBand(int x, int y, const uint8_t * sprite, const uint8_t * mask, uint8_t cols, uint8_t rev) {
    if(x + cols <= 0 || x >= WIDTH || y + 8 <= 0 || y >= HEIGHT) return;

    half_t s, m;
    int8_t i = x < 0 ? -x : 0;
    int p = (y >> 3) * WIDTH + i + x;
    uint8_t h = y & 7;

    if(cols + x >= WIDTH) cols = WIDTH - x;

    for(; i < cols; i ++, p ++) {
        if (rev) {
            s.v = pgm_read_byte(sprite + cols - i - 1) << h;
            if(mask)
                m.v = pgm_read_byte(mask + cols - i - 1) << h;
            else
                m.v = ((uint16_t)0xff) << h;
        }
        else {
            s.v = pgm_read_byte(sprite + i) << h;
            if(mask)
                m.v = pgm_read_byte(mask + i) << h;
            else
                m.v = ((uint16_t)0xff) << h;
        }

        if(y >= 0 && y < HEIGHT)
            sBuffer[p] = sBuffer[p] & ~m.l | s.l & m.l;

        if(h && y > -8 && y < HEIGHT - 8)
            sBuffer[p + WIDTH] = sBuffer[p + WIDTH] & ~m.h | s.h & m.h;
    }
}

void Jaylib::drawFastVLine(int16_t x, int16_t y, uint8_t h, uint8_t color) {
    uint8_t shift;

    // Check if the line is off to the left or right edge
    // or has a positive length.
    if (x < 0 || x >= WIDTH || h == 0)
        return;

    // Crop the line if it's off the top edge.
    if (y < 0)
        y = 0;

    // Crop the line if it's off the bottom edge.
    if(y + h > HEIGHT)
        h = HEIGHT - y;

    register uint8_t mask;

    // Handle the beginning of the line where the first
    // segment might only partially fill up an 8-pixel block.
    shift = y & 0x7;
    if(h <= 8 - shift) {
        mask = ((1 << h) - 1) << shift;
        h = 0;
    }
    else {
        mask = 0xFF << shift;
        h -= 8 - shift;
    }

    // The screen is arranged as 8-pixel vertical stripes laid horizontally.
    register uint8_t *pBuf = sBuffer + (y / (HEIGHT / 8)) * WIDTH + x;

    // Draw the first partial segment.
    if(color) *pBuf |= mask;
    else *pBuf &= ~mask;

    // Draw all complete 8-pixel segments.
    while(h > 8) {
        pBuf += WIDTH;
        if(color) *pBuf = 0xFF;
        else *pBuf = 0x00;
        h -= 8;
    }

    // Handle the case where a partial segment is left over.
    if(h) {
        mask = ((1 << h) - 1);
        pBuf += WIDTH;
        if(color) *pBuf |= mask;
        else *pBuf &= ~mask;
    }
}

void Jaylib::poll(uint8_t rate) {
    uint8_t newPoll = buttonsState();
    buttonsEdge = newPoll & ~buttons;
    buttonsHeld = buttons = newPoll;

    if(newPoll) {
        if (++ buttonsCount >= rate)
            buttons = buttonsCount = 0;
    }
    else
        buttonsCount = 0;
}

uint8_t Jaylib::on(uint8_t buttons) {
    return this->buttonsEdge & buttons;
}

uint8_t Jaylib::held(uint8_t buttons) {
    return this->buttonsHeld & buttons;
}

void Jaylib::smallPrint(const uint8_t * str) {
    char c;
    for(;c = *str; str ++) {
        c -= 32;
        drawBand(cursor_x, cursor_y, PRINTABLE_CHARS + 3 * c, PRINTABLE_MASK, 3, 0);
        drawBand(cursor_x + 3, cursor_y, PRINTABLE_KERN, PRINTABLE_MASK, 1, 0);

        cursor_x += 4;
        if(cursor_x >= WIDTH - 3) {
            cursor_x = 0;
            cursor_y += 6;
        }
    }
}

void Jaylib::largePrint(const uint8_t * str, int kern) {
    char c;
    for(;c = *str; str ++) {
        c = (c == ' ') ? 0 : c - 'A' + 1; //TODO: support all ascii
        drawBand(cursor_x, cursor_y, PRINTABLE_CHARS_LARGE + 5 * c, PRINTABLE_MASK_LARGE, 5, 0);
        drawBand(cursor_x + 5, cursor_y, PRINTABLE_KERN_LARGE, PRINTABLE_MASK_LARGE, kern, 0);

        cursor_x += 5 + kern;
        if(cursor_x >= WIDTH - 5) {
            cursor_x = 0;
            cursor_y += 8;
        }
    }
}

void Jaylib::largePrint(const uint8_t * str) {
    largePrint(str, 1);
}

void Jaylib::setCursor(int x, int y) {
    cursor_x = x;
    cursor_y = y;
}
