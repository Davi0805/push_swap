#ifndef     PUSH_SWAP_H
# define    PUSH_SWAP_H

#include <unistd.h>
#include "./Libft/ft_printf.h"
#include <stdio.h>

typedef struct  s_stack
{
    int content;
    struct s_stack *next;
}               t_stack;


int parse_error(int ac, char **av);
int equal_number(int ac, char **av);

// UTILIDADES PARA LINKED LISTS
t_stack	*ft_stacknew(int content);
t_stack *fill_from_av(int ac, char **av);
int	stack_size(t_stack *lst);

// MOVIMENTACAO
t_stack *stack_swap(t_stack *target);
void stack_push(t_stack *src, t_stack **target);

#endif