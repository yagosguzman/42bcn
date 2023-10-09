/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:45:37 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/06 17:47:18 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	print_list(t_node *list_a, t_node *list_b)
{
	printf("\n---------STACK A---------\n\n");
	if (list_a == NULL) 
	{
		printf("La lista A está vacía.\n\n");
	}
	else 
	{
		while (list_a != NULL)
		{
			printf("%i \n", list_a->content);
			list_a = list_a->next;
		}
	}
	printf("\n---------STACK B---------\n\n");
	if (list_b == NULL) 
	{
		printf("La lista B está vacía.\n\n");
	}
	else 
	{
		while (list_b != NULL)
		{
			printf("%i \n", list_b->content);
			list_a = list_b->next;
		}
	}
}