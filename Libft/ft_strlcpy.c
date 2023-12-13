/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:09:25 by ysanchez          #+#    #+#             */
/*   Updated: 2023/07/05 19:56:24 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j] != 0)
		j++;
	if (dstsize == 0)
		return (j);
	while (src[i] != 0 && i < (dstsize -1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
/*
int main()
{
    char src[]= "HOLA ADIOS";
    char dst[] = "Hello";
    printf("%s \n", src);
    printf("%s \n", dst);
	strlcpy(dst, src, 3);
    ft_strlcpy(dst, src, 3);
	printf("%s \n", src);
    printf("%s \n", dst);
	return (0);
}*/