#include "printf.h"
#include <stdio.h>

void	ft_flags(char **start, t_file *file)
{
	char	flags[10];
	char	f[2];

	ft_strcpy(flags, "#0-+ ");
	while (*start && **start && ft_strchr(flags, **start))
	{
		f[0] = *ft_strchr(flags, **start);
		f[1] = '\0';
		if (!ft_strchr(file->flags, f[0]))
			ft_strcat(file->flags, f);
		(*start)++;
	}
	file->nb = ft_atoim(*start);
	while (ft_isdigit(**start))
		(*start)++;
	if (**start == '.')
	{
		file->precision = ft_atoim(++(*start));
		while (ft_isdigit(**start))
			(*start)++;
	}
	printf("flags = %s| nb = %ju | precision = %jd\n", file->flags, file->nb, file->precision);
}
