#include "libft.h"

void	ft_putnchar(char c, int n, int fd)
{
	char	*str;

	if (fd < 0 || n <= 0 || !(str = ft_strnew(n)))
		return ;
	ft_memset(str, c, n);
	write(fd, str, n);
	free(str);
}
