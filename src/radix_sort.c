/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 04:13:34 by bbali             #+#    #+#             */
/*   Updated: 2022/06/30 04:13:34 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while (max >> max_bits)
		max_bits++;
	return (max_bits);
}

static int	pa_all(t_stack **a, t_stack **b, t_ops **ops)
{
	while (ft_stacksize(*b))
		if (!pa(a, b, ops))
			return (0);
	return (1);
}

int	radix_sort(t_stack **a, t_stack **b, t_ops **ops)
{
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;

	i = -1;
	size = ft_stacksize(*a);
	while (++i < get_max_bits(a))
	{
		j = -1;
		while (++j < size)
		{
			head_a = *a;
			if (((head_a->index >> i) & 1))
			{
				if (!ra(a, ops))
					return (0);
			}
			else if (!pb(a, b, ops))
				return (0);
		}
		if (!pa_all(a, b, ops))
			return (0);
	}
}
