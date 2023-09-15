/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:34:51 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/15 20:23:23 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pusha(t_node *first_a, t_node *first_b)
{
	t_node	*node2push;

	node2push = first_b;
	first_b = first_b->next;
	first_a = clone_node(node2push, first_a);
	free_node(node2push);
	ft_putstr_fd("pa\n", 1);
}

void	ft_pushb(t_node *first_b, t_node *first_a)
{
	t_node	*node2push;

	node2push = first_a;
	first_a = first_a->next;
	first_b = clone_node(node2push, first_b);
	free_node(node2push);
	ft_putstr_fd("pb\n", 1);
}

void	ft_swapa(t_node *node)
{
	t_node	*aux;

	aux = node;
	node = node->next;
	aux->next = node->next;
	node->next = aux;
	ft_putstr_fd("sa\n", 1);
}

void	ft_swapb(t_node *node)
{
	t_node	*aux;

	aux = node;
	node = node->next;
	aux->next = node->next;
	node->next = aux;
	ft_putstr_fd("sb\n", 1);
}

void	node_swap(t_node *node)
{
	t_node	*aux;

	aux = node;
	node = node->next;
	aux->next = node->next;
	node->next = aux;
}

void	ft_swap(t_node *list_a, t_node *list_b)
{
	if ((list_a->content > list_a->next->content)
		&& (list_b->content < list_b->next->content))
	{

		node_swap(list_a);
		node_swap(list_b);
		ft_putstr_fd("ss\n", 1);
	}
	else if (list_a->content > (list_a->next)->content)
	{
		node_swap(list_a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (list_b->content < (list_b->next)->content)
	{
		node_swap(list_b);
		ft_putstr_fd("sb\n", 1);
	}
}
