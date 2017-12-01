#include "printf.h"

int	ft_print_hexa(va_list *ap, t_file *file)
{
	char	*str;
	size_t	i;
	unsigned	int	nbr;

	str = ft_utoa((nbr = ft_get_type_u(ap, file)), "0123456789abcdef");
	ft_nbprec(&str, file->precision - ft_strlen(str));
	if (ft_strchr(file->flags, '#') && nbr > 0)
		str = ft_strjoinfree(ft_strdup("0x"), str);
	i = (file->nb > ft_strlen(str)) ? file->nb - ft_strlen(str) : 0;
	if (ft_strchr(file->flags, '0'))
		(file->precision >= 0) ?
		ft_putnchar(' ', i - file->nb, 1) : ft_putzero(&str, &i, "0x", file);
	if (!ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	ft_putstr_fd(str, 1);
	if (ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	file->ct = ft_strlen(str) + i;
	free(str);
	return (1);
}

int	ft_print_Hexa(va_list *ap, t_file *file)
{
	char	*str;
	size_t	i;
	unsigned	int	nbr;

	str = ft_utoa((nbr = ft_get_type_u(ap, file)), "0123456789ABCDEF");
	ft_nbprec(&str, file->precision - ft_strlen(str));
	if (ft_strchr(file->flags, '#') && nbr > 0)
		str = ft_strjoinfree(ft_strdup("0X"), str);
	i = (file->nb > ft_strlen(str)) ? file->nb - ft_strlen(str) : 0;
	if (ft_strchr(file->flags, '0'))
		(file->precision >= 0) ?
		ft_putnchar(' ', i - file->nb, 1) : ft_putzero(&str, &i, "0X", file);
	if (!ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	ft_putstr_fd(str, 1);
	if (ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	file->ct = ft_strlen(str) + i;
	free(str);
	return (1);
}
