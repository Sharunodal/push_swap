/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:33:05 by arissane          #+#    #+#             */
/*   Updated: 2024/07/21 11:57:08 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **dst, t_node **src)
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

void	pa(t_node **a, t_node **b)
{
	if (*b != NULL)
	{
		push(a, b);
		ft_putendl_fd("pa", 1);
	}
}

void	pb(t_node **a, t_node **b)
{
	if (*a != NULL)
	{
		push(b, a);
		ft_putendl_fd("pb", 1);
	}
}

int	mock_push(t_node **trgt, t_node **src, int check)
{
	if (check == 1)
		push(trgt, src);
	if (check == 2)
		push(src, trgt);
	return (1);
}
