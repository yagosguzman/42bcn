/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:26:43 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/13 18:25:30 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigitplus(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' && str[i] != ' ' && str[i] != '-' && str[i] != '+')
			|| str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

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

int	main(int argc, char **argv)
{
	printf("%i", ft_checkvalid(argv));
	return (0);
}