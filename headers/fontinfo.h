#ifndef _fontinfo_h_
#define _fontinfo_h_

#include <avr/pgmspace.h>

#include "colors.h"

#define ASCII_toUpper(x) ((x>96)&&(x<123))?x-32:x
#define ASCII_SpacesInTab 2

typedef struct
{
  uint8_t maxXSize;
  uint8_t maxYSize;
  uint8_t startChar;
  uint8_t endChar;
  uint16_t bytesPerSymbol;
  uint16_t color;
  uint16_t data;
} FONT_INFO;

#endif
