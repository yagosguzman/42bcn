/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:55:33 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/06 20:10:59 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*FUNCIONES DEL PUSH SWAP*/
//Swap

//Push

//Rotate

//Reverse rotate

t_node	*extract_argv(char *argv[])
{
	char	**list;
	int		i;
	int		*int_list;
	t_node	*list_a;

	i = 0;
	list_a = NULL;
	list = ft_split(argv[1], " ");
	if (ft_checkvalid(list) == 1) // comprobamos que ningun num se repita y comprobemos que todos son nums
		return (ft_free(list));
	int_list = (int *)malloc((ft_strlen(*list) + 1) * sizeof(int));
	if (!int_list)
		return(ft_free(list));
	while (*list[i])
	{
		int_list[i] = int_ft_atoiextra(*list[i], int_list);
		if (!int_list)
			return (NULL);
		i++;
	}
	ft_free(list);
	while (int_list[i])
	{
		insert_end(list_a, int_list[i]);
		i++;
	}
	ft_free(int_list);
	return (list_a);
}

int	order_a(t_node **root)
{
	t_node *current_node;

	current_node = *root;
	while (current_node->next != NULL)
	{
		if (current_node->content < current_node->next->content)
			current_node = current_node->next;
		else
			return (1);
	}
	return (0);
}

int	push_swap(int argc, char **argv)
{
	char	**list_a;
	char	**list_b;
	int		node_length;
	if (!argc || argc == 1)
		return (NULL);
	if (argc == 2)
		*list_a = extract_argv(argv[1]);
	list_b = NULL;
	node_length = node_count(list_a);
	while (order_a(list_a) == 1 && node_count(list_a) != node_length)
	{
		
	}
}
