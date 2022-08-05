/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:42:07 by bbali             #+#    #+#             */
/*   Updated: 2022/07/25 18:42:07 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_args	*ft_argslast(t_args *head)
{
	t_args	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

t_args	*ft_argsnew(char *av, int is_malloc)
{
	t_args	*new;

	new = (t_args *) malloc(sizeof(t_args));
	if (!new)
		return (NULL);
	if (!is_malloc)
		new->av = ft_strdup(av);
	else
		new->av = av;
	if (!new->av)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

void	ft_argsadd_back(t_args **args, t_args *new)
{
	t_args	*n;

	if (*args)
	{
		n = ft_argslast(*args);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*args = new;
		(*args)->next = NULL;
	}
}

int	add_args(t_args **args, char *av)
{
	t_args	*new;

	new = ft_argsnew(av, 0);
	if (!new)
		return (0);
	ft_argsadd_back(args, new);
	return (1);
}

int	ft_args_size(t_args *head)
{
	int		i;
	t_args	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
