/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:55:39 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/13 16:29:40 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_front(t_node *root, int value)
{
	t_node	*first_node;

	first_node = malloc(sizeof(t_node));
	if (!first_node)
		exit (NULL);
	first_node->content = value;
	first_node->next = root;
	root = first_node;
}
 
t_node	*ft_lstnew(int value)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->content = value;
	newnode->next = NULL;
	return (newnode);
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

void	free_listnode(t_node *root)
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
}

void	insert_after(t_node *node, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->content = value;
	new_node->next = node->next;
	node->next = new_node;
}

int		node_count(t_node *root)
{
	int		i;
	t_node	*current_node;

	i = 0;
	current_node = root;
	while (current_node != NULL)
	{
		current_node = current_node->next;
		i++;
	}
	return (i);
}

t_node	*last_node(t_node *root)
{
	t_node	*last_node;

	last_node = root;
	while (last_node->next != NULL)
		last_node = last_node->next;
	return (last_node);
}