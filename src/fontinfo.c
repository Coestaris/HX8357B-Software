#include "headers/fontinfo.h"

uint8_t CAT_ITEM_ISENCODED(CAT_ITEM a)
{
   return bitw_bit(a.length, 15);
}

CAT_ITEM CAT_GET(uint16_t data, uint16_t index)
{
  return (CAT_ITEM) { .offset = pgm_read_word(data + 4 + index * 4), .length = pgm_read_word(data + 4 + index * 4 + 2)};
}
