/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:25:46 by ysanchez          #+#    #+#             */
/*   Updated: 2024/02/26 21:02:50 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_philo *philo, int pos, t_fork *forks, int philo_num)
{
	if (philo->id % 2 == 0)
	{
		philo->firstfork = &forks[(pos + 1) % philo_num];
		philo->secondfork = &forks[pos];
	}
	else
	{
		philo->firstfork = &forks[pos];
		philo->secondfork = &forks[(pos + 1) % philo_num];
	}
}

void	init_philo(t_args *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < table->philo_num)
	{
		philo = &table->philoarr[i];
		philo->id = i + 1;
		philo->num_eat = 0;
		philo->goal = 0;
		philo->table = table;
		mutex_handler(&philo->philo_mutex, INIT);
		init_forks(philo, i, table->forks, philo->id);
		i++;
	}
}

int	init_data(t_args *table)
{
	int	i;

	i = 0;
	table->finish = -1;
	table->ready = -1;
	table->running = 0;
	table->start = 0;
	mutex_handler(&table->table_mutex, INIT);
	mutex_handler(&table->write_mutex, INIT);
	table->forks = malloc(sizeof(t_fork) * table->philo_num);
	if (!table->forks)
		return (ft_error(3));
	while (i < table->philo_num)
	{
		mutex_handler(&table->forks[i].fork, INIT);
		table->forks[i].id = i;
		i++;
	}
	table->philoarr = malloc(sizeof(t_philo) * table->philo_num);
	if (!table->philoarr)
		return (ft_error(3));
	init_philo(table);
	return (0);
}
