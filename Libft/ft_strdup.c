/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:45:56 by ysanchez          #+#    #+#             */
/*   Updated: 2023/06/01 17:28:52 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t			i;
	size_t			j;
	unsigned char	*ptr;

	i = ft_strlen(s1);
	j = 0;
	if (!s1)
		return (NULL);
	ptr = malloc(i * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (j < i)
	{
		ptr[j] = s1[j];
		j++;
	}
	ptr[j] = '\0';
	return ((char *) ptr);
}
