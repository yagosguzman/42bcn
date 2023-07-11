/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:03:54 by ysanchez          #+#    #+#             */
/*   Updated: 2023/07/11 18:34:25 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int		ft_printf(char const *format, ...);
int		ft_putchar(char x);
int		ft_putstr(char *x);
int		ft_argselection (va_list arg, char const *format, int i);
int		ft_putformat(va_list args, char const *format);

#endif
