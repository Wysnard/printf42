#include "printf.h"

static	void	ft_octalprec(char **str, size_t i, t_file *file)
{
	char	*zero;
	char	*tmp;
	char	save[3];

	if (ft_strchr(file->flags, '#'))
		file->precision--;
	if (i < 1)
		return ;
	if (!(zero = ft_strnew(i)))
		exit(EXIT_FAILURE);
	ft_memset(zero, '0', i);
	zero[i] = '\0';
	tmp = zero;
	if (**str == '-')
	{
		save[0] = **str;
		save[1] = '\0';
		zero = ft_strjoin(save, tmp);
		ft_strcpy(*str, (*str) + 1);
		free(tmp);
	}
	*str = ft_strjoinfree(zero, *str);
}

int	ft_print_octal(va_list *ap, t_file *file)
{
	char	*str;
	size_t	i;
	unsigned	int	nbr;

	str = ft_utoa((nbr = va_arg(*ap, unsigned int)), "01234567");
	ft_octalprec(&str, file->precision - ft_strlen(str), file);
	if (ft_strchr(file->flags, '#') && nbr > 0)
		str = ft_strjoinfree(ft_strdup("0"), str);
	i = (file->nb > ft_strlen(str)) ? file->nb - ft_strlen(str) : 0;
	if (ft_strchr(file->flags, '0'))
		(file->precision >= 0) ?
		ft_putnchar(' ', i - file->nb, 1) : ft_putzero(&str, &i, "0", file);
	if (!ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	ft_putstr_fd(str, 1);
	if (ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	file->ct = ft_strlen(str) + i;
	free(str);
	return (1);
}
