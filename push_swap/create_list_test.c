/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:09:10 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/08 20:27:57 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c < '0' || c > '9')
		return (1);
	return (0);
}

int	ft_isdigitplus(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' && str[i] != ' ' && str[i] != '-' && str[i] != '+')
			|| str[i] > '9')
			return (1);
		i++;
	}
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
	if ((str[i] == '-' && ft_isdigit(str[i + 1]) == 0)
		|| (str[i] == '+' && ft_isdigit(str[i + 1]) == 0))
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

t_node	*testextract_argv(int argc, char **argv, t_node *list_a)
{
	int	i;

	i = 1;
	list_a = ft_lstnew(ft_atoi(argv[i]));
	i++;
	argc--;
	while (argc > 1)
	{
		insert_end(list_a, ft_atoi(argv[i]));
		argc--;
		i++;
	}
	return (list_a);
}

void	print_list(t_node *list_a)
{
	while (list_a != NULL)
	{
		printf("%i\n", list_a->content);
		list_a = list_a->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*list_a;

	list_a = NULL;
	testextract_argv(argc, argv, list_a);
	print_list(list_a);
	return (0);
}