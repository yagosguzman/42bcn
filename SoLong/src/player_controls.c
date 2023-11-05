/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:42:08 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/05 21:22:56 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

void	move_up(t_game *game)
{
	int	i;
	int next;

	i = 0;
	next = i - game->len;
	while (game->wholemap[i] != 'P')
		i++;
	game->pos = i;
	if (game->wholemap[next] && game->wholemap[next] != '1')
	{
		if (!check_win(game, next))
		{
			game->moves++;
			if (game->wholemap[next] == 'C')
				game->coins--;
			game->wholemap[i] = '0';
			game->wholemap[next] = 'P';
		}
	}
	game->currentpos = game->pup;
}

void	move_down(t_game *game)
{
	int	i;
	int	next;

	i = 0;
	next = i + game->len;
	while (game->wholemap[i] != 'P')
		i++;
	game->pos = i;
	if (game->wholemap[next] && game->wholemap[next] != '1')
	{
		if (!check_win(game, next))
		{
			game->moves++;
			if (game->wholemap[next] == 'C')
				game->coins--;
			game->wholemap[i] = '0';
			game->wholemap[next] = 'P';
		}
	}
	game->currentpos = game->pdown;
}

void	move_left(t_game *game)
{
	int	i;
	int	next;

	i = 0;
	next = i - 1;
	while (game->wholemap[i] != 'P')
		i++;
	game->pos = i;
	if (game->wholemap[next] && game->wholemap[next] != '1')
	{
		if (!check_win(game, next))
		{
			game->moves++;
			if (game->wholemap[next] == 'C')
				game->coins--;
			game->wholemap[i] = '0';
			game->wholemap[next] = 'P';
		}
	}
	game->currentpos = game->pleft;
}

void	move_right(t_game *game)
{
	int	i;
	int	next;

	i = 0;
	next = i + 1;
	while (game->wholemap[i] != 'P')
		i++;
	game->pos = i;
	if (game->wholemap[next] && game->wholemap[next] != '1')
	{
		if (!check_win(game, next))
		{
			game->moves++;
			if (game->wholemap[next] == 'C')
				game->coins--;
			game->wholemap[i] = '0';
			game->wholemap[next] = 'P';
		}
	}
	game->currentpos = game->pright;
}

void	player_move(t_game *game, int key, int pos)
{
	mlx_put_image_to_window(game->mlx, game->win, game->floor, game->x, game->y);
	if (key == W)
	{
		move_up(game);
		pick_collectable(game, pos);
		check_win(game, pos);
		print_moves(game);
	}
	if (key == S)
	{
		move_down(game);
		pick_collectable(game, pos);
		check_win(game, pos);
		print_moves(game);
	}
	if (key == A)
	{
		move_left(game);
		pick_collectable(game, pos);
		check_win(game, pos);
		print_moves(game);
	}
	if (key == D)
	{
		move_right(game);
		pick_collectable(game, pos);
		check_win(game, pos);
		print_moves(game);
	}
}