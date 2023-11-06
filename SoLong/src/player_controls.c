/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:42:08 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/06 13:32:52 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

void	move_up(t_game *game)
{
	int	i;
	int	next;

	i = game->pos;
	next = i - game->len;
	if (game->wholemap[next] && game->wholemap[next] != '1')
	{
		if (!check_win(next, game))
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

	i = game->pos;
	next = i + game->len;
	if (game->wholemap[next] != '1')
	{
		if (!check_win(next, game))
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

	i = game->pos;
	next = i - 1;
	if (game->wholemap[next] && game->wholemap[next] != '1')
	{
		if (!check_win(next, game))
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

	i = game->pos;
	next = i + 1;
	if (game->wholemap[next] && game->wholemap[next] != '1')
	{
		if (!check_win(next, game))
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

void	player_move(int key, t_game *game)
{
	// mlx_put_image_to_window(game->mlx, game->win, game->floor, game->x, game->y);
	if (key == W)
	{
		move_up(game);
		check_win(game->pos, game);
		print_moves(game);
		render_map(game);
	}
	if (key == S)
	{
		move_down(game);
		check_win(game->pos, game);
		print_moves(game);
		render_map(game);
	}
	if (key == A)
	{
		move_left(game);
		check_win(game->pos, game);
		print_moves(game);
		render_map(game);
	}
	if (key == D)
	{
		move_right(game);
		check_win(game->pos, game);
		print_moves(game);
		render_map(game);
	}
}
