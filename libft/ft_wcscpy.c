#include "libft.h"

wchar_t	*ft_wcscpy(wchar_t *dest, const wchar_t *src)
{
	wchar_t	*cp;

	cp = dest;
	while ((*cp++ = *src++))
		;
	return (dest);
}
