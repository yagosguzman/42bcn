/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:03:48 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/04 20:17:26 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_sorted(t_node *list_a)
{
	if (list_a == NULL)
		return (1);
	while (list_a->next != NULL)
	{
		if (list_a->content < list_a->next->content)
			list_a = list_a->next;
		else
			return (1);
	}
	return (0);
}

t_node	*biggest_node(t_node *node)
{
	int		biggest_value;
	t_node	*biggest_node;

	if (node == NULL)
		return (NULL);
	biggest_value = INT_MIN;
	while (node != NULL)
	{
		if (node->content > biggest_value)
		{
			biggest_value = node->content;
			biggest_node = node;
		}
		node = node->next;
	}
	return (biggest_node);
}

t_node	*smallest_node(t_node *node)
{
	int		smallest_value;
	t_node	*smallest_node;

	if (node == NULL)
		return (NULL);
	smallest_value = INT_MAX;
	while (node != NULL)
	{
		if (node->content < smallest_value)
		{
			smallest_value = node->content;
			smallest_node = node;
		}
		node = node->next;
	}
	return (smallest_node);
}

int	node_count(t_node *root)
{
	int		i;
	t_node	*current_node;

	i = 0;
	current_node = root;
	while (current_node != NULL)
	{
		current_node = current_node->next;
		i++;
	}
	return (i);
}

void	place_on_top(t_node **node, t_node *top_node, char stack)
{
	while (*node != top_node)
	{
		if (stack == 'a')
		{
			if (top_node->first_half == true)
				rotate_a(node);
			else
				rev_rotate_a(node);
		}
		if (stack == 'b')
		{
			if (top_node->first_half == true)
				rotate_b(node);
			else
				rev_rotate_b(node);
		}
	}
}
