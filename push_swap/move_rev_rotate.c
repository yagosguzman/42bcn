/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:50:45 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/22 17:53:18 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_node **node)
{
	t_node	*aux;
	t_node	*tail;

	if (node_count(*node) < 2)
		exit(1);
	aux = *node;
	tail = last_node(*node);
	while (aux->next->next != NULL)
		aux = aux->next;
	tail->next = *node;
	*node = tail;
	aux->next = NULL;
	ft_putstr_fd("rra\n", 1);
}

void	rev_rotate_b(t_node **node)
{
	t_node	*aux;
	t_node	*tail;

	if (node_count(*node) < 2)
		exit(1);
	aux = *node;
	tail = last_node(*node);
	while (aux->next->next != NULL)
		aux = aux->next;
	tail->next = *node;
	*node = tail;
	aux->next = NULL;
	ft_putstr_fd("rrb\n", 1);
}

void	rev_rotate_r(t_node **list_a, t_node **list_b)
{
	t_node	*aux_a;
	t_node	*aux_b;
	t_node	*tail_a;
	t_node	*tail_b;

	if (node_count(*list_a) < 2 || node_count(*list_b) < 2)
		exit(1);
	aux_a = *list_a;
	aux_b = *list_b;
	tail_a = last_node(*list_a);
	tail_b = last_node(*list_b);
	while (aux_a->next->next != NULL)
		aux_a = aux_a->next;
	tail_a->next = *list_a;
	*list_a = tail_a;
	aux_a->next = NULL;
	while (aux_b->next->next != NULL)
		aux_b = aux_b->next;
	tail_b->next = *list_b;
	*list_b = tail_b;
	aux_b->next = NULL;
	ft_putstr_fd("rr\n", 1);
}