#include "../includes/push_swap.h"

void    sa(t_stack **a, bool print)
{
    t_stack *tmp;

    if (!*a || !(*a)->next)
        return;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = (*a)->next;
    (*a)->next = tmp;
    if (print)
        write(1, "sa\n", 3);
}

void    sb(t_stack **b, bool print)
{
    t_stack *tmp;

    if (!*b || !(*b)->next)
        return;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = (*b)->next;
    (*b)->next = tmp;
    if (print)
        write(1, "sb\n", 3);
}

void    ss(t_stack **a, t_stack **b)
{
    sa(a, false);
    sb(b, false);
    write(1, "ss\n", 3);
}
