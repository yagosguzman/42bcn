/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:12:32 by ysanchez          #+#    #+#             */
/*   Updated: 2023/08/03 17:34:56 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnumber(int number)
{
	int	c;

	c = 0;
	if (number == -2147483648)
	{
		c += ft_putstr("-2147483648");
		return (c);
	}
	if (number < 0 && number > -2147483648)
	{
		c += ft_putchar('-');
		number = -number;
	}
	if (number >= 10)
	{
		c += ft_putnumber(number / 10);
		c += ft_putchar(number % 10 + '0');
	}
	else
		c += ft_putchar(number + '0');
	return (c);
}

int	ft_putnumberunsigned(unsigned long number)
{
	int	c;

	c = 0;
	if (number >= 10)
		c += ft_putnumber(number / 10);
	c += ft_putchar(number % 10 + '0');
	return (c);
}

int	ft_putnumberhexaupper(unsigned long long number)
{
	char	*base;
	int		c;

	base = "0123456789ABCDEF";
	c = 0;
	if (number > 15)
		c += ft_putnumberhexaupper(number / 16);
	c += ft_putchar(base[number % 16]);
	return (c);
}

int	ft_putnumberhexalower(unsigned long long number)
{
	char	*base;
	int		c;

	base = "0123456789abcdef";
	c = 0;
	if (number > 15)
		c += ft_putnumberhexalower(number / 16);
	c += ft_putchar(base[number % 16]);
	return (c);
}

int	ft_printptr(void *ptr)
{
	int	c;

	c = 0;
	c += ft_putstr("0x");
	if (ptr == NULL)
	{
		c += ft_putchar('0');
		return (c);
	}
	c += ft_putnumberhexalower((unsigned long long)ptr);
	return (c);
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

/*
int	main()
{
	char	*str;
	int		l;

	str = "Hello, World!";
	l = 234567;
	printf("---%i\n", printf("---%s\n", str));
	printf("+++%Q", ft_printf("+++%s\n", str));
	printf("---%i\n", printf("---%s---%d\n", str, l));
	printf("+++%i\n", ft_printf("+++%s+++%d\n", str, l));
	return (0);
}*/
