

#include "../headers/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!lst)
		return ;
	ptr = *lst;
	while ((*lst) != NULL)
	{
		ptr = (*lst)->next;
		if (del != NULL)
			del((*lst)->content);
		free(*lst);
		(*lst) = ptr;
	}
	lst = NULL;
}
