/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:29:49 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/16 19:19:18 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_args	t_args;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				id;
}	t_fork;

typedef struct s_philo
{
	pthread_t	thread_id;
	int			id;
	int			num_eat;
	int			goal;
	long		last_time_eat;
	t_fork		*leftfork;
	t_fork		*rightfork;
	t_args		*args;
}	t_philo;

struct s_args
{
	int		philo_num;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		max_eat;
	int		start;
	int		finish;
	t_fork	*forks;
	t_philo	*philo;
} ;

int	init_philo(char **argv);
int	checker_philo(int argc, char **argv, t_args *args);
int	check_valid_arg(char **argv);
int	ft_error(int errnum);

#endif