#include "libft.h"

wchar_t	*ft_wcsdup(wchar_t	*wcs)
{
	wchar_t	*dup;
	size_t	len;

	if (!(dup = ft_wcsnew((len = ft_wcslen(wcs)))))
		return (NULL);
	ft_wcsncpy(dup, wcs, len);
	dup[len] = '\0';
	return (dup);
}
