#include "usart.h"
//---------------------------------------------------------------
void USART_Init()
{
	// USART initialization
	// Communication Parameters: 8 Data, 1 Stop, No Parity
	// USART Receiver: On
	// USART Transmitter: On
	// USART Mode: Asynchronous
	// USART Baud Rate: 115200
	UBRRH=0x00;
	UBRRL=0x08;//Baud 115200
	UCSRB=(1<<RXCIE) | (1<<RXEN) | (1<<TXEN);// Enable USART reception and transmission, Allow Transmission Interrupt
	UCSRC=(1<<URSEL) |(1<<UCSZ1) | (1<<UCSZ0);
	// 	UCSRA | = (1 << U2X ); // For 8 MHz
	// 	We turn to the register UCSRC (URSEL = 1),
	// 	asynchronous mode (UMSEL = 0), without parity (UPM1 = 0 and UPM0 = 0),
	// 	1 stop bit (USBS = 0), 8-bit package (UCSZ1 = 1 and UCSZ0 = 1)
	// 	UCSRC | = (1 << UPM1); // parity
}
//---------------------------------------------------------------
void USART_Transmit( unsigned char data )
{
	while (!(UCSRA & (1<<UDRE)));//Wait until data is sent
	UDR = data;//Sent Data
}
//----------------------------------------
void  USART_TX (uint8_t *str1, uint8_t cnt)
{
	uint8_t i;
	for(i=0;i<cnt;i++)
	USART_Transmit(str1[i]);
}
//----------------------------------------