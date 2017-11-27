#ifndef PRINTF_H
# define PRINTF_H
# include "libft.h"

typedef	struct	s_file
{
	size_t	ct;
	int precision;
	int count;
	int	dial;
	int minus;
	int	zero;
	int	plus;
	int space;
	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}	flags;
}					t_file;

int	ft_printf(const char *arg1, ...);

void	ft_init_flags(t_file *file);
int	ft_process(char **start, t_file *file, va_list *ap);
void	ft_operateur(char **start, t_file *file);
void	ft_flags(char **start, t_file *file);

int	ft_print_char(va_list *ap, t_file *file);
int	ft_print_str(va_list *ap, t_file *file);
int	ft_print_int(va_list *ap, t_file *file);

#endif
