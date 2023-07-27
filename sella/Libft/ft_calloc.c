

#include "../headers/libft.h"
#include <errno.h>

void	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	unsigned long	i;
	void			*ptr1;

	i = 0;
	ptr = malloc(size * count);
	if (ptr == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	if (ptr != NULL)
	{
		while (i < (count * size))
		{
			ptr[i] = '\0';
			i++;
		}
	}
	ptr1 = (void *)ptr;
	return (ptr1);
}
