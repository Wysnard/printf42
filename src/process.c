#include "printf.h"

void	ft_conversion(char **start, t_file *file, va_list *ap)
{
	if (**start == 'c')
		ft_print_char(ap, file);
	else if (**start == 's')
		ft_print_str(ap, file);
	else if (**start == 'd' || **start == 'i')
		ft_print_int(ap, file);
	else if (**start == 'u')
		ft_print_unsigned(ap, file);
	else if (**start == 'x')
		ft_print_hexa(ap, file);
	else if (**start == 'X')
		ft_print_Hexa(ap, file);
	else if (**start == 'o')
		ft_print_octal(ap, file);
	(*start)++;
}

int	ft_process(char **start, t_file *file, va_list *ap)
{
	ft_init_flags(file);
	ft_flags(start, file);
	ft_conversion(start, file, ap);
	return (1);
}
