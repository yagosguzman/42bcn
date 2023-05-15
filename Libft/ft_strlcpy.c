/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:09:25 by ysanchez          #+#    #+#             */
/*   Updated: 2023/05/15 20:01:58 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t size)
{
	size_t i;

	i = 0;
	if (size == 0)
		return (1);
	else
	while (src[i] != 0)
	{
		dst[i] = src [i];
		i++;
	}
	return (size);
}
int main()
{
    char *src= "HOLA ADIOS";
    char *dst = "Hello";
    printf("%s \n %s", src, dst);
    ft_strlcpy(dst, src, 6);
	printf("%s \n %s", src, dst);
    return (0);
}
