#include "printf.h"

int	ft_print_unsigned(va_list *ap, t_file *file)
{
	char	*str;
	intmax_t	i;

	str = ft_utoa(va_arg(*ap, unsigned int), "0123456789");
	i = (file->nb > ft_strlen(str)) ? file->nb - ft_strlen(str) : 0;
	if (!ft_strchr(file->flags, '-') && i)
		(ft_strchr(file->flags, '0')) ?
		ft_putzero(str, &i) : ft_putnchar(' ', i, 1);
	ft_putstr_fd(str, 1);
	if (ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	file->ct = ft_strlen(str) + i;
	free(str);
	return (1);
}
