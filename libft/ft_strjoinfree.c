#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*result;

	if (!(result = ft_strjoin(s1, s2)))
		return (NULL);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (result);
}
