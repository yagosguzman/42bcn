/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:55:33 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/27 19:35:28 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_a(t_node *root)
{
	t_node	*current_node;

	current_node = root;
	while (current_node->next != NULL)
	{
		if (current_node->content < current_node->next->content)
			current_node = current_node->next;
		else
			return (1);
	}
	return (0);
}

int	order_b(t_node **root)
{
	t_node	*current_node;

	current_node = *root;
	while (current_node->next != NULL)
	{
		if (current_node->content > current_node->next->content)
			current_node = current_node->next;
		else
			return (1);
	}
	return (0);
}

int	push_swap(int argc, char **argv)
{
	t_node	*list_a;
	t_node	*list_b;
	int		node_length;

	list_a = NULL;
	if (ft_checkvalid(argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!argc || argc <= 2)
		return (1);
	if (argc > 2)
	{
		list_a = extract_argv(argc, argv);
		if (!list_a)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
	}
	list_b = NULL;
	node_length = node_count(list_a);
	algorithm_selection(list_a, list_b, node_length);
	print_list(list_a);
	return (0);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (0);
}
