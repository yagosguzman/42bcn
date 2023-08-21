/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:49:44 by ysanchez          #+#    #+#             */
/*   Updated: 2023/08/21 16:42:37 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*merge_strings(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = malloc ((length_line(s1) + length_line(s2) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*read_line(int fd, char *buffer, char *stash)
{
	int		i;
	char	*temp;

	i = 1;
	while (i != '\0')
	{
		i = read (fd, buffer, BUFFER_SIZE);
		if (read <= 0)
		{
			free (buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		if (!stash)
			stash = malloc(1 * sizeof(char));
		temp = stash;
		stash = merge_strings(temp, buffer);
	}
	return (stash);
}

int	length_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*find_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
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
	int		i;
	int		j;
	char	*temp_stash;

	i = 0;
	j = 0;
	temp_stash = stash;
	stash = malloc((length_line(temp_stash) - length_line(line) + 1)
			* sizeof(char));
	if (!stash)
		return (NULL);
	i = 0;
	while (temp_stash[j] != '\0')
	{
		stash[i] = temp_stash[j];
		i++;
		j++;
	}
	stash[i] = '\0';
	free (temp_stash);
	return (stash);
}
