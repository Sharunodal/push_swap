/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:35:02 by arissane          #+#    #+#             */
/*   Updated: 2024/07/21 11:57:23 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (stacksize(*stack) < 2)
		return ;
	first = *stack;
	last = end_node(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_node **a)
{
	if (stacksize(*a) > 1)
	{
		rotate(a);
		ft_putendl_fd("ra", 1);
	}
}

void	rb(t_node **b)
{
	if (stacksize(*b) > 1)
	{
		rotate(b);
		ft_putendl_fd("rb", 1);
	}
}

void	rr(t_node **a, t_node **b)
{
	if (stacksize(*a) > 1 && stacksize(*b) > 1)
	{
		rotate(a);
		rotate(b);
		ft_putendl_fd("rr", 1);
	}
}

int	mock_rotate(t_node **a, t_node **b, int check)
{
	if (check == 1)
		rotate(a);
	if (check == 2)
		rotate(b);
	if (check == 3)
	{
		rotate(a);
		rotate(b);
	}
	return (1);
}
