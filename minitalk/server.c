/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:08:46 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/19 21:04:45 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr(int sig)
{
	static int	bit = 0;
	static char	c = '\0';

	if (sig == SIGUSR1)
		c = c | (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar(c);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("Welcome to ysanchez's server, your PID is [", 1);
	ft_putnbr(getpid());
	ft_putstr_fd("]\n", 1);
	while (1)
	{
		signal(SIGUSR1, handle_sigusr);
		signal(SIGUSR2, handle_sigusr);
	}
	return (0);
}
