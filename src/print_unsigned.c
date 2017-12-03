#include "printf.h"

uintmax_t	ft_get_type_u(va_list *ap, t_file *file)
{
	uintmax_t	nbr;

	nbr = va_arg(*ap, uintmax_t);
	if (file->convert == hh)
		nbr = (unsigned char)nbr;
	else if (file->convert == h)
		nbr = (short unsigned)nbr;
	else if (file->convert == l)
		nbr = (unsigned long)nbr;
	else if (file->convert == ll)
		nbr = (unsigned long long)nbr;
	else if (file->convert == j)
		nbr = (uintmax_t)nbr;
	else if (file->convert == z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned)nbr;
	return (nbr);
}

int	ft_print_unsigned(va_list *ap, t_file *file)
{
	char	*str;
	size_t	i;
	uintmax_t	nbr;

	str = ft_utoa((nbr = ft_get_type_u(ap, file)), "0123456789");
	ft_nbprec(&str, file->precision - ft_strlen(str));
	i = (file->nb > ft_strlen(str)) ? file->nb - ft_strlen(str) : 0;
	if (ft_strchr(file->flags, '0'))
		(file->precision >= 0) ?
		ft_putnchar(' ', i - file->nb, 1) : ft_putzero(&str, &i, "", file);
	if (!ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	ft_putstr_fd(str, 1);
	if (ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	file->ct += ft_strlen(str) + i;
	free(str);
	return (1);
}
