#ifndef     PUSH_SWAP_H
# define    PUSH_SWAP_H

#include <unistd.h>
#include "./Libft/ft_printf.h"
#include <stdio.h>

#define QUIET 0

#define SWAP_A 1
#define SWAP_B 2
#define SS 3

#define PA 4
#define PB 5

#define RA 6
#define RB 7

#define RRA 8
#define RRB 9




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
void	stack_add_end(t_stack **lst, t_stack *new);
void	stack_add_front(t_stack **lst, t_stack *new);
void free_stack(t_stack *target);
int is_sorted(t_stack *stack);
t_stack	*last_stack(t_stack *lst);

// MOVIMENTACAO
void stack_swap(t_stack *target, int flag);
void stack_swap_both(t_stack *stack_a, t_stack *stack_b);
void stack_push(t_stack **src, t_stack **target, int flag);
void stack_rotate(t_stack *target, int flag);
void stack_rotate_both(t_stack *stack_a, t_stack *stack_b);
void stack_reverse_rotate(t_stack **target, int flag);
void stack_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

//SORT
void first_digit_sort(t_stack **src, t_stack **target, int size);
// DEVOLVE PARA STACK A
void send_back_to_a(t_stack **stack_a, t_stack **stack_b, int size);
void second_digit_sort(t_stack **stack_a, t_stack **stack_b, int size, int shift);
void sort_stack_b(t_stack *stack_b);


#endif