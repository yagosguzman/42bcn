/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:33:42 by ysanchez          #+#    #+#             */
/*   Updated: 2023/05/25 20:09:42 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*ptrb;

	ptrb = (char *)b;
	i = 0;
	while (i < len)
	{
		*ptrb = c;
		i++;
		ptrb++;
	}
	return (b);
}*/
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = c;
		i++;
	}
	return (b);
}
