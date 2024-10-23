/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:50:11 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/10/23 16:56:37 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		bit_shifts;

	stack_a = NULL;
	stack_b = NULL;
	bit_shifts = 0;
	if (ac == 1)
		return (1);
	else if ((parse_error(ac, av) == 1 || equal_number(ac, av) == 1) && ac != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (ac > 2)
		stack_a = fill_from_av(ac, av);
	else if (ac == 2)
	{
		stack_a = fill_from_split(av[1]);
		if (stack_a == NULL)
			return (1);
	}
	while (bit_shifts < 32 && !is_sorted(stack_a))
	{
		if (bit_shifts == 0)
			first_digit_sort(&stack_a, &stack_b, stack_size(stack_a));
		else
			second_digit_sort(&stack_a, &stack_b,
				stack_size(stack_a), bit_shifts);
		send_back_to_a(&stack_a, &stack_b, stack_size(stack_b));
		bit_shifts++;
	}
	temp_a = stack_a;
	temp_b = stack_b;
	free_stack(temp_a);
	free_stack(temp_b);
	return (0);
}
