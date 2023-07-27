/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:29:36 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/01/27 13:30:09 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	ft_basic(unsigned char *s1, unsigned char *s2, size_t	i)
{
	if ((s1[i] - s2[i]) == 0)
		return (0);
	return (s1[i] - s2[i]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	else if (n < 0)
		return (-1);
	else
	{
		while ((unsigned char)s1[i] != '\0'
			&& (unsigned char)s2[i] != '\0' && i < n)
		{
			if ((unsigned char)s1[i] != (unsigned char)s2[i])
				return (ft_basic((unsigned char *)s1, (unsigned char *)s2, i));
			i++;
		}
		if (i != n)
			return (ft_basic((unsigned char *)s1, (unsigned char *)s2, i));
	}
	return (0);
}
