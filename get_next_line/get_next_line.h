/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:38:04 by ysanchez          #+#    #+#             */
/*   Updated: 2023/08/15 21:39:13 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*read_line(int fd, char *buffer, char *stash);
int		length_line(char *stash);
char	*find_line(char *line, char *stash);
char	*clean_stash(char *line, char *stash);
int		ft_strlen(char *str);
char	*merge_strings(char *s1, char *s2);

#endif