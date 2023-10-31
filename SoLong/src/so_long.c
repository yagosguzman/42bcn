/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:49:59 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/31 21:59:01 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

void	window_init(t_node *game, char *map)
{
	game->mlx = mlx_init();
	mlx_new_window(game->mlx, 500, 500, "Ninja Escape");


}

int	init_data(t_node *game, char *map)
{
	/*ponemos todo a 0, hacemos checks del mapa, leemos el mapa
	y lo printamos en pantalla si es correcto*/

}

void	check_solution(t_node *game)
{
	int	i;
	int	up;
	int	down;

	i = 0;
	while (game->wholemap[i])
	{
		up = i - game->len; // esto no siempre va a ser posible
		down = i + game->len; // tambien puede ser que no sea totalmente rodeado si el mapa es grande
		if (game->wholemap[i] == 'C' || game->wholemap[i] == 'E'
			|| game->wholemap[i] == 'P')
		{
			if (game->wholemap[i + 1] == '1' && game->wholemap[i - 1] == '1'
				&& game->wholemap[up] == '1' && game->wholemap[down] == '1')
				ft_error(game, 7);
		}
	}
}

int	main(int argc, char **argv)
{
	t_node	*game;

	if (argc != 2)
	{
		ft_putstr_fd("Error, please write ./so_long <maps/anymap.ber>\n", 2);
		return (1);
	}
	checker_exec(game, argv[1]);

	mlx_key_hook(game->win,/*función por definir*/,game);
	mlx_hook(game->win,);
	mlx_loop(game->mlx);
	return (0);
}