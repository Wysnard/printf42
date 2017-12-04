#include "printf.h"

static	size_t	ft_get_binaire(size_t	len, t_file *file)
{
	int	i;

	if (file->convert == hh)
		i = 8 - len;
	else if (file->convert == h)
		i = 16 - len;
	else if (file->convert == l)
		i = 32 - len;
	else if (file->convert == ll)
		i = 64 - len;
	else if (file->convert == j)
		i = 64 - len;
	else if (file->convert == z)
		i = 32 - len;
	else
		i = 8 - len;
	if (i < 0)
		return (0);
	return (i);
}

int	ft_print_b(va_list *ap, t_file *file)
{
	char	*str;
	size_t	i;
	uintmax_t	nbr;
	size_t	len;

	str = ft_utoa((nbr = ft_get_type_u(ap, file)), "01");
	i = ft_get_binaire(len = ft_strlen(str), file);
	ft_putzero(&str, &i, "0b", file);
	if (file->precision == 0)
		str[0] = '\0';
	else
		ft_nbprec(&str, file->precision - len);
	if (ft_strchr(file->flags, '#') && nbr > 0
	&& (str = ft_strjoinfree(ft_strdup("0b"), str)))
		str[len + 2] = '\0';
	i = (file->nb > ft_strlen(str)) ? file->nb - ft_strlen(str) : 0;
		if (ft_strchr(file->flags, '0') && file->precision >= 0)
			ft_putnchar(' ', i - file->nb, 1);
		else if (ft_strchr(file->flags, '0') && !ft_strchr(file->flags, '-'))
			ft_putzero(&str, &i, "0b", file);
	if (i)
		(!ft_strchr(file->flags, '-')) ?
		ft_putspace(&str, &i, 'f') : ft_putspace(&str, &i, 'b');
	ft_putstr_fd(str, 1);
	file->ct += ft_strlen(str) + i;
	free(str);
	return (1);
}
