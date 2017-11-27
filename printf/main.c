#include "includes/libft.h"
#include <stdio.h>

int	main()
{
	ft_putnbr(ft_printf("%-20.10d|\n", 0));
	ft_putchar('\n');
	ft_putnbr(printf("%-20.10s|\n", "lol les amis potos\n"));
	ft_putchar('\n');
	return (0);
}
