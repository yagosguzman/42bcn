/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:13:31 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/27 19:35:31 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	condition1(t_node *list_a, t_node *list_b)
// {
// 	if (list_a->content > list_a->next->content ||
// 		list_a->content > last_node(list_a)->content ||
// 		list_b->content < list_b->next->content ||
// 		list_b->content < last_node(list_b)->content )
// 		return (1);
// 	return (0);
// }
// 
// void	ft_ss_sa_sb(t_list *lst_a, t_list *lst_b)
// {
// 	if (lst_a->content > (lst_a->next)->content &&
// 		lst_b->content < (lst_b->next)->content)
// 	{
// 		ft_lst_swap(lst_a);
// 		ft_lst_swap(lst_b);
// 		ft_putstr("ss\n");
// 	}
// 	else if (lst_a->content > (lst_a->next)->content)
// 	{
// 		ft_lst_swap(lst_a);
// 		ft_putstr("sa\n");
// 	}
// 	else if (lst_b->content < (lst_b->next)->content)
// 	{
// 		ft_lst_swap(lst_b);
// 		ft_putstr("sb\n");
// 	}
// }

void	algorithm_selection(t_node *list_a, t_node *list_b, int node_length)
{
	if (node_length == 3)
		alg_3(&list_a);
	if (node_length == 4)
		alg_4(&list_a, &list_b);
	if (node_length == 5)
		alg_5(&list_a, &list_b);
	if (node_length > 5)
		big_alg(&list_a, &list_b);
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

void	alg_5(t_node **list_a, t_node **list_b)
{
	while (node_count(*list_a) > 3)
	{
		key_data(*list_a, *list_b);
		place_on_top(list_a, smallest_node(*list_a), 'a');
		push_b(list_b, list_a);
	}
}

void	big_alg(t_node **list_a, t_node **list_b)
{
	t_node	*smallest;
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
	smallest = smallest_node(*list_a);
	if (smallest->first_half == true)
		while (*list_a != smallest)
			rotate_a(list_a);
	else
		while (*list_a != smallest)
			rev_rotate_a(list_a);
}

