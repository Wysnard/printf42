/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:01:52 by vlay              #+#    #+#             */
/*   Updated: 2017/12/05 22:32:52 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa(double nbr, size_t size)
{
	char	*buf;

	if (nbr == 0)
		return (ft_strdup("0"));
	buf = ft_itoa(nbr);
	if (size > 0)
		buf = ft_strjoin(buf, ".");
	nbr *= 10 * size;
	buf = ft_strjoinfree(buf, ft_utoa(nbr, "0123456789"));
	return (buf);
}
