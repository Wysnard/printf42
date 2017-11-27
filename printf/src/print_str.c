#include "printf.h"

int	ft_print_str(va_list *ap, t_file *file)
{
	const	char	*str;
	(void)file;

	str = va_arg(*ap, const char *);
	ft_putstr(str);
	file->ct += ft_strlen(str);
	return (1);
}
