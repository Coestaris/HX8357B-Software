#include "avr/io.h"

#include "src/headers/timing.h"
#include "src/headers/uart.h"
#include "src/headers/graphics.h"
#include "src/headers/fonts/font_std.h"
#include "src/headers/bmpinfo.h"

int main(void)
{
    gr_init();
    gr_setRotation(1);
    gr_fill(cl_OLIVE
    );

    while(1);
    return 0;
}
