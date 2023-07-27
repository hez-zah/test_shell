/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:10:34 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/03/18 01:33:46 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_limit
{
	char			*limit;
	int				index_limit;
	struct s_limit	*next_limit;	
}t_limit;

typedef struct s_pip
{
	char			**pip_arg;
	t_limit			*limit;
	int				fd_red[2];
	pid_t			pid;
	int				permi;
	int				herd_in;
	int				herd_out;
	int				access;
	int				pip_infile;
	int				pip_outfile;
	int				pip_in;
	int				pip_out;
	int				index;
	struct s_pip	*next_pip;
}t_pip;


char		*ft_strjoin_exe(char const *s1, char const *s2);
size_t		ft_strlen1(const char *s);
char		*ft_concat(char const *s1, char const *s2);

char		*patht(char *cmd, char **env);
char		*ft_patht(char *cmd, char **env);
t_limit		*creat_linkdlist(t_limit	*head, char *limit, int index);

char		*get_next_line(int fd);
char		*ft_strjoin1(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
char		*copy(char *txt, char *save, int i);
char		*conc(char *stash, char *buf);

void		init_limit(t_pip *pip);
void		child_1(char **env, t_pip *pip);
void		child_2(char **env, t_pip *pip);
void		affich(t_pip *pip);
void		creat_pipe(t_pip *pip);
void		file_redric(t_pip *pip);

void		redir_pip(t_pip *pip, char **env);
void		herdoc(t_pip *pip);
void		file_red_pip(t_pip *pip, int i);
void		app_redir(t_pip *pip, char **env);

int			ft_check_cmd_arg(char *str);
int			check_herdoc(char **arg);

t_pip		*make_pip(t_pip *head, char *arg, int index);
void		redir_pip(t_pip *pip, char **env);
int			creat_file1(char *filename, int lo_method);
int			check_infile_herd(char **str);

void		close_pip_file(t_pip *pip);
void		close_file(t_pip *pip);
void		free_stack_herdoc(t_limit **limit);
// void		free_pip(t_pip *pip);
// void		free_stack_pip(t_pip *pip);
// void		free_pip(t_list *pip);
int			freeDoublePointer(char **str);
#endif
