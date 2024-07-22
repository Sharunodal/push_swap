/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:00:02 by arissane          #+#    #+#             */
/*   Updated: 2024/07/19 09:32:50 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push(t_node **dst, t_node **src)
{
	t_node	*temp_dst;
	t_node	*temp_src;
	t_node	*temp;

	if (*src == NULL)
		return ;
	temp_src = *src;
	temp_dst = *dst;
	temp = temp_src;
	temp_src = temp_src->next;
	*src = temp_src;
	if (*dst == NULL)
	{
		temp_dst = temp;
		temp_dst->next = NULL;
		*dst = temp_dst;
	}
	else
	{
		temp->next = temp_dst;
		*dst = temp;
	}
}

void	swap(t_node **stack)
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

void	rotate(t_node **stack)
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

void	rev_rotate(t_node **stack)
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
