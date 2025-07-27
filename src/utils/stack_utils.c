/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 13:05:20 by yyudi             #+#    #+#             */
/*   Updated: 2025/07/27 13:25:10 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *stack_new(int value)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack *last;

	if (!*stack)
	{
		*stack = new;
		return;
	}
	last = stack_last(*stack);
	last->next = new;
}

t_stack *stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	 ft_stack_size(t_stack *stack)
{
	int size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	free_stack(t_stack **stack)
{
	t_stack *tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
