/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:55:33 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/02 17:10:27 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_node *list_a)
{
	if (list_a == NULL) 
	{
		printf("La lista está vacía.\n");
	}
	else 
	{
		while (list_a != NULL)
		{
			printf("%i\n", list_a->content);
			list_a = list_a->next;
		}
	}
}

int	push_swap(int argc, char **argv)
{
	t_node	*list_a;
	t_node	*list_b;
	int		node_length;

	list_a = NULL;
	if (ft_checkvalid(argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!argc || argc <= 2)
		return (1);
	if (argc > 2)
	{
		list_a = extract_argv(argc, argv);
		if (!list_a)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
	}
	list_b = NULL;
	node_length = node_count(list_a);
	algorithm_selection(&list_a, &list_b, node_length);
	free_listnode(list_b);
	free_listnode(list_a);
	return (0);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (0);
}
