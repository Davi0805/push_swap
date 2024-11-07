/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:59:08 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/11/07 14:08:45 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "./Libft/ft_printf.h"
# include <stdio.h>
// MACROS
# define QUIET 0
# define SWAP_A 1
# define SWAP_B 2
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RRA 8
# define RRB 9

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

int		parse_error(int ac, char **av);
int		equal_number(int ac, char **av);
t_stack	*fill_from_split(char *str);
int		ft_split_error_check(char **argv);
int		ft_split_parse_error(char **av);

// UTILIDADES PARA LINKED LISTS
t_stack	*ft_stacknew(int content);
t_stack	*fill_from_av(int ac, char **av);
int		stack_size(t_stack *lst);
void	stack_add_front(t_stack **lst, t_stack *new);
void	free_stack(t_stack *target);
int		is_sorted(t_stack *stack);
t_stack	*last_stack(t_stack *lst);

// MOVIMENTACAO
void	stack_swap(t_stack *target, int flag);
void	stack_push(t_stack **src, t_stack **target, int flag);
void	stack_rotate(t_stack *target, int flag);
void	stack_reverse_rotate(t_stack **target, int flag);

// SORT
void	send_back_to_a(t_stack **stack_a, t_stack **stack_b, int size);
void	sort(t_stack **stack_a, t_stack **stack_b);
void	sort_b(t_stack **stack_a, t_stack **stack_b,
			int bit_needed, int bit_shifts);
void	replace_with_index(t_stack *stack, int size);
void	three_num(t_stack **stack);
void	four_five_num(t_stack **stack, t_stack **stack_b);
int		get_median_value(t_stack *stack);
t_stack	*parse_setup(int ac, char **av);

#endif
