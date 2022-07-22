/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  stack_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 03:05:25 by bbali             #+#    #+#             */
/*   Updated: 2022/06/30 03:05:25 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int value)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

t_stack	*ft_stacklast(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*n;

	if (*stack)
	{
		n = ft_stacklast(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

int	ft_stacksize(t_stack *head)
{
	size_t	i;
	t_stack	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
