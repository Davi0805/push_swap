/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:08:47 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/10/22 17:15:16 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_error(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < -2147483648)
			return (1);
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j]) == 0 && av[i][j] != '-' && av[i][j] != '+')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	equal_number(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < ac)
	{
		while (j < ac)
		{
			if (ft_atol(av[i]) == ft_atol(av[j]) && j != i)
				return (1);
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
}

int	ft_split_error_check(char **argv)
{
	int	i;
	int	j;
	int	size;

	size = 0;
	i = 0;
	j = 0;
	while (argv[size] != NULL)
		size++;
	while (i < size)
	{
		while (j < size)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]) && j != i)
				return (1);
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
}

int	ft_split_parse_error(char **av)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = 0;
	while (av[size] != NULL)
		size++;
	while (i < size)
	{
		if (ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < -2147483648)
			return (1);
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j]) == 0 && av[i][j] != '-' && av[i][j] != '+')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
