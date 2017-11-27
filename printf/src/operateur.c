#include "printf.h"

void	ft_operateur(char **start, t_file *file)
{
	if (**start != '+' && **start != '-')
		return ;
	while (**start == '+' || **start == '-')
	{
		if (**start == '+')
			file->plus = 1;
		else if (**start == '-')
			file->minus = 1;
		(*start)++;
	}
}
