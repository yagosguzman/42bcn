/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:05:59 by ysanchez          #+#    #+#             */
/*   Updated: 2023/06/23 16:10:01 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*templist;

	if (!lst || !f)
		return (NULL);
	newlist = (t_list *)malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	newlist->content = f(lst->content);
	templist = newlist;
	lst = lst->next;
	while (lst)
	{
		newlist->next = (t_list *)malloc(sizeof(t_list));
		if (!newlist->next)
		{
			ft_lstclear(&templist, del);
			return (NULL);
		}
		newlist = newlist->next;
		newlist->content = f(lst->content);
		lst = lst->next;
	}
	newlist->next = NULL;
	return (templist);
}
