#include "../../headers/minishell.h"

static char	*ft_call(const char *led1, const char *led2, char *p)
{
	int	i;
	int	j;

	i = 0;
	while (led1[i] != '\0')
	{
		p[i] = led1[i];
		i++;
	}
	p[i] = ' ';
	i++;
	j = 0;
	while (led2[j] != '\0')
	{
		p[i] = led2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_concat(char const *s1, char const *s2)
{
	char	*p;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	p = malloc((ft_strlen (s1) + ft_strlen (s2) + 2) * sizeof(char));
	if (!p)
		return (NULL);
	return (ft_call (s1, s2, p));
}
