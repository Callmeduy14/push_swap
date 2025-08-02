#include "../includes/push_swap.h"

int get_optimal_chunk_count(int size)
{
    if (size <= 100) return 5;    // Naikkan dari 5 ke 6
    if (size <= 500) return 11;   // Naikkan dari 15 ke 17
    return 15;                    // Untuk >500 angka
}

int get_steps_to_top(t_stack *stack, int value)
{
    int pos = 0;
    while (stack && stack->index != value)
    {
        pos++;
        stack = stack->next;
    }
    return pos;
}
bool is_chunk_empty(t_stack *stack, int min, int max)
{
    while (stack)
    {
        if (stack->index >= min && stack->index <= max)
            return false;
        stack = stack->next;
    }
    return true;
}

bool should_rotate_b(t_stack *b, int min, int max)
{
    int target;

    if (!b || !b->next)
        return (false);
    target = min + (max - min) / 2;
    return (b->index < target);
}
