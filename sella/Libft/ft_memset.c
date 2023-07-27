

#include "../headers/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst1;
	unsigned char	c1;
	unsigned int	i;

	c1 = (unsigned char)c;
	dst1 = (unsigned char *)b;
	i = 0;
	while (len > i)
	{
		dst1[i] = c1;
		i++;
	}
	return (b);
}
