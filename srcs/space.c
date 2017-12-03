#include "printf.h"

void	ft_putwspace(wchar_t **str, size_t *i)
{
	wchar_t	*space;
	size_t	k;

	k = 0;
	if (!(space = ft_wcsnew(*i)))
		exit(EXIT_FAILURE);
	while (k < *i)
		space[k++] = ' ';
	space[*i] = '\0';
	*str = ft_wcsjoinfree(*str, space);
	*i = 0;
}

void	ft_putspace(char **str, size_t *i)
{
	char	*space;

	if (!(space = ft_strnew(*i)))
		exit(EXIT_FAILURE);
	ft_memset(space, ' ', *i);
	space[*i] = '\0';
	*str = ft_strjoinfree(*str, space);
	*i = 0;
}