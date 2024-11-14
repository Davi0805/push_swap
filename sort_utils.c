/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:55:53 by davi              #+#    #+#             */
/*   Updated: 2024/11/14 13:59:24 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_num(t_stack **stack)
{
	t_stack	*current;
	t_stack	*last;

	current = *stack;
	last = last_stack(*stack);
	if (last->content != 2)
	{
		if (current->content == 2)
			stack_rotate(*stack, RA);
		else
			stack_reverse_rotate(stack, RRA);
	}
	if ((*stack)->content > (*stack)->next->content)
		stack_swap(*stack, SWAP_A);
}

void	four_five_num(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_size(*stack_b) <= 1)
	{
		if ((*stack_a)->content == 0 || (*stack_a)->content == 1)
			stack_push(stack_a, stack_b, PB);
		else
			stack_rotate(*stack_a, RA);
	}
	if ((*stack_b)->content == 0)
		stack_swap(*stack_b, SWAP_B);
	if (get_median_value(*stack_a) != 4)
	{
		if ((*stack_a)->content == 4)
			stack_rotate(*stack_a, RA);
		else
			stack_reverse_rotate(stack_a, RRA);
	}
	if ((*stack_a)->content > (*stack_a)->next->content)
		stack_swap(*stack_a, SWAP_A);
	stack_push(stack_b, stack_a, PA);
	stack_push(stack_b, stack_a, PA);
}

int	get_median_value(t_stack *stack)
{
	int		i;
	t_stack	*cur;

	cur = stack;
	i = 0;
	if (stack_size(stack) < 3)
		return (-1);
	while (i != 2)
	{
		cur = cur->next;
		i++;
	}
	return (cur->content);
}
