

#include "../headers/minishell.h"

t_pip	*lst_new1(void)
{
	t_pip	*one;

	one = (t_pip *)malloc(sizeof(t_pip));
	if (one == NULL)
		return (NULL);
	one->pip_infile = 0;
    one->pip_outfile = 1;
	one->next_pip = NULL;
	return (one);
}

t_pip	*exe_lstlast(t_pip *ptr)
{
	if (!ptr)
		return (0);
	while (ptr->next_pip != NULL)
		ptr = ptr->next_pip;
	return (ptr);
}

t_pip	*lstadd_back1(t_pip *lst, t_pip *new)
{
	t_pip	*last;

	last = exe_lstlast(lst);
	if (last)
		last->next_pip = new;
	else
		lst = new;
	return (lst);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	return (ft_strncmp(s1, s2, 1 + (size_t)ft_strlen(s2)));
}

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	ft_strclen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	ft_strslen(char *str, char *check)
{
	int	i;

	i = 0;
	while (ft_strchr(check, str[i]) == 0 && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcdup(const char *s1, char c)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(sizeof(*s1) * (ft_strclen((char *)s1, c) + 1));
	if (copy == NULL)
		return (NULL);
	while (s1[i] != '\0' && s1[i] != c)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
