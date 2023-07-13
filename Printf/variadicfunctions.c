/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadicfunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:30:33 by ysanchez          #+#    #+#             */
/*   Updated: 2023/06/28 17:30:33 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

ft_sum(int argnum, ...)
{
	va_list	args;
	va_start(args, argnum);
	int	total;
	int	i;
	total = 0;
	while (i < argnum)
	{
		total += va_arg(args, int);
		i++; 
	}
	va_end(args);
	return (total);
}
