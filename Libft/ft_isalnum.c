/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:26:24 by ysanchez          #+#    #+#             */
/*   Updated: 2023/06/23 16:26:44 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c < 'a' || c > 'z')
		&& (c < 'A' || c > 'Z')
		&& (c < '0' || c > '9'))
		return (0);
	return (1);
}
