#include "libft.h"

wchar_t	*ft_wcsnew(size_t len)
{
	wchar_t	*wcs;

	if (!(wcs = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1))))
		return (NULL);
	return (wcs);
}
