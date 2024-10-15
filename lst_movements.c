#include "push_swap.h"



// CRIAR MOVIMENTO SS AO INVES DE ADAPTAR ESSA FUNC
void stack_swap(t_stack *target, int flag)
{
	t_stack *second;
	int swap;

	if (stack_size(target) <= 1)
		return;
	swap = target->content;
	second = target->next;
	target->content = second->content;
	second->content = swap;

	if (flag == 1)
		ft_printf("sa\n");
	else if (flag == 2)
		ft_printf("sb\n");

	/* return(target); */
}

void stack_swap_both(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *second;
	int swap;

	// SA
	swap = stack_a->content;
	second = stack_a->next;
	stack_a->content = second->content;
	second->content = swap;

	// SB
	swap = stack_b->content;
	second = stack_b->next;
	stack_b->content = second->content;
	second->content = swap;


	ft_printf("ss\n");
}

void stack_push(t_stack **src, t_stack **target, int flag)
{
	int target_size;
	int src_size;
	int i;
	t_stack *temp;

	i = 0;
	target_size = stack_size(*target);
	src_size = stack_size(*src);

	// LEMBRAR DE ADICIONAR CONDICAO PARA CASO SRC ESTEJA VAZIA
	if (src_size == 0)
		return;
	else if (target_size == 0)
	{
		*target = ft_stacknew((*src)->content);
		temp = *src;
		while (i < src_size - 2)
		{
			stack_swap(temp, QUIET);
			temp = temp->next;
			i++;
		}
		stack_swap(temp, QUIET);
		free(temp->next);
		temp->next = NULL;

	}
	else
	{
		stack_add_front(target, ft_stacknew((*src)->content));
		temp = *src;
		while (i < src_size - 2)
		{
			stack_swap(temp, QUIET);
			temp = temp->next;
			i++;
		}
		stack_swap(temp, QUIET);
		free(temp->next);
		temp->next = NULL;
	}

	if (flag == 4)
		ft_printf("pa\n");
	else if (flag == 5)
		ft_printf("pb\n");
}

/* void stack_push(t_stack **src, t_stack **dest, int flag) {
    if (!src || !*src) return;

    t_stack *temp = *src;
    *src = (*src)->next;
    temp->next = *dest;
    *dest = temp;

    if (flag == PB) {
        ft_printf("pb\n");
    } else if (flag == PA) {
        ft_printf("pa\n");
    }
} */

void stack_rotate(t_stack *target, int flag)
{
	int target_size;
	int i;
	t_stack *temp;

	temp = target;
	target_size = stack_size(target);

	if (target_size == 0)
		return;

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

/* void stack_rotate(t_stack **target, int flag)
{
    if (!target || !*target || !(*target)->next)
        return;

    t_stack *first = *target;
    t_stack *last = *target;

    // Encontrar o último elemento da lista
    while (last->next)
        last = last->next;

    // Mover o primeiro elemento para o final
    *target = first->next;
    first->next = NULL;
    last->next = first;

    // Imprimir a operação realizada
    if (flag == 6)
        ft_printf("ra\n");
    else if (flag == 7)
        ft_printf("rb\n");
} */


void stack_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	int stack_a_size;
	int stack_b_size;
	int i;
	t_stack *temp;

	temp = stack_a;
	stack_a_size = stack_size(stack_a);
	stack_b_size = stack_size(stack_b);

	if (stack_a_size == 0 || stack_b_size == 0)
		return;

	/* ft_printf("target_size: %i\n", target_size); */
	i = 0;
	while (i < stack_a_size - 1)
	{
		stack_swap(temp, QUIET);
		temp = temp->next;
		i++;
	}
	temp = stack_b;
	i = 0;
	while (i < stack_b_size - 1)
	{
		stack_swap(temp, QUIET);
		temp = temp->next;
		i++;
	}

	ft_printf("rr\n");
}

void stack_reverse_rotate(t_stack **target, int flag)
{
	int target_size;
	int i;
	t_stack *temp;

	temp = *target;
	i = 0;
	target_size = stack_size(*target);
	/* ft_printf("target_size: %i\n", target_size); */
	while (i < target_size - 2)
	{
		temp = temp->next;
		i++;
	}
	stack_add_front(target, ft_stacknew(temp->next->content));
	/* ft_printf("ULTIMO? : %i\n", temp->content); */
	/* free(temp->next->content); */
	free(temp->next);
	temp->next = NULL;
	/* free(temp); */
	if (flag == 8)
		ft_printf("rra\n");
	else if (flag == 9)
		ft_printf("rrb\n");
}

void stack_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	stack_reverse_rotate(stack_a, QUIET);
	stack_reverse_rotate(stack_b, QUIET);
	ft_printf("rrr\n");
}