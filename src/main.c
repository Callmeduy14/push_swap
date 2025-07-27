/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 13:10:45 by yyudi             #+#    #+#             */
/*   Updated: 2025/07/27 13:10:46 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"  // Pastikan include ini ada

int main(int argc, char **argv)
{
	t_stack *a = NULL;
	t_stack *b = NULL;

	if (argc < 2)
		return (0);

	parse_args(argc, argv, &a);

	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}

	assign_index(a);

	if (ft_stack_size(a) <= 3)	   // Pastikan konsisten dengan nama di header
		sort_three(&a);
	else if (ft_stack_size(a) <= 5)  // Idem
		sort_five(&a, &b);
	else
		radix_sort(&a, &b);

	free_stack(&a);
	free_stack(&b);
	return (0);
}
