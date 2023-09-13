/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:27:37 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/13 18:24:34 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*extract_argv(int argc, char **argv)
{
	t_node	*list_a;
	int		i;

	list_a = NULL;
	i = 1;
	while (argc > 1)
	{
		list_a = insert_end(list_a, ft_atoi(argv[i]));
		argc--;
		i++;
	}
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

int	ft_free(char **str)
{
	int	i;

	i = 0;
	while (*str[i])
		free(str[i++]);
	free(**str);
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		flag;
	long	result;

	flag = 0;
	result = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if ((str[i] == '-' && ft_isdigitplus(str[i + 1]) == 0)
		|| (str[i] == '+' && ft_isdigitplus(str[i + 1]) == 0))
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
	return ((int)result);
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
