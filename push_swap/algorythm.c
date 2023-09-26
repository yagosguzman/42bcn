/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:13:31 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/26 18:23:00 by ysanchez         ###   ########.fr       */
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
void	alg_4(t_node **list_a, t_node **list_b);
{
	while (node_count(*list_a) > 3)
	{
		key_data(*list_a, *list_b);

		push_b(list_b, list_a);
	
}

void	alg_to5(t_node **list_a, t_node **list_b)
{
	t_node	*tail;
	int		min;
	int		max;

	while (node_count(*list_a) > 3)
		push_b(list_b, list_a);
	if ((*list_b)->content > (*list_b)->next->content)
	{
		max = (*list_b)->content;
		min = (*list_b)->next->content;
	}
	else
	{
		min = (*list_b)->content;
		max = (*list_b)->next->content;
	}
	alg_3(list_a);
	tail = last_node(*list_a);
	while (node_count(*list_b) != 0)
	{
		if ((*list_b)->content == min)
		{
			if (min < (*list_a)->content)
				push_a(list_a, list_b);
			else
			{
				push_a(list_a, list_b);
				swap_a(list_a);
			}
		}
		else
		{
			if (max > tail->content)
			{
				push_a(list_a, list_b);
				rotate_a(list_a);
			}
			else
			{
				rev_rotate_a(list_a);
				push_a(list_a, list_b);
				rotate_a(list_a);
				rotate_a(list_a);
			}
		}
	}
}
void	place_on_top(t_node **list_a)
{
	
}