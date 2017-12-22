#ifndef _graphics_h_
#define _graphics_h_

#include "avr/io.h"
#include "util/delay.h"

#include <string.h>

#include "bitwise.h"
#include "fontinfo.h"
#include "tft_hardware.h"

#define swap(a,b) {uint16_t _loc_=a;a=b;b=_loc_;}

void gr_init(void);
void gr_initPorts(void);
void gr_writedata(uint8_t c);
void gr_writecommand(uint8_t c);

void gr_text_printStrCase(FONT_INFO info, uint8_t * data, uint8_t upperCase);
void gr_text_printStr(FONT_INFO info, uint8_t * data);
void gr_text_printChar(FONT_INFO info, uint8_t symbol);
void gr_text_print(FONT_INFO info, uint8_t index);
void gr_text_setPos(uint16_t x, uint16_t y);
void gr_text_setCursor(FONT_INFO info, uint16_t x, uint16_t y);

void gr_fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void gr_fill(uint16_t color);

void gr_drawPixel(uint16_t x, uint16_t y, uint16_t color);

void gr_setAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
void gr_setRotation(uint8_t m);

uint16_t gr_getWidth(void);
uint16_t gr_getHeight(void);

extern uint16_t _width;
extern uint16_t _height;

#define betweenSymbolSpaceX 2
#define betweenSymbolSpaceY 2

//#define CLIP_CHECK

#endif
