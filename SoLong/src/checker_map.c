/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:57:38 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/25 13:40:46 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	checker_exec(t_node *game, char *argv)
{
	if (valid_file(game, argv[1]) != 0 || closed_map(game, argv[1]) != 0
		|| check_rectangular(game, argv[1] != 0))
		return (1);
	return (0);
}

int	valid_file(t_node *game, char *map)
{
	int	len;

	len = ft_strlen(map) - 1;
	if (map[len] != 'r' || map[len - 1] != 'e' || map[len - 2] != 'b'
		|| map[len - 3] != '.' || len < 3)
		return (ft_error(game, 1));
	return (0);
}

int	closed_map(t_node *game, char *map)
{
		return (ft_error(game, 3));
	return (0);
}
int	check_rectangular(t_node *game, char *map)
{
		return (ft_error(game, 4));
	return (0);
}

void	check_wholemap(t_node *game)
{
	int	i;

	i = 0;
	while (game->wholemap[i])
	{
		if (game->wholemap[i] != '1' || game->wholemap[i] != '0'
			|| game->wholemap[i] != 'C' || game->wholemap[i] != 'E'
			|| game->wholemap[i] != 'P' || game->wholemap[i] != '\n')
			ft_error(game, 2);
		if (game->wholemap[i] == 'C')
			game->coins++;
		if (game->wholemap[i] == 'E')
			game->exit++;
		if (game->wholemap[i] == 'P')
			game->player++;
	}
	if (game->coins == 0 || game->exit != 1 || game->player != 1)
		ft_error(game, 5);
}


