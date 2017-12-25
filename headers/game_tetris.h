#ifndef _game_tetris_h_
#define _game_tetris_h_

#include "avr/io.h"

uint8_t isCollide(void);
void draw(uint16_t color);
void apply(void);
void ml(void);
void mr(void);
void rot(uint8_t r);

void game_routine(void);

void initGame(void);
void initGr(void);

#define P1_L bitw_bit(PINH, 5)
#define P1_R bitw_bit(PINH, 6)
#define P2_L bitw_bit(PINH, 4)
#define P2_R bitw_bit(PINH, 3)
#define betweenFrameDelay 10
#define blockSpeed 60
#define figW 20
#define figH 20

#endif

// ======== FIGURES =========

//1 - 0 0
//    0 0

//2 - 0 0 0 0

//3 - 0 0 0
//      0

//4 - 0 0
//      0 0

//5 - 0 0 0
//        0
