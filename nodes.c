/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:30:54 by arissane          #+#    #+#             */
/*   Updated: 2024/07/19 13:50:09 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*end_node(t_node *a)
{
	t_node	*temp;

	if (a == NULL)
		return (NULL);
	temp = a;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

t_node	*smallest_value(t_node *node)
{
	long	max;
	t_node	*temp;

	if (node == NULL)
		return (NULL);
	max = LONG_MAX;
	while (node != NULL)
	{
		if (node->value < max)
		{
			max = node->value;
			temp = node;
		}
		node = node->next;
	}
	return (temp);
}

t_node	*largest_value(t_node *node)
{
	long	min;
	t_node	*temp;

	if (node == NULL)
		return (NULL);
	min = LONG_MIN;
	while (node != NULL)
	{
		if (node->value > min)
		{
			min = node->value;
			temp = node;
		}
		node = node->next;
	}
	return (temp);
}

int	stacksize(t_node *node)
{
	size_t	i;

	i = 0;
	while (node != NULL)
	{
		node = node->next;
		i++;
	}
	return (i);
}

void	new_node(t_node **a, int nb, int pos)
{
	t_node	*new;
	t_node	*last;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = nb;
	new->true_pos = pos;
	new->next = NULL;
	if (*a == NULL)
		*a = new;
	else
	{
		last = end_node(*a);
		last->next = new;
	}
}
