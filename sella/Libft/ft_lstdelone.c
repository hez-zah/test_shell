

#include "../headers/libft.h"

void	ft_lstdelone(t_list *ptr, void (*del)(void *))
{
	if (!ptr || !del)
		return ;
	del(ptr->content);
	free(ptr);
}
