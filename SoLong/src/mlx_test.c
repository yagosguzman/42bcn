/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:07:42 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/01 18:13:26 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	keypress(int keysym, t_node *game)
{
	(void)game;
	printf("You have pressed %d.\n", keysym);
	return (0);
}

int	destroy_test(t_node *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	return (0);
}
