/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:58:46 by ysanchez          #+#    #+#             */
/*   Updated: 2024/04/28 18:13:22 by ysanchez         ###   ########.fr       */
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
	precise_usleep(philo->data->time_to_die);
	mutex_handler(&philo->rightfork->fork_mtx, UNLOCK);
	write_status(DIED, philo);
}

void	*routine(void *v_data)
{
	t_data	*data;


	data = v_data;
	// if (data->philoarr->id % 2 != 0)
	// 	precise_usleep(data->time_to_eat / 10);
	while (data->finish != 1)
	{
		if (data->philo_num == 1)
		{
			solo_philo(data->philoarr);
			break ;
		}
		multiple_philos(data->philoarr);
	}
	return ((void *)0);
}

void	init_dining(t_data *data)
{
	data->start = ft_gettime(0);
	mutex_handler(&data->data_mtx, UNLOCK);
	routine((void *)data->philoarr);
}
