#include "includes/libft.h"
#include <stdio.h>

int	main()
{
	// wchar_t texte[50] = L"爆ぜろリアル！弾けろシナプス！パニッシュメントディス、ワールド！";
	// wchar_t *cp;
	// wchar_t	w = L'é';
  //
	// cp = NULL;
	// cp = ft_wcsdup(texte);
	ft_putnbr(ft_printf("%#llx|\n", 9223372036854775807));
	ft_putchar('\n');
	ft_putnbr(printf("%#llx|\n", 9223372036854775807));
	// ft_putstr("\nWSC = ");
	// ft_putnbr(ft_wcslen(texte));
	// ft_putchar('\n');
	// free(cp);
	return (0);
}
