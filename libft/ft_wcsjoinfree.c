#include "libft.h"

wchar_t	*ft_wcsjoinfree(wchar_t	*w1, wchar_t *w2)
{
	wchar_t	*wcs;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(wcs = ft_wcsnew(ft_wcslen(w1) + ft_wcslen(w2))))
		return (NULL);
	while ((wcs[i] = w1[i]))
		i++;
	while ((wcs[i++] = w2[j++]))
		;
	wcs[i] = '\0';
	if (w1)
		free(w1);
	if (w2)
		free(w2);
	return (wcs);
}
