/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam03prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:04:33 by ysanchez          #+#    #+#             */
/*   Updated: 2024/01/03 15:29:48 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);

#endif

UTILS

char *ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int srcsize;
	int i;

	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < srcsize && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

char *ft_strdup(const char *src)
{
	char *dst;
	int len;

	len = ft_strlen(src) + 1;
	dst = (char *)malloc(len) * sizeof (char);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, src, len);
	return (dst);
}

char *ft_strjoin(char *s1, char *s2, int s2len)
{
	int s1len;
	char *join;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	join = (char *)malloc(s1len + s2len + 1) * sizeof(char);
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, (s1len + 1));
	ft_strlcpy((join + s1len), s2, (s2len + 1));
	free (s1);
	return (join);
}
MAIN FUNCTION

char *get_next_line(int fd)
{
	static char *buffer[BUFFER_SIZE + 1];
	char *line;
	char *newline;
	int count;
	int last;

	line = ft_strdup(buffer);
	while ((!ft_strchr(line, '\n')) && (count = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[count] = '\0';
		line = ft_strjoin(line, buffer, count);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		last = newline - line + 1;
		ft_strlcpy(buffer, newline +1, BUFFER_SIZE + 1);
	}
	else
	{
		last = ft_strlen(line);
		ft_strlcpy(buffer, "", BUFFER_SIZE + 1);
	}
	line[last] = '\0';
	return (line);
}
