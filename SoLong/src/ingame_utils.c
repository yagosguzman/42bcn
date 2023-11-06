/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:12:13 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/06 13:15:07 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	keypress(int key, t_game *game)
{
	if (key == ESC || key == 17)
	{
		mlx_destroy_window(game->mlx, game->win);
		free(game);
		exit (0);
	}
	if (key == W || key == ARR_UP)
		player_move(W, game);
	if (key == A || key == ARR_LEFT)
		player_move(A, game);
	if (key == S || key == ARR_DOWN)
		player_move(S, game);
	if (key == D || key == ARR_RIGHT)
		player_move(D, game);
	return (0);
}

int	check_win(int pos, t_game *game)
{
	if (game->coins == 0)
		select_img(game, 'X', game->exitloc);
	if (game->wholemap[pos] == 'E' && game->coins == 0)
	{
		ft_putstr_fd("CONGRATULATIONS!\nThe samurai escaped!", 1);
		game->finish = 1;
		// ft_free(game);
		return (1);
	}
	if (game->wholemap[pos] == 'E' && game->coins != 0)
	{
		ft_putstr_fd("Collect all the katanas to open the door.", 1);
		return (0);
	}
	else
		return (0);
}
