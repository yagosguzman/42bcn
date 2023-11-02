/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:58:51 by ysanchez          #+#    #+#             */
/*   Updated: 2023/06/07 20:31:01 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n, int sign)
{
	int	i;

	i = 0;
	if (n == 0)
		i += 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i + sign);
}

static int	ft_sign(long n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	int		i;
	long	number;
	int		sign;
	char	*result;

	i = 0;
	number = (long) n;
	sign = ft_sign(number);
	if (sign)
		number *= -1;
	i = ft_intlen(number, sign);
	result = malloc ((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result [i--] = '\0';
	while (i >= 0)
	{
		result[i--] = ((number % 10) + 48);
		number /= 10;
	}
	if (sign > 0)
		result[0] = 45;
	return (result);
}
/* int main(void)
{
	ft_itoa(-125);
	return(0);
}
 */