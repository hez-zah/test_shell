

#include "../headers/libft.h"

void	ft_lstiter(t_list *ptr, void (*f)(void *))
{
	if (!ptr || !f)
		return ;
	while (ptr != NULL)
	{
		f(ptr->content);
		ptr = ptr->next;
	}
}
