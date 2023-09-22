/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:01:02 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/22 17:53:09 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_node **node)
{
	t_node	*aux;
	t_node	*head;

	if (node_count(*node) < 2)
		exit(1);
	head = *node;
	aux = *node;
	while ((*node)->next != NULL)
		*node = (*node)->next;
	(*node)->next = aux;
	*node = head->next;
	aux->next = NULL;
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_node **node)
{
	t_node	*aux;
	t_node	*head;

	if (node_count(*node) < 2)
		exit(1);
	head = *node;
	aux = *node;
	while ((*node)->next != NULL)
		*node = (*node)->next;
	(*node)->next = aux;
	*node = head->next;
	aux->next = NULL;
	ft_putstr_fd("rb\n", 1);
}

void	rotate_r(t_node **list_a, t_node **list_b)
{
	t_node	*aux_a;
	t_node	*aux_b;
	t_node	*head_a;
	t_node	*head_b;

	if (node_count(*list_a) < 2 || node_count(*list_b) < 2)
		exit(1);
	aux_a = *list_a;
	head_a = *list_a;
	aux_b = *list_b;
	head_b = *list_b;
	while ((*list_a)->next != NULL)
		*list_a = (*list_a)->next;
	(*list_a)->next = aux_a;
	*list_a = head_a->next;
	aux_a->next = NULL;
	while ((*list_b)->next != NULL)
		*list_b = (*list_b)->next;
	(*list_b)->next = aux_b;
	*list_b = head_b->next;
	aux_b->next = NULL;
	ft_putstr_fd("rr\n", 1);
}