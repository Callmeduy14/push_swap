#include "../includes/push_swap.h"

void	ra(t_stack **a, bool print)
{
	t_stack	*first;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return;
	first = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last = stack_last(*a);
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool print)
{
	t_stack	*first;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return;
	first = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	last = stack_last(*b);
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, false);
	rb(b, false);
	write(1, "rr\n", 3);
}
