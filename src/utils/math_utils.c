#include "../includes/push_swap.h"

bool	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	assign_index(t_stack *stack)
{
	t_stack	*ptr;
	t_stack	*current;
	int		index;

	current = stack;
	while (current)
	{
		ptr = stack;
		index = 0;
		while (ptr)
		{
			if (ptr->value < current->value)
				index++;
			ptr = ptr->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	get_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}
