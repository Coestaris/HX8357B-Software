#include "headers/graphics.h"

uint16_t _width = 0;
uint16_t _height = 0;
uint16_t offset = 0;
uint16_t yoffset = 0;

void gr_text_setCursor(FONT_INFO info, uint16_t x, uint16_t y)
{
  offset = x * info.maxXSize;
  yoffset = y * info.maxYSize;
}

void gr_text_setPos(uint16_t x, uint16_t y)
{
  offset = x;
  yoffset = y;
}

void gr_text_printStrCase(FONT_INFO info, uint8_t * data, uint8_t upperCase)
{
  uint8_t d;
  if(upperCase) while(*data)
  {
      d = *data++;
      gr_text_printChar(info, ASCII_toUpper(d));
  } else while(*data)
  {
      d = *data++;
      gr_text_printChar(info, d);
  }
}

void gr_text_printStr(FONT_INFO info, uint8_t * data)
{
  uint8_t d;
  while(*data)
  {
      d = *data++;
      gr_text_printChar(info,d);
  }
}

void gr_text_printChar(FONT_INFO info, uint8_t symbol)
{
  if(symbol > info.endChar || symbol < info.startChar)
  {
    if(symbol == 32)
      {
        if(offset + info.maxXSize + betweenSymbolSpaceX >= _width)
        {
          offset = 0;
          if(yoffset + info.maxYSize + betweenSymbolSpaceY >= _height)
          {
            yoffset = 0;
          } else yoffset += info.maxYSize;
        } else
            {
              gr_setAddrWindow(yoffset, offset, yoffset + info.maxYSize - 1, offset + info.maxXSize - 1);
              for(int i = 0; i< info.maxYSize * info.maxYSize; i++)
                PushColor(info.bgColor);
              offset += info.maxXSize + betweenSymbolSpaceX;
            }
        return;
      }
    else if(symbol == '\n')
      {
        if(yoffset + info.maxYSize + betweenSymbolSpaceY >= _height)
        {
          yoffset = 0;
        } else yoffset += info.maxYSize + betweenSymbolSpaceY;
        offset = 0;
        return;
      }
    else if(symbol == '\t')
      {
        for(uint8_t i = 0; i < ASCII_SpacesInTab; i++)
        {
          if(offset + info.maxXSize + betweenSymbolSpaceX >= _width)
          {
            offset = 0;
            if(yoffset + info.maxYSize + betweenSymbolSpaceY >= _height)
              yoffset = 0;
            else yoffset += info.maxYSize;
          } else offset += info.maxXSize + betweenSymbolSpaceX;
        }
        return;
      } else gr_text_print(info, 0);
  }
  else gr_text_print(info, symbol - info.startChar + 1);
}

void gr_text_print(FONT_INFO info, uint8_t index)
{
  uint16_t bits = info.maxXSize * info.maxYSize;
  uint32_t globalBit = 0;
  uint16_t memShift = info.data + (uint16_t)4 + (uint16_t)index * info.bytesPerSymbol;

  gr_setAddrWindow(yoffset, offset, yoffset + info.maxYSize - 1, offset + info.maxXSize - 1);
  for (uint16_t i = 0; i < info.bytesPerSymbol; i++)
  {
    uint8_t byte = pgm_read_byte_near(memShift + i);
    for (uint8_t currentBit = 0; currentBit < 8; currentBit++)
    {
      if(globalBit++ > bits)
        goto spacing;
      if(bitw_bit(byte, currentBit))
        {PushColor(info.color);}
      else PushColor(info.bgColor);
    }
  }
  spacing:
  if(offset + info.maxXSize + betweenSymbolSpaceX >= gr_getWidth())
    {
      offset = 0;
      yoffset += info.maxYSize;
    } else offset += info.maxXSize + betweenSymbolSpaceX;
}

void gr_fill(uint16_t color)
{
  gr_fillRect(0, 0, _height, _width, color);
}

void gr_fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
#ifdef CLIP_CHECK
  if ((x >= _width) || (y >= _height) || (w==0) || (h==0)) return;
  if ((x + w - 1) >= _width)  w = _width  - x;
  if ((y + h - 1) >= _height) h = _height - y;
