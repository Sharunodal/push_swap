/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:44:21 by arissane          #+#    #+#             */
/*   Updated: 2024/07/21 11:57:44 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (stacksize(*stack) < 2)
		return ;
	first = *stack;
	last = end_node(*stack);
	while (first->next->next != NULL)
		first = first->next;
	first->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_node **a)
{
	if (stacksize(*a) > 1)
	{
		rev_rotate(a);
		ft_putendl_fd("rra", 1);
	}
}

void	rrb(t_node **b)
{
	if (stacksize(*b) > 1)
	{
		rev_rotate(b);
		ft_putendl_fd("rrb", 1);
	}
}

void	rrr(t_node **a, t_node **b)
{
	if (stacksize(*a) > 1 && stacksize(*b) > 1)
	{
		rev_rotate(a);
		rev_rotate(b);
		ft_putendl_fd("rrr", 1);
	}
}

int	mock_rev_rotate(t_node **a, t_node **b, int check)
{
	if (check == 1)
		rev_rotate(a);
	if (check == 2)
		rev_rotate(b);
	if (check == 3)
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	return (1);
}
