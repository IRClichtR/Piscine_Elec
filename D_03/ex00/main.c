#include <avr/io.h>
//set uart to 115200
#define BAUD 115200
//baudrate = apply formula
#define UBRR_VAL ((F_CPU/8/BAUD) - 1) / 2 

void	uart_init()
{
	
//set high and low value
// high value 
	UBRR0H = (uint8_t)(UBRR_VAL << 8); 
// set low value
	UBRR0L =(uint8_t)(UBRR_VAL);
//enable the transmitter and receiver
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
// set data format
}

void	uart_tx(char c)
{
	// wait condition == wait for the buffer to be empty for the info to be transmitted
	while (!(UCSR0A & (1 << UDRE0)))
		;
	UDR0 = c;
}

int	main()
{
	uart_init();
	uart_tx('Z');
	while (1)
	{
	}
}
