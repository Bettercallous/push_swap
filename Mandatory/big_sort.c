/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:09:20 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/02/21 05:48:46 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_chunks(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	count;
	int	chunk;

	count = 0;
	chunk = 15;
	if (size >= 500)
		chunk = 40;
	while (*stack_a)
	{
		if ((*stack_a)->value < (count + chunk))
		{
			pb(stack_a, stack_b);
			if ((*stack_b) && (*stack_b)->value < (count + 1))
					rb(stack_b);
			count++;
		}
		else
			ra(stack_a);
	}
	return (count);
}

static void	move_back_to_a(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	rotation;

	rotation = 0;
	while (nbr--)
	{
		rotation = get_rotation(*stack_b, nbr);
		if (rotation == 1)
			while ((*stack_b)->value != nbr)
				rb(stack_b);
		if (rotation == -1)
			while ((*stack_b)->value != nbr)
				rrb(stack_b);
		pa(stack_a, stack_b);
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b, int *tab, int size)
{
	int	count;

	replace_value_with_index((*stack_a), tab, size);
	count = sort_chunks(stack_a, stack_b, size);
	move_back_to_a(stack_a, stack_b, count);
}
