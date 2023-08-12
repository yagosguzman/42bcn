/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:36:59 by ysanchez          #+#    #+#             */
/*   Updated: 2023/08/12 20:49:17 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*stash;
	char			*line;
	static int		j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, stash);
	free(buffer);
	if (!line)
		return (NULL);
	stash = clean_stash(line);
	return (line);
}

int	main (void)
{
	fd = open("sample3.txt", O_RDONLY | O_CREAT);
	get_next_line(fd);
	return (0);
}