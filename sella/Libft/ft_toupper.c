

#include "../headers/libft.h"

int	ft_toupper(int c)
{
	int		d;

	d = c;
	if (c >= 97 && c <= 122)
		d = c - 32;
	return (d);
}
