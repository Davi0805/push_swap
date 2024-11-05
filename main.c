/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:50:11 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/11/05 22:08:40 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*temp_a;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = parse_setup(ac, av);
	if (stack_a == NULL)
		return (1);
	if (is_sorted(stack_a) == 1)
	{
		free_stack(stack_a);
		return (0);
	}
	replace_with_index(stack_a, stack_size(stack_a));
	if (stack_size(stack_a) == 3)
		three_num(&stack_a);
	else if (stack_size(stack_a) == 4 || stack_size(stack_a) == 5)
		four_five_num(&stack_a, &stack_b);
	else
		sort(&stack_a, &stack_b);
	temp_a = stack_a;
	free_stack(temp_a);
	return (0);
}
