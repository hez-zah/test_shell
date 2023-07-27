

#include "../../headers/minishell.h"

t_list	*freekeyvalue(char *key, char *value)
{
	free(key);
	free(value);
	return (NULL);
}

t_list	*ev_keyval_lst_add(char *key, char *value)
{
	t_list		*new;
	t_keyval	*keyval;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (freekeyvalue(key, value));
	keyval = malloc(sizeof(t_keyval));
	if (keyval == NULL)
	{
		free(new);
		return (freekeyvalue(key, value));
	}
	new->content = keyval;
	new->next = NULL;
	keyval->key = key;
	if (value)
		keyval->value = value;
	else
		keyval->value = ft_strdup("");
	ft_malloc_fail_check(keyval->value);
	return (new);
}

t_list	*ev_single_env_to_lst(char *env)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	key = ft_strcdup(env, '=');
	ft_malloc_fail_check(key);
	while (env[i] && env[i] != '=')
		i++;
	value = ft_strcdup(&env[i + 1], 0);
	if (value == NULL)
	{
		free(key);
		ft_malloc_fail_check(value);
	}
	return (ev_keyval_lst_add(key, value));
}

void	ev_del_keyval(void *in)
{
	t_keyval	*keyval;

	keyval = (t_keyval *)in;
	free(keyval->key);
	free(keyval->value);
	free(keyval);
}

t_list	*ev_init_env(char **environ)
{
	int		i;
	t_list	*new;
	t_list	*tmp;

	i = 0;
	new = NULL;
	while (environ[i])
	{
		tmp = ev_single_env_to_lst(environ[i]);
		if (tmp == NULL)
		{
			ft_lstclear(&new, ev_del_keyval);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		i++;
	}
	return (new);
}

char	*ev_getenv(char *key, t_list *envlst)
{
	t_keyval	*keyval;

	while (envlst != NULL)
	{
		keyval = (t_keyval *)envlst->content;
		if (ft_strncmp(key, keyval->key, 1 + ft_strlen(key)) == 0)
			return (keyval->value);
		envlst = envlst->next;
	}
	return (NULL);
}
