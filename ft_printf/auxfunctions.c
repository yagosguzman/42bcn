/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:12:32 by ysanchez          #+#    #+#             */
/*   Updated: 2023/08/02 20:39:47 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnumber(int number)
{
	int	c;

	c = 0;
	if (number < 0)
	{
		c += ft_putchar('-');
		number = -number;
	}
	if (number >= 10)
	{
		ft_putnumber(number / 10);
		c += ft_putchar(number % 10 + '0');
	}
	else
		c += ft_putchar(number + '0');
	return (c);
}

int	ft_putnumberhexa(unsigned long long number)
{
	return (0);
}

int	ft_putnumberunsigned(unsigned long number)
{
	return (0);
}

int	ft_printptr(void *ptr)
{
	return (0);
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
		return (c + ft_putnumberhexa(n));
	}
	else if (format == 'X')
	{
		n = va_arg(args, unsigned long long);
		return (c + ft_putnumberhexa(n));
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
