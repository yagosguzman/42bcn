/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:27:37 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/05 00:16:07 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*extract_argv(int argc, char **argv)
{
	t_node	*list_a;
	int		i;

	list_a = NULL;
	if (argc == 1)
		return (list_a);
	i = 1;
	while (argc > 1)
	{
		list_a = insert_end(list_a, ft_atoi(argv[i]));
		if (ft_atoi(argv[i]) == 0)
			if (ft_zerocmp(argv[i]) == 1)
				return (free_listnode(list_a));
		argc--;
		i++;
	}
	if (ft_checkrepeat(list_a) == 1)
		return (free_listnode(list_a));
	return (list_a);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if ((str[i] == '-' && ft_isdigitplus(&str[i + 1]) == 0)
		|| (str[i] == '+' && ft_isdigitplus(&str[i + 1]) == 0))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + ((str[i] - 48) * sign);
		i++;
	}
	if (result < -2147483648 || result > 2147483647)
		return (0);
	return (result);
}

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}
