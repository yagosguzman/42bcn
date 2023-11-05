/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:12:13 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/05 16:46:19 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	keypress(t_game *game, int key)
{
	if (key == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		free(game);
		return (0);
	}
	if (key == W || key == ARR_UP)
		player_move(game, W);
	if (key == A || key == ARR_LEFT)
		player_move(game, A);
	if (key == S || key == ARR_DOWN)
		player_move(game, S);
	if (key == D || key == ARR_RIGHT)
		player_move(game, D);
	return (0);
}

void	pick_collectable(t_game *game, int i, int j)
{
	if (game->wholemap[i][j] == 'C')
	{
		game->katana--;
		game->wholemap[i][j] == '0';
	}

}

int	check_win(t_game *game, char pos)
{
	if (pos == 'E' && game->katana == 0)
	{
		ft_putstr_fd("CONGRATULATIONS!\nThe samurai escaped!", 1);
		ft_free(game);
		return (0);
	}
	if (pos == 'E' && game->katana != 0)
	{
		ft_putstr_fd("Collect all the katanas to open the door.", 1);
		return (1);
	}
}

void	player_move(t_game *game, int key, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, game->floor, game->x, game->y);
	if (game->wholemap[i - game->len] && game->wholemap[i - game->len] != '1'
		&& key == W)
	{
		
	}
	if (game->wholemap[i + game->len] && game->wholemap[i + game->len] != '1'
		&& key == S)
	{
		
	}
	if (game->wholemap[i - 1] && game->wholemap[i - 1] != '1' && key == A)
	{
		
	}
	if (game->wholemap[i + 1] && game->wholemap[i + 1] != '1' && key == D)
	{
		
	}
}