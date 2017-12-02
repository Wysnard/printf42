#include "printf.h"
#include <stdio.h>

static	void	ft_convert(char **start, t_file *file, char *flags)
{
	(void)flags;
	if (**start == 'z')
		file->convert = z;
	else if (**start == 'j')
		file->convert = j;
	else if ((*start)[1] == 'l' && (*start)[2] == 'l')
		file->convert = ll;
	else if (**start == 'l')
		file->convert = l;
	else if (**start == h)
		file->convert = h;
	else if ((*start)[1] == 'h' && (*start)[2] == 'h')
		file->convert = hh;
	// if (ft_strchr(flags, **start))
	// 	file->convert = none;
	while (ft_strchr(flags, **start))
		(*start)++;
}

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
	ft_strcpy(flags, "hljz");
	ft_convert(start, file, flags);
	// printf("flags = %s| nb = %ju | precision = %jd | convert = %d\n", file->flags, file->nb, file->precision, file->convert);
}
