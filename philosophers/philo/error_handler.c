/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:26:26 by ysanchez          #+#    #+#             */
/*   Updated: 2023/11/16 18:56:07 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(int errnum)
{
	if (errnum == 0)
		printf ("Error\nIncorrect number of arguments.\nPlease write ./philo "
			"[1][2][3][4][*5]\n1.number_of_philosophers\n2.time_to_die(in ms)\n"
			"3.time_to_eat(in ms)\n4.time_to_sleep (in ms)\n(*Optional)\n5."
			"number_of_times_each_philosopher_must_eat\n");
	if (errnum == 1)
		printf("Error\nFound unexpected characters in the arguments.\n");
	if (errnum == 2)
		printf("Error\nYou can only use unsigned integers as arguments.\n");
	return (1);
}
