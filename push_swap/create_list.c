/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:27:37 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/05 19:59:22 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	aux_words(char const *s, char c)
{
	int				words;
	unsigned long	i;

	i = 0;
	words = 0;
	if (s[i] && s[i] != c)
		words++;
	while (i < ft_strlen(s))
	{
		if (i != 0 && s[i] != c && s[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

static void	aux_free(char **listword, int x)
{
	while (--x >= 0)
		free(listword[x]);
	free(listword);
}

static char	**aux_lenword(char const *s, char c, char **listword, int i)
{
	int		j;
	int		x;

	j = 0;
	x = 0;
	while ((size_t)i < ft_strlen(s))
	{
		if (s[i] != c && (s[i + 1] == c || (size_t)(i + 1) == ft_strlen(s)))
		{
			listword[x] = ft_substr(s, (i - j), j + 1);
			if (!listword[x])
			{
				aux_free(listword, x);
				return (NULL);
			}
			j = 0;
			x++;
			i++;
		}
		if (s[i] != c)
			j++;
		i++;
	}
	return (listword);
}

char	**ft_split(char const *str, char separator)
{
	int		i;
	char	**listword;

	i = 0;
	if (!str)
		return (NULL);
	listword = (char **)malloc ((aux_words(s, separator) + 1) * sizeof(char *));
	if (!listword)
		return (NULL);
	listword[aux_words(str, separator)] = NULL;
	return (aux_lenword(str, separator, listword, i));
}
// aplicar atoi en la listword; si falla return error. 

int	ft_atoi(const char *str)
{
	int		i;
	int		flag;
	long	result;

	flag = 0;
	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag++;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (flag == 1)
		result = -result;
	if (result < -2147483648 || result > 2147483647)
		return (0);
	return (result);
}
// Revision de errores post atoi para ver si es un resultado valido o no.
if (num == 0 && ft_strcmp(str, "0") != 0)
	return ("Error");
