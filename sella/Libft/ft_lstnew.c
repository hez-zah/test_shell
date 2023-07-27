

#include "../headers/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*one;

	one = (t_list *)malloc(sizeof(t_list));
	if (one == NULL)
		return (NULL);
	one->content = content;
	one->next = NULL;
	return (one);
}
