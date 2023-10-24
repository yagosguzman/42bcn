/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:36:59 by ysanchez          #+#    #+#             */
/*   Updated: 2023/08/22 19:40:17 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *stash)
{
	int		i;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	while (i > 0 && !ft_strlen(stash, 2))
	{
		i = read (fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (ft_free(&stash));
		}
		if (i > 0)
		{
			buffer[i] = '\0';
			stash = merge_strings(stash, buffer);
			if (!stash)
				return (ft_free(&buffer));
		}
	}
	free(buffer);
	if (i == 0 && ft_strlen(stash, 1) == 0)
		return (ft_free(&stash));
	return (stash);
}

char	*find_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (stash[ft_strlen(stash, 3)] == '\n')
		line = malloc((ft_strlen(stash, 3) + 2) * sizeof(char));
	else
		line = malloc((ft_strlen(stash, 3) + 1) * sizeof(char));
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
	int			i;
	int			j;
	static char	*new_stash;

	i = 0;
	j = (ft_strlen(stash, 3) + ft_strlen(stash, 2));
	new_stash = malloc((ft_strlen(stash, 1) - 
				ft_strlen(line, 1) + 1) * sizeof(char));
	if (!new_stash)
		return (ft_free(&stash));
	if (ft_strlen(stash, 2) && stash[ft_strlen(stash, 3) + 1])
	{
		while (stash[j] != '\0')
		{
			new_stash[i] = stash[j];
			i++;
			j++;
		}
		new_stash[i] = '\0';
		if (stash != NULL)
			free(stash);
	}
	else
	{
		ft_free(&new_stash);
		return (ft_free(&stash));
	}
	return (new_stash);
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
	stash = clean_stash(line, stash);
	if (!line)
		return (ft_free(&stash));
	return (line);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("sample1.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	return (0);
// }