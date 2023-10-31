/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:57:38 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/30 19:19:14 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

void	valid_file(t_node *game, char *map)
{
	int	len;

	len = ft_strlen(map) - 1;
	if (map[len] != 'r' || map[len - 1] != 'e' || map[len - 2] != 'b'
		|| map[len - 3] != '.' || len < 3)
		ft_error(game, 1);
}

void	check_rectangular(t_node *game)
{
	int	check;

	check = ft_strlen(game->len) - 1;
	while (check < ft_strlen(game->wholemap))
	{
		if (game->wholemap[check] != '\n' || game->wholemap[check] != '\0')
			ft_error(game, 4);
		check += game->len;
	}
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

void	checker_exec(t_node *game, char *argv)
{
	valid_file(game, argv[1]);
	open_map(argv[1], game);
	check_walls(game);
	check_rectangular(game);
}
void	data_init(t_node *game)
{
	
}


