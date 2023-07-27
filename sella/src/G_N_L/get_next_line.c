/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:27:27 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/03/18 01:35:21 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// char	*lock(char *stash, char *buf, int ret)
// {
// 	char	*ptr;

// 	buf[ret] = '\0';
// 	ptr = stash;
// 	stash = ft_strjoin1(stash, buf);
// 	free (ptr);
// 	stash = conc (stash, buf);
// 	return (stash);
// }

char	*read_static(char *stash, int fd)
{
	char	*buf;
	char	*ptr;
	int		ret;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ret = 1;
	while (!ft_strchr(stash, '\n') && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			if (stash)
				free (stash);
			free (buf);
			return (NULL);
		}
		buf[BUFFER_SIZE] = '\0';
		ptr = stash;
		stash = ft_strjoin1(stash, buf);
		free(ptr);
	}
	free(buf);
	return (stash);
}

// char	*read_line(char *stash)
// {
// 	char	*line;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (stash[i] != '\n' && stash[i] != '\0')
// 		i++;
// 	line = (char *)malloc((i + 2) * sizeof(char));
// 	if (!line)
// 		return (NULL);
// 	j = 0;
// 	read
// 	while (stash[j] != '\n' && stash[j] != '\0')
// 	{
// 		line[j] = stash[j];
// 		j++;
// 	}
// 	if (stash[j] == '\n')
// 	{
// 		line[j] = '\n';
// 		j++;
// 	}
// 	line[j] = '\0';
// 	return (line);
// }

// char	*save_static(char *txt)
// {
// 	char	*save;
// 	size_t	i;

// 	i = 0;
// 	while (txt[i] != '\n' && txt[i] != '\0')
// 		i++;
// 	if ((ft_strlen1(txt) - i) == 0)
// 	{
// 		save = (char *)malloc(1 * sizeof(char));
// 		if (!save)
// 			return (NULL);
// 		save[0] = '\0';
// 		free (txt);
// 		return (save);
// 	}
// 	save = (char *)malloc((ft_strlen1(txt) - i) * sizeof(char));
// 	if (!save || !txt)
// 		return (NULL);
// 	i++;
// 	save = copy(txt, save, i);
// 	free (txt);
// 	return (save);
// }

char	*get_next_line(int fd)
{
	// static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	line = read_static(line, fd);
	// if (!stash)
	// {
	// 	free (stash);
	// 	return (NULL);
	// }
	// line = read_line(line);
	// stash = save_static(stash);
	return (line);
}
