/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:45:13 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/02 15:03:27 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

void	check_firstline(t_game *game)
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

void	check_lastline(t_game *game)
{
	int	i;

	i = (game->height -1) * game->len;
	while (game->wholemap[i++] != '\0')
		if (game->wholemap[i] != '1')
			ft_error(game, 3);
}

void	check_walls(t_game *game)
{
	int	first;
	int	last;

	first = 0;
	last = game->len - 2;
	check_firstline(game);
	check_lastline(game);
	while (first < ft_strlen(game->wholemap)
		|| last < ft_strlen(game->wholemap))
	{
		if (game->wholemap[first] != '1' || game->wholemap[last] != '1')
			ft_error(game, 3);
		first += game->len;
		last += game->len;
	}
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

// int	main (int argc, char **argv)
// {
// 	t_node	*game;

// 	game = 0;
// 	if (argc == 2)
// 		printf("%i", open_map(argv[1], game));
// 	else
// 		return (1);
// 	return (0);
// }