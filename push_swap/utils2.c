/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:58:10 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/05 00:17:18 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*return_best(t_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node != NULL)
	{
		if (node->best == true)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	move_node(t_node **list_a, t_node **list_b)
{
	t_node	*best;

	best = return_best(*list_b);
	if (best->first_half == true && best->target->first_half == true)
		rotate_both(list_a, list_b, best);
	else if (best->first_half == false && best->target->first_half == false)
		rev_rotate_both(list_a, list_b, best);
	place_on_top(list_b, best, 'b');
	place_on_top(list_a, best->target, 'a');
	push_a(list_a, list_b);
}
