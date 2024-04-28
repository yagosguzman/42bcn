/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:58:46 by ysanchez          #+#    #+#             */
/*   Updated: 2024/04/27 14:24:56 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	multiple_philos(t_philo *philo)
{
	ft_eating(philo);
	ft_sleeping(philo);
	ft_thinking(philo);
}

void	solo_philo(t_philo *philo)
{
	mutex_handler(&philo->rightfork->fork_mtx, LOCK);
	write_status(TOOK_1ST_FORK, philo);
	precise_usleep(philo->data->time_to_die * 1000, philo->data);
	mutex_handler(&philo->rightfork->fork_mtx, UNLOCK);
}

void	*routine(void *v_data)
{
	t_philo	*philo;

	philo = v_data;
	if (philo->id % 2 != 0)
		precise_usleep(philo->data->time_to_eat * 100, philo->data);
	while (philo->goal < philo->data->philo_num)
	{
		if (philo->data->philo_num == 1)
		{
			solo_philo(philo);
			break ;
		}
		multiple_philos(philo);
	}
	return ((void *)0);
}

void	init_dining(t_data *data)
{
	data->start = gettime(MILLISEC);
	mutex_handler(&data->data_mtx, UNLOCK);
	routine((void *)data->philoarr);
}
