#include "../../headers/minishell.h"

int	creat_file1(char *filename, int lo_method)
{
	if (lo_method == 0)
	{
		if (access(filename, F_OK) == 0)
			return (open(filename, O_RDONLY));
		else
		{
			write(2, "zsh: No such file or directory: ", 32);
			write(2, filename, ft_strlen(filename));
			exit (1);
		}
	}
	else if (lo_method == 1)
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644));
	else
		return (open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644));
}

void	file_redric(t_pip *pip)
{
	int i;

	i = 0;
	while (pip->pip_arg[++i])
	{
		if (!ft_strncmp(pip->pip_arg[i], "<<", 2))
		{
			pip->access = 1;
			continue;
		}
		else if (!ft_strncmp(pip->pip_arg[i], "<", 1) && pip->pip_arg[i + 1])
		{
			pip->access = 0;
		}
	}
}

void	herdoc(t_pip *pip)
{
	t_pip *dmp;

	dmp = pip;
	while (dmp)
	{
		if (check_herdoc(dmp->pip_arg))
		{
			dmp->permi = 0;
			init_limit(dmp);
			dmp->fd_red[0] = 0;
			dmp->fd_red[1] = 1;
			creat_pipe(dmp);
			affich(dmp);
			file_redric(dmp);
			free_stack_herdoc(&dmp->limit);
		}
		dmp = dmp->next_pip;
	}
}
