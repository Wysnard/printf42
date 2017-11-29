#include "printf.h"

int	ft_print_char(va_list *ap, t_file *file)
{
	size_t		i;

	i = 0;
	if (!ft_strchr(file->flags, '-') && file->nb)
		ft_putnchar(' ', (i = file->nb - 1), 1);
	ft_putchar(va_arg(*ap, int));
	if (ft_strchr(file->flags, '-') && file->nb)
		ft_putnchar(' ', (i = file->nb - 1), 1);
	file->ct += i + 1;
	return (file->ct);
}
