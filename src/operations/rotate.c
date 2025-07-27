/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:58:20 by yyudi             #+#    #+#             */
/*   Updated: 2025/07/27 13:13:51 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack *tmp;
	t_stack *last;

	if (!*a || !(*a)->next)
		return;
	tmp = *a;
	*a = (*a)->next;
	last = stack_last(*a);
	tmp->next = NULL;
	last->next = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack *tmp;
	t_stack *last;

	if (!*b || !(*b)->next)
		return;
	tmp = *b;
	*b = (*b)->next;
	last = stack_last(*b);
	tmp->next = NULL;
	last->next = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
