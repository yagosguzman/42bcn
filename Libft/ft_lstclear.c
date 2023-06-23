/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:32:24 by ysanchez          #+#    #+#             */
/*   Updated: 2023/06/21 17:01:02 by ysanchez         ###   ########.fr       */
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
