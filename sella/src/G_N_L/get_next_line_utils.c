/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:19:49 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/03/18 01:35:17 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

size_t	ft_strlen1(const char *s)
{
	size_t	i;

	i = 0;
	while (s && *(s + i))
		i++;
	return (i);
}

char	*ft_strjoin1(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	p = malloc((ft_strlen1 (s1) + ft_strlen1 (s2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (s1 && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			break ;
		else
			i++;
	}
	if (s[i] != (char)c)
		return (NULL);
	else
		return ((char *)s + i);
}

char	*copy(char *txt, char *save, int i)
{
	int	j;

	j = 0;
	while (txt[i] != '\0')
	{
		save[j] = txt[i];
		i++;
		j++;
	}
	save[j] = '\0';
	return (save);
}

char	*conc(char *stash, char *buf)
{
	if (stash && !stash[0] && !buf[0])
	{
		free (buf);
		free (stash);
		return (NULL);
	}
	free (buf);
	return (stash);
}
