/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:16:30 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/02 15:03:08 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_error(t_game *game, int errnum)
{
	ft_putstr_fd("Error\n", 2);
	if (errnum == 1)
		ft_putstr_fd("Incorrect map file extension.\n", 2);
	if (errnum == 2)
		ft_putstr_fd("Unexpected elements on the map.\n", 2);
	if (errnum == 3)
		ft_putstr_fd("The map is not completely surrounded by walls.\n", 2);
	if (errnum == 4)
		ft_putstr_fd("The map is not rectangular.\n", 2);
	if (errnum == 5)
		ft_putstr_fd("The amount of players, coins or exits is wrong.\n", 2);
	if (errnum == 6)
		ft_putstr_fd("Problem reading the map.\n", 2);
	if (errnum == 7)
		ft_putstr_fd("The map has no possible solution.\n", 2);
	return (ft_free(game));
}

int	ft_error_mlx(t_game *game, int errnum)
{
	ft_putstr_fd("Error\n", 2);
	if (errnum == 1)
		ft_putstr_fd("Problem initializing MLX Library.\n", 2);
	if (errnum == 2)
		ft_putstr_fd("Problem initializing Window on MLX.\n", 2);
	return (1);
}
