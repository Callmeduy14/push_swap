/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:51:41 by yyudi             #+#    #+#             */
/*   Updated: 2025/07/27 13:23:44 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack {
	int			 value;
	int			 index;
	struct s_stack  *next;
	struct s_stack  *prev;
} t_stack;

/* OPERATIONS */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* SORTING */
void	sort_stack(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	radix_sort(t_stack **a, t_stack **b);

/* UTILS */
t_stack *stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
int	 	stack_size(t_stack *stack);
t_stack *stack_last(t_stack *stack);
void	stack_clear(t_stack **stack);
int	 	get_min(t_stack *stack);
bool	is_sorted(t_stack *stack);
void	assign_index(t_stack *stack);

/* PARSING */
void	parse_args(int argc, char **argv, t_stack **a);
void	error_exit(t_stack **a, t_stack **b);

// Tambahkan/ubah deklarasi ini:
void    free_stack(t_stack **stack);
int     ft_stack_size(t_stack *stack);  // atau ubah ke stack_size jika itu yang digunakan

int     ft_atoi(const char *str);

#endif
