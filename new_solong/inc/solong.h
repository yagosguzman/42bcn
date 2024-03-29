/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:58:12 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/08 22:08:29 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

# define T_SIZE 80
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define ARR_UP 126
# define ARR_DOWN 125
# define ARR_LEFT 123
# define ARR_RIGHT 124
# define BUFFER_SIZE 100

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*floor;
	void	*wall;
	void	*katana;
	void	*door;
	void	*opdoor;
	void	*currentpos;
	void	*pdown;
	void	*pup;
	void	*pleft;
	void	*pright;
	char	*wholemap;
	char	*btmap;
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
	int		pos;
	int		finish;
}	t_game;

/*GET NEXT LINE*/
char	*get_next_line(int fd);
char	*read_line(int fd, char *stash);
char	*find_line(char *stash);
char	*clean_stash(char *line, char *stash);
char	*ft_free_gnl(char **str);
char	*merge_strings(char *s1, char *s2);
int		ft_strlen_mode(char *str, int mode);

/*CHECKERS*/
int		valid_file(t_game *game, char *map);
int		check_firstline(t_game *game);
int		check_lastline(t_game *game);
int		check_walls(t_game *game);
int		check_rectangular(t_game *game);
int		check_wholemap(t_game *game);
int		checker_exec(t_game *game, char *argv);
int		check_solution(t_game *game);

/*UTILS*/
void	ft_bzero(void *str, int n);
void	*ft_calloc(int n, int size);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putchar(char c);
void	ft_putnbr(int num);
char	*ft_strchr(char *s, int c);

/*ERROR HANDLER*/
void	ft_putstr_fd(char *s, int fd);
int		ft_free(t_game *game);
int		ft_error(t_game *game, int errnum);
int		ft_error_mlx(int errnum);

/*MAP*/
void	create_btmap(t_game *game);
void	backtrack_map(t_game *game, int pos);
int		open_map(char *map, t_game *game);

/*GAME*/
int		init_data(t_game *game);
void	init_img(t_game *game);
int		minilib_init(t_game *game);
void	print_moves(t_game *game);
void	select_img(t_game *game, char c, int pos);
void	render_map(t_game *game);
void	render_win(t_game *game);
int		check_win(int fpos, t_game *game);

/*CONTROLS*/
int		keypress(int key, t_game *game);
void	player_move(int key, t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

#endif
