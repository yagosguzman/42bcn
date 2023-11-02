/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:49:44 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/26 19:18:20 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

/* VARIANTE 1 : UN STRLEN NORMAL*/
/* VARIANTE 2 : NOS DEVUELVE SI HAY UN \n O NO */
/* VARIANTE 3 : CUANTO FALTA HASTA \n O \0 */
int	ft_strlen_mode(char *str, int mode)
{
	int	i;

	i = 0;
	if (mode == 1 && str[i])
	{
		while (str[i] != '\0')
			i++;
		return (i);
	}
	else if (mode == 2 && str[i])
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
	}
	else if (mode == 3 && str[i])
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		return (i);
	}
	return (0);
}

char	*merge_strings(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = malloc ((ft_strlen_mode(s1, 1) + ft_strlen_mode(s2, 1) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	ft_free_gnl(&s1);
	return (newstr);
}

char	*ft_free_gnl(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
