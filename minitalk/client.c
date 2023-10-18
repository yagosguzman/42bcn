/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:57:30 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/18 20:00:09 by ysanchez         ###   ########.fr       */
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

int	ft_atoi(char *str)
{
	int				i;
	long long int	result;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
		if (result > INT_MAX)
			return (-1);
	}
	return (result);
}

int	ft_isdigit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

void	char_2_bin(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
		{
			if (kill(pid, SIGUSR1) != 0)
				ft_putstr_fd("Failed to send signal.\n", 2);
			if (kill(pid, SIGUSR2) != 0)
				ft_putstr_fd("Failed to send signal.\n", 2);
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
		ft_putstr_fd("ERROR, WRONG FORMAT\n"
			"To properly use Minitalk write ./client <PID> \"Message\"\n"
			"Example: ./client 4242 Hello World!\n", 2); 
		return (1);
	}
	if (ft_isdigit(argv[1]) == 1)
		ft_putstr_fd("Invalid PID, please check the PID number again.\n", 2);
	if (!argv[2])
		ft_putstr_fd("ERROR, Empty message, please check your input.\n", 2);
	else
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		if (pid == -1)
			ft_putstr_fd("Invalid PID, please check the PID number again.\n", 2);
		while (argv[2] && argv[2][i])
			char_2_bin(pid, argv[2][i++]);
		char_2_bin(pid, '\n');
	}
	return (0);
}
