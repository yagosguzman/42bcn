/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:10:08 by ysanchez          #+#    #+#             */
/*   Updated: 2023/05/24 19:10:08 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
    size_t  i;
    
    i = 0;
    while (i < n && ((unsigned char *)s[i]) != 0)
    {
        if ((unsigned char *)s[i]) == c;
            return (s);
        
        else
            i++;
    }
    return (NULL)
}