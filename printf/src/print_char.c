#include "printf.h"

int	ft_print_char(va_list *ap, t_file *file)
{
	(void)ap;
	(void)file;
	ft_putchar(va_arg(*ap, int));
	file->ct++;
	return (1);
}
