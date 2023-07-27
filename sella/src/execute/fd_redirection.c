/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fd_redir.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:46:47 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/14 15:27:54 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// void	fd_replacer(int *to_replace, int new_fd)
// {
// 	*to_replace = new_fd;
// }

// void	fd_open_and_replace(int *to_replace, char *filename, int openflags)
// {
// 	int	new_fd;

// 	new_fd = open(filename, openflags, 0666);
// 	if (new_fd == -1)
// 		return ;
//     if (*to_replace != -50) {
//         close(*to_replace);
//     }
// 	*to_replace = new_fd;
// }

void	fd_redirect(t_pipe *info, int index)
{
	// if (ft_strncmp(info->tokens[index], "<<", 2) == 0)
	// 	fd_replacer(&(info->input_fd), heredoc(info->tokens[index + 1]));

	// if (ft_strncmp(info->tokens[index], ">>", 2) == 0)
	// 	fd_open_and_replace(&(info->output_fd), info->tokens[index + 1],
	// 		O_WRONLY | O_APPEND | O_CREAT);
	// else if (ft_strncmp(info->tokens[index], ">", 1) == 0)
	// 	fd_open_and_replace(&(info->output_fd), info->tokens[index + 1],
	// 		O_WRONLY | O_CREAT | O_TRUNC);
	// else if (ft_strncmp(info->tokens[index], "<", 1) == 0)
	// 	fd_open_and_replace(&(info->input_fd), info->tokens[index + 1], O_RDONLY);

	free(info->tokens[index]);
	free(info->tokens[index + 1]);
	info->tokens[index] = NULL;
	info->tokens[index + 1] = NULL;
	while (info->tokens[index + 2] != NULL)
	{
		info->tokens[index] = info->tokens[index + 2];
		index++;
	}
	info->tokens[index] = NULL;
}

// void	*fd_redirections(t_pipe *info)
// {
// 	int	i;

// 	i = 0;
//     while (info->tokens[i] != NULL)
// 	{
// 		if (info->tokens[i][0] == '<' || info->tokens[i][0] == '>')
// 			fd_redirect(info, i);
// 		else
// 			i++;
// 	}
// 	return ((void *)info);
// }
