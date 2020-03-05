#include "main.h"
//--------------------------------------------------
int main(void)
{
	USART_Init();//Baud Rate:115200;
	net_ini();
	sei();
	while (1)
	{
		net_pool();
	}
}
//--------------------------------------------------
// USART_Transmit(65);
// _delay_ms(1000);