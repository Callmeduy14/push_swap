/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 13:06:03 by yyudi             #+#    #+#             */
/*   Updated: 2025/07/27 13:24:13 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack **a, t_stack **b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	check_duplicates(t_stack *a)
{
	t_stack *tmp;
	t_stack *current;

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

void	parse_args(int argc, char **argv, t_stack **a)
{
	int	 i;
	int	 value;
	t_stack *new;

	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		new = stack_new(value);
		if (!new)
			error_exit(a, NULL);
		stack_add_back(a, new);
		i++;
	}
	check_duplicates(*a);
}
