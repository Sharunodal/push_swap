/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:37:39 by arissane          #+#    #+#             */
/*   Updated: 2024/07/21 12:25:11 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	struct s_node	*next;
	int				value;
	int				true_pos;
}	t_node;

t_node	*end_node(t_node *a);
t_node	*smallest_value(t_node *node);
t_node	*largest_value(t_node *node);
int		validate(char **str);
int		stacksize(t_node *node);
int		check_order(t_node *stack);;
long	ft_atol(const char *str);
void	new_node(t_node **a, int nb, int pos);
long	distance(t_node *a, t_node *target);
void	free_array(char **array);
void	free_list(t_node **stack);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	sort(t_node **a, t_node **b, int len);
int		mock_push(t_node **trgt, t_node **src, int check);
int		mock_swap(t_node **a, t_node **b, int check);
int		mock_rotate(t_node **a, t_node **b, int check);
int		mock_rev_rotate(t_node **a, t_node **b, int check);
int		mock_sort(t_node **a, int len, int part, int actions);
int		mock_sort_more(t_node **a, t_node **b, int len, int part);

#endif
