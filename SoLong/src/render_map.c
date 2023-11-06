/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:49:41 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/06 21:38:41 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

void	print_moves(t_game *game)
{
	if (!game->finish)
	{
		ft_putstr_fd("Player moves : ", 1);
		ft_putnbr(game->moves);
		write(1, "\n", 1);
	}
}

int	minilib_init(t_game *game)
{
	game->x = (game->len - 1) * T_SIZE;
	game->y = (game->height) * T_SIZE;
	game->moves = 1;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (ft_error_mlx(1));
	game->win = mlx_new_window(game->mlx, game->x, game->y, "so_long");
	if (game->win == NULL)
		return (free(game->mlx), ft_error_mlx(2));
	return (0);
}

void	select_img(t_game *game, char c, int pos)
{
	int	x;
	int	y;

	x = (pos % game->len) * T_SIZE;
	y = (pos / game->len) * T_SIZE;
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor, x, y);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x, y);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->katana, x, y);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->door, x, y);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->currentpos, x, y);
	if (c == 'W')
		mlx_put_image_to_window(game->mlx, game->win, game->opdoor, x, y);
	if (c == 'X')
	{
		if (game->coins == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->opdoor, x, y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->door, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->currentpos, x, y);
	}
}

void	render_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->wholemap[i] != '\0')
	{
		if (game->wholemap[i] != '0')
			select_img(game, '0', i);
		if (game->wholemap[i] == '0')
			select_img(game, '0', i);
		if (game->wholemap[i] == '1')
			select_img(game, '1', i);
		if (game->wholemap[i] == 'C')
			select_img(game, 'C', i);
		if (game->wholemap[i] == 'E' && game->coins > 0)
			select_img(game, 'E', i);
		if (game->wholemap[i] == 'E' && game->coins == 0)
			select_img(game, 'W', i);
		if (game->wholemap[i] == 'P')
			select_img(game, 'P', i);
		if (game->wholemap[i] == 'X')
			select_img(game, 'X', i);
		i++;
	}
}

void	render_win(t_game *game)
{
	int	i;

	i = 0;
	while (game->wholemap[i] != '\0')
	{
		select_img(game, '0', i);
		if (game->wholemap[i] == '1')
			select_img(game, '1', i);
		if (game->wholemap[i] == 'E')
			select_img(game, 'W', i);
		i++;
	}
}
