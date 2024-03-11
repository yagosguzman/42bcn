/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:12:29 by ysanchez          #+#    #+#             */
/*   Updated: 2024/03/11 11:36:32 by ysanchez         ###   ########.fr       */
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
		return (NULL);
	result[i] = '\0';
	i--;
	while (i >= 0)
	{
		result[i] = f(i, s[i]);
		i--;
	}
	return (result);
}
