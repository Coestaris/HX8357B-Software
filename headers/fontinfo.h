#ifndef _fontinfo_h_
#define _fontinfo_h_

#include <avr/pgmspace.h>

#include "bitwise.h"
#include "colors.h"

#define ASCII_toUpper(x) ((x>96)&&(x<123))?x-32:x
#define ASCII_SpacesInTab 2

typedef struct
{
  uint16_t offset;
  uint16_t length;
} CAT_ITEM;

uint8_t CAT_ITEM_ISENCODED(CAT_ITEM a);
CAT_ITEM CAT_GET(uint16_t data, uint16_t index);

typedef struct
{
  uint8_t encoded;
  uint8_t maxXSize;
  uint8_t maxYSize;
  uint8_t startChar;
  uint8_t endChar;
  uint16_t bytesPerSymbol;
  uint16_t color;
  uint16_t bgColor;
  uint16_t data;
} FONT_INFO;

#endif
