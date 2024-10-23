/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:58:55 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/10/23 16:51:01 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Caso seja varios argumentos
/* t_stack *fill_from_av(int ac, char **av)
{
    int i;
    t_stack *start;
    t_stack *stack;

    i = 1;
    stack = ft_stacknew((int)ft_atoi(av[i]));

    start = stack;

    while(i < ac - 1)
    {
        i++;
        stack->next = ft_stacknew((int)ft_atoi(av[i]));
        stack = stack->next;
    }
    return (start);
} */

t_stack	*fill_from_av(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*new_node;
	t_stack	*current;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		new_node = ft_stacknew(ft_atol(argv[i]));
		if (!new_node)
		{
			free_stack(stack);
			return (NULL);
		}
		if (!stack)
			stack = new_node;
		else
		{
			current = stack;
			while (current->next != NULL)
				current = current->next;
			current->next = new_node;
		}
		i++;
	}
	return (stack);
}

t_stack	*fill_from_split(char *str)
{
	t_stack	*stack;
	t_stack	*current;
	t_stack	*new;
	char	**argv;
	int		i;

	i = 0;
	stack = NULL;
	argv = NULL;
	argv = ft_split(str, ' ');
	if (argv == NULL || ft_split_error_check(argv) == 1
		|| ft_split_parse_error(argv) == 1)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	while (argv[i] != NULL)
	{
		new = ft_stacknew(ft_atol(argv[i]));
		if (!new)
		{
			free_stack(stack);
			return (NULL);
		}
		if (!stack)
			stack = new;
		else
		{
			current = stack;
			while (current->next != NULL)
				current = current->next;
			current->next = new;
		}
		i++;
	}
	return (stack);
}
