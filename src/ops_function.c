/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:50:12 by bbali             #+#    #+#             */
/*   Updated: 2022/07/18 18:50:12 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ops	*ft_opsnew(char *instructions)
{
	t_ops	*new;

	new = (t_ops *) malloc(sizeof(t_ops));
	if (!new)
		return (NULL);
	new->instruction = ft_strdup(instructions);
	if (!new->instruction)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

static t_ops	*ft_opslast(t_ops *head)
{
	t_ops	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

static void	ft_opsadd_back(t_ops **ops, t_ops *new)
{
	t_ops	*n;

	if (*ops)
	{
		n = ft_opslast(*ops);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*ops = new;
		(*ops)->next = NULL;
	}
}

int	add_ops(t_ops **ops, char *instructions)
{
	t_ops	*new;

	new = ft_opsnew(instructions);
	if (!new)
		return (0);
	ft_opsadd_back(ops, new);
	return (1);
}

void	print_ops(t_ops *head)
{
	t_ops	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putendl_fd(tmp->instruction, STDOUT_FILENO);
		tmp = tmp->next;
	}
}
