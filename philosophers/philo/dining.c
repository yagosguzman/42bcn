/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:38:53 by ysanchez          #+#    #+#             */
/*   Updated: 2023/12/01 17:54:46 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *dining_sim(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
}

int	init_dining(t_args *args)
{
	int	i;

	i = 0;
	if (args->max_eat == 0)
		return (ft_error(4));
	else if (args->philo_num == 1)
		new_function;
	else
	{
		while (i < args->philo_num)
		{
			thread_handler(&args->philoarr[i].thread_id, dining_sim,
				&args->philoarr[i], CREATE);
			i++;
		}
	}
}
