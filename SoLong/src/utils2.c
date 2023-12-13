/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:39:57 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/08 20:34:32 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	ft_free(t_game *game)
{
	free(game->wholemap);
	free(game->btmap);
	free(game);
	exit (1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	if (!s1)
		s1 = "";
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

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return (s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return (s);
	return (0);
}
