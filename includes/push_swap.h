/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:27:58 by yyudi             #+#    #+#             */
/*   Updated: 2025/08/02 02:21:36 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack {
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* Stack Operations */
void		sa(t_stack **a, bool print);
void		sb(t_stack **b, bool print);
void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		ra(t_stack **a, bool print);
void		rb(t_stack **b, bool print);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a, bool print);
void		rrb(t_stack **b, bool print);
void		rrr(t_stack **a, t_stack **b);

/* Stack Utils */
t_stack		*stack_new(int value);
void		stack_add_back(t_stack **stack, t_stack *new);
void		stack_add_front(t_stack **stack, t_stack *new);
t_stack		*stack_last(t_stack *stack);
int			stack_size(t_stack *stack);
void		free_stack(t_stack **stack);

/* Math Utils */
int			ft_atoi(const char *str, t_stack **a);
bool		is_sorted(t_stack *stack);
void		assign_index(t_stack *stack);
int			get_min(t_stack *stack);
int			get_max(t_stack *stack);
int			get_position(t_stack *stack, int value);
int     find_max_position(t_stack *stack);

/* Parsing */
void		parse_args(int argc, char **argv, t_stack **a);
void		error_exit(t_stack **a, t_stack **b);

/* Sorting */
void		sort_stack(t_stack **a, t_stack **b);
void		sort_two(t_stack **a);
void		sort_three(t_stack **a);
void		sort_five(t_stack **a, t_stack **b);
void		sort_medium(t_stack **a, t_stack **b);
void		chunk_sort(t_stack **a, t_stack **b);

/* Sorting Utils */
int			find_highest_index(t_stack *stack);
int			get_optimal_chunk_count(int size);
int			find_max_index(t_stack *stack);
int			get_steps_to_top(t_stack *stack, int value);
bool		is_chunk_empty(t_stack *stack, int min, int max);
bool		should_rotate_b(t_stack *b, int min, int max);
int			find_target_position(t_stack *a, int value);
void		smart_insert(t_stack **a, t_stack **b);
#endif

