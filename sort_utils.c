#include "push_swap.h"

void	three_num(t_stack **stack)
{
	t_stack *current;
	t_stack *last;

	current = *stack;
	last = last_stack(*stack);
	if (last->content != 2)
	{
		if (current->content == 2)
			stack_rotate(*stack, RA);
		else
			stack_reverse_rotate(stack, RRA);
	}
	if (current->content > current->next->content)
		stack_swap(*stack, SWAP_A);
}


/* void	sort_four_to_five_elements(t_stacks *s)
{
	while (s->b_size <= 1)
	{
		if (s->a[0] == 0 || s->a[0] == 1)
			push("pb", s);
		else
			rotate(s->a, s->a_size, "up", "a");
	}
	if (s->b[0] == 0)
		swap("sb", s->b, s->b_size);
	if (s->a[2] != 4)
	{
		if (s->a[0] == 4)
			rotate(s->a, s->a_size, "up", "a");
		else
			rotate(s->a, s->a_size, "down", "a");
	}
	if (s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	push("pa", s);
	push("pa", s);
} */
