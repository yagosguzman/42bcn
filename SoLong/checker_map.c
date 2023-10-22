/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:57:38 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/22 12:49:26 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	checker_exec(t_node *game, char **argv)
{
	if (valid_file(argv[1] != 0 || allowed_map(game, argv[1]) != 0))
		return (1);
	return (0);
}

int	valid_file(char *map)
{
	int	len;

	len = ft_strlen(map) - 1;
	if (map[len] != 'r' || map[len - 1] != 'e' || map[len - 2] != 'b'
		|| map[len - 3] != '.')
	{
		ft_putstr_fd("Invalid file extension, the map MUST BE a .ber file.", 2);
		return (1);
	}
	return (0);
}

int	allowed_map(t_node *game, char *map)
{
	char	*allowed;
	int		i;
	int		j;

	i = 0;
	j = 0;
	allowed = "01CEP";
	while (map[i])
	{
		while (allowed[j])
		{
			if (map[i] != allowed[j])
				j++;
			else
			{
				j == 0;
				i++;
			}
		}
		if (allowed[j] == '\0')
			return (ft_error(game, 2));
	}
	return (0);
}

