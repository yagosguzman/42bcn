/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:51:08 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/21 22:34:24 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

int	ft_error(t_node *game, int num)
{
	if (num == 1)
		ft_putstr_fd("Incorrect map file extension, all maps must be .ber", 2);
	if (num == 2)
		ft_putstr_fd("Unexpected elements on the map, impossible to launch", 2);

	ft_free(game);
}
