/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:29:49 by ysanchez          #+#    #+#             */
/*   Updated: 2023/12/01 17:54:54 by ysanchez         ###   ########.fr       */
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

# define INIT 0
# define LOCK 1
# define UNLOCK 2
# define DESTROY 3
# define CREATE 4
# define JOIN 5
# define DETACH 6

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
	t_fork		*firstfork;
	t_fork		*secondfork;
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
	t_philo	*philoarr;
} ; 

/*CHECKER + DATA INIT*/
int		checker_philo(int argc, char **argv, t_args *args);
int		init_data(t_args *args);
void	init_philo(t_args *args);
void	init_forks(t_philo *philo, int pos, t_fork *forks);

/*UTILS*/
int		mutex_handler(pthread_mutex_t *mutex, int operation);
int		thread_handler(pthread_t *thread, void *(*foo)(void *),
			void *data, int operation);

/*ERROR HANDLER*/
int		ft_error(int errnum);
int		ft_mutex_error(int errnum);
int		ft_thread_error(int errnum);

#endif