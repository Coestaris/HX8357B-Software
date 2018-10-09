#ifndef _colors_h_
#define _colors_h_

#define cl_BLACK       0x0000
#define cl_NAVY        0x000F
#define cl_DARKGREEN   0x03E0
#define cl_DARKCYAN    0x03EF
#define cl_MAROON      0x7800
#define cl_PURPLE      0x780F
#define cl_OLIVE       0x7BE0
#define cl_LIGHTGREY   0xC618
#define cl_DARKGREY    0x7BEF
#define cl_BLUE        0x001F
#define cl_GREEN       0x07E0
#define cl_CYAN        0x07FF
#define cl_RED         0xF800
#define cl_MAGENTA     0xF81F
#define cl_YELLOW      0xFFE0
#define cl_WHITE       0xFFFF
#define cl_ORANGE      0xFD20
#define cl_GREENYELLOW 0xAFE5
#define cl_PINK        0xF81F

//Returns random color.
#define cl_random (random() % 0xFFFF)

//Returns random color with evenly distributed chance for each channel.
#define cl_randomTrue (cl_FromRGB(random() % 255, random() % 255, random() % 255))

//Converts default 24-bit 8.8.8 RGB color to 16-bit 5.6.5 color
#define cl_FromRGB(red,green,blue) ((uint16_t)((((31 * (red + 4)) / 255) << 11) | (((63 * (green + 2)) / 255) << 5) | ((31 * (blue + 4)) / 255)))

#endif
