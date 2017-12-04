#include "includes/libft.h"
#include <stdio.h>
#include <limits.h>

int	main()
{
	wchar_t texte[50] = L"爆ぜろリアル！弾けろシナプス！パニッシュメントディス、ワールド！";
	// wchar_t *cp;
	// wchar_t	w = L'é';
  //
	// cp = NULL;
	// cp = ft_wcsdup(texte);
	ft_putnbr(ft_printf("%s %d %x %% %S\n", "bonjour ", 42, 42, L"لحم خنزير"));
	ft_putchar('\n');
	ft_putnbr(printf("%s %d %x %% %s\n", "bonjour ", 42, 42, "لحم خنزير"));
	ft_putchar('\n');
	// ft_putstr("\nWSC = ");
	// ft_putnbr(ft_wcslen(texte));
	// ft_putchar('\n');
	// free(cp);
	return (0);
}
