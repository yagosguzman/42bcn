/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:58:46 by ysanchez          #+#    #+#             */
/*   Updated: 2024/04/25 21:27:32 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(t_data *data)
{
	
}

int	init_dining(t_data *data)
{
	if (data->philo_num == 1)
		solo_philo(data);
}
