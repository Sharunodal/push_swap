/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:18:17 by arissane          #+#    #+#             */
/*   Updated: 2024/07/21 12:29:48 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_node **a, t_node *min)
{
	t_node	*max;

	max = largest_value(*a);
	while (check_order(*a) != 0)
	{
		if (*a == max && (*a)->next == min)
			ra(a);
		else if ((*a)->next == max && (*a)->next->next == min)
			rra(a);
		else
			sa(a);
	}
}

static void	sort_parts(t_node **a, t_node **b)
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
				pa(a, b);
			rb(b);
		}
		while (dist < 0 && *b != max)
		{
			if ((*b)->true_pos == max->true_pos - 1)
				pa(a, b);
			rrb(b);
		}
		pa(a, b);
		if ((*a)->true_pos > (*a)->next->true_pos)
			sa(a);
	}
}

static void	sort_until_3(t_node **a, t_node **b, int len)
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
				rr(a, b);
			else
				ra(a);
		}
		else
		{
			pb(a, b);
			i--;
		}
	}
	min = smallest_value(*a);
	sort_three(a, min);
	sort_parts(a, b);
}

static void	sort_more(t_node **a, t_node **b, int len, int part)
{
	int	total;
	int	count;

	total = part;
	count = 0;
	while (total < (len - 3))
	{
		while ((*a)->true_pos <= total && count < part)
		{
			pb(a, b);
			if (*b && (*b)->true_pos < (total - part / 2))
			{
				if (*a && (*a)->true_pos > total)
					rr(a, b);
			}
			count++;
		}
		if (count == part)
		{
			total = total + part;
			count = 0;
		}
		ra(a);
	}
	sort_until_3(a, b, len);
}

void	sort(t_node **a, t_node **b, int len)
{
	t_node	*min;
	int		part;

	part = 0;
	min = smallest_value(*a);
	if (len == 2)
		ra(a);
	if (len == 3)
		sort_three(a, min);
	if (len == 4 || len == 5)
	{
		sort_until_3(a, b, len);
		return ;
	}
	part = mock_sort(a, len, part, 0);
	sort_more(a, b, len, part);
}
