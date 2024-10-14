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

// LEMBRAR DE IMPLEMENTAR MACRO E PRINT DE MOVIMENTO
t_stack *stack_swap(t_stack *target)
{
	t_stack *second;
	int swap;

	swap = target->content;
	second = target->next;
	target->content = second->content;
	second->content = swap;

	return(target);
}
//ft_lstadd_front modificado
void stack_push(t_stack *src, t_stack *target)
{
	int target_size;
	int src_size;
	int i;
	t_stack *temp;

	i = 0;
	target_size = stack_size(target);
	src_size = stack_size(src);
	if (target_size == 0)
	{
		target = ft_stacknew(src->content);
		temp = src;
		while (i < src_size)
		{
			stack_swap(temp);
			temp = temp->next;
			i++;
		}
	}
}