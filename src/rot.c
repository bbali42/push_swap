/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:16:01 by bbali             #+#    #+#             */
/*   Updated: 2022/07/01 20:16:01 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rot(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_stacksize(*stack) < 2)
		return (0);
	head = *stack;
	tail = ft_stacklast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (1);
}

int	ra(t_stack **a, t_ops **ops)
{
	if (!rot(a) || !add_ops(ops, "ra"))
		return (0);
	return (1);
}

int	rb(t_stack **b, t_ops **ops)
{
	if (!rot(b) || !add_ops(ops, "rb"))
		return (0);
	return (1);
}

int	rr(t_stack **a, t_stack **b, t_ops **ops)
{
	if (!rot(a) || !rot(b) || !add_ops(ops, "rb"))
		return (0);
	return (1);
}
