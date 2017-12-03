/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:03:05 by vlay              #+#    #+#             */
/*   Updated: 2017/12/03 18:03:18 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

static	int	ft_ct(intmax_t n, size_t base)
{
	int ct;

	ct = 0;
	while (n)
	{
		n /= base;
		ct++;
	}
	return (ct);
}

char		*ft_imtoa_base(intmax_t nbr, char *base_to)
{
	char	*str;
	int		i;
	int		len;
	int		ct;

	if (nbr == 0)
		return (ft_strndup(base_to, 1));
	len = ft_strlen(base_to);
	ct = (nbr < 0) ? ft_ct(-nbr, len) + 1 : ft_ct(nbr, len);
	str = ft_strnew(ct);
	i = 1;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		str[ct - i++] = base_to[nbr % len];
		nbr /= len;
	}
	str[ct] = '\0';
	return (str);
}

// char		*ft_imtoa(intmax_t nbr)
// {
// 	return ((nbr == -9223372036854775808) ?
// 	ft_strdup("-9223372036854775808") : ft_imtoa_base(nbr, "0123456789"));
// }
