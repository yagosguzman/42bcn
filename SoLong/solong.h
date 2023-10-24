/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:58:12 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/24 21:15:40 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include "./minilibx/mlx.h"

typedef struct s_node
{
	void	*mlx;
	void	*win;
	void	*player;
	int		error;
	int		line;
	int		linecheck;
	int		moves;
	int		map;
	int		len;
	int		height;
}	t_node;

/*CHECKERS*/
int		valid_file(t_node *game, char *map);
int		allowed_map(t_node *game, char *map);
int		closed_map(t_node *game, char *map);
int		check_rectangular(t_node *game, char *map);
int		check_elements(t_node *game, char *map);
int		checker_exec(t_node *game, char *argv);


/*UTILS*/
int		ft_error(t_node *game, int errnum);
int		ft_free(t_node *game);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *str);


#endif


