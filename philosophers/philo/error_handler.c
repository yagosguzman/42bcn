/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:26:26 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/22 21:17:56 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(int errnum)
{
	if (errnum == 0)
		printf ("Error\nIncorrect number of arguments.\nPlease write ./philo "
			"[1][2][3][4][*5]\n1.number_of_philosophers\n2.time_to_die(in ms)\n"
			"3.time_to_eat(in ms)\n4.time_to_sleep (in ms)\n(*Optional)\n5."
			"number_of_times_each_philosopher_must_eat\n");
	if (errnum == 1)
		printf("Error\nFound unexpected characters in the arguments.\n");
	if (errnum == 2)
		printf("Error\nYou can only use unsigned integers as arguments.\n");
	if (errnum == 3)
		printf("Error\nProblem creating malloc.\n");
	return (1);
}

int	ft_mutex_error(int errnum)
{
	if (errnum == INIT)
		printf("Problem initializing the mutex.\n");
	if (errnum == LOCK)
		printf("Problem locking the mutex.\n");
	if (errnum == UNLOCK)
		printf("Problem unlocking the mutex.\n");
	if (errnum == DESTROY)
		printf("Problem destroying the mutex.\n");
	return (1);
}

int	ft_thread_error(int errnum)
{
	if (errnum == CREATE)
		printf("Problem creating the thread.\n");
	if (errnum == JOIN)
		printf("Problem while joining the thread.\n");
	if (errnum == DETACH)
		printf("Problem detaching the thread.\n");
	return (1);
}
