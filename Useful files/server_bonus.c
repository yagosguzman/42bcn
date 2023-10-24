/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:15:50 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/24 20:23:47 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr(int sig, siginfo_t *info, void *s)
{
	static int	bit = 0;
	static char	c = '\0';

	(void)info;
	(void)s;
	if (sig == SIGUSR1)
		c = c | (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar(c);
		bit = 0;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_sigusr;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_putstr_fd("Error handling signals\n", 2);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_putstr_fd("Error handling signals\n", 2);
	ft_putstr_fd("Welcome to ysanchez's server, your PID is [", 1);
	ft_putnbr(getpid());
	ft_putstr_fd("]\n", 1);
	while (1)
		usleep(50);
	return (0);
}
