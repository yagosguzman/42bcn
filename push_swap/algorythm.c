/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:13:31 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/22 20:27:43 by ysanchez         ###   ########.fr       */
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

void alg_3(t_node **node)
{
	if (((*node)->content > (*node)->next->content)
		&& ((*node)->next->content < (*node)->next->next->content))
	{
		if ((*node)->content < (*node)->next->next->content)
			swap_a(node);
		else
			rotate_a(node);
	}
	else if (((*node)->content > (*node)->next->content)
		&& ((*node)->next->content > (*node)->next->next->content))
	{
		rotate_a(node);
		swap_a(node);
	}
	else if (((*node)->content < (*node)->next->content)
		&& (*node)->next->content > (*node)->next->next->content)
	{
		if ((*node)->content > (*node)->next->next->content)
			rev_rotate_a(node);
		else
		{
			swap_a(node);
			rotate_a(node);
		}
	}
	else if (((*node)->content < (*node)->next->content)
		&& (*node)->next->content < (*node)->next->next->content)
		exit(0);
}

void	alg_4(t_node **list_a, t_node **list_b)
{
	t_node	*tail;

	tail = last_node(*list_a);
	if (((*list_a)->content < (*list_b)->next->content)
		&& ((*list_a)->content < tail->content))
	{
		push_b(list_b, list_a);
		alg_3(list_a);
		push_a(list_a, list_b);
	}
}