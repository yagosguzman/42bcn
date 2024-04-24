/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:25:46 by ysanchez          #+#    #+#             */
/*   Updated: 2024/04/24 20:02:13 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_philo *philo, int pos, t_fork *forks)
{
	if (philo->id == 1)
	{
		philo->leftfork = &forks[pos];
		philo->rightfork = &forks[philo->table->philo_num - 1];
	}
	else
	{
		philo->leftfork = &forks[pos];
		philo->rightfork = &forks[(pos - 1)];
	}
}

void	init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->philo_num)
	{
		philo = &data->philoarr[i];
		philo->id = i + 1;
		philo->num_eat = 0;
		philo->goal = 0;
		philo->table = data;
		mutex_handler(&philo->philo_mutex, INIT);
		init_forks(philo, i, data->forks);
		i++;
	}
}

int	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->finish = -1;
	data->ready = -1;
	data->running = 0;
	data->start = 0;
	mutex_handler(&data->table_mutex, INIT);
	mutex_handler(&data->write_mutex, INIT);
	data->forks = malloc(sizeof(t_fork) * data->philo_num);
	if (!data->forks)
		return (ft_error(3));
	while (i < data->philo_num)
	{
		mutex_handler(&data->forks[i].fork_mtx, INIT);
		data->forks[i].id = i;
		i++;
	}
	data->philoarr = malloc(sizeof(t_philo) * data->philo_num);
	if (!data->philoarr)
		return (ft_error(3));
	init_philo(data);
	i = 0;
	while ((long)i < data->philo_num)
	{
		printf("Philo number: %d\nFirst fork is %i, second is  %i\n", data->philoarr[i].id, data->philoarr[i].leftfork->id, data->philoarr[i].rightfork->id);
		i++;
	}
	return (0);
}
