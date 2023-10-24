/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:45:13 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/24 21:57:43 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_endline(char *line, t_node *game)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			game->linecheck == 0;
		i++;
	}
}
int	open_map(char *map, t_node *game)
{
	int	fd;
	char *line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_free(game);
	while (game->map != -1)
	{
		game->height++;
		line = get_next_line(fd);
		if (!line)
			ft_error(game, 6);
		game->len = ft_strlen(line);
		check_endline(line, game);
		if (ft_strlen(line) + game->linecheck != game->len)

	}
}
