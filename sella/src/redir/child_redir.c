#include "../../headers/minishell.h"

void	print_err(char *led)
{
	write(2, led, ft_strlen(led));
	write(2, ": No such file or directory. ", 29);
	write(2, "\n", 1);
	exit(1);
}

void	checkdir(char *led, char **str, char **env)
{
	struct stat path_stat;

	stat(led, &path_stat);
	if (S_ISDIR(path_stat.st_mode))
	{
		write(2, led, ft_strlen(led));
		write(2, ": is a directory.\n", 18);
	}
	else
	{
		execve(led, str, env);
		write(2, led, ft_strlen(led));
		write(2, ": command not found\n", 21);
	}
}

int	ft_check_cmd_arg(char *str)
{
	if (!ft_strncmp(str, "<<", 2) || !ft_strncmp(str, "<", 1)
		|| !ft_strncmp(str, ">", 1) || !ft_strncmp(str, "", 1))
		return (0);
	return (1);
}

int		check_infile_herd(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_strncmp(str[i], "<<", 2) && str[i + 1])
			return (1);
	return (0);
}

void		refine_args(t_pip *pip, int i)
{
	free(pip->pip_arg[i]);
	free(pip->pip_arg[i + 1]);
	pip->pip_arg[i] = NULL;
	pip->pip_arg[i + 1] = NULL;
	while (pip->pip_arg[i + 2] != NULL)
	{
		pip->pip_arg[i] = pip->pip_arg[i + 2];
		i++;
	}
	pip->pip_arg[i] = NULL;
}

void	file_red_pip(t_pip *pip, int i)
{
	if (!ft_strncmp(pip->pip_arg[i], "<<", 2))
	{
		refine_args(pip, i);
		return ;
	}
	else if (!ft_strncmp(pip->pip_arg[i], "<", 1) && pip->pip_arg[i + 1])
		pip->pip_infile = creat_file1(pip->pip_arg[i + 1], 0);
	else if (!ft_strncmp(pip->pip_arg[i], ">>", 2) && pip->pip_arg[i + 1])
		pip->pip_outfile = creat_file1(pip->pip_arg[i + 1], 2);
	else if (!ft_strncmp(pip->pip_arg[i], ">", 1) && pip->pip_arg[i + 1])
		pip->pip_outfile =  creat_file1(pip->pip_arg[i + 1], 1);
	refine_args(pip, i);
}

void	child_red_pip(char **env, t_pip  *pip)
{
	char	*led;

	if (pip->access)
		dup2(pip->herd_in, 0);
	else if (pip->pip_infile > 0)
		dup2(pip->pip_infile, 0);
	if (pip->pip_outfile != 1)
		dup2(pip->pip_outfile, 1);
	led = pip->pip_arg[0];
	if (!access(led, F_OK))
		checkdir(led, pip->pip_arg, env);
	else if (access(led, F_OK) && !ft_strnstr(led, "/", ft_strlen(led)))
	{
		if (ft_patht(led, env) && led)
			execve(ft_patht(led, env), pip->pip_arg, env);
		else
		{
			write(2, led, ft_strlen(led));
			write(2, ": command not found\n", 21);
		}
	}
	else
		print_err(led);
	close_file(pip);
}

void	redir_pip(t_pip *pip, char **env)
{
	child_red_pip(env, pip);
}
