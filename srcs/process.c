#include "printf.h"
#include <stdio.h>

void	ft_conversion(char **start, t_file *file, va_list *ap)
{
	if (ft_isupper(**start) && **start != 'X')
		file->convert = l;
	if (**start == 'c' || **start == 'C')
		ft_print_char(ap, file);
	else if (**start == 's' || **start == 'S')
		(file->convert == l) ?
		ft_print_wstr(ap, file) : ft_print_str(ap, file);
	else if (**start == 'd' || **start == 'i' || **start == 'D')
		ft_print_int(ap, file);
	else if (**start == 'u' || **start == 'U')
		ft_print_unsigned(ap, file);
	else if (**start == 'x')
		ft_print_hexa(ap, file);
	else if (**start == 'X')
		ft_print_Hexa(ap, file);
	else if (**start == 'o' || **start == 'O')
		ft_print_octal(ap, file);
	else if (**start == 'p')
		ft_print_pointer(ap, file);
	else if (**start == 'b')
		ft_print_b(ap, file);
	else if (**start == '%')
		ft_print_perc(ap, file);
	else
		return ;
	(*start)++;
}

int	ft_process(char **start, t_file *file, va_list *ap)
{
	if (**start == '\0')
		return (0);
	ft_init_flags(file);
	// printf("point de depart = %s|\n", *start);
	ft_flags(start, file);
	// printf("Arrivee = %c|\n", **start);
	ft_conversion(start, file, ap);
	// printf("Print = %c|\n", **start);
	return (1);
}
