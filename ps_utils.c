/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:27:35 by arissane          #+#    #+#             */
/*   Updated: 2024/07/21 11:30:22 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	distance(t_node *a, t_node *target)
{
	long	dist_start;
	long	dist_end;

	dist_start = 0;
	dist_end = 0;
	while (a != target)
	{
		dist_start++;
		a = a->next;
	}
	while (a != NULL)
	{
		dist_end++;
		a = a->next;
	}
	if (dist_start > dist_end)
		return (-dist_end);
	return (dist_start);
}

int	check_order(t_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	number;
	long	sign;
	size_t	i;

	number = 0;
	sign = 1;
	i = 0;
	if (str[i] == '\0')
		return ('\0');
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (sign * number);
}

void	free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_list(t_node **stack)
{
	t_node	*temp;

	if (stack == NULL)
		return ;
	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}
