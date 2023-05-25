/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:15:12 by ysanchez          #+#    #+#             */
/*   Updated: 2023/05/25 20:41:26 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle == 0)
		return (((char *)haystack));
	while ((haystack[i] != 0 || needle[j] != 0) && i < len)
	{
		if (haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		else
		{
			j = 0;
			i++;
		}
	}
	haystack[i - j] = (char *)haystack;
	return ((char *)haystack);
}
