/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:49:59 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/08 12:43:39 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	init_data(t_game *game)
{
	minilib_init(game);
	init_img(game);
	render_map(game);
	return (0);
}

void	init_img(t_game *game)
{
	int	sz;

	sz = T_SIZE;
	game->floor = mlx_xpm_file_to_image(game->mlx, "img/floor.xpm", &sz, &sz);
	game->wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm", &sz, &sz);
	game->katana = mlx_xpm_file_to_image(game->mlx, "img/katana.xpm", &sz, &sz);
	game->door = mlx_xpm_file_to_image(game->mlx, "img/door.xpm", &sz, &sz);
	game->opdoor = mlx_xpm_file_to_image(game->mlx, "img/opdoor.xpm", &sz, &sz);
	game->pup = mlx_xpm_file_to_image(game->mlx, "img/pup.xpm", &sz, &sz);
	game->pdown = mlx_xpm_file_to_image(game->mlx, "img/pdown.xpm", &sz, &sz);
	game->pleft = mlx_xpm_file_to_image(game->mlx, "img/pleft.xpm", &sz, &sz);
	game->pright = mlx_xpm_file_to_image(game->mlx, "img/pright.xpm", &sz, &sz);
	game->currentpos = game->pdown;
}

static int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nPlease write ./so_long <maps/anymap.ber>\n", 2);
		return (1);
	}
	game = ft_calloc(1, sizeof(t_game));
	if (checker_exec(game, argv[1]) != 0)
		return (1);
	init_data(game);
	mlx_key_hook(game->win, keypress, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
