/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:36:59 by ysanchez          #+#    #+#             */
/*   Updated: 2023/08/21 20:26:42 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buffer, char *stash)
{
	int		i;

	i = 1;
	while (i != 0 && !ft_strchr(buffer, '\n'))
	{
		i = read (fd, buffer, BUFFER_SIZE);
		if (read < 0)
			return (NULL);
		buffer[i] = '\0';
		stash = merge_strings(stash, buffer);
	}
	if (i == 0 && ft_strlen(stash) == 0)
		return (NULL);
	return (stash);
}

char	*find_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc((length_line(stash) + 1) * sizeof(char));
	if (!line)
		return (NULL);
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
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	j = 0;
	new_stash = malloc((ft_strlen(stash) - ft_strlen(line) + 1) * sizeof(char));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	while (line[j] == stash[j])
		j++;
	while (stash[j] != '\0')
	{
		new_stash[i] = stash[j];
		i++;
		j++;
	}
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!stash)
	{
		stash = malloc(1 * sizeof(char));
		if(!stash)
			return (NULL);
		stash[0] = '\0';
	}
	stash = read_line(fd, buffer, stash);
	free(buffer);
	if (!stash)
		return (NULL);
	line = find_line(stash);
	if (!line)
	{
		free(stash);
		return (NULL);
	}
	stash = clean_stash(line, stash);
	return (line);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("sample1.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	return (0);
// }
