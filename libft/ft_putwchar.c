#include "libft.h"

void	ft_putwchar_fd(wchar_t chr, int fd)
{
	int	i;

	i = -1;
	if (chr <= 0x7F)
		ft_putchar_fd(chr, fd);
	else if (chr <= 0x7FF && !(i = 0))
		ft_putchar_fd((chr >> 6) | 0xC0, fd);
	else if (chr <= 0xFFFF && (i = 1))
		ft_putchar_fd((chr >> 12) | 0xE0, fd);
	else if (chr <= 0x1FFFFF && (i = 2))
		ft_putchar_fd((chr >> 18) | 0xF0, fd);
	else if (chr <= 0x3FFFFFF && (i = 3))
		ft_putchar_fd((chr >> 24) & 0xF8, fd);
	while (i >= 0)
		ft_putchar_fd(((chr >> (6 * i--)) & 0x3F) | 0x80, fd);
}

void	ft_putwchar(wchar_t chr)
{
	ft_putwchar_fd(chr, 1);
}