/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:51:34 by ysanchez          #+#    #+#             */
/*   Updated: 2023/05/15 20:55:36 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

/*void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst == NULL && src == NULL)
		return (dst);
	const char	*auxsrc;
	char		*auxdst;
	size_t i;

	i = 0;
	auxsrc = src;
	auxdst = dst;
	while (i < n)
	{
		auxdst[i] = auxsrc[i];
		i++;
	}
	dst = auxdst;
	return (dst);
}*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst == NULL && src == NULL)
		return (NULL);
	size_t i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((const char *)src)[i];
		i++;
	}
	return (dst);
}