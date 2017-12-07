/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:22:34 by vlay              #+#    #+#             */
/*   Updated: 2017/12/07 16:43:59 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_octal(va_list *ap, t_file *file)
{
	char		*str;
	size_t		i;
	uintmax_t	nbr;

	nbr = ft_get_type_u(ap, file);
	str = ft_utoa(nbr, "01234567");
	if (file->precision == 0)
		str[0] = '\0';
	else
		ft_nbprec(&str, file->precision - ft_strlen(str));
	if (ft_strchr(file->flags, '#') && nbr > 0)
		str = ft_strjoinfree(ft_strdup("0"), str);
	i = (file->nb > ft_strlen(str)) ? file->nb - ft_strlen(str) : 0;
	if (ft_strchr(file->flags, '0'))
	{
		if (file->precision >= 0)
			ft_putnchar(' ', i - file->nb, 1);
		else if (!ft_strchr(file->flags, '-'))
			ft_putzero(&str, &i, "0", file);
	}
	if (i)
		(!ft_strchr(file->flags, '-')) ?
		ft_putspace(&str, &i, 'f') : ft_putspace(&str, &i, 'b');
	ft_putstr_fd(str, 1);
	file->ct += ft_strlen(str) + i;
	free(str);
	return (1);
}
