/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:03:44 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/22 21:40:05 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philo_num)
	{
		args->philoarr[i].id = i + 1;
		args->philoarr[i].num_eat = 0;
		args->philoarr[i].goal = 0;
		args->philoarr[i].args = args;
		args->philoarr[i].leftfork;
		args->philoarr[i].rightfork;
		i++;
	}
}

int	init_data(t_args *args)
{
	int	i;

	i = 0;
	args->finish = -1;
	args->philoarr = malloc(sizeof(t_philo) * args->philo_num);
	if (!args->philoarr)
		return (ft_error(3));
	args->forks = malloc(sizeof(t_fork) * args->philo_num);
	if (!args->forks)
		return (ft_error(3));
	while (i < args->philo_num)
	{
		mutex_handler(&args->forks[i].fork, INIT);
		args->forks[i].id = i;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc < 5 || argc > 6)
		return (ft_error(0));
	checker_philo(argc, argv, &args);
	init_data(argv);
	return (0);
}
