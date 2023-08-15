/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:49:44 by ysanchez          #+#    #+#             */
/*   Updated: 2023/08/15 14:14:10 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buffer, char *stash)
{
	int	i;

	i = 1;
	while (i != '\0')
	{
		i = read (fd, buffer, BUFFER_SIZE);
		if (read <= 0)
		{
			free (buffer);
			return (NULL);
		}
		buffer[BUFFER_SIZE + 1] = '\0';
		i = 0;
		while (buffer[i] != '\0')
		{
			stash[i] = buffer[i];
			i++;
		}
		stash[++i] = '\0';
	}
	return (stash);
}

int	length_line(char *stash)
{
	int	i;

	i = 0;
	while (stash)
	{
		if (stash[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

char	*find_line(char *line, char *stash)
{
	int	i;

	i = 0;
	while (stash[i] != '\0' || stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[++i] = '\n';
	line[++i] = '\0';
	return (line);
}

char	*clean_stash(char *line, char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	j = 0;
	new_stash = malloc(BUFFER_SIZE + 1 * sizeof(char));
	while (line[i] == stash[j])
	{
		i++;
		j++;
	}
	i = 0;
	while (stash[j] != '\0')
	{
		new_stash[i] = stash[j];
		i++;
		j++;
	}
	new_stash[++i] = '\0';
	return (new_stash);
}
