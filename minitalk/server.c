/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:15:50 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/13 19:24:49 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr1(int sig)
{

}
void	handle_sigusr2(int sig)
{
	
}

int	main (int argc, char **argv)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{

	}
	else
	{
		
	}
}
