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

# define INT_MAX "2147483647"
# define INT_MIN "2147483648"

typedef struct s_args
{
	char			*av;
	struct s_args	*next;
}				t_args;

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
int		check_args(t_args **args);
int		digit_len(char *str, int start);
// args_utils.c
int		ft_strdigit_cmp(char *str, int offset, char *str_nb);
// Sort algorithm => sort_5.c | radix_sort.c
int		small_sort(t_stack **a, t_stack **b, t_ops **ops);
int		radix_sort(t_stack **a, t_stack **b, t_ops **ops);
// Algo utils
void	index_stack(t_stack **stack);
int		is_sorted(t_stack **stack);
int		get_min(t_stack **stack, int val);
int		get_distance(t_stack **stack, int index);
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
// Args utils	=> args_parse.c | args_function.c
t_args	**init_args(char **av);
t_args	*ft_argsnew(char *av, int is_malloc);
int		add_args(t_args **args, char *instructions);
void	ft_argsadd_back(t_args **args, t_args *new);
int		ft_args_size(t_args *head);
void	free_args(t_args **args);
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