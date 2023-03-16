#include <avr/io.h>
#include <util/delay.h>

int	main()
{
	DDRB |= (1 << PB0);//definir comme port sortant
	DDRD &= ~(1 << PD2);//definir le port ddrd comme port entrant
	while (1)
	{
		if (PIND & (1 << PD2)) 
			PORTB &= ~(1 << PB0);
		else
			PORTB |= (1 << PB0);
	}
	return (0);
}
