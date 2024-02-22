/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:56:20 by ysanchez          #+#    #+#             */
/*   Updated: 2024/02/20 13:32:00 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_dead(t_philo *philo)
{
	long	last_time_eat;
	long	time_passed;
	long	time_to_die;

	if (get_value(&philo->philo_mutex, &philo->goal) == 1)
		return (1);
	last_time_eat = get_value(&philo->philo_mutex, &philo->last_time_eat);
	time_passed = gettime(MILLISECONDS) - last_time_eat;
	time_to_die = philo->args->time_to_die / 1000;
	if (time_passed > time_to_die)
		return (0);
	else
		return (1);
}

void	*dead_check(void *data)
{
	t_args	*args;
	int		i;

	args = (t_args *)data;
	while (all_running(&args->args_mutex, &args->running,
			args->philo_num) != 1)
		;
	while (simulation_finished(args) != 0)
	{
		i = 0;
		while (i < args->philo_num && simulation_finished(args) != 0)
		{
			if (philo_dead(&args->philoarr[i]) == 0)
			{
				write_status(DIED, args->philoarr + i);
				set_value(&args->args_mutex, &args->finish, 0);
			}
		}
	}
	return (NULL);
}
