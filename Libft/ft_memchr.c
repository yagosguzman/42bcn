/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:18:56 by ysanchez          #+#    #+#             */
/*   Updated: 2024/03/07 11:30:15 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (!s && !c && !n)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if ((((unsigned char *)s)[i]) == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
