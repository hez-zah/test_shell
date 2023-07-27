#include "../../headers/minishell.h"

int	check_sort(t_pip *pip)
{
	t_limit *head;
	int i;

	i = 0;
	head = pip->limit;
	while (head)
	{
		i++;
		head = head->next_limit;
	}
	return (i);
}

int	check_entr(t_pip *pip, char *led)
{
	t_limit *head;

	head = pip->limit;
	while (head)
	{
		if (pip->permi == head->index_limit &&
				!ft_strncmp(head->limit, led, ft_strlen(led)))
					pip->permi += 1;
		head = head->next_limit;
	}
	return (pip->permi);
}

char	*befor_limit(t_pip *pip)
{
	t_limit *head;

	head = pip->limit;
	if (!pip->permi)
		return (head->limit);
	while (head->next_limit->next_limit)
		head = head->next_limit;
	return (head->limit);
}

void affich(t_pip *pip)
{
	char *led;

	write(1, ">", 1);
	led = get_next_line(0);
	while (1)
	{
		pip->permi = check_entr(pip, led);
		if (pip->permi == check_sort(pip))
		{
			free(led);
			break;
		}
		if (pip->permi == check_sort(pip) - 1)
			if (ft_strncmp(befor_limit(pip), led, ft_strlen(led)))
				write(pip->herd_out, led, ft_strlen(led));
		write(1, ">", 1);
		free(led);
		led = get_next_line(0);
	}
	close(pip->herd_out);
}

void	creat_pipe(t_pip *pip)
{
	int fd[2];

	if (pipe(fd) < 0)
		write(2, "Error\n", 6);
	pip->herd_in = fd[0];
	pip->herd_out = fd[1];
}