/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:58:10 by ysanchez          #+#    #+#             */
/*   Updated: 2023/10/03 19:14:21 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*return_best(t_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node != NULL)
	{
		if (node->best == true)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	move_node(t_node **list_a, t_node **list_b)
{
	t_node	*best;

	best = return_best(*list_b);
	if (best->first_half == true && best->target->first_half == true)
		rotate_both(list_a, list_b, best);
	else if (best->first_half == false && best->target->first_half == false)
		rev_rotate_both(list_a, list_b, best);
	place_on_top(list_b, best, 'b');
	place_on_top(list_a, best->target, 'a');
	push_a(list_a, list_b);
}

void	index_assign(t_node *list_a)
{
	int	*index;
	int	i;
	t_node *head;

	index = malloc(sizeof(int) * node_count(list_a));
	i = 0;
	head = list_a;
	while (list_a != NULL)
	{
		index[i++] = list_a->content;
		list_a = list_a->next;
	}
	index[i] = '\0';
	index = bubbleSort(index, (i - 1));
	i = 0;
	list_a = head;
	while (index[i])
	{
		if (list_a->content == index[i])
		{
			list_a->index = i;
			i++;
			list_a = head;
		}
		list_a = list_a->next;
	}
	list_a = head;
	print_list(list_a);
}

// int	*sorting_array(int *arr, int size)
// {
// 	int	i;
// 	int min;
// 	int j;

// 	i = 0;
// 	while (i < (size - 1))
// 	{
// 		min = i;
// 		j = i + 1;
// 		while (j < size)
// 		{	if (arr[j] < arr[min])
// 				min = j;
// 			j++;
// 		}
// 		if (min != i)
// 		{
// 			arr[i] = arr[i] + arr[min];
// 			arr[min] = arr[min] - arr[i];
// 			arr[i] = arr[i] - arr[min];
// 		}
// 		i++;
// 	}
// 	return (arr);
// }

int *bubbleSort(int *arr, int size)
{
    int i;
    int j;
    int swapped;

	i = 0;
	swapped = 1;
    while (i < size - 1 && swapped) 
	{
        swapped = 0;
        j = 0;
        while (j < size - i - 1)
		{
            if (arr[j] > arr[j + 1])
			{
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
                swapped = 1;
            }
            j++;
        }
        i++;
    }
	return (arr);
}
