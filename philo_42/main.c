/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:03:44 by ysanchez          #+#    #+#             */
/*   Updated: 2024/02/23 18:08:38 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	data;

	if (argc < 5 || argc > 6)
		return (ft_error(0));
	if (checker_philo(argc, argv, &data) != 0)
		return (1);
	if (init_data(&data) != 0)
	{
		clean_sim(&data);
		return (1);
	}
	if (init_dining(&data) != 0)
	{
		clean_sim(&data);
		return (1);
	}
	clean_sim(&data);
	printf("Dining finished.\n");
	return (0);
}
