#include "includes/libft.h"
#include <stdio.h>
#include <limits.h>

int	main()
{
	// unsigned	c = ;
	// wchar_t texte[50] = L"爆ぜろリアル！弾けろシナプス！パニッシュメントディス、ワールド！";
	// char	c;
	// wchar_t *cp;
	// wchar_t	w = L'é';
  //
	// cp = NULL;
	// cp = ft_wcsdup(texte);
	ft_putnbr(ft_printf("%hx, %hx", 0, USHRT_MAX));
	ft_putchar('\n');
	ft_putnbr(printf("%hx, %hx", 0, USHRT_MAX));
	ft_putchar('\n');
	// ft_putstr("\nWSC = ");
	// ft_putnbr(ft_wcslen(texte));
	// ft_putchar('\n');
	// free(cp);
	return (0);
}
