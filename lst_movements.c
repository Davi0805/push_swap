/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:11:10 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/11/07 14:02:52 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// CRIAR MOVIMENTO SS AO INVES DE ADAPTAR ESSA FUNC
void	stack_swap(t_stack *target, int flag)
{
	t_stack	*second;
	int		swap;

	if (stack_size(target) <= 1)
		return ;
	swap = target->content;
	second = target->next;
	target->content = second->content;
	second->content = swap;
	if (flag == 1)
		ft_printf("sa\n");
	else if (flag == 2)
		ft_printf("sb\n");
}

void	stack_push(t_stack **src, t_stack **dest, int flag)
{
	t_stack	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	if (flag == PB)
		ft_printf("pb\n");
	else if (flag == PA)
		ft_printf("pa\n");
}

void	stack_rotate(t_stack *target, int flag)
{
	int		target_size;
	int		i;
	t_stack	*temp;

	temp = target;
	target_size = stack_size(target);
	if (target_size == 0)
		return ;
	i = 0;
	while (i < target_size - 1)
	{
		stack_swap(temp, QUIET);
		temp = temp->next;
		i++;
	}
	if (flag == 6)
		ft_printf("ra\n");
	else if (flag == 7)
		ft_printf("rb\n");
}

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
