/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:49:59 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/27 22:24:43 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	init_data(t_node *game, char *map)
{
	/*ponemos todo a 0, hacemos checks del mapa, leemos el mapa
	y lo printamos en pantalla si es correcto*/

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
	open_map(argv[1], game);
	mlx_key_hook(game->win,/*función por definir*/,game);
	mlx_hook(game->win,);
	mlx_loop(game->mlx);
	return (0);
}