/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:49:44 by ysanchez          #+#    #+#             */
/*   Updated: 2023/08/12 19:43:48 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_line(int fd, char *stash)
{
	int			i;
	static int	j;

	while (*stash != '\0' || *stash != '\n')
	{
		while (i <= BUFFER_SIZE)
		{
			read(fd, buffer, BUFFER_SIZE);
			line[j] = buf[i];
			i++;
			j++;
		}
	}
}

char	*read_line(int fd, char *buffer, char *stash)
{
	int			i;
	static int	j;

	i = 1;
	j = 0;
	while (i != '\0')
	{
		i = read (fd, buffer, BUFFER_SIZE);
		if (read == -1)
			return (NULL);
		if (i == 0)
			return ;
		buffer[i] = '\0';
		stash[j] = 
	}
}

char	*clean_stash(char *line)
{

}