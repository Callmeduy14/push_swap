#include "../includes/push_swap.h"

void dispatch_sort(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);

    if (size == 2)
        sort_two(a);
    else if (size == 3)
        sort_three(a);
    else if (size <= 5)
        sort_five(a, b);
    else if (size <= 20)
        sort_medium(a, b);
    else
        chunk_sort(a, b);
}

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    if (argc < 2)
        return 0;

    parse_args(argc, argv, &a);

    if (is_sorted(a))
    {
        free_stack(&a);
        return 0;
    }

    assign_index(a);

    // Pilih algoritma berdasarkan ukuran stack
    if (stack_size(a) <= 5)
{
    if (stack_size(a) == 2)
        sa(&a, true);
    else if (stack_size(a) == 3)
        sort_three(&a);
    else
        sort_five(&a, &b);
}
	else
        chunk_sort(&a, &b);

    free_stack(&a);
    free_stack(&b);
    return 0;
}
