/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:14:43 by vlay              #+#    #+#             */
/*   Updated: 2017/12/04 19:19:24 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

static	void	ft_convert(char *start, t_file *file)
{
	if (*start == 'z')
		file->convert = z;
	else if (*start == 'j')
		file->convert = j;
	else if (start[0] == 'l' && (start)[1] == 'l')
		file->convert = ll;
	else if (*start == 'l')
		file->convert = l;
	else if (*start == 'h' && start[1] == 'h')
		file->convert = hh;
	else if (*start == 'h')
		file->convert = h;
}

void			ft_flags(char **start, t_file *file)
{
	char	f[2];

	while (*start && **start && ft_strchr("#0-+ ", **start))
	{
		f[0] = *ft_strchr("#0-+ ", **start);
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
	ft_convert(*start, file);
	while (ft_strchr("hljz", **start))
		(*start)++;
}
