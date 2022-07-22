/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 01:37:46 by bbali             #+#    #+#             */
/*   Updated: 2022/06/25 01:37:46 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack **stack, char **av)
{
	t_stack	*new;
	int		i;

	i = 1;
	while (av[i])
	{
		new = ft_stacknew(ft_atoi(av[i]));
		ft_stackadd_back(stack, new);
		i++;
	}
	index_stack(stack);
}

static void	sort_stack(t_stack **a)
{
	t_stack	**b;
	t_ops	**ops;

	b = (t_stack **)malloc(sizeof(t_stack *));
	if (!b)
	{
		free_stack(a);
		return ;
	}
	ops = (t_ops **)malloc(sizeof(t_ops *));
	if (!ops)
	{
		free_stack(a);
		free_stack(b);
		return ;
	}
	*b = NULL;
	*ops = NULL;
	if (ft_stacksize(*a) <= 5)
		if (!small_sort(a, b, ops))
			ft_error(a, b, ops);
	if (ft_stacksize(*a) > 5)
		if (!radix_sort(a, b, ops))
			ft_error(a, b, ops);
	end_prg(a, b, ops);
}

int	main(int ac, char **av)
{
	t_stack	**a;

	if (!check_args(ac, av))
		return (0);
	a = (t_stack **)malloc(sizeof(t_stack *));
	init_stack(a, av);
	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	sort_stack(a);
	return (0);
}
