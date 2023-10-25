/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:51:08 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/25 13:25:55 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
	return (ft_free(game));
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
