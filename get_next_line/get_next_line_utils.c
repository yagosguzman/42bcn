/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:49:44 by ysanchez          #+#    #+#             */
/*   Updated: 2023/08/15 21:36:25 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*merge_strings(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
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
		else
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
	new_stash[i] = '\0';
	return (new_stash);
}
