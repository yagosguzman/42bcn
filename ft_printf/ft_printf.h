/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:04:06 by ysanchez          #+#    #+#             */
/*   Updated: 2023/08/03 17:02:26 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(char const *format, ...);
int		ft_putchar(char x);
int		ft_putstr(char *x);
int		ft_argselection(va_list arg, char const *format, int i);
int		ft_putformat(va_list args, char const *format);
int		ft_putnumber(int number);
int		ft_putnumberunsigned(unsigned long number);
int		ft_putnumberhexaupper(unsigned long long number);
int		ft_putnumberhexalower(unsigned long long number);
int		ft_printptr(void *ptr);
int		numbertype(char const format, va_list args);

#endif