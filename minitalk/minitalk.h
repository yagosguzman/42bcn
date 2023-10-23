/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:16:09 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/23 18:22:58 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(char *str);
int		ft_isdigit(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int num);
void	sig_confirm(int sig);

#endif