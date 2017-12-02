#include "libft.h"

void	ft_putwstr_fd(wchar_t *wstr, int fd)
{
	size_t	i;

	i = 0;
	while (wstr[i])
		ft_putwchar_fd(wstr[i++], fd);
}

void	ft_putwstr(wchar_t *wstr)
{
	ft_putwstr_fd(wstr, 1);
}
