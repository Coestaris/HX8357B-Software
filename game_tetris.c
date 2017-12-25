#include "headers/game_tetris.h"

#include "headers/fonts/font_std.h"
#include "headers/timing.h"
#include "headers/uart.h"
#include "headers/graphics.h"

// ======== LOCAL VARS ==========

int16_t figX;
int16_t figY;
uint8_t color;
uint8_t type;
uint8_t rotate;
uint8_t map[24][16];
const uint16_t colors[18] = {
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
FONT_INFO font;

// ======== INIT PROCS ==========

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
  memset(map, 0, 24 * 16);
  UART_Init(MYUBRR_DEF);
  gr_text_setPos(0,0);
  font.bgColor = cl_BLACK;
  font.color = cl_WHITE;
}

// ======================================================
// METHOD: isCollide
// CHECKS IF FIGURE IS COLIDING WITH MAP AND APPLYS IT
// ======================================================
uint8_t isCollide(void)
{
  switch(type)
  {
    case 0:
    {
      switch(rotate)
      {
        case 0:
        case 1:
        case 2:
        case 3:
        {
          if(figX - 1 < 0)
          {
            apply();
            return 1;
          }

          if(map[figX - 1][figY] ||
             map[figX - 1][figY + 1])
          {
            apply();
            return 1;
          }
        }
      }
      return 0;
    }
    case 1:
    {
      switch (rotate)
      {
        case 0:
        case 3:
        {
          if(figX - 1 < 0)
          {
            apply();
            return 1;
          }

          if(map[figX - 1][figY])
          {
            apply();
            return 1;
          };

          return 0;
        };
        case 1:
        case 2:
        {
          if(figX - 1 < 0)
          {
            apply();
            return 1;
          }

          if(map[figX - 1][figY] ||
             map[figX - 1][figY + 1] ||
             map[figX - 1][figY + 2] ||
             map[figX - 1][figY + 3])
          {
            apply();
            return 1;
          };

          return 0;
        };
      }
    }
    case 2:
    {
      switch(rotate)
      {
        case 0:
        {
          if(figX - 1 < 0)
          {
            apply();
            return 1;
          }

          if(map[figX - 1][figY] ||
             map[figX][figY + 1])
          {
            apply();
            return 1;
           }

           return 0;
        }
        case 1:
        {
          if(figX - 2 < 0)
          {
            apply();
            return 1;
          }
          if(map[figX - 2][figY + 1] ||
             map[figX - 1][figY] ||
             map[figX - 1][figY + 2])
          {
            apply();
            return 1;
           }

           return 0;
        }
        case 2:
        {
          if(figX - 1 < 0)
          {
            apply();
            return 1;
          }

          if(map[figX - 1][figY] ||
             map[figX][figY - 1])
          {
            apply();
            return 1;
           }

          return 0;
        }
        case 3:
        {
          if(figX - 1 < 0)
          {
            apply();
            return 1;
          }

          if(map[figX - 1][figY] ||
             map[figX - 1][figY + 1] ||
             map[figX - 1][figY + 2])
          {
            apply();
            return 1;
          }

          return 0;
        }
      };
    }
    case 3:
    {
      switch(rotate)
      {
        case 0:
        {
          if(figX - 1 < 0)
          {
            apply();
            return 1;
          }

          if(map[figX - 1][figY] ||
             map[figX][figY + 1])
          {
            apply();
            return 1;
          }
          return 0;
        }
        case 1:
        {
          if(figX - 1 < 0)
          {
            apply();
            return 1;
          }

          if(map[figX - 1][figY + 1] ||
             map[figX - 1][figY + 2] ||
             map[figX][figY])
          {
            apply();
            return 1;
          }
          return 0;
        }
        case 2:
        {
          if(figX - 1 < 0)
          {
            apply();
            return 1;
          }

          if(map[figX][figY - 1] ||
             map[figX - 1][figY])
          {
            apply();
            return 1;
          }
          return 0;
        }
        case 3:
        {
          if(figX - 1 < 0)
          {
            apply();
            return 1;
          }

          if(map[figX - 1][figY] ||
             map[figX - 1][figY + 1] ||
             map[figX][figY + 2])
          {
            apply();
            return 1;
          }
        }
      }
    }
    case 4:
    {
      return 0;
    }
  }
}

