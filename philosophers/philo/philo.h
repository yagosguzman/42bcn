/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:29:49 by ysanchez          #+#    #+#             */
/*   Updated: 2023/12/10 20:20:39 by ysanchez         ###   ########.fr       */
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

typedef enum e_thread
{
	CREATE,
	JOIN,
	DETACH
}	t_thread;

typedef enum e_mutex
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY
}	t_mutex;

typedef enum e_time
{
	SECONDS,
	MILLISECONDS,
	MICROSECONDS
}	t_time;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TOOK_1ST_FORK,
	TOOK_2ND_FORK,
	DIED
}	t_status;

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
	int			last_time_eat;
	t_fork		*firstfork;
	t_fork		*secondfork;
	t_args		*args;
}	t_philo;

struct s_args
{
	long			philo_num;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			max_eat;
	long			start;
	long			ready;
	long			finish;
	pthread_mutex_t	args_mutex;
	pthread_mutex_t	write_mutex;
	t_fork			*forks;
	t_philo			*philoarr;
} ; 

/*CHECKER + DATA INIT*/
int		checker_philo(int argc, char **argv, t_args *args);
int		init_data(t_args *args);
void	init_philo(t_args *args);
void	init_forks(t_philo *philo, int pos, t_fork *forks);
int		init_dining(t_args *args);
void	solo_philo(t_philo *philo);


/*UTILS*/
int		mutex_handler(pthread_mutex_t *mutex, t_mutex operation);
int		thread_handler(pthread_t *thread, void *(*foo)(void *),
			void *data, t_thread operation);
void	set_long(pthread_mutex_t *mutex, long *dst, long value);
long	get_int(pthread_mutex_t *mutex, long *src);
int		simulation_finished(t_args *args);


/*SYNC UTILS*/
void	sync_threads(t_args *args);
long	gettime(t_time time_unit);


/*ERROR HANDLER*/
int		ft_error(int errnum);
int		ft_mutex_error(int errnum);
int		ft_thread_error(int errnum);

#endif