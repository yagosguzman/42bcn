/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:34:51 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/07 15:46:48 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_node **first_a, t_node **first_b)
{
	ft_putstr("pb\n");
}


void	ft_swap(t_node *root_a, t_node *root_b)
{
	if (root_a->content > root_a->next->content &&
		root_b->content < root_b->next->content)
	{

		ft_lst_swap(lst_a);
		ft_lst_swap(lst_b);
		ft_putstr("ss\n");
	}
	else if (lst_a->content > (lst_a->next)->content)
	{
		ft_lst_swap(lst_a);
		ft_putstr("sa\n");
	}
	else if (lst_b->content < (lst_b->next)->content)
	{
		ft_lst_swap(lst_b);
		ft_putstr("sb\n");
	}
}
void node_swap(t_node *root)
{
	t_node	*aux;

	aux = root->next;
	root->next->next = root;
	root->next = aux->next;	
}

void node_swapcontent(t_node *root)
{
	
}


void	swap_b(t_node **first_b)
{
	ft_putstr("sb\n");
}

void	swap_s (t_node **first_a, t_node **first_b)
{
		ft_putstr("ss\n");
}

int	main(void)
{
	t_node	*current;

	current = NULL;
	
}