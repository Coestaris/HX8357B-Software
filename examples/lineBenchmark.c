#include "avr/io.h"

#include "headers/timing.h"
#include "headers/uart.h"
#include "headers/graphics.h"

#include "headers/fonts/font_std.h"

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

FONT_INFO font;

int main(void)
{
  initTimer();
  gr_init();
  gr_setRotation(1);
  //gr_fill(cl_GREEN);
  char chars[20];
  char chars1[20];
  memset(chars, 0, 20);
  memset(chars1, 0, 20);
  color_t colors[gr_TFTWIDTH];
  font = font_std();
  for(int i = 0; i < gr_TFTWIDTH; i++)
  {
    colors[i] = cl_FromRGB(map(i, 0, gr_TFTWIDTH, 0, 255), map(i, 0, gr_TFTWIDTH, 75, 125), map(i, 0, gr_TFTWIDTH, 255, 0));
  }

  uint32_t m1 = millis();

  for(int j = 0; j < 20; j++)
  {
    if(j % 2) for(int i = 0; i < gr_TFTWIDTH; i++)
        gr_vline(i, 0, gr_TFTHEIGHT, colors[i]);
    else for(int i = 0; i < gr_TFTWIDTH; i++)
        gr_vline(gr_TFTWIDTH - i, 0, gr_TFTHEIGHT, colors[i]);
  }

  uint32_t m2 = millis();
  itoa((int)(m2 - m1), chars, 10);
    _delay_ms(500);
  m1 = millis();

  for(int j = 0; j < 20; j++)
  {
    if(j % 2) for(int i = 0; i < gr_TFTHEIGHT; i++)
        gr_hline(i, 0, gr_TFTWIDTH, colors[i]);
    else for(int i = 0; i < gr_TFTHEIGHT; i++)
        gr_hline(gr_TFTHEIGHT - i, 0, gr_TFTWIDTH, colors[i]);
  }

  m2 = millis();
  gr_text_setPos(0, 0);

  gr_fill(cl_BLACK);
  font.bgColor = cl_BLACK;
  font.color = cl_GREEN;
  gr_text_printStr(font, "Vert. completed in ");
  gr_text_printStr(font, chars);
  gr_text_printStr(font, " ms\n");
  gr_text_printStr(font, "Hor.  completed in ");
  itoa((int)(m2 - m1), chars1, 10);
  gr_text_printStr(font, chars1);
  gr_text_printStr(font, " ms\n");

  while(1);
  return 0;
}
