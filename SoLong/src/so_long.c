/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:49:59 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/26 17:41:07 by ysanchez         ###   ########.fr       */
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

	game = NULL;

	if (argc != 2)
	{
		ft_putstr_fd("Error, please write ./so_long <anymap.ber>", 2);
		return (1);
	}
	if (checker_exec(game, argv[1]) != 0)
		return (1);
	return (0);
}