/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:27:37 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/07 13:26:51 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

int	int_free(int **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
		str = NULL;
		return (NULL);
	}
	return (NULL);
}

int	ft_free(int **str)
{
	int	i;

	i = 0;
	while (*str[i])
		free(str[i++]);
	free(**str);
	return (0);
}

int	ft_isdigit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		else
			str++;
	}
	return (0);
}

static int	aux_words(char *s, char c)
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

static char	**aux_lenword(char *s, char c, char **listword, int i)
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

char	**ft_split(char *str, char separator)
{
	int		i;
	char	**listword;

	i = 0;
	if (!str)
		return (NULL);
	listword = (char **)malloc ((aux_words(str, separator) + 1) * sizeof(char *));
	if (!listword)
		return (NULL);
	listword[aux_words(str, separator)] = NULL;
	return (aux_lenword(str, separator, listword, i));
}

int	ft_atoiextra(char *str, int *int_list)
{
	int		i;
	int		flag;
	int		result_check;
	long	result;

	flag = 0;
	result = 0;
	i = 0;
	result_check = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag++;
		i++;
	}
	while (str[i] != '\0') // la condicion de que sean digitos no es necesaria (ya chequeado en ft_checkvalid)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (flag == 1)
		result = -result;
	if (result < -2147483648 || result > 2147483647)
		result_check = 1;
	if (result_check == 1)
		return (int_free(&int_list));
	return (result);
}

int	ft_checkvalid(char **list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= ft_strlen(*list))
	{
		if (ft_isdigit(list[i]) == 1)
		{
			printf("ERROR NOT DIGIT\n");
			return (1);
		}
		else
			i++;
	}
	i = 0;
	while (j < ft_strlen(*list))
	{
		while (i < ft_strlen(*list))
		{
			if (ft_strcmp(list[i], list[i + j]) == 1)
				i++;
			else
			{
				printf("ERROR REPEAT\n");
				return (1);
			}
	}
	i = 0;
	j++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		if (s1[i] != s2[i])
			return (1);
	}
	return (0);
}
