/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:12:58 by ysanchez          #+#    #+#             */
/*   Updated: 2024/03/07 21:17:24 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	aux_begin(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && set[j])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static int	aux_end(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1);
	j = 0;
	while (i >= 1 && set[j])
	{
		if (s1[i - 1] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		i;
	int		j;
	int		k;

	if (!s1 || !set)
		return (NULL);
	i = aux_begin(s1, set);
	if (i == (int)ft_strlen(s1))
		return (ft_strdup(""));
	j = aux_end(s1, set);
	k = 0;
	newstr = malloc ((j - i + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while ((j - i) >= 1)
	{
		newstr[k] = s1[i];
		k++;
		i++;
	}
	newstr[k] = '\0';
	return (newstr);
}
/* int	main (void)
{
	char	*s1 = "  \t \t \n   \n\n\n\t";
    char	*s2 = "";
	printf("%s", ft_strtrim(s1, s2));
	return(0);
} */