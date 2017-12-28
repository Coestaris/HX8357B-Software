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

#define P1_L bitw_bit(PINH, 5)
#define P1_R bitw_bit(PINH, 6)
#define P2_L bitw_bit(PINH, 4)
#define P2_R bitw_bit(PINH, 3)

#define betweenFrameDelay 10

#define PLDX 2
#define Height 90
#define Width 30
#define Y1 10
#define Y2 440
#define MinX 1
#define MaxX 230

int main(void)
{
  font = font_std();
  initTimer();
  initGr();
  DDRH = 0;
  uint8_t p1Score = 0;
  uint8_t p2Score = 0;
  goto settinggame;

endgame: ;
  _delay_ms(2000);

settinggame:;
  gr_fill(cl_BLACK);
  uint16_t x1 = gr_TFTWIDTH / 2 - Height / 2;
  uint16_t x2 = gr_TFTWIDTH / 2 - Height / 2;

  int16_t ballX = gr_TFTHEIGHT / 2;
  int16_t ballY = gr_TFTWIDTH / 2;

  int8_t sign = random() % 2;
  int16_t dx = sign ? random() % 2 + 1 : -(random() % 2 + 1);
  sign = random() % 2;
  int16_t dy = sign ? random() % 2 + 1 : -(random() % 2 + 1);

  gr_text_setPos(0,0);
  font.bgColor = cl_BLACK;
  font.color = cl_WHITE;

  uint8_t last = 0;

  gr_fillRect(x1, Y1, Width, Height, cl_WHITE);
  gr_fillRect(x2, Y2, Width, Height, cl_WHITE);

  while (1) {
      uint32_t m1 = millis();
      //Player 1 triggers
      if(P1_L) if(x1 > MinX) {
        if(P1_R) goto player2;
        gr_fillRect(x1, Y1, Width, Height, cl_BLACK);
        x1-=PLDX;
        gr_fillRect(x1, Y1, Width, Height, cl_WHITE);
      }
      if(P1_R) if(x1 < MaxX)
      {
        gr_fillRect(x1, Y1, Width, Height, cl_BLACK);
        x1+=PLDX;
        gr_fillRect(x1, Y1, Width, Height, cl_WHITE);
      }

      player2:
      //Player 2 triggers
      if(P2_L) if(x2 > MinX) {
        if(P2_R) goto ballrender;
        gr_fillRect(x2, Y2, Width, Height, cl_BLACK);
        x2-=PLDX;
        gr_fillRect(x2, Y2, Width, Height, cl_WHITE);
      }
      if(P2_R) if(x2 < MaxX)
      {
        gr_fillRect(x2, Y2, Width, Height, cl_BLACK);
        x2+=PLDX;
        gr_fillRect(x2, Y2, Width, Height, cl_WHITE);
      }

      ballrender:
      if(ballX <= Y1 + Width)
      {
        if(x1 < ballY && x1 + Height > ballY) //In border
          dx = - dx;
        else {
          p2Score++;
          gr_text_setPos(0, 0);
          gr_text_printStr(font, "Player 2 Wins\nrestarting in 2s");
          goto endgame;
        }
      };

      if(ballX >= Y2)
      {
        if(x2 < ballY && x2 + Height > ballY) //In border
          dx = - dx;
        else {
          gr_text_setPos(0, 0);
          gr_text_printStr(font, "Player 1 Wins\nrestarting in 2s");
          p1Score++;
          goto endgame;
        }
      }

      if(ballY >= gr_TFTWIDTH - 4 || ballY <= 0)
        dy =- dy;

      gr_drawCircle(ballX, ballY, 2, cl_BLACK);

      ballX += dx;
      ballY += dy;

      gr_drawCircle(ballX, ballY, 2, cl_WHITE);
      gr_line(gr_TFTHEIGHT / 2, 0, gr_TFTHEIGHT / 2, gr_TFTWIDTH, cl_WHITE);
      gr_text_setPos(gr_TFTHEIGHT / 2 - font.maxXSize - 1, 0);
      gr_text_printChar(font, 48 + p1Score);
      gr_text_setPos(gr_TFTHEIGHT / 2 + 2, 0);
      gr_text_printChar(font, 48 + p2Score);

      uint32_t m2 = millis();

      if(m2 / 2000 - last)
      {
        last = m2 / 2000;
        if(dx < 0) dx--;
        else dx++;

        if(dy < 0) dy--;
        dy++;
      }
      delay_ms((uint32_t)abs(betweenFrameDelay - m2 + m1));
  }
}
