/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:35:32 by ysanchez          #+#    #+#             */
/*   Updated: 2023/07/11 18:44:50 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;

	va_start (args, format);
	i = ft_putformat(args, format);
	va_end(args);
	return(i);
}

int	main (void)
{
	ft_printf("Imprime este carácter: %c", 'X');
	printf("Imprime este carácter: %c", 'X');
	return (0);
}
/*
c = 1 solo caracter
s = string
p = puntero void * en formato hexadecimal
d = numero decimal base 10
i = numero entero base 10
u = numero decimal base 10 sin signo
x = numero hexadecimal (base 16) en minusculas
X = numero hexadecimal (base 16) en mayusculas
% = imprime el "%"

Returns the count of printed characters when the function is successful and -1 when the function fails.

int	main()
{
	char	*str;
	int		l;

	str = "Hello, World!";
	l = 234567;
	printf("---%i\n", printf("---%s\n", str));
	printf("+++%i\n", ft_printf("+++%s\n", str));
	printf("---%i\n", printf("---%s---%d\n", str, l));
	printf("+++%i\n", ft_printf("+++%s+++%d\n", str, l));
	return (0);
}

*/
