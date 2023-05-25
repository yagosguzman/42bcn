/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:28:11 by ysanchez          #+#    #+#             */
/*   Updated: 2023/05/25 20:09:48 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*ptrstr;

	ptrstr = str;
	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		*ptrstr = 0;
		i++;
		ptrstr++;
	}
	str = ptrstr;
}
