/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:52:29 by ysanchez          #+#    #+#             */
/*   Updated: 2024/02/26 20:47:46 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (0);
	else
		return (1);
}

void	save_info(int i, long result, t_args *table)
{
	if (i == 1)
		table->philo_num = result;
	else if (i == 2)
		table->time_to_die = result;
	else if (i == 3)
		table->time_to_eat = result;
	else if (i == 4)
		table->time_to_sleep = result;
	else if (i == 5)
		table->max_eat = result;
	else
		return ;
}

int	arg_to_long(int argnum, char *str, t_args *database)
{
	int		i;
	int		j;
	long	result;

	i = 0;
	result = 0;
	while (is_space(str[i]) == 0 && str[i] != '\0')
		i++;
	if (str[i] == '+')
		i++;
	j = i;
	while (str[j])
		j++;
	if ((j - i) > 19)
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	if (result > LONG_MAX || result <= 0)
		return (1);
	else
		save_info(argnum, result, database);
	return (0);
}

int	check_valid_arg(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (is_space(argv[i][j]) == 0)
			j++;
		if (argv[i][j] == '\0' || (argv[i][j] == '+' && argv[i][j + 1] == '\0'))
			return (1);
		if (argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			else
				j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	checker_arg(int argc, char **argv, t_args *database)
{
	int	i;

	i = 1;
	if (argc == 5)
		database->max_eat = -1;
	if (check_valid_arg(argv) == 1)
		return (ft_error(1));
	while (i < argc)
	{
		if (arg_to_long(i, argv[i], database) == 1)
			return (ft_error(2));
		i++;
	}
	return (0);
}
