#include "../includes/push_swap.h"

void	rra(t_stack **a, bool print)
{
	t_stack	*last;
	t_stack	*prev;

	if (!*a || !(*a)->next)
		return;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->prev = NULL;
	last->next = *a;
	(*a)->prev = last;
	*a = last;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool print)
{
	t_stack	*last;
	t_stack	*prev;

	if (!*b || !(*b)->next)
		return;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->prev = NULL;
	last->next = *b;
	(*b)->prev = last;
	*b = last;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, false);
	rrb(b, false);
	write(1, "rrr\n", 4);
}
