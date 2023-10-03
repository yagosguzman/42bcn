/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:27:37 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/03 19:03:56 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*extract_argv(int argc, char **argv)
{
	t_node	*list_a;
	int		i;

	list_a = NULL;
	if (argc == 1)
		return (list_a);
	i = 1;
	while (argc > 1)
	{
		list_a = insert_end(list_a, ft_atoi(argv[i]));
		if (ft_atoi(argv[i]) == 0)
			if (ft_zerocmp(argv[i]) == 1)
				return (free_listnode(list_a));
		argc--;
		i++;
	}
	if (ft_checkrepeat(list_a) == 1)
		return (free_listnode(list_a));
	index_assign(list_a);
	return (list_a);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if ((str[i] == '-' && ft_isdigitplus(&str[i + 1]) == 0)
		|| (str[i] == '+' && ft_isdigitplus(&str[i + 1]) == 0))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + ((str[i] - 48) * sign);
		i++;
	}
	if (result < -2147483648 || result > 2147483647)
		return (0);
	return (result);
}

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}
// static char	*ft_substr(char *s, int start, int len)
// {
// 	int	i;
// 	char	*substr;

// 	i = 0;
// 	if (start >= ft_strlen(s))
// 		len = 0;
// 	else if (len > ft_strlen(s + start))
// 		len = ft_strlen(s + start);
// 	substr = malloc((len + 1) * sizeof(char));
// 	if (!substr)
// 		return (NULL);
// 	while (start < ft_strlen(s) && s[start + i] && len > i)
// 	{
// 		substr[i] = ((char *)s)[start + i];
// 		i++;
// 	}
// 	substr[i] = '\0';
// 	return (substr);
// }
// 
// int	argcounter(char *str, char separator)
// {
// 	int				words;
// 	unsigned long	i;

// 	i = 0;
// 	words = 0;
// 	if (str[i] && str[i] != separator)
// 		words++;
// 	while (i < (unsigned long)ft_strlen(str))
// 	{
// 		if (i != 0 && str[i] != separator && str[i - 1] == separator)
// 			words++;
// 		i++;
// 	}
// 	return (words);
// }
// 
// static void	aux_free(char **listword, int x)
// {
// 	while (--x >= 0)
// 		free(listword[x]);
// 	free(listword);
// }

// static char	**aux_lenword(char *s, char c, char **listword, int i)
// {
// 	int		j;
// 	int		x;

// 	j = 0;
// 	x = 0;
// 	while (i < ft_strlen(s))
// 	{
// 		if (s[i] != c && (s[i + 1] == c || (i + 1) == ft_strlen(s)))
// 		{
// 			listword[x] = ft_substr(s, (i - j), j + 1);
// 			if (!listword[x])
// 			{
// 				aux_free(listword, x);
// 				return (NULL);
// 			}
// 			j = 0;
// 			x++;
// 			i++;
// 		}
// 		if (s[i] != c)
// 			j++;
// 		i++;
// 	}
// 	return (listword);
// }

// char	**ft_split(char *str, char separator)
// {
// 	int		i;
// 	char	**listword;

// 	i = 0;
// 	if (!str)
// 		return (NULL);
// 	listword = (char **)malloc ((argcounter(str, separator) + 1)
// 			* sizeof(char *));
// 	if (!listword)
// 		return (NULL);
// 	listword[argcounter(str, separator)] = NULL;
// 	return (aux_lenword(str, separator, listword, i));
// }s