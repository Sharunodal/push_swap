/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:36:26 by arissane          #+#    #+#             */
/*   Updated: 2024/07/21 11:53:40 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mock_sort_three(t_node **a, t_node **b, t_node *min, int actions)
{
	t_node	*max;

	max = largest_value(*a);
	while (check_order(*a) != 0)
	{
		if (*a == max && (*a)->next == min)
			actions += mock_rotate(a, b, 1);
		else if ((*a)->next == max && (*a)->next->next == min)
			actions += mock_rev_rotate(a, b, 1);
		else
			actions += mock_swap(a, b, 1);
	}
	return (actions);
}

static int	mock_sort_parts(t_node **a, t_node **b, int actions)
{
	t_node	*max;
	long	dist;

	while (*b != NULL)
	{
		max = largest_value(*b);
		dist = distance(*b, max);
		while (dist > 0 && *b != max)
		{
			if ((*b)->true_pos == max->true_pos - 1)
				actions += mock_push(a, b, 1);
			actions += mock_rotate(a, b, 2);
		}
		while (dist < 0 && *b != max)
		{
			if ((*b)->true_pos == max->true_pos - 1)
				actions += mock_push(a, b, 1);
			actions += mock_rev_rotate(a, b, 2);
		}
		actions += mock_push(a, b, 1);
		if ((*a)->true_pos > (*a)->next->true_pos)
			actions += mock_swap(a, b, 1);
	}
	return (actions);
}

static int	mock_sort_until_3(t_node **a, t_node **b, int len, int actions)
{
	int		i;
	int		half;
	t_node	*min;

	i = stacksize(*a);
	half = len - (i / 2);
	while (i > 3)
	{
		if ((*a)->true_pos > (len - 3))
		{
			if (*b && (*b)->true_pos > half)
				actions += mock_rotate(a, b, 3);
			else
				actions += mock_rotate(a, b, 1);
		}
		else
		{
			actions += mock_push(a, b, 2);
			i--;
		}
	}
	min = smallest_value(*a);
	actions += mock_sort_three(a, b, min, actions);
	return (mock_sort_parts(a, b, actions));
}

int	mock_sort_more(t_node **a, t_node **b, int len, int part)
{
	int	total;
	int	count;
	int	actions;

	total = part;
	count = 0;
	actions = 0;
	while (total < (len - 3))
	{
		while ((*a)->true_pos <= total && count < part)
		{
			actions += mock_push(a, b, 2);
			if (*b && *a && (*b)->true_pos < (total - part / 2)
				&& (*a)->true_pos > total)
				actions += mock_rotate(a, b, 3);
			count++;
		}
		if (count == part)
		{
			total = total + part;
			count = 0;
		}
		actions += mock_rotate(a, b, 1);
	}
	return (mock_sort_until_3(a, b, len, actions));
}
