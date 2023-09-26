/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:55:33 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/26 12:25:43 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_node	*MALextract_argv(char *argv, t_node *list_a)
// {
// 	char	**list;
// 	int		i;
// 	int		*int_list;

// 	i = 0;
// 	list_a = NULL;
// 	list = ft_split(argv, 32);
// 	// while (**list)
// 	// {
// 	// 	printf("%s\n", *list);
// 	// 	*list++;
// 	// }
// 	if (ft_checkvalid(list) == 1) // CHECK DESPUES DE ATOI PARA VER QUE NO SE REPITEN NUMS
// 		return (ft_free(list));
// 	int_list = (int *)malloc((ft_strlen(*list) + 1) * sizeof(int));
// 	if (!int_list)
// 		return(ft_free(list));
// 	while (*list[i])
// 	{
// 		int_list[i] = ft_atoiextra(*list, int_list);
// 		if (!int_list)
// 			return (NULL);
// 		i++;
// 	}
// 	while (**int_list)
// 	{
// 		printf("%i\n", *int_list);
// 		*int_list++;
// 	}
// 	ft_free(list);
// 	i = 0;
// 	while (int_list[i])
// 	{
// 		insert_end(list_a, int_list[i]);
// 		i++;
// 	}
// 	ft_free(int_list);
// 	print_list(list_a);
// 	return (list_a);
// }

int	order_a(t_node *root)
{
	t_node	*current_node;

	current_node = root;
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
	if (node_length == 3)
		alg_3(&list_a);
	if (node_length <= 5 && node_length > 3)
		alg_to5(&list_a, &list_b);
	// while (order_a(list_a) == 1 && node_count(list_a) != node_length)
	// {
	// 	if (node_length == 3)
	// 	{
	// 		alg_3(&list_a);
	// 	}
	// }
	// 	while (condition1(list_a, list_b) == 1)
	// 	{
	// 	}
	// }
	print_list(list_a);
	return (0);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (0);
}