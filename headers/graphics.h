#ifndef _graphics_h_
#define _graphics_h_

#include "avr/io.h"
#include "util/delay.h"

#include <string.h>

#include "bitwise.h"
#include "fontinfo.h"
#include "tft_hardware.h"

typedef uint16_t color_t;

uint16_t abs(uint16_t a);
#define swap(a,b) {uint16_t _loc_=a;a=b;b=_loc_;}
#define PushColor(x) {PORTC=x;PORTA=x>>8;gr_h_WR_STB;}

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

void gr_vline(uint16_t x, uint16_t y1, uint16_t y2, color_t color);
void gr_hline(uint16_t y, uint16_t x1, uint16_t x2, color_t color);
void gr_line(int16_t x1, int16_t y1, int16_t x2, int16_t y2, color_t color);
void gr_fillCircle(int16_t x0, int16_t y0, int16_t radius, color_t color);
void gr_drawCircle(int16_t x0, int16_t y0, int16_t radius, color_t color);
void gr_drawRect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, color_t color);
void gr_fillRect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, color_t color);
void gr_drawPixel(uint16_t x, uint16_t y, color_t color);
void gr_fill(color_t color);

void gr_setBrightness(uint8_t value);
void gr_setAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
void gr_setRotation(uint8_t m);

uint16_t gr_getWidth(void);
uint16_t gr_getHeight(void);

extern uint16_t _width;
extern uint16_t _height;

#define betweenSymbolSpaceX 0
#define betweenSymbolSpaceY 2

//#define CLIP_CHECK

#endif
