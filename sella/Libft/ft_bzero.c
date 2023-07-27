

#include "../headers/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*dst1;

	dst1 = (char *)s;
	i = 0;
	while (n > i)
	{
		dst1[i] = 0;
		i++;
	}
}
