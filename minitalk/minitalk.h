/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:16:09 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/18 19:56:26 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"

void	handle_sigusr(int sig);
int		ft_isdigit(char *str);
void	char_2_bin(int pid, char c);
void	ft_putstr_fd(char *s, int fd);

#endif