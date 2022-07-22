/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:19:55 by bbali             #+#    #+#             */
/*   Updated: 2022/07/01 20:19:55 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*tmp;
	t_stack	*head_to;
	t_stack	*head_from;

	if (ft_stacksize(*stack_from) == 0)
		return (0);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (1);
}

int	pa(t_stack **a, t_stack **b, t_ops **ops)
{
	if (!push(a, b) || !add_ops(ops, "pa"))
		return (0);
	return (1);
}

int	pb(t_stack **a, t_stack **b, t_ops **ops)
{
	if (!push(b, a) || !add_ops(ops, "pb"))
		return (0);
	return (1);
}
