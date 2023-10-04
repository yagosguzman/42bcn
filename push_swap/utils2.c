/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:58:10 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/04 12:48:27 by ysanchez         ###   ########.fr       */
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

void	index_assign(t_node *list_a)
{
	int		*index;
	int		size;
	int		i;
	t_node	*head;

	size = node_count(list_a);
	index = malloc(sizeof(int) * size);
	i = 0;
	head = list_a;
	while (list_a != NULL)
	{
		index[i++] = list_a->content;
		list_a = list_a->next;
	}
	index = bubblesort(index, size);
	i = 0;
	list_a = head;
	while (i < size)
	{
		if (list_a->content == index[i])
		{
			list_a->index = i;
			i++;
			list_a = head;
		}
		else
			list_a = list_a->next;
	}
	free(index);
}

int	*bubblesort(int *arr, int size)
{
	int	swapped;
	int	pass;
	int	j;
	int	temp;

	swapped = 1;
	pass = 0;
	while (swapped)
	{
		swapped = 0;
		j = 0;
		while (j < size - pass - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		pass++;
	}
	return (arr);
}
