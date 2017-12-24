#ifndef _timing_h_
#define _timing_h_

#include "avr/interrupt.h"
#include "util/delay.h"
#include "util/atomic.h"

#define CTC_MATCH_OVERFLOW ((F_CPU / 1000) / 8)

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
  OCR1AH = (CTC_MATCH_OVERFLOW >> 8);
  OCR1AL = CTC_MATCH_OVERFLOW;
  TIMSK1 |= (1 << OCIE1A);
  sei();
}

void delay_ms(uint32_t period)
{
    do
    {
        _delay_ms(1); //only takes constants
    } while(--period);
}

#endif
