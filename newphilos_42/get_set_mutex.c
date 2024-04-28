/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:32:20 by ysanchez          #+#    #+#             */
/*   Updated: 2024/04/28 16:10:07 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_value(pthread_mutex_t *mutex, long *dst, long value)
{
	mutex_handler(mutex, LOCK);
	*dst = value;
	mutex_handler(mutex, UNLOCK);
}

long	get_value(pthread_mutex_t *mutex, long *src)
{
	long	result;

	mutex_handler(mutex, LOCK);
	result = *src;
	mutex_handler(mutex, UNLOCK);
	return (result);
}

int	simulation_finished(t_data *data)
{
	if (get_value(&data->data_mtx, &data->finish) == 0
		|| get_value(&data->data_mtx, &data->full) < data->philo_num)
		return (0);
	return (1);
}
