/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:49:41 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/08 22:11:16 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/solong_bonus.h"

void	init_img(t_game *game)
{
	int	sz;

	sz = T_SIZE;
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&sz, &sz);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&sz, &sz);
	game->katana = mlx_xpm_file_to_image(game->mlx, "textures/katana.xpm",
			&sz, &sz);
	game->door = mlx_xpm_file_to_image(game->mlx, "textures/door.xpm",
			&sz, &sz);
	game->opdoor = mlx_xpm_file_to_image(game->mlx, "textures/opdoor.xpm",
			&sz, &sz);
	game->pup = mlx_xpm_file_to_image(game->mlx, "textures/pup.xpm",
			&sz, &sz);
	game->pdown = mlx_xpm_file_to_image(game->mlx, "textures/pdown.xpm",
			&sz, &sz);
	game->pleft = mlx_xpm_file_to_image(game->mlx, "textures/pleft.xpm",
			&sz, &sz);
	game->pright = mlx_xpm_file_to_image(game->mlx, "textures/pright.xpm",
			&sz, &sz);
	game->currentpos = game->pdown;
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
