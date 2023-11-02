/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:49:59 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/01 18:15:25 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	window_init(t_node *game, char *map)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (ft_error_mlx(game, 1));
	game->win = mlx_new_window(game->mlx, 600, 400, "Ninja Escape");
	if (game->win == NULL)
		return (free(game->mlx), ft_error_mlx(game, 2));
	

}

int	init_data(t_node *game, char *map)
{
	/*ponemos todo a 0, hacemos checks del mapa, leemos el mapa
	y lo printamos en pantalla si es correcto*/

}

void	check_possible(t_node *game)
{
	if (game->all_collected && exit == 1)
		return map_valid;
	if (on_wall)
		return (game->error);
	if (on_coin)
		game->coin++;
	if (on_exit && game->all_collected)
		finish_game;
	if(game->can_move)
		return map_valid;
	return (game->error);
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
	mlx_hook(game->win, Keyrelease, KeyReleaseMask, &keypress, &game);
	mlx_loop(game->mlx);
	return (0);
}