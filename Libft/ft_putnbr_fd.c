/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:17:22 by ysanchez          #+#    #+#             */
/*   Updated: 2023/06/08 17:11:11 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	strnum[12];

	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n < 0 && n > -2147483648)
	{
		n = -n;
		write (fd, "-", 1);
	}
	i = 0;
	while (n > 0 && n <= 2147483647)
	{
		strnum[i] = ((n % 10) + 48);
		i++;
		n = n / 10;
	}
	strnum[i--] = '\0';
	while (i >= 0)
	{
		write (fd, &strnum[i], 1);
		i--;
	}
}
/* 
int	main(void)
{
	ft_putnbr_fd(150, 1);
	return (0);
} */