/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:17:30 by bbali             #+#    #+#             */
/*   Updated: 2022/07/01 20:17:30 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	revrot(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_stacksize(*stack) < 2)
		return (0);
	head = *stack;
	tail = ft_stacklast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (1);
}

int	rra(t_stack **a, t_ops **ops)
{
	if (!revrot(a) || !add_ops(ops, "rra"))
		return (0);
	return (1);
}

int	rrb(t_stack **b, t_ops **ops)
{
	if (!revrot(b) || !add_ops(ops, "rrb"))
		return (0);
	return (1);
}

int	rrr(t_stack **a, t_stack **b, t_ops **ops)
{
	if (!revrot(a) || !revrot(b) || !add_ops(ops, "rrr"))
		return (0);
	return (1);
}
