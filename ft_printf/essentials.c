/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essentials.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:30:36 by ysanchez          #+#    #+#             */
/*   Updated: 2023/07/11 20:23:26 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putchar(char x)
{
	return(write (1, &x, 1));
}

int		ft_putstr(char *x)
{
	int	i;

	i = 0;
	while (x[i] != '\0')
	{
		write(1, &x[i], 1);
		i++;
	}
	return(i);
}
int		ft_putformat(va_list args, char const *format)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			c += ft_argselection(args, format, i);
		}
		else 
			c += ft_putchar(format[i]);
		i++;
	}
	return (c);
}

int		ft_argselection (va_list args, char const *format, int i)
{
	if (format[i] == 'c')
	   return (ft_putchar(va_arg(args, int)));
	else if (format[i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format[i] == 'p')
		return (ft_putnumberbase((unsigned long long)va_arg(args, void *), 
				"0123456789ABCDEF"));
	else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u' 
			|| format[i] == 'x' || format[i] == 'X')
		return (numbertype(format[i], args));
	else if (format[i] == '%')
		return (ft_putchar('%'));
}
