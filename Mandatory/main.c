/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:33:17 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/01/15 11:33:17 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	set_algo(t_stack **stack_a, t_stack **stack_b, int size, int *tab)
{
	if (is_sorted(*stack_a))
		exit(0);
	else if (size >= 2 && size <= 5)
		mini_sort(stack_a, stack_b, size);
	else if (size > 5)
		big_sort(stack_a, stack_b, tab, size);
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
		arr[i] = ft_atoi(av[i]);
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

int	main(int ac, char **av)
{
	int		*arr;
	char	**args;
	int		stack_size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	args = is_correct_input(av);
	stack_a = fill_stack(args);
	stack_b = NULL;
	stack_size = ft_stacksize(stack_a);
	arr = fill_ref_array(stack_size, args);
	sort_ref_array(arr, stack_size);
	set_algo(&stack_a, &stack_b, stack_size, arr);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
