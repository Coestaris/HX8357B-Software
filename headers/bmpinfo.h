#ifndef _bmpinfo_h_
#define _bmpinfo_h_

typedef enum
{
  Color_565 = 0x1,
  Color_555 = 0x2, 
  Color_332 = 0x4,
  GrayScale = 0x8,
  GrayScale_encoded = 0x10,
  Binary = 0x20,
  Binary_encoded = 0x40,
  Default = 0x80
} colorMode_t;

typedef struct
{
  uint16_t width;
  uint16_t height;
  colorMode_t colorMode;
} BMP_INFO;

#endif
