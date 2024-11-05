/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:53:09 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/11/05 22:15:32 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_b(t_stack **stack_a, t_stack **stack_b,
		int bit_needed, int bit_shifts)
{
	int	length_b;

	length_b = stack_size(*stack_b);
	while (bit_shifts <= bit_needed && length_b-- && !is_sorted(*stack_a))
	{
		if ((((*stack_b)->content) >> bit_shifts) & 1)
			stack_push(stack_b, stack_a, PA);
		else
			stack_rotate(*stack_b, RB);
	}
	if (is_sorted(*stack_a))
		send_back_to_a(stack_a, stack_b, stack_size(*stack_b));
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	bit_needed;
	int	length_a;
	int	bit_shifts;

	bit_needed = 0;
	bit_shifts = -1;
	length_a = stack_size(*stack_a);
	while (length_a > 1 && ++bit_needed)
		length_a /= 2;
	while (++bit_shifts <= bit_needed)
	{
		length_a = stack_size(*stack_a);
		while (length_a-- && !is_sorted(*stack_a))
		{
			if ((((*stack_a)->content) >> bit_shifts) & 1)
				stack_rotate(*stack_a, RA);
			else
				stack_push(stack_a, stack_b, PB);
		}
		sort_b(stack_a, stack_b, bit_needed, bit_shifts + 1);
	}
	send_back_to_a(stack_a, stack_b, stack_size(*stack_b));
}

void	populate_stack_w_index(t_stack *stack, int *index_array, int size)
{
	int	index;
	int	i;

	while (stack)
	{
		i = 0;
		index = 0;
		while (i < size)
		{
			if (index_array[i] < stack->content)
				index++;
			i++;
		}
		stack->content = index;
		stack = stack->next;
	}
}

void	replace_with_index(t_stack *stack, int size)
{
	t_stack	*current;
	int		*index_array;
	int		i;

	i = 0;
	index_array = malloc(size * sizeof(int));
	current = stack;
	while (current)
	{
		index_array[i++] = current->content;
		current = current->next;
	}
	current = stack;
	populate_stack_w_index(current, index_array, size);
	free(index_array);
}
