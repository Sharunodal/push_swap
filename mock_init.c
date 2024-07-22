/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:53:29 by arissane          #+#    #+#             */
/*   Updated: 2024/07/19 16:32:00 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_stack(t_node **a, t_node **temp_a)
{
	t_node	*temp;

	temp = *a;
	while (temp != NULL)
	{
		new_node(temp_a, temp->value, temp->true_pos);
		temp = temp->next;
	}
}

static int	limit_size(int len)
{
	int	limit;

	if (len < 101)
		limit = 51;
	else
		limit = 151;
	return (limit);
}

static int	part_size(int len)
{
	int	part;

	if (len < 101)
		part = 5;
	else
		part = 50;
	return (part);
}

int	mock_sort(t_node **a, int len, int part, int actions)
{
	t_node	*temp_a;
	t_node	*temp_b;
	int		max;
	int		limit;
	int		final;

	temp_a = NULL;
	temp_b = NULL;
	max = INT_MAX;
	part = part_size(len);
	limit = limit_size(len);
	while (part < limit)
	{
		copy_stack(a, &temp_a);
		actions = mock_sort_more(&temp_a, &temp_b, len, part);
		if (actions < max)
		{
			max = actions;
			final = part;
		}
		part++;
		free_list(&temp_a);
		free_list(&temp_b);
	}
	return (final);
}
