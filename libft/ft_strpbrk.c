#include "libft.h"

char *ft_strpbrk(const char *s, const char *accept)
{
	if (!s || !accept)
		return (NULL);
	while (*s)
	{
		if (ft_strchr(accept, *s))
			return ((char *)s);
		s++;
	}
	return (NULL);
}
