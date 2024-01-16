#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int i;
	int srcsize;

	i = 0;
	srcsize = ft_strlen(src);
	if (dstsize > 0)
	{
		while (i < srcsize && i < dstsize -1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

char *ft_strdup(const char* src)
{
	int len;
	char *dst;

	len = ft_strlen(src) + 1;
	dst = (char *)malloc(len * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, src, len);
	return (dst);
}

char *ft_strjoin(char *s1, const char *s2, int s2len)
{
	int s1len;
	char *join;
	
	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	join = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, s1len + 1);
	ft_strlcpy((join + s1len), s2, s2len +1);
	free(s1);
	return (join);
}

char *get_next_line(int fd)
{
	int count;
	int last;
	static char buffer[BUFFER_SIZE + 1];
	char *line;
	char *newline;

	line = ft_strdup(buffer);
	while (!(ft_strchr(line, '\n')) && (count = read(fd, buffer, BUFFER_SIZE)) > 0)
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
		ft_strlcpy(buffer, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		last = ft_strlen(line);
		ft_strlcpy(buffer, "", BUFFER_SIZE + 1);
	}
	line[last] = '\0';
	return (line);
}

