/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:08:43 by ysanchez          #+#    #+#             */
/*   Updated: 2023/12/10 20:19:30 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(t_status status, t_philo *philo)
{
	long	time_passed;

	time_passed = gettime(MILLISECONDS) - philo->args->start;
	if (get_long(philo->args->args_mutex, philo->goal))
		return ;
	mutex_handler(&philo->args->write_mutex, LOCK);
	if (simulation_finished(philo->args) != 0)
	{
		if (status == TOOK_1ST_FORK || status == TOOK_2ND_FORK)
			printf("%ld %i has taken a fork.\n", time_passed, philo->id);
		if (status == EATING)
			printf("%ld %i is eating.\n", time_passed, philo->id);
		if (status == SLEEPING)
			printf("%ld %i is sleeping.\n", time_passed, philo->id);
		if (status == THINKING)
			printf("%ld %i is thinking.\n", time_passed, philo->id);
		if (status == DIED)
			printf("%ld %i died.\n", time_passed, philo->id);
	}
	mutex_handler(&philo->args->write_mutex, UNLOCK);
}
