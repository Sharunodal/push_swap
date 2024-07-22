/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:07:59 by arissane          #+#    #+#             */
/*   Updated: 2024/07/21 11:56:54 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (stacksize(*stack) < 2)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_node **a)
{
	if (stacksize(*a) > 1)
	{
		swap(a);
		ft_putendl_fd("sa", 1);
	}
}

void	sb(t_node **b)
{
	if (stacksize(*b) > 1)
	{
		swap(b);
		ft_putendl_fd("sb", 1);
	}
}

void	ss(t_node **a, t_node **b)
{
	if (stacksize(*b) > 1 && stacksize(*b) > 1)
	{
		swap(a);
		swap(b);
		ft_putendl_fd("ss", 1);
	}
}

int	mock_swap(t_node **a, t_node **b, int check)
{
	if (check == 1)
		swap(a);
	if (check == 2)
		swap(b);
	return (1);
}
