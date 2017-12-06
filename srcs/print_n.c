#include "printf.h"

int	ft_print_n(va_list *ap, t_file *file)
{
	int	*i;

	i = va_arg(*ap, int *);
	*i = file->ct;
	return (1);
}
