/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:03:18 by bbali             #+#    #+#             */
/*   Updated: 2022/07/01 21:03:18 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	switch_case_3(t_stack **a)
{
	t_stack	*head;
	int		min;
	int		next_min;

	head = *a;
	min = get_min(a, -1);
	next_min = get_min(a, min);
	if (is_sorted(a))
		return (1);
	if (head->index == min && head->next->index != next_min)
		return (-1);
	else if (head->index == next_min && head->next->index == min)
		return (-2);
	else if (head->index == next_min)
		return (-3);
	else if (head->next->index == min)
		return (-4);
	return (-5);
}

static int	sort_3(t_stack **a, t_ops **ops)
{
	if (switch_case_3(a) == -1)
		if (!sa(a, ops) || !ra(a, ops))
			return (0);
	if (switch_case_3(a) == -2)
		if (!sa(a, ops))
			return (0);
	if (switch_case_3(a) == -3)
		if (!rra(a, ops))
			return (0);
	if (switch_case_3(a) == -4)
		if (!ra(a, ops))
			return (0);
	if (switch_case_3(a) == -5)
		if (!sa(a, ops) || !rra(a, ops))
			return (0);
	return (1);
}

static int	sort_4(t_stack **a, t_stack **b, t_ops **ops)
{
	int	distance;

	if (is_sorted(a))
		return (1);
	distance = get_distance(a, get_min(a, -1));
	if (distance == 1)
		if (!ra(a, ops))
			return (0);
	if (distance == 2)
		if (!ra(a, ops) || !ra(a, ops))
			return (0);
	if (distance == 3)
		if (!rra(a, ops))
			return (0);
	if (is_sorted(a))
		return (1);
	if (!pb(a, b, ops))
		return (0);
	if (!sort_3(a, ops))
		return (0);
	if (!pa(a, b, ops))
		return (0);
	return (1);
}

static int	sort_5(t_stack **a, t_stack **b, t_ops **ops)
{
	int	distance;

	distance = get_distance(a, get_min(a, -1));
	if (distance == 1)
		if (!ra(a, ops))
			return (0);
	if (distance == 2)
		if (!ra(a, ops) || !ra(a, ops))
			return (0);
	if (distance == 3)
		if (!rra(a, ops) || !rra(a, ops))
			return (0);
	if (distance == 4)
		if (!rra(a, ops))
			return (0);
	if (is_sorted(a))
		return (1);
	if (!pb(a, b, ops))
		return (0);
	if (!sort_4(a, b, ops))
		return (0);
	if (!pa(a, b, ops))
		return (0);
	return (1);
}

int	small_sort(t_stack **a, t_stack **b, t_ops **ops)
{
	int	size;

	size = ft_stacksize(*a);
	if (size == 2)
		if (!sa(a, ops))
			return (0);
	if (size == 3)
		if (!sort_3(a, ops))
			return (0);
	if (size == 4)
		if (!sort_4(a, b, ops))
			return (0);
	if (size == 5)
		if (!sort_5(a, b, ops))
			return (0);
	return (1);
}
