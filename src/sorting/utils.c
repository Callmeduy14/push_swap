#include "../includes/push_swap.h"

int	find_highest_index(t_stack *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	get_position(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}


int find_max_position(t_stack *stack)
{
    t_stack *tmp;
    int max;
    int pos;
    int i;

    if (!stack)
        return (0);

    tmp = stack;
    max = tmp->index;
    pos = 0;
    i = 0;

    while (tmp)
    {
        if (tmp->index > max)
        {
            max = tmp->index;
            pos = i;
        }
        tmp = tmp->next;
        i++;
    }
    return (pos);
}

static int find_insert_position(t_stack *a, int value)
{
    int pos;
    int closest;
    int target_pos;

    pos = 0;
    closest = INT_MAX;
    target_pos = 0;

    while (a)
    {
        if (a->value > value && a->value < closest)
        {
            closest = a->value;
            target_pos = pos;
        }
        pos++;
        a = a->next;
    }
    return (target_pos);
}

void smart_insert(t_stack **a, t_stack **b)
{
    int target_pos;

    if (!*b)
        return;

    if (stack_size(*a) == 0)
    {
        pa(a, b);
        return;
    }

    target_pos = find_insert_position(*a, (*b)->value);

    if (target_pos <= stack_size(*a) / 2)
        while (target_pos-- > 0)
            ra(a, true);
    else
        while (target_pos++ < stack_size(*a))
            rra(a, true);

    pa(a, b);
}
