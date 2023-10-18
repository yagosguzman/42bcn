/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:15:50 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/18 20:00:05 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	static int	bit;
	static int	i;
	int			n;

	if (sig == SIGUSR1)
		n = 1;
	if (sig == SIGUSR2)
		n = 0;
	i = (i << 1) + n;
	bit++;
	if (bit == 8)
	{
		write (1, &n, 1);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handle_sigusr;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_putstr_fd("Error handling signals\n", 2);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_putstr_fd("Error handling signals\n", 2);
	printf("Welcome to ysanchez's server, your PID is [%i]\n", getpid());
	while (1)
		usleep(100);
	return (0);
}
