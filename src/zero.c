#include "printf.h"

void	ft_putzero(char **str, size_t *i, char *prefix, t_file *file)
{
	char	*zero;
	char	*tmp;
	char	save[3];

	if (!(zero = ft_strnew(*i)))
		exit(EXIT_FAILURE);
	ft_memset(zero, '0', *i);
	zero[*i] = '\0';
	tmp = zero;
	if (ft_strchr(file->flags, '0') && ft_strnequ(*str, prefix, 2))
	{
		ft_strcpy(save, prefix);
		(ft_isdigit((*str)[1])) ?
		ft_strcpy(*str, &(*str)[1]) : ft_strcpy(*str, &(*str)[2]);
		zero = ft_strjoin(save, tmp);
		free(tmp);
	}
	else if (!ft_isdigit(**str))
	{
		save[0] = **str;
		save[1] = '\0';
		ft_strcpy(*str, (*str) + 1);
		zero = ft_strjoin(save, tmp);
		free(tmp);
	}
	*str = ft_strjoinfree(zero, *str);
	*i = 0;
}
