#include "avr/io.h"

#include "headers/timing.h"
#include "headers/uart.h"
#include "headers/graphics.h"

#include "headers/fonts/font_std.h"

FONT_INFO font;

void initGr(void)
{
  gr_init();
  gr_setRotation(1);
  gr_fill(cl_BLACK);
}

void initGame(void)
{
  font = font_std();
  initTimer();
  initGr();
  DDRH = 0;
  gr_text_setPos(0,0);
  font.bgColor = cl_BLACK;
  font.color = cl_WHITE;
}

#define P1_L bitw_bit(PINH, 5)
#define P1_R bitw_bit(PINH, 6)
#define P2_L bitw_bit(PINH, 4)
#define P2_R bitw_bit(PINH, 3)
#define betweenFrameDelay 10

#define blockSpeed 50

int main(void)
{
  initGame();
  goto settinggame;

endgame: ;
  _delay_ms(1000);

settinggame:;
  gr_fill(cl_BLACK);
  int16_t figW = 20;
  int16_t figH = 20;
  gr_text_setPos(10, 60);
  UART_Init(MYUBRR_DEF);
  uint8_t map[24][16];
  memset(map, 0, 24 * 16);
  color_t colors[18] = {
    cl_NAVY,
    cl_DARKGREEN,
    cl_DARKCYAN,
    cl_MAROON,
    cl_PURPLE,
    cl_OLIVE,
    cl_LIGHTGREY,
    cl_DARKGREY,
    cl_BLUE,
    cl_GREEN,
    cl_CYAN,
    cl_RED,
    cl_MAGENTA,
    cl_YELLOW,
    cl_WHITE,
    cl_ORANGE,
    cl_GREENYELLOW,
    cl_PINK
  };

  uint32_t last = 0;

  newFig:;
  int16_t figX = 20;
  int16_t figY = random() % 13 + 1;
  uint8_t color = random() % 16 + 1;
  uint8_t type = random() % 3;
  uint8_t rotate = random() % 4;

  //rotate = 3;
  //type = 2;

  while (1) {
      uint32_t m1 = millis();
      //Player 1 triggers

      if(P1_L)
      {
        uint32_t m1_2 = millis();
        last = m1_2;
        if(P1_R)
          goto timing;
        if(figY > 0)
        {
          if(type == 0)
          {
            gr_drawRect(figX * figW, figY * figH, figW * 2, figH * 2, cl_BLACK);
            figY--;
            gr_drawRect(figX * figW, figY * figH, figW * 2, figH * 2, cl_RED);
            _delay_ms(50);
          } else
          if(type == 1)
          {
            switch (rotate) {
              case 0:
              case 3:
              {
                gr_drawRect(figX * figW, figY * figH, figW * 4, figH, cl_BLACK);
                figY--;
                gr_drawRect(figX * figW, figY * figH, figW * 4, figH, cl_RED);
                _delay_ms(50);
                break;
              }
              case 1:
              case 2:
              {
                gr_drawRect(figX * figW, figY * figH, figW, figH * 4, cl_BLACK);
                figY--;
                gr_drawRect(figX * figW, figY * figH, figW, figH * 4, cl_RED);
                _delay_ms(50);
                break;
              }
            }
          }
        }
      }
      if(P1_R)
      {
        uint32_t m1_2 = millis();
        last = m1_2;
        if(type == 0)
        {
          if(figY < 14)
          {
            gr_drawRect(figX * figW, figY * figH, figW * 2, figH * 2, cl_BLACK);
            figY++;
            gr_drawRect(figX * figW, figY * figH, figW * 2, figH * 2, cl_RED);
            _delay_ms(50);
          }
        } else
        if(type == 1)
        {
          switch (rotate) {
            case 0:
            case 3:
            {
              if(figY < 15) {
                gr_drawRect(figX * figW, figY * figH, figW * 4, figH, cl_BLACK);
                figY++;
                gr_drawRect(figX * figW, figY * figH, figW * 4, figH, cl_RED);
                _delay_ms(50);
              }
              break;
            }
            case 1:
            case 2:
            {
              if(figY < 12) {
                gr_drawRect(figX * figW, figY * figH, figW, figH * 4, cl_BLACK);
                figY++;
                gr_drawRect(figX * figW, figY * figH, figW, figH * 4, cl_RED);
              }
              _delay_ms(50);
              break;
            }
          }
        }
      }

      uint32_t m1_1 = millis();
      if(m1_1 - last >= blockSpeed)
      {
        last = m1_1;
        if(type == 0)
        {
          gr_drawRect(figX * figW, figY * figH, figW * 2, figH * 2, cl_BLACK);

          if(figX - 1 < 0)
          {
              map[figX][figY] = color;
              map[figX][figY + 1] = color;
              map[figX + 1][figY] = color;
              map[figX + 1][figY + 1] = color;
              goto redrawMap;
          }

          if(map[figX - 1][figY] ||
             map[figX - 1][figY + 1])
          {
            map[figX][figY] = color;
            map[figX][figY + 1] = color;
            map[figX + 1][figY] = color;
            map[figX + 1][figY + 1] = color;
            goto redrawMap;
          }

          figX-= 1;
          gr_drawRect(figX * figW, figY * figH, figW * 2, figH * 2, cl_RED);
        } else
        if(type == 1)
        {
          switch (rotate)
          {
            case 0:
            case 3:
            {
              gr_drawRect(figX * figW, figY * figH, figW * 4, figH, cl_BLACK);
              if(figX - 1 < 0)
              {
                map[figX][figY] = color;
                map[figX + 1][figY] = color;
                map[figX + 2][figY] = color;
                map[figX + 3][figY] = color;
                goto redrawMap;
              }

              if(map[figX - 1][figY])
              {
                map[figX][figY] = color;
                map[figX + 1][figY] = color;
                map[figX + 2][figY] = color;
                map[figX + 3][figY] = color;
                goto redrawMap;
              }
              figX-= 1;
              gr_drawRect(figX * figW, figY * figH, figW * 4, figH, cl_RED);
              break;
            };
            case 1:
            case 2:
            {
              gr_drawRect(figX * figW, figY * figH, figW, figH * 4, cl_BLACK);
              if(figX - 1 < 0)
              {
                map[figX][figY] = color;
                map[figX][figY + 1] = color;
                map[figX][figY + 2] = color;
                map[figX][figY + 3] = color;
                goto redrawMap;
              }

              if(map[figX - 1][figY] ||
                 map[figX - 1][figY + 1] ||
                 map[figX - 1][figY + 2] ||
                 map[figX - 1][figY + 3])
              {
                map[figX][figY] = color;
                map[figX][figY + 1] = color;
                map[figX][figY + 2] = color;
                map[figX][figY + 3] = color;
                goto redrawMap;
              }
              figX-= 1;
              gr_drawRect(figX * figW, figY * figH, figW, figH * 4, cl_RED);
              break;
            };
          }
        }
        if(type == 2)
        {
          switch (rotate)
          {
            case 0:
            {
              gr_drawRect(figX * figW, figY * figH, figW * 3, figH, cl_BLACK);
              gr_drawRect((figX + 1) * figW, (figY + 1) * figH, figW, figH, cl_BLACK);

              if(figX - 1 < 0)
              {
                map[figX][figY] = color;
                map[figX + 1][figY] = color;
                map[figX + 2][figY] = color;
                map[figX + 1][figY + 1] = color;
                goto redrawMap;
              }

              if(map[figX - 1][figY] ||
                 map[figX][figY + 1])
              {
                 map[figX][figY] = color;
                 map[figX + 1][figY] = color;
                 map[figX + 2][figY] = color;
                 map[figX + 1][figY + 1] = color;
                 goto redrawMap;
               }

              figX-= 1;
              gr_drawRect(figX * figW, figY * figH, figW * 3, figH, cl_RED);
              gr_drawRect((figX + 1) * figW, (figY + 1) * figH, figW, figH, cl_RED);
              break;
            }
            case 1:
            {
              gr_drawRect(figX * figW, figY * figH, figW, figH * 3, cl_BLACK);
              gr_drawRect((figX - 1) * figW, (figY + 1) * figH, figW, figH, cl_BLACK);
              if(figX - 2 < 0)
              {
                map[figX][figY] = color;
                map[figX - 1][figY + 1] = color;
                map[figX][figY + 1] = color;
                map[figX][figY + 2] = color;
                goto redrawMap;
              }
              if(map[figX - 2][figY + 1] ||
                 map[figX - 1][figY] ||
                 map[figX - 1][figY + 2])
              {
                map[figX][figY] = color;
                map[figX - 1][figY + 1] = color;
                map[figX][figY + 1] = color;
                map[figX][figY + 2] = color;
                goto redrawMap;
               }
              figX-= 1;
              gr_drawRect(figX * figW, figY * figH, figW, figH * 3, cl_RED);
              gr_drawRect((figX - 1) * figW, (figY + 1) * figH, figW, figH, cl_RED);
              break;
            }
            case 2:
            {
              gr_drawRect(figX * figW, figY * figH, figW * 3, figH, cl_BLACK);
              gr_drawRect((figX + 1) * figW, (figY - 1) * figH, figW, figH, cl_BLACK);

              if(figX - 1 < 0)
              {
                map[figX][figY] = color;
                map[figX + 1][figY] = color;
                map[figX + 2][figY] = color;
                map[figX + 1][figY - 1] = color;
                goto redrawMap;
              }

              if(map[figX - 1][figY] ||
                 map[figX][figY - 1])
              {
                 map[figX][figY] = color;
                 map[figX + 1][figY] = color;
                 map[figX + 2][figY] = color;
                 map[figX + 1][figY - 1] = color;
                 goto redrawMap;
               }

              figX-= 1;
              gr_drawRect(figX * figW, figY * figH, figW * 3, figH, cl_RED);
              gr_drawRect((figX + 1) * figW, (figY - 1) * figH, figW, figH, cl_RED);
              break;
            }
            case 3:
            {
              gr_drawRect(figX * figW, figY * figH, figW, figH * 3, cl_BLACK);
              gr_drawRect((figX + 1) * figW, (figY + 1) * figH, figW, figH, cl_BLACK);
              if(figX - 1 < 0)
              {
                map[figX][figY] = color;
                map[figX + 1][figY + 1] = color;
                map[figX][figY + 1] = color;
                map[figX][figY + 2] = color;
                goto redrawMap;
              }
              if(map[figX - 1][figY] ||
                 map[figX - 1][figY + 1] ||
                 map[figX - 1][figY + 2])
              {
                map[figX][figY] = color;
                map[figX + 1][figY + 1] = color;
                map[figX][figY + 1] = color;
                map[figX][figY + 2] = color;
                goto redrawMap;
               }
              figX-= 1;
              gr_drawRect(figX * figW, figY * figH, figW, figH * 3, cl_RED);
              gr_drawRect((figX + 1) * figW, (figY + 1) * figH, figW, figH, cl_RED);
              break;
            }
          };
        }
      }

      goto timing;

      redrawMap:
      for(uint8_t i = 0; i < 24; i++)
      {
        for(uint8_t bit = 0; bit < 16; bit++)
        {
          if(map[i][bit])
          {
            gr_fillRect(i * figW, bit * figH, figW, figH, colors[map[i][bit]]);
            gr_drawRect(i * figW, bit * figH, figW, figH, cl_BLACK);
          }
        }
      }
      goto newFig;

      timing:;
      uint32_t m2 = millis();
      int32_t newDelay = betweenFrameDelay - m2 + m1;
      if(newDelay == 0)
        continue;
      delay_ms(newDelay < 0 ? - newDelay : newDelay);
  }
}
