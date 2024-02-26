/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:38:53 by ysanchez          #+#    #+#             */
/*   Updated: 2024/02/26 20:13:15 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dining_sim(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	sync_threads(philo->args);
	// while (get_value(&philo-args->args_mutex, &args->ready) != 0)
	set_value(&philo->philo_mutex, &philo->last_time_eat, gettime(MILLISEC));
	set_value(&philo->args->write_mutex, &philo->args->running,
		philo->args->running + 1);
	fairness_solution(philo); // Hace que todos los th hagan algo al inicio
	while (simulation_finished(philo->args) != 0)
	{
		if (get_value(&philo->args->args_mutex, &philo->goal) == 1)
			break;
		else
		{
			ft_eating(philo);
			ft_sleeping(philo);
			ft_thinking(philo);
		}
	}
	return (NULL);
}

void	*solo_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	set_value(&philo->philo_mutex, &philo->last_time_eat, gettime(MILLISEC));
	set_value(&philo->args->args_mutex, &philo->args->running,
		philo->args->running + 1);
	set_value(&philo->args->write_mutex, &philo->args->start,
		gettime(MILLISEC));
	write_status(TOOK_1ST_FORK, philo);
	usleep(philo->args->time_to_die);
	return (NULL);
}

int	init_dining(t_args *args)
{
	int	i;

	i = 0;
	if (args->philo_num == 1)
		thread_handler(&args->philoarr[0].thread_id, solo_philo,
			&args->philoarr[0], CREATE);
	else
	{
		while (i < args->philo_num)
		{
			thread_handler(&args->philoarr[i].thread_id, dining_sim,
				&args->philoarr[i], CREATE);
			i++;
		}
		thread_handler(&args->checker, dead_check, args, CREATE);
		args->start = gettime(MILLISEC);
		set_value(&args->args_mutex, &args->ready, 0);
	}
	i = 0;
	while (i < args->philo_num)
	{
		thread_handler(&args->philoarr[i].thread_id, NULL, NULL, JOIN);
		i++;
	}
	set_value(&args->args_mutex, &args->finish, 0);
	thread_handler(&args->checker, NULL, NULL, JOIN);
	return (0);
}
