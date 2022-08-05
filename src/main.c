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

static t_stack	**init_stack(t_args **args)
{
	t_stack	**stack;
	t_stack	*new;
	t_args	*head;

	stack = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack)
		return (NULL);
	*stack = NULL;
	head = *args;
	while (head)
	{
		new = ft_stacknew(ft_atoi(head->av));
		if (!new)
		{
			free_stack(stack);
			free_args(args);
			return (NULL);
		}
		ft_stackadd_back(stack, new);
		head = head->next;
	}
	index_stack(stack);
	free_args(args);
	return (stack);
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
	t_args	**args;

	if (ac < 2)
		return (0);
	args = init_args(av);
	if (!args || !check_args(args))
		return (0);
	a = init_stack(args);
	if (!a)
		return (0);
	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	sort_stack(a);
	return (0);
}
