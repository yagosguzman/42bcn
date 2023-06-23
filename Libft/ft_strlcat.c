/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:02:03 by ysanchez          #+#    #+#             */
/*   Updated: 2023/06/16 13:04:08 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	oglen;

	i = 0;
	j = 0;
	oglen = ft_strlen(dst);
	if (dstsize == 0 || dstsize < oglen)
		return (dstsize + ft_strlen(src));
	while (dst[i])
		i++;
	while ((i + j) < dstsize - 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	if (src[j] == '\0')
		return (ft_strlen(dst));
	return (oglen + ft_strlen(src));
}
/* int	main(void)
{
	char src[]= "L";
    char dst[9] = "Hello";
    printf("%lu \n", strlcat(dst, src, 3));
	return (0);
} */