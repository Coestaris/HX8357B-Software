#include "avr/io.h"
#include "util/delay.h"

#include "headers/uart.h"
#include "headers/graphics.h"

#include "headers/fonts/font_std.h"

FONT_INFO font;

int main(void)
{
  gr_init();
  font = font_std();
  gr_setRotation(1);

  gr_text_setPos(0, 0);
  gr_fill(TFT_BLACK);

  font.color = TFT_GREEN;
  gr_text_setPos(0, 0);
  gr_text_printStrCase(font, "\"Pack my box with five dozen\nliquor jugs\": According to\nWikipedia, this one is used on\nNASA's Space Shuttle.\n\n", 0);
  gr_text_printStrCase(font, "\"Pack my box with five dozen\nliquor jugs\": According to\nWikipedia, this one is used on\nNASA's Space Shuttle.", 1);



  _delay_ms(2000);

  while (1);
}
