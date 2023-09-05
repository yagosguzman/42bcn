/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:55:39 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/05 19:59:25 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_front(t_node **root, int value)
{
	t_node	*first_node;

	first_node = malloc(sizeof(t_node));
	if (!first_node)
		exit (NULL);
	first_node->content = value;
	first_node->next = *root;
	*root = first_node;
}

void	insert_back(t_node **root, int value)
{
	t_node	*current;
	t_node	*last_node;

	current = *root;
	last_node = malloc(sizeof(t_node));
	if (!last_node)
		exit(NULL);
	while (current->next != NULL)
		current = current->next;
	current->next = last_node;
	last_node->next = NULL;
}

void	free_listnode(t_node **root)
{
	t_node	*current_node;
	t_node	*aux_node;

	current_node = *root;
	while (current_node != NULL)
	{
		aux_node = current_node;
		current_node = current_node-> next;
		free(aux_node);
	}
	*root = NULL;
}