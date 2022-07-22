/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 01:37:39 by bbali             #+#    #+#             */
/*   Updated: 2022/06/25 01:37:39 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;

typedef struct s_ops
{
	char			*instruction;
	struct s_ops	*next;
}				t_ops;

// check_args.c
int		check_args(int ac, char **av);
// Sort algorithm => sort_5.c | radix_sort.c
int		small_sort(t_stack **a, t_stack **b, t_ops **ops);
int		radix_sort(t_stack **a, t_stack **b, t_ops **ops);
// Algo utils
void	index_stack(t_stack **stack);
int		is_sorted(t_stack **stack);
int		get_min(t_stack **stack, int val);
int		get_distance(t_stack **stack, int index);
void	make_top(t_stack **stack, int distance, t_ops **ops);
void	free_stack(t_stack **stack);
// [ swap | push | rot | revrot ].c
int		sa(t_stack **a, t_ops **ops);
int		sb(t_stack **b, t_ops **ops);
int		ss(t_stack **a, t_stack **b, t_ops **ops);
int		pa(t_stack **a, t_stack **b, t_ops **ops);
int		pb(t_stack **b, t_stack **a, t_ops **ops);
int		ra(t_stack **a, t_ops **ops);
int		rb(t_stack **b, t_ops **ops);
int		rr(t_stack **a, t_stack **b, t_ops **ops);
int		rra(t_stack **a, t_ops **ops);
int		rrb(t_stack **b, t_ops **ops);
int		rrr(t_stack **a, t_stack **b, t_ops **ops);
// Stack utils
int		ft_stack(t_stack **stack);
t_stack	*ft_stacknew(int value);
t_stack	*ft_stacklast(t_stack *head);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
int		ft_stacksize(t_stack *head);
void	print_stack(t_stack *head);
void	ft_error(t_stack **a, t_stack **b, t_ops **ops);
void	end_prg(t_stack **a, t_stack **b, t_ops **ops);
// Ops utils
int		add_ops(t_ops **ops, char *instructions);
void	print_ops(t_ops *head);
void	free_ops(t_ops **ops);

#endif