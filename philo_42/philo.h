/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:29:49 by ysanchez          #+#    #+#             */
/*   Updated: 2024/04/24 19:57:31 by ysanchez         ###   ########.fr       */
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
	MILLISEC,
	MICROSEC
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
	pthread_t		thread_id;
	int				id;
	long			num_eat;
	long			goal;
	long			last_time_eat;
	t_args			*args;
	pthread_mutex_t	philo_mutex;
	t_fork			*leftfork;
	t_fork			*rightfork;
}	t_philo;

struct s_args
{
	long			philo_num;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			max_eat;
	long			finish;
	long			ready;
	long			running;
	long			start;
	pthread_mutex_t	args_mutex;
	pthread_mutex_t	write_mutex;
	t_fork			*forks;
	t_philo			*philoarr;
	pthread_t		checker;
} ;

/*########## check_arg.c ##########*/
int		check_valid_arg(char **argv);
void	save_info(int i, long result, t_args *args);
int		arg_to_long(int argnum, char *str, t_args *database);
int		checker_philo(int argc, char **argv, t_args *args);

/*########## data_init.c ##########*/
void	init_forks(t_philo *philo, int pos, t_fork *forks);
void	init_philo(t_args *args);
int		init_data(t_args *args);

/*########## utils.c ##########*/
int		mutex_handler(pthread_mutex_t *mutex, t_mutex operation);
int		thread_handler(pthread_t *thread, void *(*foo)(void *),
			void *data, t_thread operation);
void	clean_sim(t_args *args);

/*########## dead_check.c ##########*/
int		philo_dead(t_philo *philo);
void	*dead_check(void *data);

/*########## get_set_mutex.c ##########*/
void	set_value(pthread_mutex_t *mutex, long *dst, long value);
long	get_value(pthread_mutex_t *mutex, long *src);
int		simulation_finished(t_args *args);

/*########## sync_utils.c ##########*/
void	sync_threads(t_args *args);
long	gettime(t_time time_unit);
void	precise_usleep(long usec, t_args *args);
int		all_running(pthread_mutex_t *mutex, long *running,
			long philo_num);
void	fairness_solution(t_philo *philo);

/*########## error_handler.c ##########*/
int		ft_error(int errnum);
int		ft_mutex_error(int errnum);
int		ft_thread_error(int errnum);

/*########## instructions.c ##########*/
void	write_status(t_status status, t_philo *philo);
void	ft_eating(t_philo *philo);
void	ft_sleeping(t_philo *philo);
void	ft_thinking(t_philo *philo);

/*########## dining.c ##########*/
void	*dining_sim(void *data);
void	*solo_philo(void *args);
int		init_dining(t_args *args);

#endif
