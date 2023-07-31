/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:35:32 by ysanchez          #+#    #+#             */
/*   Updated: 2023/07/31 20:15:41 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;

	va_start (args, format);
	i = ft_putformat(args, format);
	va_end(args);
	return (i);
}

int	main (void)
{
	int	ejemplo;
	int	*ptr;
	int res1;
	int res2;

	ejemplo = 10;
	ptr = &ejemplo;
	res1 = ft_printf("Str %s\n", NULL);
	res2 = printf("Str %s\n", NULL);
	printf("\nRes %d\nRes %d\n", res1, res2);

	return (0);
}
