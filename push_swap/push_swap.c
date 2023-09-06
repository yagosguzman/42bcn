/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:55:33 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/06 19:00:32 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*FUNCIONES DEL PUSH SWAP*/
//Swap

//Push

//Rotate

//Reverse rotate

// int main (void)
// {
// 	char *str = "999a9";

// 	printf("%i", ft_atoi(str));
// 	return (0);
// }

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		if (s1[i] != s2[i])
			return (1);
	}
	return (0);
}

int	ft_isdigit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		else
			*str++;
	}
	return (0);
}

int main(int argc. char *argv[])
{
	Node* list_a = malloc(sizeof(Node));
	if (!list_a)
		return(NULL);
	list_a->content = ft_atoi(number);
	list_a.next = malloc(sizeof(Node));
	list_a.next->content = ft_atoi(number++);
	list_a.next->next = NULL;

	free(list_a.next);
	return (0);
}

int	check_valid(char **list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= ft_strlen(list))
	{
		if (ft_isdigit(list[i]) == 1)
			return (1);
		else
			i++;
	}
	i = 0;
	while (j <= ft_strlen(list)) // < o <=??
	{
		while (i <= ft_strlen(list))
		{
			if (ft_strcmp(list[i], list[i + j]) == 1)
				i++;
			else
				return (1);
	}
	i = 0;
	j++;
	}
	return (0);
}

t_node	*extract_argv(char *argv[])
{
	char	**list;
	int		i;
	int		*int_list;

	i = 0;
	list = ft_split(argv[1], " ");
	if (ft_checkvalid(list) == 1) // comprobamos que ningun num se repita y comprobemos que todos son nums
		return (ft_free(list));
	int_list = (int *)malloc((ft_strlen(*list) + 1) * sizeof(int));
	if (!int_list)
		return(ft_free(list));
	while (*list[i])
	{
		int_list[i] = int_ft_atoiextra(*list[i]);
		i++;
	}
	ft_free(list);
	if ()
	//acordarse de liberar split una vez tenemos todo en listas
}

// tenemos que liberar la memoria desde atras hacia delante.
int	push_swap(int argc, char **argv)
{
	char **list_a;
	if (!argc || argc == 1)
		return (NULL);
	if (argc == 2)
		*list_a = extract_argv(argv[1]);

}