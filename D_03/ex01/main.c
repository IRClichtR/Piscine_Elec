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

void	timer_setup()
{
	TCCR1A |= (1 << CS12);
	ICR1 = 15624;
	OCR1A = ICR1 * 2;
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
	char	*str;
	int		i;

	timer_setup();
	uart_init();
	str = "Coucou Caroline et Helene !\n";
	i = 0;
	while (str[i])
	{
		uart_tx(str[i]);
		i++;
	}
	while (1)
	{
	}
}

