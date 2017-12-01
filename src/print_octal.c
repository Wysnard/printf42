#include "printf.h"

int	ft_print_octal(va_list *ap, t_file *file)
{
	char	*str;
	size_t	i;
	unsigned	int	nbr;

	str = ft_utoa((nbr = va_arg(*ap, unsigned int)), "01234567");
	if (ft_strchr(file->flags, '#') && nbr > 0)
		str = ft_strjoinfree(ft_strdup("0"), str);
	i = (file->nb > ft_strlen(str)) ? file->nb - ft_strlen(str) : 0;
	if (ft_strchr(file->flags, '0'))
		ft_putzero(&str, &i, "0");
	if (!ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	ft_putstr_fd(str, 1);
	if (ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	file->ct = ft_strlen(str) + i;
	free(str);
	return (1);
}