// ======================================================
// METHOD: apply
// APPLYS FIGURE TO MAP
// ======================================================
void apply(void)
{
  switch(type)
  {
    case 0:
    {
      switch(rotate)
      {
        case 0:
        case 1:
        case 2:
        case 3:
        {
          map[figX][figY] = color;
          map[figX][figY + 1] = color;
          map[figX + 1][figY] = color;
          map[figX + 1][figY + 1] = color;
          return;
        }
      }
    }
    case 1:
    {
      switch (rotate)
      {
        case 0:
        case 3:
        {
          map[figX][figY] = color;
          map[figX + 1][figY] = color;
          map[figX + 2][figY] = color;
          map[figX + 3][figY] = color;
          return;
        };
        case 1:
        case 2:
        {
          map[figX][figY] = color;
          map[figX][figY + 1] = color;
          map[figX][figY + 2] = color;
          map[figX][figY + 3] = color;
          return;
        };
      }
    }
    case 2:
    {
      switch(rotate)
      {
        case 0:
        {
          map[figX][figY] = color;
          map[figX + 1][figY] = color;
          map[figX + 2][figY] = color;
          map[figX + 1][figY + 1] = color;
          return;
        }
        case 1:
        {
          map[figX][figY] = color;
          map[figX - 1][figY + 1] = color;
          map[figX][figY + 1] = color;
          map[figX][figY + 2] = color;
          return;
        }
        case 2:
        {
         map[figX][figY] = color;
         map[figX + 1][figY] = color;
         map[figX + 2][figY] = color;
         map[figX + 1][figY - 1] = color;
         return;
        }
        case 3:
        {
          map[figX][figY] = color;
          map[figX + 1][figY + 1] = color;
          map[figX][figY + 1] = color;
          map[figX][figY + 2] = color;
          return;
        }
      };
    }
    case 3:
    {
      switch(rotate)
      {
        case 0:
        {
          map[figX][figY] = color;
          map[figX + 1][figY] = color;
          map[figX + 1][figY + 1] = color;
          map[figX + 2][figY + 1] = color;
          return;
        }
        case 1:
        {
          map[figX][figY + 1] = color;
          map[figX][figY + 2] = color;
          map[figX + 1][figY] = color;
          map[figX + 1][figY + 1] = color;
          return;
        }
        case 2:
        {
          map[figX][figY] = color;
          map[figX + 1][figY] = color;
          map[figX + 1][figY - 1] = color;
          map[figX + 2][figY - 1] = color;
          return;
        }
        case 3:
        {
          map[figX][figY] = color;
          map[figX][figY + 1] = color;
          map[figX + 1][figY + 1] = color;
          map[figX + 1][figY + 2] = color;
          return;;
        }
      }
    }
  }
}

void ml(void)
{

}

void mr(void)
{

}

