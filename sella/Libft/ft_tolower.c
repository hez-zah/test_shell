

#include "../headers/libft.h"

int	ft_tolower(int c)
{
	int		d;

	d = c;
	if (c >= 65 && c <= 90)
		d = c + 32;
	return (d);
}
