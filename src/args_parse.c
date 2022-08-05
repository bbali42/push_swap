/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:01:24 by bbali             #+#    #+#             */
/*   Updated: 2022/07/25 20:01:24 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	char	*ft_malloc_str(char const *str, char set)
{
	char	*res;
	int		i;

	i = 0;
	while (str[i] && str[i] != set)
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != set)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	ft_args_n_add(t_args **args, char *str, char c)
{
	int		i;
	t_args	*new;	

	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			new = ft_argsnew(ft_malloc_str(str, c), 1);
			if (!new)
				return (0);
			ft_argsadd_back(args, new);
			i++;
			while (*str && *str != c)
				str++;
		}
	}
	return (1);
}

static int	parse_args(t_args **args, char **av)
{
	int		i;
	t_args	*new;

	i = 1;
	while (av[i])
	{
		if (ft_strchr(av[i], ' ') && !ft_args_n_add(args, av[i], ' '))
		{
			free_args(args);
			return (0);
		}
		else if (!ft_strchr(av[i], ' '))
		{
			new = ft_argsnew(av[i], 0);
			if (!new)
			{
				free_args(args);
				return (0);
			}
			ft_argsadd_back(args, new);
		}
		i++;
	}
	return (1);
}

t_args	**init_args(char **av)
{
	t_args	**res;

	res = (t_args **)malloc(sizeof(t_args *));
	if (!res)
		return (NULL);
	*res = NULL;
	if (!parse_args(res, av))
		return (NULL);
	return (res);
}
