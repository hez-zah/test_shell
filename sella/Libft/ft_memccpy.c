

#include "../headers/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dst1;
	unsigned char	*src1;
	unsigned char	c1;

	c1 = (unsigned char)c;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		dst1[i] = src1[i];
		if (src1[i] == c1)
			return ((void *)&dst1[i + 1]);
		i++;
	}
	return (NULL);
}
