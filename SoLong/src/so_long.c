/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:49:59 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/08 20:26:45 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

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

int	init_data(t_game *game)
{
	minilib_init(game);
	init_img(game);
	render_map(game);
	return (0);
}

static int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->wholemap);
	free(game->btmap);
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
