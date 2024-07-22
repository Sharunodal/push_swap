/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:20:37 by arissane          #+#    #+#             */
/*   Updated: 2024/07/21 11:39:06 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	set_true_position(t_node *node, int len, int i)
{
	t_node	*tracker;
	t_node	*temp;
	long	max;
	long	min;

	min = LONG_MIN;
	while (len > 0)
	{
		max = LONG_MAX;
		tracker = node;
		while (tracker != NULL)
		{
			if (tracker->value < max && tracker->value > min)
			{
				max = tracker->value;
				temp = tracker;
			}
			tracker = tracker->next;
		}
		min = temp->value;
		temp->true_pos = i;
		i++;
		len--;
	}
}

static void	create_stack(t_node **a, int argc, char **argv)
{
	size_t	i;
	long	number;

	i = 0;
	while (argv[i] != NULL)
	{
		number = ft_atol(argv[i]);
		new_node(a, number);
		i++;
	}
	if (argc == 2)
		free_array(argv);
}

static char	**check_args(int argc, char **argv)
{
	int	check;

	check = 1;
	if (argc < 2)
		exit (0);
	if (argv[1] != NULL)
	{
		if (argc == 2)
			argv = ft_split(argv[1], ' ');
		else
			argv = (&argv[1]);
		check = validate(argv);
	}
	if (check == -1)
	{
		if (argc == 2)
			free_array(argv);
		write(1, "Error\n", 7);
		exit (0);
	}
	return (argv);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		len;

	a = NULL;
	b = NULL;
	argv = check_args(argc, argv);
	create_stack(&a, argc, argv);
	len = stacksize(a);
	set_true_position(a, len, 1);
	check_output(a, b);
	return (0);
}
