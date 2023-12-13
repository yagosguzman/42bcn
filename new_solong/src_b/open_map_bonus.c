/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:45:13 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/08 22:11:24 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/solong_bonus.h"

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

	i = ((game->height -1) * game->len);
	while (game->wholemap[i] != '\0')
		if (game->wholemap[i++] != '1')
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

static void	transfer_stash(t_game *game, char *tmpstash, char *line)
{
	tmpstash = game->wholemap;
	game->wholemap = ft_strjoin(tmpstash, line);
	free(tmpstash);
	free(line);
}

int	open_map(char *map, t_game *game)
{
	int		fd;
	char	*line;
	char	*tmpstash;

	tmpstash = "";
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (ft_free(game));
	line = get_next_line(fd);
	if (!line)
		return (ft_error(game, 6));
	while (line != NULL)
	{
		game->linecheck = 1;
		game->height++;
		if (game->len == 0)
			game->len = ft_strlen(line);
		check_endline(line, game);
		if (ft_strlen(line) + game->linecheck != game->len)
			return (ft_error(game, 4));
		transfer_stash(game, tmpstash, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
