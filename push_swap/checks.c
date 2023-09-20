/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:20:44 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/20 18:09:41 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] < '0' || c[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigitplus(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if ((str[i] < '0' && str[i] != ' ') || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkvalid(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_isdigitplus(argv[i]) == 1)
			return (1);
		else
			i++;
	}
	return (0);
}

int	ft_checkrepeat(t_node *list)
{
	t_node	*check;
	t_node	*head;

	head = list;
	check = list;
	while (check->next != NULL)
	{
		while (list != NULL)
		{
			if (list->content == check->content)
					return (1);
			list = list->next;
		}
		list = head;
		check = check->next;
	}
	return (0);
}
int ft_check_double(t_node *list_a)
{
	int	i;
	int	size;
	int	*check = NULL;

	size = node_count(list_a) - 1;
	i = 0;
	while (i < size)
	{
		check[i] = list_a->content;
		list_a = list_a->next;
		i++;
	}
	i = 0;
	while (check[i])
	{
		if (check[i] == check[i+1])
			return (1);
		i++;
	}
	return (0);
}