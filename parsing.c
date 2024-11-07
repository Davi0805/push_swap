/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:58:55 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/11/07 15:13:05 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

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

t_stack	*populate_stack(char **argv)
{
	int		i;
	t_stack	*stack;
	t_stack	*cur;
	t_stack	*new_node;

	i = 0;
	stack = NULL;
	while (argv[i] != NULL)
	{
		new_node = ft_stacknew(ft_atol(argv[i]));
		if (!stack)
			stack = new_node;
		else
		{
			cur = stack;
			while (cur->next != NULL)
				cur = cur->next;
			cur->next = new_node;
		}
		i++;
	}
	return (stack);
}

t_stack	*fill_from_split(char *str)
{
	t_stack	*stack;
	char	**argv;

	stack = NULL;
	argv = NULL;
	argv = ft_split(str, ' ');
	if (argv == NULL || ft_split_error_check(argv) == 1
		|| ft_split_parse_error(argv) == 1)
	{
		ft_free_split(argv);
		write(1, "Error\n", 6);
		return (NULL);
	}
	stack = populate_stack(argv);
	ft_free_split(argv);
	return (stack);
}

t_stack	*parse_setup(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (ac == 1)
		return (NULL);
	else if ((parse_error(ac, av) == 1 || equal_number(ac, av) == 1) && ac != 2)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	if (ac > 2)
		stack_a = fill_from_av(ac, av);
	else if (ac == 2)
	{
		stack_a = fill_from_split(av[1]);
		if (stack_a == NULL)
			return (NULL);
	}
	return (stack_a);
}
