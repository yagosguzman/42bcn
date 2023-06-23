/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:26:21 by ysanchez          #+#    #+#             */
/*   Updated: 2023/06/12 14:18:17 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (s[i] != (unsigned char)c && i > 0)
		i--;
	if (s[i] != (unsigned char)c)
		return (NULL);
	return ((char *)&s[i]);
}
/*
int	main (void)
{
	ft_strrchr("HOLA!", 33);
	return (0);
}
*/