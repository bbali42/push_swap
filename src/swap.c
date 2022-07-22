/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:09:14 by bbali             #+#    #+#             */
/*   Updated: 2022/07/01 20:09:14 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_stacksize(*stack) < 2)
		return (0);
	head = *stack;
	next = head->next;
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (1);
}

int	sa(t_stack **a, t_ops **ops)
{
	if (!swap(a) || !add_ops(ops, "sa"))
		return (0);
	return (1);
}

int	sb(t_stack **b, t_ops **ops)
{
	if (!swap(b) || !add_ops(ops, "sb"))
		return (0);
	return (1);
}

int	ss(t_stack **a, t_stack **b, t_ops **ops)
{	
	if (!swap(a) || !swap(b) || !add_ops(ops, "sb"))
		return (0);
	return (1);
}
