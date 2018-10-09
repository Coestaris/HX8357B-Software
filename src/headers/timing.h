#ifndef _timing_h_
#define _timing_h_

#include <string.h>
#include <stdlib.h>

#include "avr/interrupt.h"
#include "util/delay.h"
#include "util/atomic.h"

#define CTC_MATCH_OVERFLOW ((F_CPU / 1000UL) / 8UL)

char chars[10];
uint32_t m1, m2;
volatile uint32_t timer1_millis;

ISR (TIMER1_COMPA_vect)
{
   timer1_millis++;
}

uint32_t millis(void)
{
   uint32_t millis_return;
   ATOMIC_BLOCK(ATOMIC_FORCEON) {
       millis_return = timer1_millis;
   }
   return millis_return;
}

void initTimer(void)
{
  TCCR1B |= (1 << WGM12) | (1 << CS11);
  OCR1AH = ((uint8_t)CTC_MATCH_OVERFLOW >> 8);
  OCR1AL = (uint8_t)CTC_MATCH_OVERFLOW;
  TIMSK1 |= (1 << OCIE1A);
  sei();
}

void delay_ms(uint32_t period)
{
    do
    {
      if(period > 50)
      {
        period-=50;
        _delay_ms(50);
        continue;
      }

      period--;
      _delay_ms(1);
    } 
    while(period);
}

void timing_mark(void)
{
  m1 = millis();
}

void timing_markSecond(void)
{
  m2 = millis();
}

char * timing_marksDelta_str(void)
{
  memset(chars, 0, 10);
  itoa((int)(m2 - m1), chars, 10);
  return chars;
}

uint32_t timing_marksDelta(void)
{
  return m2 - m1;
}

uint32_t timing_delta(void)
{
  return millis() - m1;
}

char * timing_delta_str(void)
{
  memset(chars, 0, 10);
  uint32_t delta = millis() - m1;
  itoa((int)delta, chars, 10);
  return chars;
}

#endif
