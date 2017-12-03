#include "printf.h"

int	ft_print_wstr(va_list *ap, t_file *file)
{
	wchar_t	*wstr;
	wchar_t	*printed;
	size_t		i;

	i = 0;
	if ((wstr = va_arg(*ap, wchar_t *)))
		printed = (file->precision >= 0) ?
		ft_wcsndup(wstr, file->precision) : ft_wcsdup(wstr);
	else
		printed = (file->precision >= 0) ?
		ft_wcsndup(L"(null)", file->precision) : ft_wcsdup(L"(null)");
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
	if ((str = va_arg(*ap, const char *)))
		printed = (file->precision >= 0) ?
		ft_strndup(str, file->precision) : ft_strdup(str);
	else
		printed = (file->precision >= 0) ?
		ft_strndup("(null)", file->precision) : ft_strdup("(null)");
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
