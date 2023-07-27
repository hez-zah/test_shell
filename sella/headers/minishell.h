/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:42:27 by oswin             #+#    #+#             */
/*   Updated: 2023/06/27 21:29:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
// # include <limits.h>
// # include <sys/stat.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "libft.h"
# include "mini_shell.h"
# define NC	"\033[0m"
# define GREEN "\033[1;32m"

typedef enum e_token_id
{
	Pipe,
	Str,
	Heredoc,
	Read,
	Write,
	Append
}				t_token_id;

typedef struct s_token
{
	t_token_id	id;
	char		*word;
}				t_token;

typedef struct s_pipe//`
{
	char	**tokens;
}				t_pipe;

typedef struct s_keyval//
{
	char	*key;
	char	*value;
}				t_keyval;

typedef struct s_mini
{
	char	*input;
	char	**environ;
	t_list	*env;//
	int		save_out;
	int		save_in;
	int		last_return;
}				t_mini;

// environment/ev_init_env.c
t_list	*freekeyvalue(char *key, char *value);
t_list	*ev_keyval_lst_add(char *key, char *value);
t_list	*ev_single_env_to_lst(char *env);
void	ev_del_keyval(void *in);
t_list	*ev_init_env(char **environ);
char	*ev_getenv(char *key, t_list *envlst);

// execute/parser
int	count_words(t_list *tokens);
char	**get_args_exec(t_list *tokens);
void	parser_init(t_pipe *pipe, char **tokenarr);
int	ms_lstadd_pipe(t_list **pipes, char **tokenarr);
t_list	*ms_parser(t_list **tokens);

// lexer/lexer.c
int	lx_error(char *token);
int	ms_lexer(t_list *tokens);

// tokenizer/tk_expander.c
char	*tk_replace_env(char *word, int dollar, t_list *env);
char	*tk_expander(char *word, t_list *env);


// tokenizer/tk__name_tokens.c
void	tk_name_token(void *in);

// tokenizer/tk_remove_quotes.c
void	tk_remove_quotes(void *token);


// tokenizer/tk_tokenizer.c
t_list	*ms_tokenizer(char *input);

// tokenizer/tk_utils.c
void	ms_del_token(void *incomming);
int	ms_lstadd_token(t_list **tokens, char *word);
int	ms_find_offset(char *in, char *delimiters, int offset);
int	ms_skip_chars(char *in, char *to_skip, int offset);

// tokenizer/tk_wordsplit.c
int ms_find_word_end(char *input, int i, char state);
char	*ms_claim_word(char *input, int start, int size);
int	ms_add_tokens(t_list **tokens, char *input);

// exit_expansion.c
void	ft_putstringtostderror(char *s1, char *s2);
void	fillnewinput(t_mini *data, char *exitstatus, char **newinput, int c);
int	count_exit_status(char *input);
void	replaceexitstatus(t_mini *data);

// main.c
void	ft_disruptive_exit(char *exit_status, int exit_int);
void	ft_malloc_fail_check(void *status);
int	ms_init(t_mini *mini, int argc, char **newenv);
void	ms_exit_cleanup(t_mini *mini);
int	main(int argc, char **argv, char **newenv);

// ms_line_executer.c
void	ms_line_executer(t_mini *data);

// fd_redirections.c
void	*fd_redirections(t_pipe *info);
void	fd_open_and_replace(int *to_replace, char *filename, int openflags);
void	fd_redirect(t_pipe *info, int index);

// utils.c
int	ft_strcmp(const char *s1, const char *s2);
void	ft_strcpy(char *dst, char *src);
int	ft_strclen(char *str, char c);
int	ft_strslen(char *str, char *check);
char	*ft_strcdup(const char *s1, char c);


t_pip	*lstadd_back1(t_pip *lst, t_pip *new);
t_pip	*lst_new1(void);
int		free_pip_arg(char **str);

#endif
