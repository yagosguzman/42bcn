/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:51:08 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/30 19:29:06 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
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

int	ft_free(t_node *game)
{
	game->error = 1;
	if (game->line)
		free(game->line);
	if (game)
		free(game);
	return (1);
}

int	ft_error(t_node *game, int errnum)
{
	ft_putstr_fd("Error\n", 2);
	if (errnum == 1)
		ft_putstr_fd("Incorrect map file extension.\n", 2);
	if (errnum == 2)
		ft_putstr_fd("Unexpected elements on the map.\n", 2);
	if (errnum == 3)
		ft_putstr_fd("The map is not completely surrounded by walls.\n", 2);
	if (errnum == 4)
		ft_putstr_fd("The map is not rectangular.\n", 2);
	if (errnum == 5)
		ft_putstr_fd("The amount of players, coins or exits is wrong.\n", 2);
	if (errnum == 6)
		ft_putstr_fd("Problem reading the map.\n", 2);
	if (errnum == 7)
		ft_putstr_fd("The map has no possible solution.\n", 2);
	return (ft_free(game));
}

