#include "printf.h"

void	ft_init_flags(t_file *file)
{
	file->precision = 0;
	file->dial = -1;
	file->minus = -1;
	file->zero = -1;
	file->plus = 0;
	file->space = -1;
	file->flags = none;
}
