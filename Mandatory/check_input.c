/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:33:23 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/01/15 11:33:23 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arg_is_number(char **av)
{
	int	i;
	int	j;

	j = 0;
	while (av[j])
	{
		i = 0;
		if (av[j][i] == '-' || av[j][i] == '+')
				i++;
		while (av[j][i] && ft_isdigit(av[j][i]))
			i++;
		if (av[j][i] && !ft_isdigit(av[j][i]))
			return (0);
		j++;
	}
	return (1);
}

static int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 0;
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

static char	*parse_input(char **av)
{
	int		i;
	int		j;
	char	*args;
	char	**tmp;

	i = 0;
	args = NULL;
	while (av[++i])
	{
		if (!*av[i])
			exit_error("Error\n");
		tmp = ft_split(av[i], ' ');
		args = ft_strjoin(args, tmp[0]);
		args = ft_strjoin(args, " ");
		j = 0;
		while (tmp[++j])
		{
			args = ft_strjoin(args, tmp[j]);
			args = ft_strjoin(args, " ");
		}
		free(tmp);
	}
	return (args);
}

char	**is_correct_input(char **av)
{
	char	*args;
	char	**all_args;

	args = parse_input(av);
	all_args = ft_split(args, ' ');
	free(args);
	if (!arg_is_number(all_args))
		return (NULL);
	if (have_duplicates(all_args))
		return (NULL);
	return (all_args);
}
