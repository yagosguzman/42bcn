/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essentials.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:30:36 by ysanchez          #+#    #+#             */
/*   Updated: 2023/08/04 18:16:53 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char x)
{
	if (write (1, &x, 1) != 1)
		return (-1);
	return (1);
}

int	ft_putstr(char *x)
{
	int	i;

	i = 0;
	if (x == NULL)
		x = "(null)";
	while (x[i] != '\0')
	{
		if (write(1, &x[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putformat(va_list args, char const *format)
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
			if (c == -1)
				return (-1);
		}
		else 
			c += ft_putchar(format[i]);
		if (c == -1)
			return (-1);
		i++;
	}
	return (c);
}

int	ft_argselection(va_list args, char const *format, int i)
{
	if (format[i] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format[i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format[i] == 'p')
		return (ft_printptr(va_arg(args, void *)));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_putnumber(va_arg(args, int)));
	else if (format[i] == 'u')
		return (ft_putnumberunsigned(va_arg(args, unsigned int)));
	else if (format[i] == 'X')
		return (ft_putnumberhexaupper(va_arg(args, unsigned int)));
	else if (format[i] == 'x')
		return (ft_putnumberhexalower(va_arg(args, unsigned int)));
	else if (format[i] == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	numbertype(char const format, va_list args)
{
	int	n;
	int	c;

	c = 0;
	if (format == 'i' || format == 'd')
	{
		n = va_arg(args, int);
		return (c + ft_putnumber(n));
	}
	else if (format == 'u')
		return (c + ft_putnumberunsigned(va_arg(args, unsigned int)));
	else if (format == 'x')
	{
		n = va_arg(args, unsigned long long);
		return (c + ft_putnumberhexalower(n));
	}
	else if (format == 'X')
	{
		n = va_arg(args, unsigned long long);
		return (c + ft_putnumberhexaupper(n));
	}
	else
		return (-1);
}
