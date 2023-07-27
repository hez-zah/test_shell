

#include "../../headers/minishell.h"

t_list	*ms_tokenizer(char *input)
{
	t_list	*tokens;

	tokens = 0;
	if (ms_add_tokens(&tokens, input))
	{
		ft_lstclear(&tokens, ms_del_token);
		ft_disruptive_exit("malloc fail", 1);
	}
	ft_lstiter(tokens, tk_name_token);
	return (tokens);
}
