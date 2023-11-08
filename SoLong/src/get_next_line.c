/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:36:59 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/08 12:38:39 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

char	*read_line(int fd, char *stash)
{
	int		i;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free_gnl(&stash));
	i = 1;
	while (i > 0 && !ft_strlen_mode(stash, 2))
	{
		i = read (fd, buffer, BUFFER_SIZE);
		if (i > 0)
		{
			buffer[i] = '\0';
			stash = merge_strings(stash, buffer);
			if (!stash)
			{
				free (buffer);
				return (ft_free_gnl(&stash));
			}
		}
	}
	free(buffer);
	if (i == -1 || (i == 0 && ft_strlen_mode(stash, 1) == 0))
		return (ft_free_gnl(&stash));
	return (stash);
}

char	*find_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (stash[ft_strlen_mode(stash, 3)] == '\n')
		line = malloc((ft_strlen_mode(stash, 3) + 2) * sizeof(char));
	else
		line = malloc((ft_strlen_mode(stash, 3) + 1) * sizeof(char));
	if (!line)
		return (ft_free_gnl(&stash));
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_stash(char *line, char *stash)
{
	int			i;
	int			j;
	char		*new;

	i = 0;
	j = (ft_strlen_mode(stash, 3) + ft_strlen_mode(stash, 2));
	new = malloc((ft_strlen_mode(stash, 1)
				- ft_strlen_mode(line, 1) + 1) * sizeof(char));
	if (!new)
		return (ft_free_gnl(&stash));
	if (ft_strlen_mode(stash, 2) && stash[j])
	{
		while (stash[j] != '\0')
			new[i++] = stash[j++];
		new[i] = '\0';
		ft_free_gnl(&stash);
	}
	else
	{
		free(new);
		return (ft_free_gnl(&stash));
	}
	return (new);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(1 * sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	stash = read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = find_line(stash);
	if (!line)
		return (NULL);
	stash = clean_stash(line, stash);
	return (line);
}
