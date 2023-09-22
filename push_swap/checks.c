/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:20:44 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/21 14:22:32 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_zerocmp(char *s1)
{
	int		i;

	i = 0;
	if (s1[i] == '+' || s1[i] == '-')
		i++;
	while (s1[i])
	{
		if (s1[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkrepeat(t_node *list)
{
	t_node	*check;

	check = list;
	list = list->next;
	while (check->next != NULL)
	{
		while (list != NULL)
		{
			if (list->content == check->content)
				return (1);
			list = list->next;
		}
		check = check->next;
		list = check->next;
	}
	return (0);
}
