/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:26:43 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/22 17:57:47 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_list(t_node *list_a)
// {
// 	while (list_a->next != NULL)
// 	{
// 		printf("%i\n", list_a->content);
// 		list_a = list_a->next;
// 	}
// }

// int	ft_isdigitplus(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if ((str[i] < '0' && str[i] != ' ' && str[i] != '-' && str[i] != '+')
// 			|| str[i] > '9')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

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

// int	main(int argc, char **argv)
// {
// 	printf("%i", ft_checkvalid(argv));
// 	return (0);
// }
/*TEST LISTAS MOVIMIENTOS*/
	// push_b(&list_b, &list_a);
	// push_b(&list_b, &list_a);
	// push_b(&list_b, &list_a);
	// rev_rotate_r(&list_a, &list_b);
	// printf("Lista A nueva\n");
	// print_list(list_a);
	// printf("Lista B nueva\n");
	// print_list(list_b);
	// print_list(list_b);
	// printf("LISTA B\n\n\nLista A\n");
	// print_list(list_a);