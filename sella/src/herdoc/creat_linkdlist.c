/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_linkdlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:12:54 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/03/18 01:34:40 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	check_herdoc(char **arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		if (!ft_strncmp(arg[i], "<<", 2))
			return (1);
	return (0);
}

t_limit	*ft_lstnew_her(char *limit, int index)
{
	t_limit	*new;

	new = NULL;
	new = (t_limit *)malloc(sizeof(t_limit));
	if (!new)
		return (NULL);
	new->limit = ft_strjoin1(limit, "\n");
	new->index_limit = index;
	new->next_limit = NULL;
	return (new);
}

t_limit	*last_add(t_limit *head, char *limit, int index)
{
	t_limit	*b;
	t_limit	*tmp;

	b = ft_lstnew_her(limit , index);
	if (!head)
		head = b;
	else
	{
		tmp = head;
		while (tmp->next_limit)
			tmp = tmp->next_limit;
		tmp->next_limit = b;
	}
	return (head);
}

t_limit	*creat_linkdlist(t_limit	*head, char *limit, int index)
{
	return (last_add(head, limit, index));
}
