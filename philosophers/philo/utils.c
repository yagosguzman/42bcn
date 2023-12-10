/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:16:16 by ysanchez          #+#    #+#             */
/*   Updated: 2023/12/10 19:47:40 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_handler(pthread_mutex_t *mutex, t_mutex operation)
{
	if (operation == INIT)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			return (ft_mutex_error(INIT));
	}
	else if (operation == LOCK)
	{
		if (pthread_mutex_lock(mutex) != 0)
			return (ft_mutex_error(LOCK));
	}
	else if (operation == UNLOCK)
	{
		if (pthread_mutex_unlock(mutex) != 0)
			return (ft_mutex_error(UNLOCK));
	}
	else if (operation == DESTROY)
	{
		if (pthread_mutex_destroy(mutex) != 0)
			return (ft_mutex_error(DESTROY));
	}
	else
		printf("Check the operation code used mutex_handler.\n");
	return (0);
}

int	thread_handler(pthread_t *thread, void *(*foo)(void *),
	void *data, t_thread operation)
{
	if (operation == CREATE)
	{
		if (pthread_create(thread, NULL, foo, data) != 0)
			return (ft_thread_error(CREATE));
	}
	else if (operation == JOIN)
	{
		if (pthread_join(*thread, NULL) != 0)
			return (ft_mutex_error(JOIN));
	}
	else if (operation == DETACH)
	{
		if (pthread_detach(*thread) != 0)
			return (ft_mutex_error(DETACH));
	}
	else
		printf("Check the operation code used in thread_handler.\n");
	return (0);
}

void	sync_threads(t_args *args)
{
	while (get_int(&args->args_mutex, &args->ready) != 0)
		;
}

long	gettime(t_time time_unit)
{
	struct timeval	time_value;

	if (gettimeofday(&time_value, NULL) != 0)
		return (ft_error(5));
	if (time_unit == SECONDS)
		return (time_value.tv_sec + (time_value.tv_usec / 1e6));
	else if (time_unit == MILLISECONDS)
		return ((time_value.tv_sec * 1e3) + (time_value.tv_usec / 1e3));
	else if (time_unit == MICROSECONDS)
		return ((time_value.tv_sec * 1e6) + time_value.tv_usec);
	else
		return (ft_error(6));
}

void	precise_usleep(long usec, t_args *args)
{
	long	start;
	long	progress;
	long	remain;

	start = gettime(MICROSECONDS);
	while (gettime(MICROSECONDS) - start < usec)
	{
		if (simulation_finished(args) == 0)
			return ;
		progress = gettime(MICROSECONDS) - start;
		remain = usec - progress;
		if (remain > 1e3)
			usleep(remain / 2);
		else
		{
			while (gettime(MICROSECONDS) - start < usec)
				;
		}
	}
}
