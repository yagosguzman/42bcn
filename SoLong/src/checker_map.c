/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:57:38 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/05 12:52:33 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	valid_file(t_game *game, char *map)
{
	int	len;

	len = ft_strlen(map) - 1;
	if (map[len] != 'r' || map[len - 1] != 'e' || map[len - 2] != 'b'
		|| map[len - 3] != '.' || len < 3)
		return (ft_error(game, 1));
	return (0);
}

int	check_rectangular(t_game *game)
{
	int	check;

	check = game->len - 1;
	while (check < ft_strlen(game->wholemap))
	{
		if (game->wholemap[check] != '\n' || game->wholemap[check] != '\0')
			return (ft_error(game, 4));
		check += game->len;
	}
	return (0);
}

int	check_wholemap(t_game *game)
{
	int	i;

	i = 0;
	while (game->wholemap[i])
	{
		if (game->wholemap[i] != '1' || game->wholemap[i] != '0'
			|| game->wholemap[i] != 'C' || game->wholemap[i] != 'E'
			|| game->wholemap[i] != 'P' || game->wholemap[i] != '\n')
			return (ft_error(game, 2));
		if (game->wholemap[i] == 'C')
			game->coins++;
		if (game->wholemap[i] == 'E')
			game->exit++;
		if (game->wholemap[i] == 'P')
			game->player++;
	}
	if (game->coins == 0 || game->exit != 1 || game->player != 1)
		return (ft_error(game, 5));
	return (0);
}

int	check_walls(t_game *game)
{
	int	first;
	int	last;

	first = 0;
	last = game->len - 2;
	check_firstline(game);
	check_lastline(game);
	while (first < ft_strlen(game->wholemap)
		|| last < ft_strlen(game->wholemap))
	{
		if (game->wholemap[first] != '1' || game->wholemap[last] != '1')
			return (ft_error(game, 3));
		first += game->len;
		last += game->len;
	}
	return (0);
}

int	checker_exec(t_game *game, char *argv)
{
	if (valid_file(game, &argv[1]) == 0)
		if (open_map(&argv[1], game) == 0)
			if (check_wholemap(game) == 0)
				if (check_walls(game) == 0)
					if (check_rectangular(game) == 0)
						return (0);
	return (1);
}



