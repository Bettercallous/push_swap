/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:13:21 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/02/20 01:13:21 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	get_len(char **av)
{
	int		i;
	int		j;
	int		len;
	char	**tmp;

	i = 0;
	len = 0;
	while (av[++i])
	{
		if (!*av[i])
			exit_error("Error\n");
		tmp = ft_split(av[i], ' ');
		j = 0;
		while (tmp[j])
		{
			len += ft_strlen(tmp[j]) + 1;
			j++;
		}
		free_strs(tmp);
	}
	return (len);
}

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

static char	*parse_input(char **av, int *len)
{
	int		i;
	int		j;
	char	*args;
	char	**tmp;

	i = 0;
	*len = get_len(av);
	args = malloc(*len);
	if (!args)
		return (NULL);
	args[0] = '\0';
	while (av[++i])
	{
		if (!*av[i])
			exit_error("Error\n");
		tmp = ft_split(av[i], ' ');
		j = -1;
		while (tmp[++j])
		{
			ft_strlcat(args, tmp[j], *len);
			ft_strlcat(args, " ", *len);
		}
		free_strs(tmp);
	}
	return (args);
}

char	**is_correct_input(char **av)
{
	int		len;
	char	*args;
	char	**all_args;

	args = parse_input(av, &len);
	all_args = ft_split(args, ' ');
	free(args);
	if (!arg_is_number(all_args))
		exit_error("Error\n");
	if (have_duplicates(all_args))
		exit_error("Error\n");
	return (all_args);
}
