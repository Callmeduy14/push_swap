#include "../includes/push_swap.h"

void	error_exit(t_stack **a, t_stack **b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	check_duplicates(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*current;

	current = a;
	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (current->value == tmp->value)
				error_exit(&a, NULL);
			tmp = tmp->next;
		}
		current = current->next;
	}
}

int	ft_atoi(const char *str, t_stack **a)
{
	long    result;
    int     sign;

    result = 0;
    sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        else
            sign = 1;
        str++;
    }
    if (!*str)
        error_exit(a, NULL);
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        if ((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN))
            error_exit(a, NULL);
        str++;
    }
    if (*str && !(*str == ' ' || (*str >= 9 && *str <= 13)))
        error_exit(a, NULL);
    return (int)(result * sign);
}

void	parse_args(int argc, char **argv, t_stack **a)
{
	int		i;
	int		value;
	t_stack	*new;

	if (argc < 2)
        error_exit(a, NULL);
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i], a);
		new = stack_new(value);
		if (!new)
			error_exit(a, NULL);
		stack_add_back(a, new);
		i++;
	}
	check_duplicates(*a);
}
