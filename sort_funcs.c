#include "push_swap.h"

void first_digit_sort(t_stack **src, t_stack **target, int size)
{
    int i = 0;

    while (i < size) 
    {
        if ((*src)->content & 1)
            stack_rotate(*src, RA); 
        else
            stack_push(src, target, PB);
    i++;
    }
}

void send_back_to_a(t_stack **stack_a, t_stack **stack_b, int size)
{
    int i = 0;
/*     t_stack *temp;

    temp = *stack_b;
    while(i < size)
    {
        if ((temp->content << 1) & 1)
            stack_rotate(temp, RB);
        temp = temp->next;
        i++;
    } */
    i = 0;
    while (i < size)
    {
        stack_push(stack_b, stack_a, PA);
        i++;
    }
    free(*stack_b);
    *stack_b = NULL;

    i = 0;
}

void second_digit_sort(t_stack **stack_a, t_stack **stack_b, int size, int shift)
{
    int i;

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

