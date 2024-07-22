/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:48:19 by arissane          #+#    #+#             */
/*   Updated: 2024/07/21 13:20:52 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	repetition(char **argv, long number, size_t i)
{
	i++;
	while (argv[i] != NULL)
	{
		if (ft_atol(argv[i]) == number)
			return (-1);
		i++;
	}
	return (0);
}

static int	is_number(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

static int	find_null(char **argv, size_t null_string)
{
	while (argv[null_string] != NULL)
	{
		if (argv[null_string][0] == '\0')
			break ;
		null_string++;
	}
	return (null_string);
}

int	validate(char **argv)
{
	size_t	i;
	size_t	null_string;
	long	number;

	i = 0;
	null_string = 0;
	while (argv[i] != NULL)
	{
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return (-1);
		if (is_number(argv[i]) == (-1))
			return (-1);
		if (repetition(argv, number, i) == (-1))
			return (-1);
		i++;
	}
	null_string = find_null(argv, null_string);
	if (i > null_string || i == 0)
		return (-1);
	return (1);
}
