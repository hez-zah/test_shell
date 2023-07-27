

#include "../headers/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (n > i)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst);
}
