/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:13:07 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/07 15:46:44 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	if (start >= (unsigned int)ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (start < (unsigned int)ft_strlen(s) && s[start + i] && len > i)
	{
		substr[i] = ((char *)s)[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
int	main (void)
{
	ft_substr("Hola que tal", 6, 4);
	return (0);
}*/