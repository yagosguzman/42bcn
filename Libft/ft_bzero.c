/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:21:48 by ysanchez          #+#    #+#             */
/*   Updated: 2023/06/23 16:22:07 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*ptrstr;

	ptrstr = str;
	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		*ptrstr = 0;
		i++;
		ptrstr++;
	}
	str = ptrstr;
}
