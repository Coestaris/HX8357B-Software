#include "avr/io.h"

#include "headers/timing.h"
#include "headers/uart.h"
#include "headers/graphics.h"

#include "headers/fonts/font_std.h"

#include "headers/bmpinfo.h"

int main(void)
{
  gr_init();
  gr_setRotation(1);
  gr_fill(cl_GREEN);

  while(1);
  return 0;
}
