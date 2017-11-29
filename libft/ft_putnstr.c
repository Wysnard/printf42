#include "libft.h"

void	ft_putnstr_fd(const char *str, size_t n, int fd)
{
	write(fd, str, n);
}
