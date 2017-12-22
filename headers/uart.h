#ifndef _uart_h_
#define _uart_h_

#include <avr/io.h>
#include <util/delay.h>

#define MYUBRR(x) F_CPU/16/x-1

#define MYUBRR_DEF MYUBRR(9600)

#define UART_ArrayLen 10

void UART_PrintChar(uint8_t c);
void UART_PrintlnChar(uint8_t c);
//void UART_PrintInt(int32_t c);
//void UART_PrintlnInt(int32_t c);
void UART_Print(uint8_t * data);
void UART_Println(uint8_t * data);

#define UART_PrintInt(c)\
{\
  uint8_t arr[20];\
  itoa(c, arr, 10);\
  UART_TransmitString(arr);\
}

#define UART_PrintlnInt(c) \
{\
  uint8_t arr[20];\
  itoa(c, arr, 10);\
  UART_TransmitString(arr);\
  UART_Transmit('\n');\
}

uint8_t UART_ReceiveBlock(uint8_t * scr, uint16_t blockLen, uint32_t delayMillis);
uint8_t UART_ReceiveSync(uint32_t delayMillis, uint8_t * result);

//base
void UART_Init(uint8_t ubrr);
uint8_t UART_Receive(void);
void UART_Transmit(uint8_t data);
void UART_TransmitString(uint8_t * data);

#endif
