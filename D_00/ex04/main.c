#include <avr/io.h>
#include <util/delay.h>

void	ft_delay(uint16_t millsec)
{
	uint32_t	i;
	uint32_t	j;

	for (i = 0 ; i < millsec ; i++)
	{
		for (j = 0 ; j < millsec / 2 ; j++)
			asm ("nop");
	}
}

int	main()
{
	DDRB |= (1 << PB0);//definir comme port sortant
	DDRD &= ~(1 << PD2);//definir le port ddrd comme port entrant
	while (1)
	{
		ft_delay(100);
		if (PIND & (1 << PD2))//si j'appuie sur le bouton
		{
			if (PORTB & (1 << PB0))
				PORTB &= ~(1 << PB0);
			else if (PORTB | 0 << PB0 == 0)
				PORTB |= (1 << PB0);
			while (!(PIND & (1 << PD2)))
				asm ("nop");
		}
	}
	return (0);
}
