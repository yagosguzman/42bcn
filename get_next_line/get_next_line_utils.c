/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:49:44 by ysanchez          #+#    #+#             */
/*   Updated: 2023/08/10 19:50:32 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *find_line (int fd, char *stash)
{
	int	i;
	int	j;

	i = 0;
	j = fd;
	while (*stash != '\0' || *stash != '\n')
	{
		while (i <= n)
		{
			read(fd, *buf, BUFFER_SIZE)
			line[j] = buf[i];
			i++;
			j++;
		}
	}
}