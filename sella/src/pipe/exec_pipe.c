#include "../../headers/minishell.h"

t_pip	*init_pip(t_pip *pip)
{
	t_pip	*tmp;
	int			fd[2];

	tmp = pip;
	while (tmp->next_pip)
	{
		if (pipe(fd) < 0)
			perror("error");
		if (tmp->index == 0)
			tmp->pip_in = tmp->pip_outfile;
		tmp->next_pip->pip_in = fd[0];
		tmp->pip_out = fd[1];
		tmp = tmp->next_pip;
	}
	tmp->pip_out = 1;
	return (pip);
}

t_pip	*redirect1(t_pip *pip)
{
	int	i;

	i = 0;
    while (pip->pip_arg[i] != NULL)
	{
		if (pip->pip_arg[i][0] == '<' || pip->pip_arg[i][0] == '>')
			file_red_pip(pip, i);
		else
			i++;
	}
	return (pip);
}

void	child_pip(t_pip *pip, char **env)
{
	// pid_t	pid;
	char	*led;

	pip = redirect1(pip);
	// waitpid(pip->pid, NULL, 0);
	pip->pid = fork();
	if (!pip->pid)
	{
		if (pip->pip_in > 1)
			dup2(pip->pip_in, 0);
		if (pip->pip_out > 1)
			dup2(pip->pip_out, 1);
		redir_pip(pip, env);
		if (pip->pip_in == 1)
		{
			led = get_next_line(pip->pip_in);
			while (led)
			{
				write(pip->pip_out, led, ft_strlen(led));
				free(led);
				led = get_next_line(pip->pip_in);
			}
		}
		exit(0);
	}
	close_pip_file(pip);
}

t_pip	*child_process_pip(t_pip *pip, char **env)
{
	// int			i;
	// int			j;
	t_pip		*dmp;

	dmp = pip;
	// i = 0;
	while (dmp)
	{
		child_pip(dmp, env);
		dmp = dmp->next_pip;
		// i++;
	}
	// j = 0;
	// while (j < i)
	// {
		// waitpid(pip->next_pip->pid, NULL, 0);
		// waitpid(pip->pid, NULL, 0);
		// j++;
	// }
	return (pip);
}

void	app_redir(t_pip *pip, char **env)
{
	init_pip(pip);
	pip = child_process_pip(pip, env);
}
