#include "printf.h"

int	ft_print_char(va_list *ap, t_file *file)
{
	char	flags[10];
	int		i;

	i = 0;
	ft_strcpy(flags, "#0-+ ");
	if (!ft_strchr(flags, '-'))
		while (i < file->nb)
			i++;
	ft_putchar(va_arg(*ap, int));
	file->ct++;
	return (file->ct);
}
