/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:08:13 by bbali             #+#    #+#             */
/*   Updated: 2022/08/05 19:08:13 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	digit_len(char *str, int start)
{
	int		i;

	i = 0;
	while (str[start + i])
		i++;
	return (i);
}

int	ft_strdigit_cmp(char *str, int offset, char *str_nb)
{
	if (digit_len(str, offset) > ft_strlen(str_nb))
		return (1);
	else if (digit_len(str, offset) == ft_strlen(str_nb))
	{
		while (offset)
		{
			str++;
			offset--;
		}
		while (*str && *str_nb && (*str == *str_nb))
		{
			str++;
			str_nb++;
		}
		return (*(unsigned char *)str - *(unsigned char *)str_nb);
	}
	return (0);
}
