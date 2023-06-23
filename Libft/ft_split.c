/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:38:07 by ysanchez          #+#    #+#             */
/*   Updated: 2023/06/20 14:48:17 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**listword;

	i = 0;
	if (!s)
		return (NULL);
	listword = (char **)malloc ((aux_words(s, c) + 1) * sizeof(char *));
	if (!listword)
		return (NULL);
	listword[aux_words(s, c)] = NULL;
	return (aux_lenword(s, c, listword, i));
}

/* int main ()
{
	char **x;
	//int j;
	x = ft_split("", 'a');
	printf("%s", x[0]);
	//printf("numero de palabras es -> %d", j);
}  */