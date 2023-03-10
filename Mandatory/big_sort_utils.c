/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 02:50:42 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/02/21 04:49:40 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_from_arr(int *tab, int number, int tab_size)
{
	int	size;

	size = tab_size - 1;
	while (size >= 0)
	{
		if (tab[size] == number)
			return (size);
		size--;
	}
	return (-1);
}

void	replace_value_with_index(t_stack *stack_a, int *tab, int size)
{
	while (stack_a)
	{
		stack_a->value = get_index_from_arr(tab, stack_a->value, size);
		stack_a = stack_a->next;
	}
}

int	get_number_index(t_stack *stack, int number)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == number)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

int	get_rotation(t_stack *stack, int number)
{
	int	index;
	int	size;

	index = get_number_index(stack, number);
	size = ft_stacksize(stack);
	if (index <= size / 2)
		return (1);
	if (index > size / 2)
		return (-1);
	return (0);
}
