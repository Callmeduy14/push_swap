/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 13:05:42 by yyudi             #+#    #+#             */
/*   Updated: 2025/07/27 13:22:33 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	 ft_atoi(const char *str)
{
	long	result;
	int	 sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (result * sign > INT_MAX || result * sign < INT_MIN)
		error_exit(NULL, NULL);
	return (result * sign);
}

bool is_sorted(t_stack *stack)  // Ubah tipe return dari int ke bool
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return false;  // Gunakan false bukan 0
		stack = stack->next;
	}
	return true;  // Gunakan true bukan 1
}

void	assign_index(t_stack *a)
{
	t_stack *ptr;
	t_stack *current;
	int	 index;

	current = a;
	while (current)
	{
		ptr = a;
		index = 0;
		while (ptr)
		{
			if (ptr->value < current->value)
				index++;
			ptr = ptr->next;
		}
		current->index = index;
		current = current->next;
	}
}
