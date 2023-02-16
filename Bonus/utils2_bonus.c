/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:46:30 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/02/13 23:15:42 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	*fill_ref_array(int size, char **av)
{
	int	i;
	int	*arr;

	i = 0;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	while (i < size)
	{
		arr[i] = (int)ft_atoi(av[i + 1]);
		i++;
	}
	return (arr);
}

void	sort_ref_array(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
