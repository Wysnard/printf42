#include "includes/libft.h"
#include <stdio.h>

int	main()
{
	ft_putnbr(ft_printf("%030.20o|\n", 1002));
	ft_putchar('\n');
	ft_putnbr(printf("%030.20o|\n", 1002));
	ft_putchar('\n');
	return (0);
}
