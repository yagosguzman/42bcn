/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:38:53 by ysanchez          #+#    #+#             */
/*   Updated: 2023/12/11 13:38:04 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dining_sim(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	sync_threads(philo->args);
	//set last meal time

	while (get_int(&philo->args->args_mutex, &philo->args->finish) != 0)
	{
		if (get_int(&philo->args->args_mutex, &philo->goal) == 1)
			return ;
		ft_eating(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
	}
	
}

int	init_dining(t_args *args)
{
	int	i;

	i = 0;
	if (args->max_eat == 0)
		return (ft_error(4));
	else if (args->philo_num == 1)
		solo_philo(args->philoarr);//TODO
	else
	{
		while (i < args->philo_num)
		{
			thread_handler(&args->philoarr[i].thread_id, dining_sim,
				&args->philoarr[i], CREATE);
			i++;
		}
		args->start = gettime(MILLISECONDS);
		set_int(&args->args_mutex, &args->ready, 0);
	}
	i = 0;
	while (i < args->philo_num)
	{
		thread_handler(&args->philoarr[i].thread_id, NULL, NULL, JOIN);
		i++;
	}
	return (0);
}
