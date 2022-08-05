/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:24:03 by bbali             #+#    #+#             */
/*   Updated: 2022/07/20 15:24:03 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

void	free_ops(t_ops **ops)
{
	t_ops	*head;
	t_ops	*tmp;

	head = *ops;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->instruction);
		free(tmp);
	}
	free(ops);
}

void	free_args(t_args **args)
{
	t_args	*head;
	t_args	*tmp;

	head = *args;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->av);
		free(tmp);
	}
	free(args);
}

void	ft_error(t_stack **a, t_stack **b, t_ops **ops)
{
	free_stack(a);
	free_stack(b);
	free_ops(ops);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(0);
}

void	end_prg(t_stack **a, t_stack **b, t_ops **ops)
{
	print_ops(*ops);
	free_stack(a);
	free_stack(b);
	free_ops(ops);
}
