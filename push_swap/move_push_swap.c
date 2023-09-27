/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:34:51 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/27 20:01:35 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **first_a, t_node **first_b)
{
	t_node	*node2push;

	node2push = *first_b;
	*first_b = (*first_b)->next;
	*first_a = insert_front(first_a, node2push->content);
	free_node(&node2push);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_node **first_b, t_node **first_a)
{
	t_node	*node2push;

	node2push = *first_a;
	*first_a = (*first_a)->next;
	*first_b = insert_front(first_b, node2push->content);
	free_node(&node2push);
	ft_putstr_fd("pb\n", 1);
}

void	swap_a(t_node **node)
{
	t_node	*first;
	t_node	*second;

	if (*node == NULL || (*node)->next == NULL)
		exit(1);
	first = *node;
	second = (*node)->next;
	first->next = second->next;
	second->next = first;
	*node = second;
	// *node = (*node)->next;
	// aux->next = (*node)->next;
	// (*node)->next = aux;
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_node **node)
{
	t_node	*aux;

	if (*node == NULL || (*node)->next == NULL)
		exit(1);
	aux = *node;
	*node = (*node)->next;
	aux->next = (*node)->next;
	(*node)->next = aux;
	ft_putstr_fd("sb\n", 1);
}

void	swap_ss(t_node **list_a, t_node **list_b)
{
	t_node	*aux_a;
	t_node	*aux_b;

	if (node_count(*list_a) < 2 || node_count(*list_b) < 2)
		exit(1);
	aux_a = *list_a;
	*list_a = (*list_a)->next;
	aux_a->next = (*list_a)->next;
	(*list_a)->next = aux_a;
	aux_b = *list_b;
	*list_b = (*list_b)->next;
	aux_b->next = (*list_b)->next;
	(*list_b)->next = aux_b;
	ft_putstr_fd("ss\n", 1);
}

// void	node_swap(t_node *node)
// {
// 	t_node	*aux;

// 	aux = node;
// 	node = node->next;
// 	aux->next = node->next;
// 	node->next = aux;
// }

// void	ft_swap(t_node *list_a, t_node *list_b)
// {
// 	if ((list_a->content > list_a->next->content)
// 		&& (list_b->content < list_b->next->content))
// 	{
// 		node_swap(list_a);
// 		node_swap(list_b);
// 		ft_putstr_fd("ss\n", 1);
// 	}
// 	else if (list_a->content > (list_a->next)->content)
// 	{
// 		node_swap(list_a);
// 		ft_putstr_fd("sa\n", 1);
// 	}
// 	else if (list_b->content < (list_b->next)->content)
// 	{
// 		node_swap(list_b);
// 		ft_putstr_fd("sb\n", 1);
// 	}
// }