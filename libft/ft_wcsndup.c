#include "libft.h"

wchar_t	*ft_wcsndup(wchar_t	*wcs, size_t n)
{
	wchar_t	*dup;

	if (!(dup = ft_wcsnew(n)))
		return (NULL);
	ft_wcsncpy(dup, wcs, n);
	dup[n] = '\0';
	return (dup);
}
