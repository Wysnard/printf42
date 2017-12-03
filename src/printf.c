#include "printf.h"

int	ft_printf(const char *arg1, ...)
{
	char	*pct;
	va_list ap;
	char *start;
	t_file	file;

	file.ct = 0;
	va_start(ap, arg1);
	if (!(start = (char *)arg1))
		return (-1);
	while (*start)
	{
		if ((pct = ft_strchr(start, '%')))
		{
			write(1, start, pct - start);
			file.ct += pct - start;
			start = pct + 1;
			ft_process(&start, &file, &ap);
		}
		else
		{
			ft_putstr_fd(start, 1);
			file.ct += ft_strlen(start);
			break ;
		}
	}
	va_end(ap);
	return (file.ct);
}
