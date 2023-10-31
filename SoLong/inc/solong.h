/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:58:12 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/31 21:56:45 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include "../minilibx/mlx.h"

typedef struct s_node
{
	void	*mlx;
	void	*win;
	void	*images[9];
	char	*line;
	char	*wholemap;
	int		coins;
	int		exit;
	int		player;
	int		error;
	int		linecheck;
	int		moves;
	int		len;
	int		height;
}	t_node;

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
# endif

/*GET NEXT LINE*/
char	*get_next_line(int fd);
char	*read_line(int fd, char *stash);
char	*find_line(char *stash);
char	*clean_stash(char *line, char *stash);
char	*ft_free_gnl(char **str);
char	*merge_strings(char *s1, char *s2);
int		ft_strlen_mode(char *str, int mode);

/*CHECKERS*/
void	valid_file(t_node *game, char *map);
void	check_walls(t_node *game);
void	check_rectangular(t_node *game);
void	checker_exec(t_node *game, char *argv);


/*UTILS*/
int		ft_error(t_node *game, int errnum);
int		ft_free(t_node *game);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);

/*MAP*/
int		open_map(char *map, t_node *game);
void	check_firstline(t_node *game);
void	check_lastline(t_node *game);
void	check_wholemap(t_node *game);

/*GAME*/
void	window_init(t_node *game, char *map);

#endif


