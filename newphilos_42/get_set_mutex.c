/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:32:20 by ysanchez          #+#    #+#             */
/*   Updated: 2024/02/26 20:30:24 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_value(pthread_mutex_t *mutex, long *dst, long value)
{
	mutex_handler(mutex, LOCK);
	*dst = value;
	mutex_handler(mutex, UNLOCK);
}

long	get_value(pthread_mutex_t *mutex, long *src)
{
	long	result;

	mutex_handler(mutex, LOCK);
	result = *src;
	mutex_handler(mutex, UNLOCK);
	return (result);
}
