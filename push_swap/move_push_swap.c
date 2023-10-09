/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:34:51 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/09 17:47:59 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **first_a, t_node **first_b)
{
	t_node	*node2push;

	if (*first_b == NULL || first_b == NULL)
		return ;
	node2push = *first_b;
	*first_b = (*first_b)->next;
	*first_a = insert_front(first_a, node2push->content);
	free_node(&node2push);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_node **first_b, t_node **first_a)
{
	t_node	*node2push;

	if (*first_a == NULL || first_a == NULL)
		return ;
	node2push = *first_a;
	*first_a = (*first_a)->next;
	*first_b = insert_front(first_b, node2push->content);
	free_node(&node2push);
	ft_putstr_fd("pb\n", 1);
}

void	swap_a(t_node **node)
{
	t_node	*aux;

	if (*node == NULL || (*node)->next == NULL || node == NULL)
		return ;
	aux = *node;
	*node = (*node)->next;
	aux->next = (*node)->next;
	(*node)->next = aux;
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_node **node)
{
	t_node	*aux;

	if (*node == NULL || (*node)->next == NULL || node == NULL)
		return ;
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

	if (node_count(*list_a) < 2 || node_count(*list_b) < 2
		|| *list_a == NULL || (*list_a)->next == NULL || list_a == NULL
		|| *list_b == NULL || (*list_b)->next == NULL || list_b == NULL)
		return ;
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
