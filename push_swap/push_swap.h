/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:20:41 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/06 19:44:55 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct t_node
{
	int				content;
	struct t_node	*next;
}	t_node;

int		push_swap(int argc, char **argv);
t_node	*extract_argv(char *argv[]);
int		check_valid(char **list);
char	**ft_split(char const *str, char separator);
int		ft_atoiextra(char *str, int *int_list);
void	insert_front(t_node **root, int value);
void	insert_end(t_node **root, int value);
void	insert_after(t_node *node, int value);
void	free_listnode(t_node **root);
int		node_count(t_node *root);

#endif