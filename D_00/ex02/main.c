#include <avr/io.h>
#include <stdint.h>

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
	DDRB |= (1 << PB0);
	while (1)
	{
		PORTB |= (1 << PB0);
		ft_delay(1000);
		PORTB &= ~(1 << PB0);
		ft_delay(1000);
	}
	return (0);
}
