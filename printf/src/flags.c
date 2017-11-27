#include "printf.h"
#include <stdio.h>

void	ft_precision(char *begin, char *end, t_file *file)
{
	if (file->precision < 0)
		return ;
	while (end >= begin)
	{
		if (*end == '.')
			break ;
		end--;
	}
	if (end < begin)
		return ;
	file->precision = ft_atoi(end + 1);
}

void	ft_convert(char *begin, t_file *file, int n)
{
	if (ft_strnstr(begin, "z", n))
		file->flags = z;
	else if (ft_strnstr(begin, "j", n))
		file->flags = j;
	else if (ft_strnstr(begin, "l", n))
		file->flags = (ft_strnstr(begin, "ll", n)) ? ll : l;
	else if (ft_strnstr(begin, "h", n))
		file->flags = (ft_strnstr(begin, "hh", n)) ? hh : h;
}

char	*ft_lookfornb(const char *begin, int n)
{
	char	*nb;

	nb = NULL;
	while (n--)
	{
		if (ft_isdigit(*begin) && *begin != '0')
			nb = (char *)begin ;
		begin++;
	}
	return (nb);
}

void	ft_get_nb(t_file *file, char *nb)
{
	if (!nb)
		return ;
	if (file->minus == 0)
		file->minus = ft_atoi(nb);
	else if (file->zero == 0)
		file->zero = ft_atoi(nb);
	else
		file->space = ft_atoi(nb);
}

void	ft_flags(char **start, t_file *file)
{
	char	flags[20];
	char	*begin;

	begin = *start;
	ft_strcpy(flags, ".#-+ hhlljz");
	while (**start && (ft_strchr(flags, **start) || ft_isdigit(**start)))
	{
		if (**start == '+')
			file->plus = 1;
		else if (**start == '-')
			file->minus = 0;
		else if (**start == ' ')
			file->space = 1;
		else if (**start == '#')
			file->dial = 1;
		else if (**start == '0')
			file->zero = 0;
		else if (**start == '.')
			file->precision = 0;
		(*start)++;
	}
	ft_precision(begin, *start, file);
	// printf("convert = %d | %s\n", ft_atoi(ft_lookfornb(begin, *start - begin)), ft_lookfornb(begin, *start - begin));
	ft_get_nb(file, ft_lookfornb(begin, *start - begin));
	ft_convert(begin, file, *start - begin);
	printf("precision = %d| minus = %d | diff = %ld\n", file->precision, file->minus, *start - begin);
}
