/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 04:14:50 by bbali             #+#    #+#             */
/*   Updated: 2022/06/30 04:14:50 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	get_distance(t_stack **stack, int index)
{
	t_stack	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

int	get_min(t_stack **stack, int val)
{
	t_stack	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

void	make_top(t_stack **stack, int distance, t_ops **ops)
{
	t_stack	*head;
	int		tmp;

	if (distance == 0)
		return ;
	head = *stack;
	tmp = ft_stacksize(head) - distance;
	if (distance <= (ft_stacksize(head) / 2))
	{
		while (distance-- > 0)
			ra(stack, ops);
	}
	else
	{
		while (tmp-- > 0)
			rra(stack, ops);
	}
}
