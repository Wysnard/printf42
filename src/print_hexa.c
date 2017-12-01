#include "printf.h"

int	ft_print_hexa(va_list *ap, t_file *file)
{
	char	*str;
	size_t	i;

	str = ft_utoa(va_arg(*ap, unsigned int), "0123456789abcdef");
	if (ft_strchr(file->flags, '#'))
		str = ft_strjoinfree(ft_strdup("0x"), str);
	i = (file->nb > ft_strlen(str)) ? file->nb - ft_strlen(str) : 0;
	if (ft_strchr(file->flags, '0'))
		ft_putzero(&str, &i);
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

	str = ft_utoa(va_arg(*ap, unsigned int), "0123456789ABCDEF");
	if (ft_strchr(file->flags, '#'))
		str = ft_strjoinfree(ft_strdup("0X"), str);
	i = (file->nb > ft_strlen(str)) ? file->nb - ft_strlen(str) : 0;
	if (ft_strchr(file->flags, '0'))
		ft_putzero(&str, &i);
	if (!ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	ft_putstr_fd(str, 1);
	if (ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	file->ct = ft_strlen(str) + i;
	free(str);
	return (1);
}
