/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:08:42 by ysanchez          #+#    #+#             */
/*   Updated: 2023/06/23 16:08:45 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*auxlst;

	if (*lst)
	{
		while (*lst != NULL)
		{
			auxlst = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = auxlst;
		}
	}
}
