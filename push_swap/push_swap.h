/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:20:41 by ysanchez          #+#    #+#             */
/*   Updated: 2023/09/22 20:28:16 by ysanchez         ###   ########.fr       */
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

/*LIST CREATION*/
t_node	*extract_argv(int argc, char **argv);
int		ft_atoi(char *str);
int		order_a(t_node *root);
char	**ft_split(char *str, char separator);
int		argcounter(char *str, char separator);
t_node	*ft_lstnew(int value);
t_node	*insert_front(t_node **root, int value);
t_node	*insert_end(t_node *root, int value);
t_node	*insert_after(t_node *node, int value);
t_node	*free_listnode(t_node *root);
int		node_count(t_node *root);
void	free_node(t_node **node);
t_node	*last_node(t_node *root);

/*INSTRUCTIONS/MOVES*/
void	push_a(t_node **first_a, t_node **first_b);
void	push_b(t_node **first_b, t_node **first_a);
void	swap_a(t_node **node);
void	swap_b(t_node **node);
void	swap_ss(t_node **list_a, t_node **list_b);
void	rotate_a(t_node **list_a);
void	rotate_b(t_node **list_b);
void	rotate_r(t_node **list_a, t_node **list_b);
void	rev_rotate_a(t_node **node);
void	rev_rotate_b(t_node **node);
void	rev_rotate_r(t_node **list_a, t_node **list_b);

/*UTILS*/
int		ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
void	print_list(t_node *list_a);

/*ALGORYTHM*/
void	alg_3(t_node **node);
void	alg_4(t_node **list_a, t_node **list_b);

#endif