#include "includes/libft.h"
#include <stdio.h>

int	main()
{
	ft_putnbr(ft_printf("%+20d|\n", 'b'));
	ft_putchar('\n');
	ft_putnbr(printf("%+20d|\n", 'b'));
	ft_putchar('\n');
	return (0);
}
