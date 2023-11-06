/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:45:13 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/06 21:23:58 by ysanchez         ###   ########.fr       */
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

int	open_map(char *map, t_game *game)
{
	int		fd;
	char	*line;

	game->len = 0;
	game->height = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (ft_free(game));
	game->wholemap = NULL;
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
		game->wholemap = ft_strjoin(game->wholemap, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	if (!s1)
		s1 = "";
	newstr = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	// free(s1); ESTE FREE ES NECESARIO POR TEMA DE LEAKS PERO CON EL NO EJECUTA
	return (newstr);
}
