/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:55:33 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/07 15:46:28 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_node *list_a)
{
	while (list_a->next != NULL)
	{
		printf("%i\n", list_a->content);
		list_a = list_a->next;
	}
}

t_node	*extract_argv(char **argv, t_node **list_a)
{
	char	**list;
	int		i;
	int		*int_list;

	i = 0;
	list_a = NULL;
	list = ft_split(argv[1], " ");
	if (ft_checkvalid(list) == 1) // CHECK DESPUES DE ATOI PARA VER QUE NO SE REPITEN NUMS
		return (ft_free(list));
	int_list = (int *)malloc((ft_strlen(*list) + 1) * sizeof(int));
	if (!int_list)
		return(ft_free(list));
	while (*list[i])
	{
		int_list[i] = ft_atoiextra(*list[i], int_list);
		if (!int_list)
			return (NULL);
		i++;
	}
	ft_free(list);
	i = 0;
	while (int_list[i])
	{
		insert_end(list_a, int_list[i]);
		i++;
	}
	ft_free(int_list);
	print_list(list_a);
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

int	order_b(t_node **root)
{
	t_node *current_node;

	current_node = *root;
	while (current_node->next != NULL)
	{
		if (current_node->content > current_node->next->content)
			current_node = current_node->next;
		else
			return (1);
	}
	return (0);
}


void	push_swap(int argc, char **argv)
{
	t_node	**list_a;
	t_node	**list_b;
	int		node_length;
	
	if (!argc || argc == 1)
		exit;
	if (argc == 2)
		*list_a = extract_argv(argv[1], list_a);
	list_b = NULL;
	node_length = node_count(list_a);
	printf("Num de nodos %i\n", node_length);
	return;

	// while (order_a(list_a) == 1 && node_count(list_a) != node_length)
	// {
	// 	while (condition1(list_a, list_b) == 1)
	// 	{

	// 	}
	// }
}
int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (0);
}