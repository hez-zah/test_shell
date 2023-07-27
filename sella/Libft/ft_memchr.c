

#include "../headers/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	c1;

	str1 = (unsigned char *)s;
	c1 = (unsigned char)c;
	i = 0;
	while (n > i)
	{
		if (str1[i] == c1)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
