/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:36:59 by ysanchez          #+#    #+#             */
/*   Updated: 2023/08/15 20:11:39 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	stash = read_line(fd, buffer, stash);
	free(buffer);
	if (!stash)
		return (NULL);
	line = malloc((length_line(stash) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	find_line(line, stash);
	clean_stash(line, stash);
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("sample3.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
