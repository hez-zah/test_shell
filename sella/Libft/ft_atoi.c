

#include "../headers/libft.h"

int	ft_atoi(const char *str)
{
	long long int	nmb;
	int				i;
	int				a;

	nmb = 0;
	i = 0;
	a = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i])
	{
		if (str[i] == '-')
			a = a * -1;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9' && str[i])
	{
		nmb = (nmb * 10) + str[i] - 48;
		i++;
	}
	return (nmb * a);
}
