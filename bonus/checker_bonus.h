/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:14:13 by arissane          #+#    #+#             */
/*   Updated: 2024/07/21 11:40:47 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"

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
void	new_node(t_node **a, int nb);
long	distance(t_node *a, t_node *target);
void	free_array(char **array);
void	free_list(t_node **stack);
void	swap(t_node **stack);
void	push(t_node **dst, t_node **src);
void	rotate(t_node **stack);
void	rev_rotate(t_node **stack);
void	check_output(t_node *a, t_node *b);

#endif
