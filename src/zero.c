#include "printf.h"

void	ft_putzero(const char *str, intmax_t *i)
{
	char	*zero;
	size_t	j;
	size_t	len;

	j = 0;
	len = ft_strlen(str);
	if (!(zero = ft_strnew(len + *i)))
		exit (EXIT_FAILURE);
	if (*str == '+')
		zero[j++] = *str++;
	while ((*i - len) > 0 && j < (*i - len))
		zero[j++] = '0';
	ft_strcpy(&zero[j], str);
	*i = 0;
}
