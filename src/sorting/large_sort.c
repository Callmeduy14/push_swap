#include "../includes/push_swap.h"

static void push_back_to_a(t_stack **a, t_stack **b)
{
    while (*b)
    {
        int max_pos = find_max_position(*b);
        int size = stack_size(*b);
        int steps;

        if (max_pos <= size / 2)
            steps = max_pos;
        else
            steps = size - max_pos;

        while (steps-- > 0)
        {
            if (max_pos <= size / 2)
                rb(b, true);
            else
                rrb(b, true);
        }
        pa(a, b);
    }
}

void chunk_sort(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    int chunk_count = get_optimal_chunk_count(size);
    int chunk_size = size / chunk_count;
    int i = 0;

    while (i++ < chunk_count)
    {
        int min = (i - 1) * chunk_size;
        int max = i * chunk_size - 1;

        if (i == chunk_count)
            max = size - 1;

        while (!is_chunk_empty(*a, min, max))
        {
            if ((*a)->index >= min && (*a)->index <= max)
            {
                pb(a, b);
                if ((*b)->index < (min + max) / 2 && stack_size(*b) > 1)
                    rb(b, true);
            }
            else
                ra(a, true);
        }
    }
    push_back_to_a(a, b);
}
