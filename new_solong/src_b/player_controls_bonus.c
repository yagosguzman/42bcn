/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:42:08 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/08 22:11:20 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/solong_bonus.h"

void	move_up(t_game *game)
{
	int	next;

	next = game->pos - game->len;
	if (game->wholemap[next] != '1' && check_win(next, game) == 0)
	{
		print_moves(game);
		game->moves++;
		if (game->wholemap[next] == 'E')
		{
			game->wholemap[game->pos] = '0';
			game->wholemap[next] = 'X';
		}
		else
		{
			if (game->wholemap[next] == 'C')
				game->coins--;
			if (game->wholemap[game->pos] == 'X')
				game->wholemap[game->pos] = 'E';
			else
				game->wholemap[game->pos] = '0';
			game->wholemap[next] = 'P';
		}
		game->pos = next;
	}
	game->currentpos = game->pup;
}

void	move_down(t_game *game)
{
	int	next;

	next = game->pos + game->len;
	if (game->wholemap[next] != '1' && check_win(next, game) == 0)
	{
		print_moves(game);
		game->moves++;
		if (game->wholemap[next] == 'E')
		{
			game->wholemap[game->pos] = '0';
			game->wholemap[next] = 'X';
		}
		else
		{
			if (game->wholemap[next] == 'C')
				game->coins--;
			if (game->wholemap[game->pos] == 'X')
				game->wholemap[game->pos] = 'E';
			else
				game->wholemap[game->pos] = '0';
			game->wholemap[next] = 'P';
		}
		game->pos = next;
	}
	game->currentpos = game->pdown;
}

void	move_left(t_game *game)
{
	int	next;

	next = game->pos - 1;
	if (game->wholemap[next] != '1' && check_win(next, game) == 0)
	{
		print_moves(game);
		game->moves++;
		if (game->wholemap[next] == 'E')
		{
			game->wholemap[game->pos] = '0';
			game->wholemap[next] = 'X';
		}
		else
		{
			if (game->wholemap[next] == 'C')
				game->coins--;
			if (game->wholemap[game->pos] == 'X')
				game->wholemap[game->pos] = 'E';
			else
				game->wholemap[game->pos] = '0';
			game->wholemap[next] = 'P';
		}
		game->pos = next;
	}
	game->currentpos = game->pleft;
}

void	move_right(t_game *game)
{
	int	next;

	next = game->pos + 1;
	if (game->wholemap[next] != '1' && check_win(next, game) == 0)
	{
		print_moves(game);
		game->moves++;
		if (game->wholemap[next] == 'E')
		{
			game->wholemap[game->pos] = '0';
			game->wholemap[next] = 'X';
		}
		else
		{
			if (game->wholemap[next] == 'C')
				game->coins--;
			if (game->wholemap[game->pos] == 'X')
				game->wholemap[game->pos] = 'E';
			else
				game->wholemap[game->pos] = '0';
			game->wholemap[next] = 'P';
		}
		game->pos = next;
	}
	game->currentpos = game->pright;
}

void	player_move(int key, t_game *game)
{
	if (key == W)
		move_up(game);
	if (key == S)
		move_down(game);
	if (key == A)
		move_left(game);
	if (key == D)
		move_right(game);
	render_map(game);
}
