#include "libft.h"

char	*ft_strnrchr(const char *s, int c, size_t n)
{
	const	char	*tmp;

	tmp = s;
	while (*tmp && n)
	{
		tmp++;
		n--;
	}
	if ((char)c == '\0')
		return ((char *)tmp);
	while (--tmp >= s)
		if (*tmp == (char)c)
			return ((char *)tmp);
	return (NULL);
}
