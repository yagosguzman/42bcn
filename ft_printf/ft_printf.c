/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:35:32 by ysanchez          #+#    #+#             */
/*   Updated: 2023/08/03 21:52:16 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		c;

	va_start (args, format);
	c = ft_putformat(args, format);
	if (c == -1)
		return (-1);
	va_end(args);
	return (c);
}

int	main(void)
{
	int	ejemplo;
	int	*ptr;
	int	res1;
	int	res2;

	ejemplo = 10;
	ptr = &ejemplo;
	res1 = ft_printf("Str %u\n", -22420);
	res2 = printf("Str %u\n", -22420);
	printf("\nRes %d\nRes %d\n", res1, res2);
	return (0);
}
