/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:07:42 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/02 21:31:51 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"

// int	keypress(int keysym, t_game *game)
// {
// 	(void)game;
// 	printf("You have pressed %d.\n", keysym);
// 	return (0);
// }

// int	destroy_test(t_game *game)
// {
// 	mlx_destroy_window(game->mlx, game->win);
// 	free(game->mlx);
// 	return (0);
// }

// int	insert_xpm(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	game->key = mlx_xpm_file_to_image(game->mlx, "img/key.xpm", 16, 16);
// }

// int	put_screen(t_game *game)
// {
// 	int	render;

// 	render = mlx_put_image_to_window(game->mlx, game->win, game->images, x , y);
// 	if (!render)
// 		destroy_test(game);
// 	return (0);
// }

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img2;
	char	*path = "../img/pdown.xpm";
	char	*path2 = "../img/katana.xpm";

	int		w = 100;
	int		h = 100;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, w*10, h*10, "Ninja Escape");
	img = mlx_xpm_file_to_image(mlx, path, &w, &h);
	img2 = mlx_xpm_file_to_image(mlx, path2, &w, &h);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 80, 10);

	mlx_loop(mlx);
	return (0);
}
