

#include "../headers/libft.h"

void	ft_putnbr_fd(long long int n, int fd)
{
	char	c;

	if (n <= -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n <= 9)
	{
		c = n + 48;
		write(fd, &c, 1);
	}
}
