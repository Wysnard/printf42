#include "printf.h"

static intmax_t	ft_get_type(va_list *ap, t_file *file)
{
	intmax_t	nbr;

	nbr = va_arg(*ap, intmax_t);
	if (file->flags == hh)
		nbr = (char)nbr;
	else if (file->flags == h)
		nbr = (short int)nbr;
	else if (file->flags == l)
		nbr = (long)nbr;
	else if (file->flags == ll)
		nbr = (long long)nbr;
	else if (file->flags == j)
		nbr = (intmax_t)nbr;
	else if (file->flags == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

int	ft_print_int(va_list *ap, t_file *file)
{
	intmax_t	nbr;
	char		*str;

	nbr = ft_get_type(ap, file);
	str = ft_imtoa_base(nbr, "0123456789");
	if (file->plus && nbr > -1)
	{
		ft_putchar('+');
		file->ct++;
	}
	ft_putstr_fd(str, 1);
	file->ct += ft_strlen(str);
	return (1);
}
