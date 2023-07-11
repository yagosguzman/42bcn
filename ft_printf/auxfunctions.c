/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:12:32 by ysanchez          #+#    #+#             */
/*   Updated: 2023/07/11 20:58:10 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_putnumberbase()
{

}

/*Deberia poner la funcion numbertype como static?*/
int	numbertype (char const format, va_arg args)
{
	int	n;
	int	c;

	c = 0;
	if (format == 'i' || format == 'd' || format == 'u')
	{
		n = va_arg(args, int);
		if (n < 0)
		{
			if (format != 'u')
				c = ft_putchar('-');
			n = -1 * n;
		}
		return (c + ft_putnumberbase((unsigned long long) n, "0123456789");
	}
	else if (format == 'x')
	{
		n = va_arg(args, unsigned long long);
		return (ft_putnumberbase(n, "0123456789abcdef");
	}
	else if (format == 'X')
	{
		n = va_arg(args, unsigned long long);
		return (ft_putnumberbase(n, "0123456789ABCDEF");
	}
}


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
}
