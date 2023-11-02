/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:49:41 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/02 14:48:31 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

void	select_img(t_game *game, char c, int i)
{
	int	x;
	int	y;

	x = (i % game->len) * 50;
	y = (i / game->len) * 50;
	if (!game->error)
	{
		if (c == '0')
			mlx_put_image_to_window(game->mlx, game->win, game->tile, x, y);
		if (c == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->wall, x, y);
		if (c == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->key, x, y);
		if (c == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->door, x, y);
		if (c == 'P')
			mlx_put_image_to_window(game->mlx, game->win, game->pdown, x, y);
	}
}

void	render_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->wholemap[i])
	{
		if (game->wholemap[i] == '\n')
			i++;
		if (game->wholemap[i] == '0')
			select_img(game, '0', i);
		if (game->wholemap[i] == '1')
			select_img(game, '1', i);
		if (game->wholemap[i] == 'C')
			select_img(game, 'C', i);
		if (game->wholemap[i] == 'E')
			select_img(game, 'E', i);
		if (game->wholemap[i] == 'P')
			select_img(game, 'P', i);
		i++;
	}
}