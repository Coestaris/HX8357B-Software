#include "avr/io.h"

#include "headers/timing.h"
#include "headers/uart.h"
#include "headers/graphics.h"

#include "headers/fonts/font_std.h"

int min(int a, int b)
{
  return a < b ? a : b;
}

int main(void)
{
  gr_init();
  FONT_INFO font = font_std();
  gr_setRotation(1);
  gr_fill(cl_BLACK);

  srand(21);

  for(int i = 0; i <= 50; i++)
  {
    int x = random() % 470 + 10;
    int y = random() % 310 + 10;

    int r = min(min(min(480 - x, x), min(320 - y, y)), 40);

    gr_fillCircle(x, y, r, cl_random);
  }

  while (1) for(uint16_t i = 0; i < 480; i++)
  {
    gr_scroll(i, 0, 480, 0);
    _delay_ms(1);
  }

  return 0;
}
