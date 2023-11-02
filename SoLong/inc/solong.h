/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:58:12 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/02 21:24:56 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include "../mlx/mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*floor;
	void	*wall;
	void	*katana;
	void	*door;
	void	*opdoor;
	void	*pdown;
	void	*pup;
	void	*pleft;
	void	*pright;
	char	*line;
	char	*wholemap;
	bool	all_collected;
	bool	can_move;
	int		coins;
	int		exit;
	int		player;
	int		error;
	int		linecheck;
	int		moves;
	int		len;
	int		height;
	int		x;
	int		y;
}	t_game;

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
void	valid_file(t_game *game, char *map);
void	check_walls(t_game *game);
void	check_rectangular(t_game *game);
void	checker_exec(t_game *game, char *argv);

/*UTILS*/
int		ft_free(t_game *game);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);

/*ERROR HANDLER*/
int		ft_error(t_game *game, int errnum);
int		ft_error_mlx(t_game *game, int errnum);


/*MAP*/
int		open_map(char *map, t_game *game);
void	check_firstline(t_game *game);
void	check_lastline(t_game *game);
void	check_wholemap(t_game *game);

/*GAME*/
int		window_init(t_game *game);
int		keypress(int keysym, t_game *game);
int		destroy_test(t_game *game);

/*MLX*/
int		init_data(t_game *game, char *map);

#endif


