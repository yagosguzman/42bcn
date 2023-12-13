/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:31:09 by ysanchez          #+#    #+#             */
/*   Updated: 2023/06/16 13:06:37 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	strlen;

	i = 0;
	strlen = ft_strlen(s);
	while (i < strlen)
	{
		f(i, s);
		i++;
		s++;
	}
}
