#include "libft.h"

wchar_t *ft_wcsncpy(wchar_t *dest, const wchar_t *src, size_t n)
{
	size_t	i;
	wchar_t	*cp;

	i = 0;
	cp = dest;
	while (src[i] && i < n)
	{
		cp[i] = src[i];
		i++;
	}
	while (i < n)
		cp[i++] = '\0';
	return (dest);
}