#endif
  gr_setAddrWindow(x, y, x+w-1, y+h-1);
  PORTA = color>>8;
  PORTC = color;
  if (h>w) swap(w,h);
  if (w>15){
    while(h--) {
      x=w;
      while (x>15) { x-=16;
        gr_h_WR_STB; gr_h_WR_STB; gr_h_WR_STB; gr_h_WR_STB;
        gr_h_WR_STB; gr_h_WR_STB; gr_h_WR_STB; gr_h_WR_STB;
        gr_h_WR_STB; gr_h_WR_STB; gr_h_WR_STB; gr_h_WR_STB;
        gr_h_WR_STB; gr_h_WR_STB; gr_h_WR_STB; gr_h_WR_STB;
      }
      while(x--) {
        gr_h_WR_L;
        gr_h_WR_H;
      }
    }
  }
  else {
    while(h--) {
      x=w;
      while(x--) { gr_h_WR_L;
        gr_h_WR_H;}
    }
  }
  gr_h_CS_H;
}

void gr_setAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
  if (x0>x1) swap(x0,x1);
  if (y0>y1) swap(y0,y1);
#ifdef CLIP_CHECK
  if((x1 >= _width) || (y1 >= _height)) return;
#endif
  gr_h_CS_L;
  gr_h_RS_L;
  PORTC = gr_c_setPageAddress;
  gr_h_WR_STB;
  gr_h_RS_H;
  PORTC = x0>>8;
  gr_h_WR_STB;
  PORTC = x0;
  gr_h_WR_STB;
  PORTC = x1>>8;
  gr_h_WR_STB;
  PORTC = x1;
  gr_h_WR_STB;
  gr_h_RS_L;
  PORTC = gr_c_setClumnAddress;
  gr_h_WR_STB;
  gr_h_RS_H;
  PORTC = y0>>8;
  gr_h_WR_STB;
  PORTC = y0;
  gr_h_WR_STB;
  PORTC = y1>>8;
  gr_h_WR_STB;
  PORTC = y1;
  gr_h_WR_STB;
  gr_h_RS_L;
  PORTC = gr_c_WriteRam;
  gr_h_WR_STB;
  gr_h_RS_H;
}

void gr_writedata(uint8_t c)
{
  gr_h_CS_L;
  PORTA = c>>8;
  PORTC = c;
  gr_h_WR_STB;
  gr_h_CS_H;
}

void gr_writecommand(uint8_t c)
{
  gr_h_CS_L;
  gr_h_RS_L;
  PORTA = 0;
  PORTC = c;
  gr_h_WR_STB;
  gr_h_RS_H;
  gr_h_CS_H;
}

void gr_initPorts(void)
{
  //Set port groups as output
  DDRA = 0xFF;
  DDRB = 0xFF;
  DDRC = 0xFF;
  //DDRD = 0b10000000;
  //DDRG = 0x7;
  DDRD = 0xFF;
  DDRG = 0xFF;

  PORTA = 0xFF;
  PORTC = 0xFF;

  gr_h_WR_H;
  gr_h_RS_H;
}

void gr_init(void)
{
  gr_initPorts();

  _width = gr_TFTWIDTH;
  _height = gr_TFTHEIGHT;

  gr_h_RST(1);
  _delay_ms(50);
  gr_h_RST(0);
  _delay_ms(10);
  gr_h_RST(1);
  _delay_ms(10);

  gr_writecommand(gr_c_sleepOut);
  gr_writedata(0x00);
  _delay_ms(50);

  //SETTING UP POWER
  gr_writecommand(gr_c_setPower);
  //gr_writedata(gr_param_voltage_VC1_264V);
  gr_writedata(gr_param_voltage_VC1_192V);
  gr_writedata(0b01000010);
  gr_writedata(gr_param_voltage_VREG1_4v);

  gr_writecommand(gr_c_setVCOM);
  //gr_writedata(gr_param_vcom_vcm(520));
  gr_writedata(gr_param_vcom_vcm(492));
  //gr_writedata(gr_param_vcom_vdv(72));
  gr_writedata(gr_param_vcom_vdv(70));

  gr_writecommand(gr_c_setPowerForNormalMode);
  gr_writedata(0x01);
  gr_writedata(0x02);

  gr_writecommand(gr_c_setPanelDriving);
  gr_writedata(0x10);
  gr_writedata(0x3B);
  gr_writedata(0x00);
  gr_writedata(0x02);
  gr_writedata(0x11);

  gr_writecommand(gr_c_setDisplayFrame);
  gr_writedata(gr_param_frameRate_52000);
  //gr_writedata(gr_param_frameRate_17981);

  gr_writecommand(gr_c_setGamma);
  gr_writedata(0x00);
  gr_writedata(0x32);
  gr_writedata(0x36);
  gr_writedata(0x45);
  gr_writedata(0x06);
  gr_writedata(0x16);
  gr_writedata(0x37);
  gr_writedata(0x75);
  gr_writedata(0x77);
  gr_writedata(0x54);
  gr_writedata(0x0C);
  gr_writedata(0x00);

  gr_writecommand(gr_c_setAddressMode);
  gr_writedata(gr_MADCTL_ML);

  gr_writecommand(gr_c_setPixelFormat);
  gr_writedata(gr_param_pixelformat_16bpp);

  gr_writecommand(gr_c_setClumnAddress);
  gr_writedata(0x00);
  gr_writedata(0x00);
  gr_writedata(0x01);
  gr_writedata(0x3F);

  gr_writecommand(gr_c_setPageAddress);
  gr_writedata(0x00);
  gr_writedata(0x00);
  gr_writedata(0x01);
  gr_writedata(0xDF);

  _delay_ms(120);
  gr_writecommand(gr_c_setDisplayOn);
  _delay_ms(25);
}

