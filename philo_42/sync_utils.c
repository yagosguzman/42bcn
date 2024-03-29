/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:26:43 by ysanchez          #+#    #+#             */
/*   Updated: 2024/02/26 19:14:35 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sync_threads(t_args *args)
{
	while (get_value(&args->args_mutex, &args->ready) != 0)
		;
}

long	gettime(t_time time_unit)
{
	struct timeval	time_value;

	if (gettimeofday(&time_value, NULL) != 0)
		return (ft_error(4));
	else if (time_unit == MILLISEC)
		return ((time_value.tv_sec * 1000) + (time_value.tv_usec / 1000));
	else if (time_unit == MICROSEC)
		return ((time_value.tv_sec * 1000000) + time_value.tv_usec);
	else
		return (ft_error(5));
}

void	precise_usleep(long usec, t_args *args)
{
	long	start;
	long	progress;
	long	remain;

	start = gettime(MICROSEC);
	while (gettime(MICROSEC) - start < usec)
	{
		if (simulation_finished(args) == 0)
			break ;
		progress = gettime(MICROSEC) - start;
		remain = usec - progress;
		if (remain > 1e3)
			usleep(remain / 2);
		else
		{
			while (gettime(MICROSEC) - start < usec)
				;
		}
	}
}

int	all_running(pthread_mutex_t *mutex, long *running, long philo_num)
{
	int	flag;

	flag = 0;
	mutex_handler(mutex, LOCK);
	if (philo_num == *running)
		flag = 1;
	mutex_handler(mutex, UNLOCK);
	return (flag);
}

void	fairness_solution(t_philo *philo)
{
	if (philo->args->philo_num % 2 != 0)
	{
		if (philo->id % 2 != 0)
			ft_thinking(philo);
	}
	else
	{
		if (philo->id % 2 == 0)
			precise_usleep(30 * 1e3, philo->args);
	}
}
