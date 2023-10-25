/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:45:13 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/25 13:59:33 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_firstline(t_node *game)
{
	int	i;

	i = 0;
	while (game->wholemap[i] != '\n')
	{
		if (game->wholemap[i] != '1')
			ft_error(game, 3);
		i++;
	}
}

void	check_lastline(t_node *game)
{
	int	i;

	i = (game->height -1) * game->len;
	while (game->wholemap[i++] != '\n')
		if (game->wholemap[i] != '1')
			ft_error(game, 3);
}

void	check_walls(t_node *game)
{
	int	first;
	int	last;

	first = 0;
	last = game->len - 1;
	check_firstline(game);
	check_lastline(game);
	while (game->wholemap) // este while no va a funcionar.
	{
		if (game->wholemap[first] != 1 || game->wholemap[last] != 1)
			ft_error(game, 3);
		first += game->len;
		last += game->len;
	}
}

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
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_free(game);
	while (game->map != -1)
	{
		game->linecheck = 1;
		game->height++;
		line = get_next_line(fd);
		if (!line)
			ft_error(game, 6);
		game->len = ft_strlen(line);
		check_endline(line, game);
		if (ft_strlen(line) + game->linecheck != game->len)
			ft_error(game, 4);
		game->wholemap = ft_strjoin(game->wholemap, line);
		if (line)
			free(line);
	}
	close(fd);

}
