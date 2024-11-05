/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:50:11 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/11/05 13:21:45 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*temp_a;
	t_stack	*temp_b;

	stack_a = NULL;
	stack_b = NULL;
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
	replace_with_index(stack_a, stack_size(stack_a));

	if (stack_size(stack_a) == 3)
		three_num(&stack_a);
	else if (stack_size(stack_a) == 4 || stack_size(stack_a) == 5)
		ft_printf("CALMA\n");
	else
		sort(&stack_a, &stack_b);

	temp_a = stack_a;
	temp_b = stack_b;
	free_stack(temp_a);
	free_stack(temp_b);
	return (0);
}
