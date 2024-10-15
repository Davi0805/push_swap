#include "push_swap.h"

//Lembrar de modificar atoi que modifiquei para atol de volta para atoi e criar uma func apenas para atol

// LEMBRAR DE MODIFICAR STRUCT 

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_stack *temp_a;
    t_stack *temp_b;

    stack_a = NULL;
    stack_b = NULL;

    // LEMBRAR DE IMPLEMENTAR CHECAGEM EM CASO DE 1 STRING DE ARGUMENTO COM TODOS OS NUMEROS
    // VERIFICAR SPLIT PRIMEIRO
    if (ac == 1)
        return (1);
    else if (parse_error(ac, av) == 1 || equal_number(ac, av) == 1)
    {
        write(1, "Error\n", 6);
        return (1);
    }

    if (ac > 2)
        stack_a = fill_from_av(ac, av);
    else if (ac == 2)
    {
        printf("TU AINDA NAO IMPLEMENTOU O SPLIT CARA PALIDA\n");
        return (0);
    }


    /* stack_swap(stack_a, SWAP_A); */
    /* stack_swap(stack_a, SWAP_A); */
    /* stack_push(&stack_a, &stack_b, PA);
    stack_push(&stack_a, &stack_b, PA);
    stack_push(&stack_a, &stack_b, PA); */

    /* stack_push(&stack_a, &stack_b, PB); */
/*     stack_push(stack_a, &stack_b, PB);
    stack_push(stack_a, &stack_b, PB); */

    /* stack_swap_both(stack_a, stack_b); */

    /* stack_rotate(stack_b, RB); */

    /* stack_rotate_both(stack_a, stack_b); */

    /* stack_reverse_rotate(&stack_a, RRA);
    stack_reverse_rotate(&stack_b, RRB); */
    /* stack_reverse_rotate_both(&stack_a, &stack_b); */

    quicksort(&stack_a, &stack_b, stack_size(stack_a));

    temp_a = stack_a;
    // TESTE STACK A
    while (stack_a != NULL)
    {
        printf("STACK A: %i\n", stack_a->content);
        stack_a = stack_a->next;
    }
    
    temp_b = stack_b;
    // TESTE STACK B
    while (stack_b != NULL)
    {
        printf("STACK B: %i\n", stack_b->content);
        stack_b = stack_b->next;
    }

    free_stack(temp_a);
    free_stack(temp_b);

    return (0);
}


/* void quicksort(t_stack **a, t_stack **b, int size) {
    if (size <= 1) {
        return;  // Base case: no need to sort 1 or fewer elements
    }

    int pivot = (*a)->content;  // Select the top element as pivot
    t_stack *temp = NULL;  // Temporary stack to hold smaller elements

    // Partition: Push elements < pivot to temp stack, leave >= pivot in stack a
    int i = 0;
    while (i < size - 1) {
        if ((*a)->content < pivot) {
            stack_push(a, &temp, PB);  // Push smaller elements to temp stack
        } else {
            stack_rotate(*a, RA);  // Rotate stack a upwards for larger elements
        }
        i++;
    }

    // Put the pivot element back in stack a
    stack_rotate(*a, RA);

    // Recursively sort the partitioned stacks
    int elements_in_a = stack_size(*a);
    int elements_in_b = stack_size(temp);
    quicksort(a, b, elements_in_a);  // Sort stack a (elements >= pivot)
    quicksort(&temp, a, elements_in_b);  // Sort temp stack (elements < pivot)

    // Push sorted elements back from temp stack to stack a
    while (elements_in_b-- > 0) {
        stack_push(&temp, a, PA);  // Push elements from temp stack to stack a
    }
} */
