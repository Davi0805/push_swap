/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:53:09 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/10/22 17:25:56 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_digit_sort(t_stack **src, t_stack **target, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((*src)->content & 1)
			stack_rotate(*src, RA);
		else
			stack_push(src, target, PB);
		i++;
	}
}

void	send_back_to_a(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack_push(stack_b, stack_a, PA);
		i++;
	}
	free(*stack_b);
	*stack_b = NULL;
}

void	second_digit_sort(t_stack **stack_a, t_stack **stack_b,
		int size, int shift)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((*stack_a)->content >> shift) & 1)
			stack_rotate(*stack_a, RA);
		else
			stack_push(stack_a, stack_b, PB);
		i++;
	}
}
