/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:18:07 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/08 20:13:31 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

void	create_btmap(t_game *game)
{
	int		i;

	i = 0;
	game->btmap = malloc(sizeof(char) * ft_strlen(game->wholemap) + 1);
	if (!game->btmap)
		ft_error(game, 8);
	while (game->wholemap[i] != '\0')
	{
		game->btmap[i] = game->wholemap[i];
		i++;
	}
	game->btmap[i] = '\0';
}

void	backtrack_map(t_game *game, int pos)
{
	if (pos >= 0 && pos < ft_strlen(game->btmap))
	{
		if (game->btmap[pos] != '1' && game->btmap[pos] != 'X')
		{
			if (game->btmap[pos] == 'C' || game->btmap[pos] == 'E'
				|| game->btmap[pos] == '0')
				game->btmap[pos] = 'X';
			backtrack_map(game, (pos - 1));
			backtrack_map(game, (pos + 1));
			backtrack_map(game, (pos - game->len));
			backtrack_map(game, (pos + game->len));
		}
	}
}

int	check_solution(t_game *game)
{
	int	i;

	i = 0;
	create_btmap(game);
	backtrack_map(game, game->pos);
	while (game->btmap[i])
	{
		if (ft_strchr("01XP\n", game->btmap[i]) == NULL)
			return (ft_error(game, 7));
		i++;
	}
	return (0);
}
