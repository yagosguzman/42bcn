/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculators.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:45:55 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/26 18:04:32 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position_finder(t_node *node)
{
	int	i;
	int	median;

	if (node == NULL)
		return ;
	i = 0;
	median = node_count(node) / 2;
	while (node != NULL)
	{
		node->position = i;
		if (i <= median)
			node->first_half = true;
		else
			node->first_half = false;
		node = node->next;
		i++;
	}
}

void	target_finder(t_node *list_b, t_node *list_a)
{
	t_node	*current_a;
	t_node	*target;
	long	best;

	while (list_b != NULL)
	{
		best = LONG_MAX;
		current_a = list_a;
		while (current_a != NULL)
		{
			if (current_a->content > list_b->content
				&& current_a->content < best)
			{
				best = current_a->content;
				target = current_a;
			}
		}
		if (best == LONG_MAX)
			list_b->target = smallest_node(list_a);
		else
			list_b->target = target;
		list_b = list_b->next;
	}
}

void	cost_calculator(t_node *list_a, t_node *list_b)
{
	int	length_a;
	int	length_b;

	length_a = node_count(list_a);
	length_b = node_count(list_b);
	while (list_b != NULL)
	{
		list_b->push_cost = list_b->position;
		if (list_b->first_half == false)
			list_b->push_cost = length_b - (list_b->position);
		if (list_b->target->first_half == true)
			list_b->push_cost += list_b->target->position;
		else
			list_b->push_cost += length_a - (list_b->target->position);
		list_b = list_b->next;
	}
}

void	best_option(t_node *list_b)
{
	long	best_value;
	t_node	*best_node;

	if (list_b == NULL)
		return ;
	best_value = LONG_MAX;
	while (list_b != NULL)
	{
		if (list_b->push_cost < best_value)
		{
			best_value = list_b->push_cost;
			best_node = list_b;
		}
		list_b = list_b->next;
	}
	best_node->best = true;
}

void	key_data(t_node *list_a, t_node *list_b)
{
	position_finder(list_a);
	position_finder(list_b);
	target_finder(list_b, list_a);
	cost_calculator(list_a, list_b);
	best_option(list_b);
}
