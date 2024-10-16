#include "push_swap.h"


    // MOVIMENTOS
    /* stack_swap(stack_a, SWAP_A);
    stack_swap(stack_a, SWAP_A);
    stack_push(&stack_a, &stack_b, PA);
    stack_push(&stack_a, &stack_b, PA);
    stack_push(&stack_a, &stack_b, PA);

    stack_push(&stack_a, &stack_b, PB);
    stack_push(stack_a, &stack_b, PB);
    stack_push(stack_a, &stack_b, PB);

    stack_swap_both(stack_a, stack_b);

    stack_rotate(stack_b, RB);

    stack_rotate_both(stack_a, stack_b);

    stack_reverse_rotate(&stack_a, RRA);
    stack_reverse_rotate(&stack_b, RRB);
    stack_reverse_rotate_both(&stack_a, &stack_b); */

//Lembrar de modificar atoi que modifiquei para atol de volta para atoi e criar uma func apenas para atol

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_stack *temp_a;
    t_stack *temp_b;
    int bit_shifts = 0;

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

    // RADIX
/*     first_digit_sort(&stack_a, &stack_b, stack_size(stack_a));
    send_back_to_a(&stack_a, &stack_b, stack_size(stack_b));
    second_digit_sort(&stack_a, &stack_b, stack_size(stack_a), 1);
    send_back_to_a(&stack_a, &stack_b, stack_size(stack_b));
    second_digit_sort(&stack_a, &stack_b, stack_size(stack_a), 2);
    send_back_to_a(&stack_a, &stack_b, stack_size(stack_b));
    second_digit_sort(&stack_a, &stack_b, stack_size(stack_a), 3);
    send_back_to_a(&stack_a, &stack_b, stack_size(stack_b));
    second_digit_sort(&stack_a, &stack_b, stack_size(stack_a), 4);
    send_back_to_a(&stack_a, &stack_b, stack_size(stack_b));
    second_digit_sort(&stack_a, &stack_b, stack_size(stack_a), 5);
    send_back_to_a(&stack_a, &stack_b, stack_size(stack_b));
    second_digit_sort(&stack_a, &stack_b, stack_size(stack_a), 6);
    send_back_to_a(&stack_a, &stack_b, stack_size(stack_b));
    second_digit_sort(&stack_a, &stack_b, stack_size(stack_a), 7);
    send_back_to_a(&stack_a, &stack_b, stack_size(stack_b));
    second_digit_sort(&stack_a, &stack_b, stack_size(stack_a), 8);
    send_back_to_a(&stack_a, &stack_b, stack_size(stack_b));
    second_digit_sort(&stack_a, &stack_b, stack_size(stack_a), 9);
    send_back_to_a(&stack_a, &stack_b, stack_size(stack_b)); */
    
        while (bit_shifts < 32 && !is_sorted(stack_a)) {
        if (bit_shifts == 0) {
            first_digit_sort(&stack_a, &stack_b, stack_size(stack_a));
        } else {
            second_digit_sort(&stack_a, &stack_b, stack_size(stack_a), bit_shifts);
        }
        /* sort_stack_b(stack_b); */
        send_back_to_a(&stack_a, &stack_b, stack_size(stack_b));
        bit_shifts++;
    }
    

    // TEMP PARA GUARDAR INICIO DA STACK PARA DAR FREE DPS
    temp_a = stack_a;
    // TESTE STACK A
    while (stack_a != NULL)
    {
        printf("STACK A: %i\n", stack_a->content);
        stack_a = stack_a->next;
    }
    
    // TEMP PARA GUARDAR INICIO DA STACK PARA DAR FREE DPS
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


