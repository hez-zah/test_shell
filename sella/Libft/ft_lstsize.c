

#include "../headers/libft.h"

int	ft_lstsize(t_list *ptr)
{
	unsigned int				i;

	if (!ptr)
		return (0);
	i = 1;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
