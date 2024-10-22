/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:50:28 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/10/22 14:54:48 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FUNC PARA INICIAR VARIAVEIS DA STRUCT E PREENCHER COM INT
t_stack	*ft_stacknew(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	stack_size(t_stack *lst)
{
	t_stack	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_stack	*last_stack(t_stack *lst)
{
	t_stack	*last;

	last = lst;
	while (lst)
	{
		if (last->next == NULL)
			return (last);
		else
			last = last->next;
	}
	return (NULL);
}

void	stack_add_end(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = last_stack(*lst);
	temp->next = new;
}

void	stack_add_front(t_stack **lst, t_stack *new)
{
	if (lst || new)
	{
		new->next = *lst;
		*lst = new;
	}
}
