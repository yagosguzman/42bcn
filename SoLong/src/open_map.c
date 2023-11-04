/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:45:13 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/04 14:03:49 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	check_firstline(t_game *game)
{
	int	i;

	i = 0;
	while (game->wholemap[i] != '\n')
	{
		if (game->wholemap[i] != '1')
			return (ft_error(game, 3));
		i++;
	}
	return (0);
}

int	check_lastline(t_game *game)
{
	int	i;

	i = (game->height -1) * game->len;
	while (game->wholemap[i++] != '\0')
		if (game->wholemap[i] != '1')
			return (ft_error(game, 3));
	return (0);
}

void	check_endline(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			game->linecheck = 0;
		i++;
	}
}

int	open_map(char *map, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (ft_free(game));
	while (map)
	{
		game->linecheck = 1;
		game->height++;
		line = get_next_line(fd);
		if (!line)
			return (ft_error(game, 6));
		if (game->len == 0)
			game->len = ft_strlen(line);
		check_endline(line, game);
		if (ft_strlen(line) + game->linecheck != game->len)
			return (ft_error(game, 4));
		game->wholemap = ft_strjoin(game->wholemap, line);
		if (line)
			free(line);
	}
	close(fd);
	return (0);
}