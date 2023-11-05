/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:51:08 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/05 19:35:36 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

void	ft_bzero(void *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(int n, int size)
{
	unsigned char	*ptr;

	ptr = malloc(n * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero((void *)ptr, n * size);
	return ((void *)ptr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int num)
{
	if (num > 9)
	{
		ft_putnbr(num / 10);
		num = num % 10;
	}
	if (num <= 9)
		ft_putchar(('0' + num));
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return (s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return (s);
	return (0);
}


