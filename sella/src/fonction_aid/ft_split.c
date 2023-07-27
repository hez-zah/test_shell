/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:21:58 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/01/27 13:21:58 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	ft_nbr(const char *s, char c)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		k++;
		while (s[i] != c && s[i] != '\0')
				i++;
	}
	if (s[i - 1] == c)
		k--;
	return (k);
}

static int	ft_pass(const char *s, char c, int i)
{
	while (s[i] == c)
		i++;
	return (i);
}

static int	ft_deff(const char *s, char c, int i)
{
	int	taille;

	taille = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i + taille] != c && s[i + taille] != '\0')
			taille++;
		break ;
	}
	return (taille + 1);
}

static char	**ft_split_aid(int k, char **p, char c, const char *s)
{
	int	t;
	int	i;
	int	j;
	int	l;

	t = 0;
	i = 0;
	while (t < k - 1 && s[i] != '\0')
	{
		i = ft_pass (s, c, i);
		j = ft_deff (s, c, i);
		*(p + t) = (char *)malloc(j * sizeof(char));
		l = 0;
		while (l < j - 1)
		{
			p[t][l] = s[i];
			i++;
			l++;
		}
		p[t][l] = '\0';
		t++;
	}
	p[t] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	int		k;
	char	**p;

	if (!s)
		return (NULL);
	k = 0;
	k = ft_nbr (s, c) + 1 ;
	p = (char **)malloc(k * sizeof(char *));
	if (!p)
		return (NULL);
	return (ft_split_aid (k, p, c, s));
}