void draw(color_t color)
{
  switch(type)
  {
    case 0:
    {
      switch(rotate)
      {
        case 0:
        case 1:
        case 2:
        case 3:
        {
          gr_drawRect(figX * figW, figY * figH, figW * 2, figH * 2, color);
          return;
        }
      }
    }
    case 1:
    {
      switch (rotate)
      {
        case 0:
        case 3:
        {
          gr_drawRect(figX * figW, figY * figH, figW * 4, figH, color);
          return;
        };
        case 1:
        case 2:
        {
          gr_drawRect(figX * figW, figY * figH, figW, figH * 4, color);
          return;
        };
      }
    }
    case 2:
    {
      switch(rotate)
      {
        case 0:
        {
          gr_drawRect(figX * figW, figY * figH, figW * 3, figH, color);
          gr_drawRect((figX + 1) * figW, (figY + 1) * figH, figW, figH, color);
          return;
        }
        case 1:
        {
          gr_drawRect(figX * figW, figY * figH, figW, figH * 3, color);
          gr_drawRect((figX - 1) * figW, (figY + 1) * figH, figW, figH, color);
          return;
        }
        case 2:
        {
          gr_drawRect(figX * figW, figY * figH, figW * 3, figH, color);
          gr_drawRect((figX + 1) * figW, (figY - 1) * figH, figW, figH, color);
          return;
        }
        case 3:
        {
          gr_drawRect(figX * figW, figY * figH, figW, figH * 3, color);
          gr_drawRect((figX + 1) * figW, (figY + 1) * figH, figW, figH, color);
          return;
        }
      };
    }
    case 3:
    {
      switch(rotate)
      {
        case 0:
        {
          gr_drawRect(figX * figW, figY * figH, figW * 2, figH, color);
          gr_drawRect((figX + 1) * figW, (figY + 1) * figH, figW * 2, figH, color);
          return;
        }
        case 1:
        {
          gr_drawRect(figX * figW, (figY + 1) * figH, figW, figH * 2, color);
          gr_drawRect((figX  + 1) * figW, (figY) * figH, figW, figH * 2, color);
          return;
        }
        case 2:
        {
          gr_drawRect(figX * figW,       figY * figH,       figW * 2, figH, color);
          gr_drawRect((figX + 1) * figW, (figY - 1) * figH, figW * 2, figH, color);
          return;
        }
        case 3:
        {
          gr_drawRect(figX * figW, figY * figH, figW, figH * 2, color);
          gr_drawRect((figX + 1) * figW, (figY + 1) * figH, figW, figH * 2, color);
          return;
        }
      };
    }
    case 4:
    {
      switch(rotate)
      {
        case 0:
        {
          gr_drawRect(figX * figW, figY * figH, figW * 3, figH, color);
          gr_drawRect((figX + 2) * figW, (figY + 1) * figH, figW, figH, color);
          return;
        }
        case 1:
        {
          gr_drawRect((figX + 1) * figW, figY * figH, figW, figH * 3, color);
          gr_drawRect(figX * figW, (figY + 2) * figH, figW, figH, color);
          return;
        }
        case 2:
        {
          gr_drawRect(figX * figW, figY * figH, figW * 3, figH, color);
          gr_drawRect(figX * figW, (figY - 1) * figH, figW, figH, color);
          return;
        }
        case 3:
        {
          gr_drawRect(figX * figW, figY * figH, figW, figH * 3, color);
          gr_drawRect((figX + 1) * figW, figY * figH, figW, figH, color);
          return;
        }
      };
    }
  }
}

void rot(uint8_t r)
{

}

// ======================================================
// METHOD: game_routine
// MAIN GAME ROUTINE OF GAME
// ======================================================
void game_routine(void)
{
  initGame();
  goto settingGame;

endgame: ;
  _delay_ms(1000);

settingGame:;
  gr_fill(cl_BLACK);
  gr_text_setPos(10, 60);
  uint32_t last = 0;
newFig:;
  figX = 20;
  figY = random() % 13 + 1;
  color = random() % 16 + 1;
  //type = random() % 3;
  type = 3;
  rotate = 3;

  while(1)
  {
    uint32_t m1 = millis();
    //TRIGERING PLAYER`S INPUT
    if(P1_L)
    {
      if(P1_R)
        goto redrawMap;
      ml();
    }
    if(P1_R)
    {
      mr();
    }

    //PROCEEDING BLOCKS
    uint32_t m1_1 = millis();
    if(m1_1 - last >= blockSpeed)
    {
      last = m1_1;
        draw(cl_BLACK);
      if(isCollide())
        goto redrawMap;
      else
      {
        figX--;
        draw(cl_RED);
      }
    }
    goto timing;

    //DRAWING MAP
    redrawMap:
    for(uint8_t i = 0; i < 24; i++)
      for(uint8_t bit = 0; bit < 16; bit++)
        if(map[i][bit])
        {
          gr_fillRect(i * figW, bit * figH, figW, figH, colors[map[i][bit]]);
          gr_drawRect(i * figW, bit * figH, figW, figH, cl_BLACK);
        }
    goto newFig;

    //SAVING CONSTANT DELAY BETWEEN FRAMES
    timing:;
    uint32_t m2 = millis();
    int32_t newDelay = betweenFrameDelay - m2 + m1;
    if(newDelay == 0)
      continue;
    delay_ms(newDelay < 0 ? - newDelay : newDelay);
  }
}
