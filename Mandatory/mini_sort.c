/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:09:25 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/01/28 15:09:25 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack **stack_a)
{
	int	max;

	max = max_value(stack_a);
	if (max == (*stack_a)->value)
	{
		ra(stack_a);
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	else if (max == (*stack_a)->next->value)
	{
		rra(stack_a);
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	else
		sa(stack_a);
}

static void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	shift_min_4_to_top(stack_a);
	if (!is_sorted(*stack_a))
		pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	shift_min_5_to_top(stack_a);
	if (is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	shift_min_4_to_top(stack_a);
	pb(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	mini_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else
		sort_5(stack_a, stack_b);
}
