#include "avr/io.h"
#include "util/delay.h"

#include "headers/uart.h"
#include "headers/graphics.h"

#include "headers/fonts/font_std.h"


int i = 0;
FONT_INFO font;

int main(void)
{
  gr_init();
  font = font_std();
  gr_setRotation(1);
  while (1)
  {
    gr_text_setPos(0, 0);

    uint16_t c = cl_randomTrue;
    gr_fill(c);
    font.bgColor = c;

    font.color = cl_randomTrue;
    gr_text_printStrCase(font, "most popular programming langs\n", 1);
    gr_text_printStrCase(font, "#\t name\t\t\t\t\tusage\tchange\n", 1);
    gr_text_printStrCase(font, "1\t Java\t\t\t\t13.268%\t-4.59%\n2\t C\t\t\t\t\t 10.158%\t+1.43%\n3\t C++\t\t\t\t\t4.717%\t-0.62%\n4\t Python\t\t\t 3.777%\t-0.46%\n5\t C#\t\t\t\t\t 2.822%\t-0.35%\n6\t JavaScript\t 2.474%\t-0.39%\n7\t V.Basic .NET	2.47%	-0.83%\n8 \tR\t\t\t\t\t\t1.906%\t+0.08%\n9 \tPHP\t\t\t\t\t1.590%\t-1.33%\n10\tMATLAB\t\t\t 1.569%\t-0.25%\n11\tSwift\t\t\t\t1.566%	-0.57%\n12\tObjective-C	1.497%	-0.83%\n13\tASM LANG\t\t 1.471%\t-1.07%\n14\tPerl\t\t\t\t 1.437%\t-0.90%\n16\tDelphi\t\t \t1.395%\t-0.55%", 1);
    _delay_ms(500);
  }
}
