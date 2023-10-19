/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:57:30 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/19 21:13:33 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_2_bin(const int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("Failed to send signal, check PID number.\n", 2);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("Failed to send signal, check PID number.\n", 2);
				exit(1);
			}
		}
		usleep(50);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_putstr_fd("ERROR, Write ./client <PID> \"Message\"\n"
			"Example: ./client 4242 Hello World!\n", 2);
		return (1);
	}
	if (ft_isdigit(argv[1]) == 1)
	{
		ft_putstr_fd("Invalid PID, please check the PID number again.\n", 2);
		return (1);
	}
	if (ft_strlen(argv[2]) == 0)
	{
		ft_putstr_fd("ERROR, Empty message, please check your input.\n", 2);
		return (1);
	}
	else
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		if (pid == -1)
		{
		 	ft_putstr_fd("Invalid PID, please check the PID again.\n", 2);
			exit(1);
		}
		while (argv[2][i] != '\0')
			char_2_bin(pid, argv[2][i++]);
		char_2_bin(pid, '\n');
	}
	return (0);
}
