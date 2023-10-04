/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:13:31 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/04 20:36:05 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm_selection(t_node **list_a, t_node **list_b, int node_length)
{
	if (list_sorted(*list_a) == 0)
		return ;
	if (node_length <= 3)
		alg_3(list_a);
	if (node_length == 4)
		alg_4(list_a, list_b);
	if (node_length <= 10 && node_length > 4)
		alg_to10(list_a, list_b);
	if (node_length > 10 && node_length <= 100)
		big_alg(list_a, list_b);
	if (list_sorted(*list_a) == 0)
		printf("done");
}

void	alg_3(t_node **node)
{
	t_node	*biggest;

	biggest = biggest_node(*node);
	if (*node == biggest)
		rotate_a(node);
	else if ((*node)->next == biggest)
		rev_rotate_a(node);
	if ((*node)->content > (*node)->next->content)
		swap_a(node);
}

void	alg_4(t_node **list_a, t_node **list_b)
{
	place_on_top(list_a, smallest_node(*list_a), 'a');
	push_b(list_b, list_a);
	alg_3(list_a);
	push_a(list_a, list_b);
}

void	alg_to10(t_node **list_a, t_node **list_b)
{
	while (node_count(*list_a) > 3)
	{
		key_data(*list_a, *list_b);
		place_on_top(list_a, smallest_node(*list_a), 'a');
		push_b(list_b, list_a);
	}
	alg_3(list_a);
	while (*list_b != NULL)
		push_a(list_a, list_b);
}

void	alg_to100(t_node **list_a, t_node **list_b, int node_length)
{
	int		key_num;

	key_num = node_length * 1 / 4;
	while (node_count(*list_b) < key_num)
	{
		position_finder(*list_a);
		place_on_top(list_a, smallest_node(*list_a), 'a');
		push_b(list_b, list_a);
	}
	key_num = node_length * 2 / 4;
	while (node_count(*list_b) < key_num)
	{
		position_finder(*list_a);
		place_on_top(list_a, smallest_node(*list_a), 'a');
		push_b(list_b, list_a);
	}
	key_num = node_length * 3 / 4;
	while (node_count(*list_b) < key_num)
	{
		position_finder(*list_a);
		place_on_top(list_a, smallest_node(*list_a), 'a');
		push_b(list_b, list_a);
	}
	while (*list_b != NULL)
	{
		position_finder(*list_a);
		place_on_top(list_a, smallest_node(*list_a), 'a');
		place_on_top(list_b, biggest_node(*list_b), 'b');
		push_a(list_a, list_b);
	}
	place_on_top(list_a, smallest_node(*list_a), 'a');
}

void	big_alg(t_node **list_a, t_node **list_b)
{
	int		length_a;

	length_a = node_count(*list_a);
	while (length_a > 3)
	{
		push_b(list_b, list_a);
		length_a--;
	}
	alg_3(list_a);
	while (*list_b != NULL)
	{
		key_data(*list_a, *list_b);
		move_node(list_a, list_b);
	}
	position_finder(*list_a);
	place_on_top(list_a, smallest_node(*list_a), 'a');
}

void	alg_index(t_node **list_a, t_node **list_b, int node_length)
{
	int	key_num;
	int	i;

	i = 1;
	key_num = (node_length / 4 * i);
	while (node_count(*list_b) < key_num)
	{
		if ((*list_a)->index <= key_num)
			push_b(list_b, list_a);
	}
}