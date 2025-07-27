/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:58:36 by yyudi             #+#    #+#             */
/*   Updated: 2025/07/27 13:04:41 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int top;
	int mid;
	int bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && mid < bot && bot > top)
		sa(a);
	else if (top > mid && mid > bot && bot < top)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && bot < top)
		ra(a);
	else if (top < mid && mid > bot && bot > top)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && bot < top)
		rra(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int size;

	size = ft_stack_size(*a);
	while (ft_stack_size(*a) > 3)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	while (ft_stack_size(*b))
	{
		pa(a, b);
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
}
