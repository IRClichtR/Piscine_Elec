#include "avr/io.h"

int	main()
{

	DDRB |= (1 << PB0); //Set PB0 as an output force the value 1 on the left bit
	while (1)// use an infinite loop to continuously light the LED
		PORTB |= (1 << PB0);
	return (0);
}
