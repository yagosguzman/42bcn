/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:55:39 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/26 16:32:27 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*insert_front(t_node **root, int value)
{
	t_node	*first_node;

	first_node = (t_node *)malloc(sizeof(t_node));
	if (!first_node)
		exit (1);
	first_node->content = value;
	first_node->next = *root;
	*root = first_node;
	return (*root);
}

t_node	*insert_end(t_node *root, int value)
{
	t_node	*current;
	t_node	*last_node;

	current = root;
	last_node = malloc(sizeof(t_node));
	if (!last_node)
		exit(1);
	last_node->content = value;
	last_node->next = NULL;
	if (root == NULL)
		root = last_node;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = last_node;
	}
	return (root);
}

void	free_node(t_node **node)
{
	t_node	*aux_node;

	aux_node = *node;
	*node = (*node)->next;
	free(aux_node);
}

t_node	*free_listnode(t_node *root)
{
	t_node	*current_node;
	t_node	*aux_node;

	current_node = root;
	while (current_node != NULL)
	{
		aux_node = current_node;
		current_node = current_node-> next;
		free(aux_node);
	}
	root = NULL;
	return (root);
}

t_node	*last_node(t_node *root)
{
	t_node	*last_node;

	last_node = root;
	while (last_node->next != NULL)
		last_node = last_node->next;
	return (last_node);
}
