#include <avr/io.h>

int	main()
{
	//open the port 
	DDRB |= (1 << PB1);
	// set the mode : mode fast PWM
	// configurer le waveform generation mode en fast pwm -> wgwn01 = 1 wgm00 == 1	
	TCCR1A |= (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);
	TCCR1B |= (1 << CS12);
	ICR1 = 15624;

		
	while (1)
		;
}
