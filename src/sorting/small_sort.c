#include "../includes/push_swap.h"

void sort_two(t_stack **a)
{
    if ((*a)->value > (*a)->next->value)
        sa(a, true);
}

// Di small_sort.c
void sort_three(t_stack **a)
{
    int first = (*a)->value;
    int second = (*a)->next->value;
    int third = (*a)->next->next->value;

    if (first > second && second < third && first < third)
        sa(a, true);
    else if (first > second && second > third) {
        sa(a, true);
        rra(a, true);
    }
    else if (first > second && second < third)
        ra(a, true);
    else if (first < second && second > third && first < third) {
        sa(a, true);
        ra(a, true);
    }
    else if (first < second && second > third)
        rra(a, true);
}

void sort_five(t_stack **a, t_stack **b)
{
    // Push 2 angka terkecil ke B
    while (stack_size(*a) > 3)
    {
        if ((*a)->index <= 1)
            pb(a, b);
        else
            ra(a, true);
    }

    // Sortir 3 angka tersisa
    sort_three(a);

    // Kembalikan dari B ke A
    while (*b)
    {
        if ((*b)->index == 0 || (*a)->index > (*b)->index)
            pa(a, b);
        else
            ra(a, true);
    }

    // Pastikan minimum ada di top
    while ((*a)->index != 0)
        ra(a, true);
}

void sort_medium(t_stack **a, t_stack **b) {
    // 1. Push elemen terkecil ke B
    while (stack_size(*a) > 5) {
        int min = get_min(*a);
        int pos = get_position(*a, min);

        if (pos <= stack_size(*a) / 2)
            while ((*a)->value != min) ra(a, true);
        else
            while ((*a)->value != min) rra(a, true);
        pb(a, b);
    }

    // 2. Sortir sisa 5 angka di A
    sort_five(a, b);

    // 3. Masukkan kembali elemen dari B ke A
    while (*b) {
        smart_insert(a, b);
    }
}
