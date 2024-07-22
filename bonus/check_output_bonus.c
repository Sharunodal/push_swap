/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_output_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:32:07 by arissane          #+#    #+#             */
/*   Updated: 2024/07/19 10:13:58 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	check_swap(t_node **a, t_node **b, char *str)
{
	if (ft_strncmp(str, "sa\n", 4) == 0)
	{
		swap(a);
		return (0);
	}
	if (ft_strncmp(str, "sb\n", 4) == 0)
	{
		swap(b);
		return (0);
	}
	if (ft_strncmp(str, "ss\n", 4) == 0)
	{
		swap(a);
		swap(b);
		return (0);
	}
	return (-1);
}

static int	check_push(t_node **a, t_node **b, char *str, int check)
{
	if (ft_strncmp(str, "pa\n", 4) == 0)
	{
		push(a, b);
		return (0);
	}
	if (ft_strncmp(str, "pb\n", 4) == 0)
	{
		push(b, a);
		return (0);
	}	
	check += check_swap(a, b, str);
	return (check);
}

static int	check_rotate(t_node **a, t_node **b, char *str, int check)
{
	if (ft_strncmp(str, "ra\n", 4) == 0)
	{
		rotate(a);
		return (0);
	}
	if (ft_strncmp(str, "rb\n", 4) == 0)
	{
		rotate(b);
		return (0);
	}
	if (ft_strncmp(str, "rr\n", 4) == 0)
	{
		rotate(a);
		rotate(b);
		return (0);
	}
	check += check_push(a, b, str, check);
	return (check);
}

static int	check_rev_rotate(t_node **a, t_node **b, char *str, int check)
{
	if (ft_strncmp(str, "rra\n", 5) == 0)
	{
		rev_rotate(a);
		return (0);
	}
	if (ft_strncmp(str, "rrb\n", 5) == 0)
	{
		rev_rotate(b);
		return (0);
	}
	if (ft_strncmp(str, "rrr\n", 5) == 0)
	{
		rev_rotate(a);
		rev_rotate(b);
		return (0);
	}
	check += check_rotate(a, b, str, check);
	return (check);
}

void	check_output(t_node *a, t_node *b)
{
	char	*str;
	int		check;

	check = 0;
	str = get_next_line(0);
	while (str != NULL)
	{
		check += check_rev_rotate(&a, &b, str, check);
		free(str);
		str = get_next_line(0);
	}
	if (check != 0)
		ft_putendl_fd("Error\n", 1);
	else if (check_order(a) == 0 && b == NULL)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_list(&a);
	free_list(&b);
}
