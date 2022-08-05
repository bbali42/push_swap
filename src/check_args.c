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
#define INT_MIN "2147483648"

static int	check_format(t_args *head)
{
	int		i;
	t_args	*tmp;

	tmp = head;
	while (tmp)
	{
		i = 0;
		if (tmp->av[i] == '-' || tmp->av[i] == '+')
			i++;
		while (tmp->av[i] == '0' && tmp->av[i + 1])
			i++;
		while (tmp->av[i])
		{
			if (!ft_isdigit(tmp->av[i]))
				return (0);
			i++;
		}
		tmp = tmp->next;
	}
	return (1);
}

static int	check_dup(t_args *head)
{
	t_args	*i;
	t_args	*j;

	i = head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (ft_atoi(i->av) == ft_atoi(j->av))
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

static int	check_int_max(t_args **head)
{
	t_args	*tmp;
	char	sign;
	int		i;

	sign = '+';
	i = 0;
	tmp = *head;
	while (tmp)
	{
		if (tmp->av[i] == '-' || tmp->av[i] == '+')
		{
			if (tmp->av[i] == '-')
				sign = '-';
			i++;
		}
		while (tmp->av[i] == '0')
				i++;
		if (sign == '+' && ft_strdigit_cmp(tmp->av, i, INT_MAX) > 0)
			return (0);
		if (sign == '-' && ft_strdigit_cmp(tmp->av, i, INT_MIN) > 0)
			return (0);
		tmp = tmp->next;
		i = 0;
	}
	return (1);
}

int	check_args(t_args **args)
{
	if (!check_format(*args) || !check_int_max(args) || !check_dup(*args))
	{
		free_args(args);
		ft_putendl_fd("Error", STDERR_FILENO);
		return (0);
	}
	if (ft_args_size(*args) < 2)
	{
		free_args(args);
		return (0);
	}
	return (1);
}
