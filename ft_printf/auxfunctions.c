/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:12:32 by ysanchez          #+#    #+#             */
/*   Updated: 2023/07/31 20:15:36 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_basecheck(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (str[i] && j <= ft_strlen(str))
	{
		while (*str)
		{
			if (str[i] == str[j])
				return (-1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	ft_putnumberbase(unsigned long long number, char *base)
{
	unsigned long long	n;
	int					base_size;
	unsigned long long	result[20];
	int					i;

	if (!base || ft_strlen(base) < 2 || ft_basecheck(base) != 0)
		return (-1);
	i = 0;
	n = number;
	base_size = ft_strlen(base);
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	while (n)
	{
		result[i] = base[n % base_size];
		n = n / base_size;
		i++;
	}
	while (--i >= 0)
		ft_putchar(result[i]);
	if (number < 0)
		return (ft_strlen((char *)result + 1)); 
	else
		return ((int)ft_strlen((char *)result));
}

int	numbertype(char const format, va_list args)
{
	int	n;
	int	c;

	c = 0;
	if (format == 'i' || format == 'd')
	{
		n = va_arg(args, int);
		if (n < 0)
		{
			if (format != 'u')
				c = ft_putchar('-');
			n = -1 * n;
		}
		return (c + ft_putnumberbase((n, "0123456789")));
	}
	else if (format == 'u')
		return (c + ft_putnumberunsigned(va_arg(args, unsigned int)));
	else if (format == 'x')
	{
		n = va_arg(args, unsigned long long);
		return (c + ft_putnumberbase(n, "0123456789abcdef"));
	}
	else if (format == 'X')
	{
		n = va_arg(args, unsigned long long);
		return (c + ft_putnumberbase(n, "0123456789ABCDEF"));
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
