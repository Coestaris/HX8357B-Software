#include "headers/uart.h"

void UART_Init(uint8_t ubrr)
{
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    UCSR0C = (1<<USBS0)|(3<<UCSZ00); //Data 8 bits, 0 stop
}

void UART_PrintChar(uint8_t c)
{
  UART_Transmit(c);
}

void UART_PrintlnChar(uint8_t c)
{
  UART_Transmit(c);
  UART_Transmit('\n');
}

void UART_Print(uint8_t * data)
{
  UART_TransmitString(data);
}
void UART_Println(uint8_t * data)
{
  UART_TransmitString(data);
  UART_Transmit('\n');
}

uint8_t UART_Receive(void)
{
  while (!(UCSR0A & (1<<RXC0)));
  return UDR0;
}

void UART_Transmit(uint8_t data)
{
  while (!( UCSR0A & (1<<UDRE0)));
  UDR0 = data;
}

uint8_t UART_ReceiveBlock(uint8_t * scr, uint16_t blockLen, uint32_t delayMillis)
{
  for (uint16_t i = 0; i < blockLen; i++)
  {
    while (!(UCSR0A & (1<<RXC0)))
      if(delayMillis--)
        _delay_ms(1);
      else return i;
    *scr++ = UDR0;
  }
  return 0;
}

uint8_t UART_ReceiveSync(uint32_t delayMillis, uint8_t * result)
{
  while (!(UCSR0A & (1<<RXC0)))
    if(delayMillis--)
    _delay_ms(1);
  else
  {
    *result = 1;
    return 0;
  }
  return UDR0;
}

void UART_TransmitString(uint8_t * data)
{
  unsigned char d;
  while(*data)
  {
      d = *data++;
      UART_Transmit(d);
  }
}
