/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:58:46 by ysanchez          #+#    #+#             */
/*   Updated: 2024/04/24 16:07:23 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_dining(t_data *data)
{
	int	i;

	i = 0;
	if (data->philo_num == 1)
		solo_philo(data);
	while (i <= data->philo_num)
	{
		thread_handler(&data->philoarr[i], 
	}
}
