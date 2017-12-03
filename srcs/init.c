#include "printf.h"

void	ft_init_flags(t_file *file)
{
	ft_bzero(file->flags, 10);
	file->precision = -1;
	file->convert = none;
}
