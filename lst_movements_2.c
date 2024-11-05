/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_movements_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:50:25 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/11/05 18:48:44 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_reverse_rotate(t_stack **target, int flag)
{
	int		target_size;
	int		i;
	t_stack	*temp;

	temp = *target;
	i = 0;
	target_size = stack_size(*target);
	while (i < target_size - 2)
	{
		temp = temp->next;
		i++;
	}
	stack_add_front(target, ft_stacknew(temp->next->content));
	free(temp->next);
	temp->next = NULL;
	if (flag == 8)
		ft_printf("rra\n");
	else if (flag == 9)
		ft_printf("rrb\n");
}

void	stack_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	stack_reverse_rotate(stack_a, QUIET);
	stack_reverse_rotate(stack_b, QUIET);
	ft_printf("rrr\n");
}
