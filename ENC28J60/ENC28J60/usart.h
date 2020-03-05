#ifndef USART_H_
#define USART_H_
#include "main.h"
void USART_Init();
void USART_Transmit( unsigned char data );
void  USART_TX (uint8_t *str1, uint8_t cnt);
#endif /* USART_H_ */