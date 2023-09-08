/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:26:43 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/08 14:35:53 by ysanchez         ###   ########.fr       */
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

int	main(void)
{
	char *str;

	str = "123 -1 ++++ a   7";
	printf("%i", ft_isdigitplus(str));
	return (0);
}