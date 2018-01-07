#include "avr/io.h"

#include "headers/graphics.h"

#include "headers/fonts/font_sevenSegmentDigits.h"

int main(void)
{
  gr_init();
  gr_setRotation(1);
  gr_fill(cl_BLACK);

  FONT_INFO font = font_sevenSegmentDigits();
  font.bgColor = cl_BLACK;
  font.color = cl_RED;

  int a = 0, b = 0, c = 0, d = 0;

  gr_text_setCursor(font, 0, 0);
  gr_text_printStr(font, "0000");

  while (1) {
    a++;
    gr_text_setCursor(font, 3, 0);
    gr_text_print(font, a + 1);
    if(a == 9)
    {
      gr_text_setCursor(font, 3, 0);
      gr_text_print(font, 0);
      a = 0;
      b++;
      gr_text_setCursor(font, 2, 0);
      gr_text_print(font, b + 1);
      if(b == 9)
      {
        gr_text_setCursor(font, 2, 0);
        gr_text_print(font, 0);
        c++;
        b = 0;
        gr_text_setCursor(font, 1, 0);
        gr_text_print(font, c + 1);
        if(c == 9)
        {
          c = 0;
          gr_text_setCursor(font, 1, 0);
          gr_text_print(font, 0);
          d++;
          gr_text_setCursor(font, 0, 0);
          gr_text_print(font, d + 1);
        }
      }
    }
  }

  return 0;
}
