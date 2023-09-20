/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:20:41 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/20 18:05:51 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // BORRAR

typedef struct t_node
{
	int				content;
	struct t_node	*next;
}	t_node;

int		push_swap(int argc, char **argv);

/*CHECKERS*/
int		ft_checkrepeat(t_node *list);
int		ft_checkvalid(char **argv);
int		ft_isdigitplus(char *str);
int		ft_zerocmp(char *s1);
int		ft_check_double(t_node *list_a);

/*LIST CREATION*/
t_node	*extract_argv(int argc, char **argv);
int		ft_atoi(char *str);
int		order_a(t_node *root);
char	**ft_split(char *str, char separator);
int		argcounter(char *str, char separator);
t_node	*ft_lstnew(int value);
t_node	*insert_front(t_node *root, int value);
t_node	*insert_end(t_node *root, int value);
t_node	*insert_after(t_node *node, int value);
t_node	*free_listnode(t_node *root);
int		node_count(t_node *root);
void	free_node(t_node *node);
t_node	*clone_node(t_node *origin, t_node *destiny);

/*UTILS*/
int		ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);

#endif