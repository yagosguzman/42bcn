/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:07:42 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/02 15:02:49 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	keypress(int keysym, t_game *game)
{
	(void)game;
	printf("You have pressed %d.\n", keysym);
	return (0);
}

int	destroy_test(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	return (0);
}

int	insert_xpm(t_game *game)
{
	int	i;

	i = 0;
	game->key = mlx_xpm_file_to_image(game->mlx, "img/key.xpm", 16, 16);
}

int	put_screen(t_game *game)
{
	int	render;

	render = mlx_put_image_to_window(game->mlx, game->win, game->images, x , y);
	if (!render)
		destroy_test(game);
	return (0);
}

int	window_init(t_game *game, char *map)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (ft_error_mlx(game, 1));
	game->win = mlx_new_window(game->mlx, 600, 400, "Ninja Escape");
	if (game->win == NULL)
		return (free(game->mlx), ft_error_mlx(game, 2));
}
