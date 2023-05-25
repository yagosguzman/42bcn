/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:02:03 by ysanchez          #+#    #+#             */
/*   Updated: 2023/05/25 20:09:41 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = 0;
	j = 0;
	while (dst[i] != 0)
		i++;
	while (src[j] != 0)
		j++;
	result = i + j;
	j = 0;
	while (src[j] != 0 && j < (dstsize - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (result);
}
/*int	main()
{
	char src[]= " HOLA ADIOS";
    char dst[17] = "Hello";
    printf("%s \n", src);
    printf("%s \n", dst);
	//strlcat(dst, src, 17);
	ft_strlcat(dst, src, 16);
    printf("%s \n", dst);
	return (0);
}*/