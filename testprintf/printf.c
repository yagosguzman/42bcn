/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:47:34 by ysanchez          #+#    #+#             */
/*   Updated: 2024/01/04 14:14:06 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_putstr(char *str, int *c)
{
	if (!str)
		str = "(null)";
	while (*str)
		*c += write(1, str++, 1);
}

void	ft_putnum(long long int num, int base, int *c)
{
	char *hex;

	hex = "0123456789abcdef";
	if (num < 0)
	{
		*c += write (1, "-", 1);
		num *= -1;
	}
	if (num >= base)
		ft_putnum(num/base, base, c);
	*c += write(1, &hex[num % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int c;

	c = 0;
	va_list pointer;
	va_start(pointer, format);
	while (*format)
	{
		if (*format == '%' && ( (*(format + 1) == 'd') || (*(format + 1) == 'x') || (*(format + 1) == 's')))
		{
			format++;
			if (*format == 's')
				ft_putstr(va_arg(pointer, char *), &c);
			else if (*format == 'd')
				ft_putnum((long long int)va_arg(pointer, int), 10, &c);
			else if (*format == 'x')
				ft_putnum((long long int)va_arg(pointer, unsigned int), 16, &c);
		}
		else
			c += write(1, format, 1);
		format++;	
	}
	va_end(pointer);
	return (c);
}

int main (void)
{
	int num;

	num = 42;
	ft_printf("%s\n", "Hello world");
	ft_printf("%d\n", num);
	ft_printf("%x\n", num);
	return (0);
}
