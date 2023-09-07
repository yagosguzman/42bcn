/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:13:31 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/07 15:46:46 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	condition1(t_node *list_a, t_node *list_b)
{
	if (list_a->content > list_a->next->content ||
		list_a->content > last_node(list_a)->content ||
		list_b->content < list_b->next->content ||
		list_b->content < last_node(list_b)->content )
		return (1);
	return (0);
}


void	ft_ss_sa_sb(t_list *lst_a, t_list *lst_b)
{
	if (lst_a->content > (lst_a->next)->content &&
		lst_b->content < (lst_b->next)->content)
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