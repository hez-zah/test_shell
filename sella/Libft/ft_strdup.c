

#include "../headers/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (copy == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
