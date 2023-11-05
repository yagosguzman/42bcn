/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:12:13 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/05 21:16:46 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	keypress(int key, t_game *game)
{
	if (key == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		free(game);
		exit (0);
	}
	if (key == W || key == ARR_UP)
		player_move(game, W, game->pos);
	if (key == A || key == ARR_LEFT)
		player_move(game, A, game->pos);
	if (key == S || key == ARR_DOWN)
		player_move(game, S, game->pos);
	if (key == D || key == ARR_RIGHT)
		player_move(game, D, game->pos);
	return (0);
}

void	pick_collectable(t_game *game, int pos)
{
	if (game->wholemap[pos] == 'C')
	{
		game->katana--;
		game->wholemap[pos] = '0';
	}

}

int	check_win(t_game *game, int pos)
{
	if (game->wholemap[pos] == 'E' && game->katana == 0)
	{
		ft_putstr_fd("CONGRATULATIONS!\nThe samurai escaped!", 1);
		ft_free(game);
		return (0);
	}
	if (game->wholemap[pos] == 'E' && game->katana != 0)
	{
		ft_putstr_fd("Collect all the katanas to open the door.", 1);
		return (1);
	}
	else
		return (0);
}


