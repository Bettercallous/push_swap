/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:54:08 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/02/17 00:54:08 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
			i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] && !ft_isdigit(av[i]))
		return (0);
	return (1);
}

static int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_correct_input(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!*av[i])
			exit_error("Error\n");
		if (!arg_is_number(av[i]))
			return (0);
		i++;
	}
	if (have_duplicates(av))
		return (0);
	return (1);
}
