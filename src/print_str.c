#include "printf.h"

int	ft_print_wstr(va_list *ap, t_file *file)
{
	wchar_t	*wstr;
	wchar_t	*printed;
	size_t		i;

	i = 0;
	(void)file;
	wstr = va_arg(*ap, wchar_t *);
	if (file->precision >= 0)
		printed = (size_t)file->precision > ft_wcslen(wstr) ? ft_wcsdup(wstr)
		: ft_wcsndup(wstr, file->precision);
	else
		printed = ft_wcsdup(wstr);
	i = (file->nb > ft_wcslen(printed)) ? file->nb - ft_wcslen(printed) : 0;
	if (!ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	ft_putwstr_fd(printed, 1);
	if (ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	file->ct += (i > 0) ? i : 0;
	file->ct += ft_wcslen(printed);
	free(printed);
	return (1);
}

int	ft_print_str(va_list *ap, t_file *file)
{
	const	char	*str;
	char		*printed;
	size_t		i;

	i = 0;
	str = va_arg(*ap, const char *);
	if (file->precision >= 0)
		printed = (size_t)file->precision > ft_strlen(str) ? ft_strdup(str)
		: ft_strndup(str, file->precision);
	else
		printed = ft_strdup(str);
	i = (file->nb > ft_strlen(printed)) ? file->nb - ft_strlen(printed) : 0;
	if (!ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	ft_putstr_fd(printed, 1);
	if (ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	file->ct += (i > 0) ? i : 0;
	file->ct += ft_strlen(printed);
	free(printed);
	return (1);
}
