/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:20:44 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/14 18:07:50 by ysanchez         ###   ########.fr       */
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

	check = list;
	while (list != NULL)
	{
		while (check->next != NULL)
		{
			if (check->content == check->next->content)
				return (1);
			else
				check = check->next;
		}
		list = list->next;
		check = list;
	}
	return (0);
}