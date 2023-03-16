#include <avr/io.h>

int	main()
{
	//open the port 
	DDRB |= (1 << PB1);
	// set the mode : mode fast PWM
	TCCR1A |= (1 << COM1A0);
	//configurer le prescaler sur 1024
	TCCR1B |= (1 << CS12);
	//TCCR1B &= ~(1 << CS11);
	//TCCR1B |= (1 << CS10);
//configurer l'overflow pour qu'il ait lieu a 1Hz = (16,000,000 / 1024) - 1
	ICR1 = 15624;
//configurer le rapport cyclique sur 50%
//	OCR1A = ICR1 / 2;
	while (1)
		;
}
