/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:55:33 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/05 19:59:24 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*FUNCIONES DEL PUSH SWAP*/
//Swap

//Push

//Rotate

//Reverse rotate

// int main (void)
// {
// 	char *str = "999a9";

// 	printf("%i", ft_atoi(str));
// 	return (0);
// }

int main(int argc. char *argv[])
{
	Node* list_a = malloc(sizeof(Node));
	if (!list_a)
		return(NULL);
	list_a.content = ft_atoi(number);
	list_a.next = malloc(sizeof(Node));
	list_a.next->content = ft_atoi(number++);
	list_a.next->next = NULL;

	free(list_a.next);
	return (0);
}

// tenemos que liberar la memoria desde atras hacia delante.

void listadd_end(Node **list, int content)
{
	Node *new_node ;
	*new_node = malloc(sizeof(Node));
	if (!new_node)
		return(NULL);
	new_node->next = NULL;
	new_node->content = value;
}
int	push_swap(int)
{
	char **list_a;
	if (!argc || argc == 1)
		return (NULL);
	if (argc == 2)
		*list_a = ft_split(argv[1]);
		list_a

}