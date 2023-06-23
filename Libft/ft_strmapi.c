/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:12:29 by ysanchez          #+#    #+#             */
/*   Updated: 2023/06/07 19:40:04 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*result;

	i = ft_strlen(s);
	result = malloc((i + 1) * sizeof(char));
	if (!result)
		return (0);
	result[i--] = '\0';
	while (i >= 0)
	{
		result[i] = f(i, s[i]);
		i--;
	}
	return (result);
}
