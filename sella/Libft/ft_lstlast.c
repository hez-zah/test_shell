

#include "../headers/libft.h"

t_list	*ft_lstlast(t_list *ptr)
{
	if (!ptr)
		return (0);
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	return (ptr);
}
