

#include "../headers/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c1;

	c1 = (char)c;
	i = ft_strlen(s);
	while (*s)
		s++;
	while (i >= 0)
	{
		if (*s == c1)
			return ((char *)s);
		i--;
		s--;
	}
	if (c1 == '\0')
		return ((char *)s);
	return (0);
}
