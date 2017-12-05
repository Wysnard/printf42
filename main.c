#include "includes/libft.h"
#include <stdio.h>
#include <limits.h>

int	main()
{
	double	l = 5.441;
	// wchar_t texte[50] = L"爆ぜろリアル！弾けろシナプス！パニッシュメントディス、ワールド！";
	// char	c;
	// wchar_t *cp;
	// wchar_t	w = L'é';
  //
	// cp = NULL;
	// cp = ft_wcsdup(texte);
	ft_putnbr(ft_printf("%s\n", ft_dtoa(5.441, 5)));
	ft_putchar('\n');
	ft_putstr("double = ");
	ft_putnbr(sizeof(l));
	ft_putchar('\n');
	ft_print_bits(l, 8);
	ft_putchar('\n');
	ft_putnbr(printf("%f\n", 5.441));
	ft_putchar('\n');
	// ft_putstr("\nWSC = ");
	// ft_putnbr(ft_wcslen(texte));
	// ft_putchar('\n');
	// free(cp);
	return (0);
}
