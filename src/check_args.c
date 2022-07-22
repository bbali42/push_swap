/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:10:55 by bbali             #+#    #+#             */
/*   Updated: 2022/07/02 19:10:55 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define INT_MAX "2147483647"
#define INT_MIN "-2147483648"

static int	is_num(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

static int	check_format(char **args)
{
	int		i;
	int		j;

	i = 1;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		while (args[i][j])
		{
			if (!is_num(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_dup(char **args)
{
	int		i;
	int		j;

	i = 1;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (!ft_strcmp(args[i], args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_int_max(char **args)
{
	int		i;

	i = 1;
	while (args[i])
	{
		if (ft_strlen(args[i]) == ft_strlen(INT_MAX))
		{
			if (ft_strcmp(args[i], INT_MAX) > 0)
				return (0);
		}
		else if (ft_strlen(args[i]) > ft_strlen(INT_MAX))
			return (0);
		if (ft_strlen(args[i]) == ft_strlen(INT_MIN))
		{
			if (ft_strcmp(args[i], INT_MIN) > 0)
				return (0);
		}
		else if (ft_strlen(args[i]) > ft_strlen(INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int ac, char **args)
{
	if (!check_format(args) || !check_dup(args) || !check_int_max(args))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (0);
	}
	if (ac <= 2)
		return (0);
	return (1);
}