void gr_drawPixel(uint16_t x, uint16_t y, uint16_t color)
{
  gr_h_CS_L;
  gr_h_RS_L;
  PORTC =  gr_c_setClumnAddress;
  gr_h_WR_STB;
  gr_h_RS_H;
  PORTC = x>>8;
  gr_h_WR_STB;
  PORTC = x;
  gr_h_WR_STB;
  PORTC = x>>8;
  gr_h_WR_STB;
  PORTC = x;
  gr_h_WR_STB;
  gr_h_RS_L;
  PORTC =  gr_c_setPageAddress;
  gr_h_WR_STB;
  gr_h_RS_H;
  PORTC = y>>8;
  gr_h_WR_STB;
  PORTC = y;
  gr_h_WR_STB;
  PORTC = y>>8;
  gr_h_WR_STB;
  PORTC = y;
  gr_h_WR_STB;
  gr_h_RS_L;
  PORTC = gr_c_WriteRam;
  gr_h_WR_STB;
  gr_h_RS_H;
  PORTC = color;
  PORTA = color>>8;
  gr_h_WR_STB;
}

uint16_t gr_getWidth(void)
{
  return  _width;
}

uint16_t gr_getHeight(void)
{
  return _height;
}

void gr_setRotation(uint8_t m)
{
  gr_writecommand(gr_c_setAddressMode);
  uint8_t rotation = m % 8;
  switch (rotation) {
   case 0: // Portrait
     gr_writedata(gr_MADCTL_BGR | gr_MADCTL_MX);
     _width  = gr_TFTWIDTH;
     _height = gr_TFTHEIGHT;
     break;
   case 1: // Landscape (Portrait + 90)
     gr_writedata(gr_MADCTL_BGR | gr_MADCTL_MV);
     _width  = gr_TFTHEIGHT;
     _height = gr_TFTWIDTH;
     break;
   case 2: // Inverter portrait
     gr_writedata(gr_MADCTL_BGR | gr_MADCTL_MY);
     _width  = gr_TFTWIDTH;
     _height = gr_TFTHEIGHT;
    break;
   case 3: // Inverted landscape
     gr_writedata(gr_MADCTL_BGR | gr_MADCTL_MV | gr_MADCTL_MX | gr_MADCTL_MY);
     _width  = gr_TFTHEIGHT;
     _height = gr_TFTWIDTH;
     break;
   case 4: // Portrait
     gr_writedata(gr_MADCTL_BGR | gr_MADCTL_MX | gr_MADCTL_MY);
     _width  = gr_TFTWIDTH;
     _height = gr_TFTHEIGHT;
     break;
   case 5: // Landscape (Portrait + 90)
     gr_writedata(gr_MADCTL_BGR | gr_MADCTL_MV | gr_MADCTL_MX);
     _width  = gr_TFTHEIGHT;
     _height = gr_TFTWIDTH;
     break;
   case 6: // Inverter portrait
     gr_writedata(gr_MADCTL_BGR);
     _width  = gr_TFTWIDTH;
     _height = gr_TFTHEIGHT;
     break;
   case 7: // Inverted landscape
     gr_writedata(gr_MADCTL_BGR | gr_MADCTL_MV | gr_MADCTL_MY);
     _width  = gr_TFTHEIGHT;
     _height = gr_TFTWIDTH;
     break;
  }
}
