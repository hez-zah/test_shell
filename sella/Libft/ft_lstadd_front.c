

#include "../headers/libft.h"

void	ft_lstadd_front(t_list **ptr, t_list *new)
{
	if (!(ptr) || !(new))
		return ;
	new->next = *ptr;
	*ptr = new;
}
