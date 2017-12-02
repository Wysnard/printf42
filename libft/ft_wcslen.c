#include "libft.h"

size_t	ft_wcslen(wchar_t	*wstr)
{
	size_t	i;

	i = 0;
	while (wstr[i])
		i++;
	return (i);
}
