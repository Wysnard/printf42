#include "includes/libft.h"
#include <stdio.h>

int	main()
{
	ft_putnbr(ft_printf("%#10X|\n", 12));
	ft_putchar('\n');
	ft_putnbr(printf("%#10X|\n", 12));
	ft_putchar('\n');
	return (0);
}
