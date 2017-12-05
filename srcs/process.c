/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:27:44 by vlay              #+#    #+#             */
/*   Updated: 2017/12/05 22:13:05 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_conversion(char **start, t_file *file, va_list *ap)
{
	if (ft_isupper(**start) && **start != 'X')
		file->convert = l;
	if (**start == 'c' || **start == 'C')
		ft_print_char(ap, file);
	else if (**start == 's' || **start == 'S')
		ft_print_str(ap, file);
	else if (**start == 'd' || **start == 'i' || **start == 'D')
		ft_print_int(ap, file);
	else if (**start == 'u' || **start == 'U')
		ft_print_unsigned(ap, file);
	else if (**start == 'x')
		ft_print_hexa(ap, file);
	else if (**start == 'X')
		ft_print_exa(ap, file);
	else if (**start == 'o' || **start == 'O')
		ft_print_octal(ap, file);
	else if (**start == 'p')
		ft_print_pointer(ap, file);
	else if (**start == 'b')
		ft_print_b(ap, file);
	else if (**start == '%')
		ft_print_perc(ap, file);
	else
		return ;
	(*start)++;
}

int		ft_process(char **start, t_file *file, va_list *ap)
{
	if (**start == '\0')
		return (0);
	ft_init_flags(file);
	if (!ft_flags(start, file, ap))
		return (0);
	ft_conversion(start, file, ap);
	return (1);
}
