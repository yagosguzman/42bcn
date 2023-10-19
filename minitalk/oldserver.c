/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldserver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:15:50 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/19 19:25:55 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int num)
{
	if (num > 9)
	{
		ft_putnbr(num / 10);
		num = num % 10;
	}
	if (num <= 9)
		ft_putchar(('0' + num));
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

void	handle_sigusr(int sig)
{
	static int	bit = 0;
	static int	i = '\0';

	if (sig == SIGUSR1)
		i = i | (1 << bit);	
	bit++;
	if (bit == 8)
	{
		ft_putchar(i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handle_sigusr;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_putstr_fd("Error handling signals\n", 2);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_putstr_fd("Error handling signals\n", 2);
	ft_putstr_fd("Welcome to ysanchez's server, your PID is [", 1);
	ft_putnbr(getpid());
	ft_putstr_fd("]\n", 1);
	while (1)
		usleep(50);
		// signal(SIGUSR1, handle_sigusr);
		// signal(SIGUSR2, handle_sigusr);
	return (0);
}
