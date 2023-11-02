/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:12:32 by ysanchez          #+#    #+#             */
/*   Updated: 2023/08/04 18:29:20 by ysanchez         ###   ########.fr       */
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
		if (c == -1)
			return (-1);
		return (c);
	}
	if (number < 0 && number > -2147483648)
	{
		c += ft_putchar('-');
		if (c == -1)
			return (-1);
		number = -number;
	}
	if (number > 9)
		c += ft_putnumber(number / 10);
	if (c == -1)
		return (-1);
	c += ft_putchar(number % 10 + '0');
	if (c == -1)
		return (-1);
	return (c);
}

int	ft_putnumberunsigned(unsigned long number)
{
	int	c;

	c = 0;
	if (number > 9)
		c += ft_putnumber(number / 10);
	if (c == -1)
		return (-1);
	c += ft_putchar(number % 10 + '0');
	if (c == -1)
		return (-1);
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
	if (c == -1)
		return (-1);
	c += ft_putchar(base[number % 16]);
	if (c == -1)
		return (-1);
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
	if (c == -1)
		return (-1);
	c += ft_putchar(base[number % 16]);
	if (c == -1)
		return (-1);
	return (c);
}

int	ft_printptr(void *ptr)
{
	int	c;

	c = 0;
	c += ft_putstr("0x");
	if (c == -1)
		return (-1);
	if (ptr == NULL)
	{
		c += ft_putchar('0');
		if (c == -1)
			return (-1);
		return (c);
	}
	c += ft_putnumberhexalower((unsigned long long)ptr);
	if (c == -1)
		return (-1);
	return (c);
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
